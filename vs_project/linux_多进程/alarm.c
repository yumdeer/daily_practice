#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    alarm(5);
    pause();
    printf("I have been awaken up \n");
}


