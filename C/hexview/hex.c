
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define	LINENUMBER	16
int		main(int argc,char *argv[],char *env[])
{
	
	char	buf[LINENUMBER+2];
	char	c;
	FILE	*f;
	int		cnt,i,j=0;
	//gets(buf);
	if(argc<2)
	{
		printf("Usage: ./hex filename");
		exit(0);
	}
	f = fopen(argv[1],"rb");
	if(f==NULL)
	{
		printf("open error!");
		exit(0);
	}
	while(1)
	{
		memset(buf,0,LINENUMBER+2);
		cnt = fread(buf,1,LINENUMBER,f);
		if(cnt!=LINENUMBER)
		{
			j++;
			printf("%05x:",j*16);
			for(i=0;i<cnt;i++)
			{
				printf("%02x ",buf[i]&0xff);
				if(32>buf[i]|| buf[i]>128)
				{
					buf[i] = 32;
				}
			}
			for(i=0;i<LINENUMBER-cnt;i++)
				printf("   ");
			printf("   %s\n",buf);
			break;
		}
		j++;
		printf("%05x:",j*16);
		for(i=0;i<LINENUMBER;i++)
		{
			
			printf("%02x ",buf[i]&0xff);
			if(32>buf[i] || buf[i]>128)
			{
				buf[i] = 32;
			}
		}
		printf("   %s\n",buf);
		
	}
	fclose(f);
	return 0;
}
