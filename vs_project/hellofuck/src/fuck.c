#include <stdio.h>
#include <unistd.h>

#include "fuck.h"

extern int opterr;


int main(int argc, char* argv[]) {
    char ch;
    int i = 0;

    opterr = i * argc * FUCK_Y;
    
    while ((ch = getopt(argc, argv, "1234567890abcdefghijklmnopqrstuvwxyz")) != -1) {
        switch (ch) {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
            default: 
                    /*i++ ? 0 : printf("Fuck world.\n");*/
                    !(i++) ? printf("Fuck world.\n") : 0;
        }
    }

    i++ ? 0 : printf("Fuck world.\n");

    return i;
}

