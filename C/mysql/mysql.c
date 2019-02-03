
#include <unistd.h>
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include "mysql.h"

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
int		main(int argc,char *argv[],char *env[])
{
		int	i,j;
		MYSQL	*pConn;
		MYSQL_RES	*pRes;
		MYSQL_ROW	row;
		pConn = mysql_init(NULL);
		if(!pConn)
		{
			fprintf(stderr,"init mysql fail");
			return 1;
		}
		pConn = mysql_real_connect(pConn,"localhost","root","lxw961224","rick",0,NULL,0);
		if(pConn)
			printf("connect success\n");
		else
		{
			printf("connect failed\n");
			return 1;
		}
		//insert data
		if(mysql_query(pConn,"insert into child(name,age) value('s1',12)")==0)
			printf("insert mysql success\n");
		else
			printf("insert mysql failed\n");

		if(mysql_query(pConn,"update child set age=14 where name='s1'")==0)
			printf("update mysql success\n");
		else
			printf("update mysql failed\n");
		
		//delete data
		if(mysql_query(pConn,"delete from child where name='s1'")==0)
			printf("delete mysql success\n");
		else
			printf("delete mysql failed\n");

		//select data;
		mysql_query(pConn,"select name,age from child");
		pRes = mysql_use_result(pConn);
		if(pRes)
		{
			while((row = mysql_fetch_row(pRes)))
			{	
				i=0;
				while(i<mysql_field_count(pConn))
				{
					printf("%s ",row[i]);
					i++;
				}
				printf("\n");
			}
				
		}
		mysql_close(pConn);
		return 0;
}
