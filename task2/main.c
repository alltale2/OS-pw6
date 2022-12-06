#include <unistd.h>
#include <sys/types.h>

#define SECONDS 3

void main(int argc, char const *argv[])
{
	pid_t pid;
	printf("FORK \n");
	pid=fork();
	if(pid==0){
		time_t now=time(NULL);
		int count=0;
		while(time(NULL)!=now+SECONDS)
			count++;
		printf("Потомок ID = %ld count = %d\n",getpid(),count);
	}else if(pid>0){
		time_t now=time(NULL);
		int count=0;
		while(time(NULL)!=now+SECONDS)
			count++;
		printf("Родитель ID = %ld count = %d\n",getpid(),count);
	}else printf("Error\n");
	return 0;
}