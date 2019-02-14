
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

static	int	isalarm = 0;
int		cnt = 0;
pthread_mutex_t	work_mutex;
void	showcwd()
{
	char	buf[256]={0};
	getcwd(buf,256);
	printf("%s\n",buf);

}


int		getMonth()
{
		time_t	start = time(NULL);
		struct	tm	*pTime;
		pTime = localtime(&start);
		return pTime->tm_mon+1;
}
int		getDay()
{
		time_t	start = time(NULL);
		struct	tm	*pTime;
		pTime = localtime(&start);
		return pTime->tm_mday;
}

void*	threadfun(void *arg)
{
		int i=0;
		for(;i<100;i++)
		{
			pthread_mutex_lock(&work_mutex);
			cnt++;
			pthread_mutex_unlock(&work_mutex);
		}
}
int		main(int argc,char *argv[],char *env[])
{
		int	i=0,j;
		int	res;
		pthread_t	thread;
		void	*result;
		res = pthread_mutex_init(&work_mutex,NULL);
		if(res!=0)
		{
			perror("mutex init failed\n");
			exit(1);
		}
		res = pthread_create(&thread,NULL,threadfun,NULL);
		if(res!=0)
		{
			perror("create thread error\n");
			exit(0);
		}
		for(i=0;i<100;i++)
		{
			pthread_mutex_lock(&work_mutex);
			cnt++;
			pthread_mutex_unlock(&work_mutex);
		}
		pthread_join(thread,&result);
		printf("%d\n",cnt);
		return 0;
}
