#ifndef __USERS__H__
#define __USERS__H__
#include <stdio.h>

typedef struct _User {
	    char username[30];
		char password[30];
		int borrowed[20];
		int numborrowed;
}User;

struct userslist{
	struct _User list[100];
	int num;
};

#endif