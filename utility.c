#include <stdio.h>
#include <stdlib.h>
int optionChoice( void ) {
    int option = -1;
    char line[80];
    fflush(stdin);
    // read in the current line as a string
    fgets(line,80,stdin);

    // atoi() converts string to integer, returns 0 if could not convert
    option = (int)atoi(line);

    return option;
}