#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>

PrintFirst(int	wDay)
{
	while(wDay-->0)
		printf("\t");
}
int
GetWeekDay(int year,int  month)
{
    int     w;
	int		c,y;
	c=year/100;
	y=year%100;//zz正确的提取
    if(month<=2 && month>0)
    {
        year--;//上一年
        c=year/100;
        y=year%100;//重新赋值
        w=c/4-2*c+y+y/4+(13*(month+13))/5;
    }
    else
    {
        w=c/4-2*c+y+y/4+(13*(month+1))/5;
    }
    if(w>0)
        w=w%7;
    else
        w=(w%7+7)%7;
    return  w;
}
int
GetCountDays(int  year,int month)
{
        int     flag;
        if((year%4==0&&year%100!=0) || year%400==0)
            flag=1;
        else
            flag=0;
        if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 ||month==12)
            return  31;//1,3,5,7,8,等月份
        if(month ==2)
        {
            if(flag)
                return  29;
            else
                return  28;
        }

        return  30;//其他月份
}
int
PrintCalendar(int year,int	month)
{
		int		cnt;//用做换行
		int		i;
		int		AllDay;
		int		w;
		char	*title[]={"日","一","二","三","四","五","六"};
		char	buffer[50];

		
		if(month>0 && month<13)
		{	
			if(year-1000>=0 && year-10000<0)
			{
			printf("\n");
			for(i=0;i<7;i++)
				printf("%s\t",title[i]);//打印出汉字
			
			printf("\n");
			sprintf(buffer,"color f%d",rand()%13+1);
			system(buffer);
			w=GetWeekDay(year,month);
			cnt = w;
			AllDay = GetCountDays(year,month);
			for(i=1;i<=AllDay;i++)
				{
					if(i==1)	PrintFirst(cnt);
					printf("%d\t",i);

					if(cnt==6)	{printf("\n");cnt=0;continue;}
					cnt++;
				}
				printf("\n");
			}//if end
			else
			return	-1;
		}
		else
		return	-1;
}
int
GetMonth(void)
{
	struct	tm	*tm1;
	time_t	tm2=time(0);
	tm1=localtime(&tm2);
	return	tm1->tm_mon+1;
}
int
GetYear()
{
	struct	tm	*tm1;
	time_t	tm2;
	tm2=time(0);
	tm1=localtime(&tm2);
	return	tm1->tm_year+1900;
}
int		main()
{
			int		month,year;
			char	buffer[100];
			system("color f4");
			sprintf(buffer,"输入任意一个月份，程序会打印出来!:\n输入格式[year,month];当前日期:(%d,%d) :",GetYear(),GetMonth());
			srand(time(0));//产生随机数
			while(1)
			{
			printf(buffer);
			scanf("%d,%d",&year,&month);
			if(PrintCalendar(year,month)==-1)
				printf("输入的数据错误,请重试!\n");
			}
			return	0;
}