//Runs 2 executables in 2 processes 
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc,char* argv[]){
 char * p1[]={argv[1],NULL};
 char * p2[]={argv[2],NULL};
 pid_t f1 = fork();
 if(f1==0){
 execvp(argv[1],p1);
 }
 printf("\n\n");
 pid_t f2 = fork();
 if(f2==0){
 execvp(argv[2],NULL);
 }
     waitpid(f1,NULL,0);
     waitpid(f2,NULL,0);
return 0;
}
