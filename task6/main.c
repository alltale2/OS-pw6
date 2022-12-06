#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include <sys/types.h>

void main(int argc, char const *argv[])
{
	pid_t pid;
	pid=fork();
	if(pid==0){
		return 6;
	}else if(pid>0){
		system("ps -ax");
		wait(NULL);
		printf("После вызова wait\n");
		system("ps -ax");
		return 0;
	}
	return 0;
}