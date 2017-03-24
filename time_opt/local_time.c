#include<time.h>
#include<stdlib.h>
#include<stdio.h>


int main()
{
	//tm *localtime(const time_t *timeval)转换本地时间
	//time_t mktime(tm *timeptr)  将时tm结构体转换成time-t
	//char *asctime(const struct tm *timeptr); 转换时间到字符串
	//char *ctime(const time_t *timeval）将时间转换字符串
	//size_t strftime(char* s,size_t,const char* format,struct tm *timeptr)

	time_t timeval;
	char buff[100]={};
	struct tm *tm_ptr;

	(void)time(&timeval);
	printf("The date is : %s",ctime(&timeval));

	(void)time(&timeval);
	tm_ptr=localtime(&timeval);
	strftime(buff,100,"%a %b %H:%M%S %Y",tm_ptr);
	printf("%s\n",buff);

	exit(0);

	


}
