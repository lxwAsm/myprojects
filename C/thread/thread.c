
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

char	message[100]="hello,args\n";
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

void*	thread_function(void *arg)
{

		printf("get date...\n");
		sleep(3);
		strcpy(message,"args changed\n");
		printf("%d-%d\n",getMonth(),getDay());
}
int		main(int argc,char *argv[],char *env[])
{
		int	i=0,j;
		int	res;
		pthread_t	thread;
		void	*result;
		res = pthread_create(&thread,NULL,thread_function,(void*)message);
		if(res!=0)
		{
			perror("thread error\n");
			exit(1);
		}
		pthread_join(thread,&result);
		printf(message);
		//exit(0);
		return 0;
}
