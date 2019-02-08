
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>

static	int	isalarm = 0;
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

void	ouch(int sig)
{
		printf("I got singal %d\n",sig);
		signal(SIGINT,SIG_DFL);
}
void	ding(int sig)
{
		isalarm = 1;
}
int		main(int argc,char *argv[],char *env[])
{
		int	i=0,j;
		char	*message;
		//signal(SIGINT,ouch);
		pid_t	pid;
		pid = fork();
		switch(pid)
		{
			case	-1:
				printf("fork fail\n");
				exit(0);
			case	0:
				sleep(5);
				kill(getppid(),SIGALRM);
				exit(0);
			default:
				printf("waiting for alarm!\n");
				signal(SIGALRM,ding);
				pause();
				if(isalarm)
					printf("ding\n");
				printf("done!\n");
		}
		
		//exit(0);
		return 0;
}
