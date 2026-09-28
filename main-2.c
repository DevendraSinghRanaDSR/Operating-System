#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int pid;
    pid=fork();
    
    if(pid==0){
        printf("Child Process: ");
        printf("\nChild ID = %d ",getpid());
        printf("\nParent ID = %d ",getppid());
    }
    else{
         wait(NULL);//it let child process complete first then parent process ie it makes it wait 
         sleep(3);  //it makes parent process sleep ie idle for 3 seconds
        printf("\nParent Process: ");
        printf("\nParent ID = %d ", getpid());
        printf("\nChild ID = %d ",pid);
    }
    return 0;
}