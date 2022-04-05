#include <stdio.h>
#include "library.h"

int main(int argc, char **argv) {
    if (argc != 1) {
        printf("You do not have to use command line argument.");
    } else {
	library_menu();
	return 0;
}
}