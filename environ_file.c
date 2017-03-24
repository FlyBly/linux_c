#include<stdlib.h>
#include<stdio.h>

//获取系统变量
extern char **environ;
int main()
{

	char **env=environ;
	
	while(*env)
	{
		
	printf("%s\n",*env);
	env++;
	}
	exit(0);

}
