
#include <stdio.h>
#include "book_management.h"
#include "utility.h"
#include "library.h"
void user_menu(char username[50],Book *h,BookList bl)
{
    int option;
    //start
	do {
		printf("\n(logged in as: %s)\nPlease choose an option:\n1) Borrow a book\n2) Return a book\n3) Search for books\n4) Display all books\n5) Log out\n Option: ",username);
		option = optionChoice();
        switch (option) {
			case 1:
				borrow(h);
				break;
			case 2:
				return_(h);
				break;
			case 3:
				search(h,bl);
				break;
			case 4:
				display(h);
				break;
			case 5:
            printf("\nLogging out...\n");
				break;
			default:
				printf("Sorry, the option you entered was invalid, please try again.\n");
                break;
		}

	} while (option != 5);
	return;
}

