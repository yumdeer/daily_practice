#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void func(){
    printf("I have been awaken up\n");
    system("date");
}

int main(){
    signal(SIGALRM,func);
    system("date");
    alarm(20);
    pause();
    printf("why print???");
    return 0;
}

