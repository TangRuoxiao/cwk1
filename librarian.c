#include <stdio.h>
#include "book_management.h"
#include "utility.h"
#include "library.h"
int librarian_manu(Book *h)
{
    int option;
	do {
		printf("\n(logged in as: librarian)\nPlease choose an option:\n1) Add a book\n2) Remove a book\n3) Search for books\n4) Display all books\n5) Log out\n Option: ");
		option = optionChoice();
        switch (option) {
			case 1:
                Book newbook;
				add_book(newbook,h);
				break;
			case 2:
				remove_book(h);
				break;
			case 3:
				search(h);
				break;
			case 4:
				display(h);
				break;
			case 5:
				break;
			default:
				printf("Sorry, the option you entered was invalid, please try again.\n");
		}

	} while (option != 5);
	return;
}
