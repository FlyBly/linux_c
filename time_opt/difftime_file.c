#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//difftime(time_t 1,time_t 2)  函数计算两时间值 返回类型double
//gmtime(time_t)  		获取时间格式的结构体 struct tm

int main()
{
	struct tm *tm_ptr;
	time_t the_time;

	(void)time(&the_time);
	tm_ptr = gmtime(&the_time);

	printf("Raw time is %ld\n",the_time);
	printf("gmtime gives :\n");
	printf("date:%02d/%02d/%02d\n",
		tm_ptr->tm_year,tm_ptr->tm_mon+1,tm_ptr->tm_mday);

  	 printf("time:%02d/%02d/%02d\n",
                tm_ptr->tm_hour,tm_ptr->tm_min,tm_ptr->tm_sec);

	exit(0);
	
}
