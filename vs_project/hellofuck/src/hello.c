#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "hello.h"

int main(int argc, char* argv[]) {
    int *x = HELLO_X;

    x = (int *)malloc(sizeof(int) * 10);
    free(x);
    printf("Hello world.\n");
    
    return (int)(sqrt(acos(sin(M_E))*M_PI) * (int)x);
}

