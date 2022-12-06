#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

void main(int argc, char const *argv[])
{
	setbuf(stdout,NULL);
	printf("MAIN %ld\n",getpid());
	int local=0;
	pid_t pid[2];
	pid[0] =fork();
	if (pid[0]==0){
		//потомок
		local++;
		printf("D\nЗначение переменной = %d\nАдресс = %p\nРодительский pid = %ld\nСвой pid = %ld\n",local,&local,getppid(),getpid());
		pid_t pidd[2];
		pidd[0]=fork();
		if (pidd[0]==0){
			//потомок
			local++;
			printf("D\nЗначение переменной = %d\nАдресс = %p\nРодительский pid = %ld\nСвой pid = %ld\n",local,&local,getppid(),getpid());
		} else if(pidd[0]>0){
			//родитель
			pidd[1]=fork();
			if(pidd[1]==0){
				//потомок
				local++;
				printf("D\nЗначение переменной = %d\nАдресс = %p\nРодительский pid = %ld\nСвой pid = %ld\n",local,&local,getppid(),getpid());
			}else if(pidd[1]>0){
				//родитель
				printf("Second MAIN IDs1 = %ld IDs2 = %ld\n",pidd[0],pidd[1]);
				wait(NULL);
			}
		}
	} else if(pid[0]>0){
		//родитель
		pid[1] =fork();
		if (pid[1]==0){
			//потомок
			local++;
			printf("D\nЗначение переменной = %d\nАдресс = %p\nРодительский pid = %ld\nСвой pid = %ld\n",local,&local,getppid(),getpid());
			pid_t pidd[2];
			pidd[0]=fork();
			if (pidd[0]==0){
				//потомок
				local++;
				printf("D\nЗначение переменной = %d\nАдресс = %p\nРодительский pid = %ld\nСвой pid = %ld\n",local,&local,getppid(),getpid());
			} else if(pidd[0]>0){
				//родитель
				pidd[1]=fork();
				if(pidd[1]==0){
					//потомок
					local++;
					printf("D\nЗначение переменной = %d\nАдресс = %p\nРодительский pid = %ld\nСвой pid = %ld\n",local,&local,getppid(),getpid());
				}else if(pidd[1]>0){
					//родитель
					printf("Second MAIN IDs1 = %ld IDs2 = %ld\n",pidd[0],pidd[1]);
				}
			}
		}else if(pid[1]>0){
			//родитель
			printf("MAIN ID1 = %ld ID2 = %ld\n",pid[0],pid[1]);
			wait(NULL);
		}
	}
	return 0;
}