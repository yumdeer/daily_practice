#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    printf("Father pid,pid=%d\n",getpid());

    pid_t p1=fork();
    pid_t p2=fork();
    if(p1==0){
        printf("in child1,pid=%d,his father,pid=%d\n",getpid(),getppid());
        return 0;
    }

    if(p2==0){
         printf("in child2,pid=%d,his father,pid=%d\n",getpid(),getppid());
         return 0;
     }
}

