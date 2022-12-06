#include <unistd.h>
#include <sys/types.h>

void main(int argc, char const *argv[])
{
	printf("pid процесса %d\n",getpid());
	printf("pid родительского процесса %d\n",getppid());
	printf("pid ргруппы %d\n",getpgrp());
	printf("ID реального пользователя %d\n",getuid());
	printf("Эффективный ID пользователя %d\n",geteuid());
	printf("ID группы %d\n",getgid());
	printf("Эффективный ID группы %d\n",getegid());
	return 0;
}