#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <math.h>

#define A 0
#define B 10
#define C 10
#define D 20
#define R 5

void main(int argc, char const *argv[])
{
	pid_t pid;
	int count_dots=/*2147483646*/100000;
	char str[11];
	int result=0;
	int check[(int)(ceil((double)count_dots/250.0)) ]; 
	for(int i = 0; i < (int)ceil((double)count_dots/250.0);i++){
		pid=fork();
		if(pid==0){
				if ((i == (ceil((double)count_dots/250.0)-1))&&((count_dots % 250)!=0))
					sprintf(str,"%i'\0'", count_dots % 250);
				else
					sprintf(str,"%i'\0'", 250);
				execlp("./d.out","d.out",str,NULL); 
				printf("%s\n", "Error");
		}else if(pid>0){
				if(wait(&result)==-1){
					printf("error wait\n");
					return 1;
			}
			//printf("result %i\n",result);
			if(WIFEXITED(result))
				check[i]=WEXITSTATUS(result);
		}
	}
	double popadanie = 0;
	for(int i = 0; i < (int)ceil((double)count_dots/250.0);i++)
		popadanie = popadanie+(double)check[i];
	double square_pramoyg=(double)((B-A)*(D-C));
	printf("square_pramoyg %f\n",square_pramoyg);
	double square_fig=(((double)popadanie)*square_pramoyg)/((double)count_dots);
	printf("Площадь фигуры = %f\n",square_fig);
	
	printf("pi = %f\n", square_fig/(double)(R*R)  );

	return 0;
}
