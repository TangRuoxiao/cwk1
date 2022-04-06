#include <stdio.h>

typedef struct _User {
	    char username;
		char password;
		int borrowed[15];
		int numborrowed;
		struct _User *next;
}User;

int load_user(FILE *file,User *h);
int store_user(FILE *file,User *h);