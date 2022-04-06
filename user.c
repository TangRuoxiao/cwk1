#include <stdio.h>
#include "book_management.h"
#include "utility.h"
#include "library.h"
void user_menu(char username,Book *h,User *hu,BookList bl)
{
    int option;
	do {
		printf("\n(logged in as: %s)\nPlease choose an option:\n1) Borrow a book\n2) Return a book\n3) Search for books\n4) Display all books\n5) Log out\n Option: ",username);
		option = optionChoice();
        switch (option) {
			case 1:
				//borrow(username,h);
				break;
			case 2:
				//return_(username,h);
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
/*
int borrow(char username,Book *h){
    int id_borrowed;
    printf("Enter the ID number of the book you wish to borrow: ");
    scanf("%d",&id_borrowed);
    if ()
    {
        printf("ID not found.");
        return;
    }
    if ()
    {
        printf("Sorry, you already have a copy of this book on loan.");
        return;
    }
    //处理信息
    return;
}
int return_(){
    int id_returned;
    if ()
    {
        printf("You have not borrowed any book.");
        return;
    }
    printf("Below is the list of Books you are currently borrowing:\n");
    for ( i = 0; i < count; i++)
    {
        
    }
    printf("Enter the ID number of the book you wish to return: ");
    scanf("%d",&id_returned);
    if ()
    {
        printf("invalid id.");
    }
    //处理信息
    printf("Returned book successfully!");
    return;
}
*/