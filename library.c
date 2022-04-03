#include <stdio.h>
#include "book_management.h"
#include "utility.h"
#include "user_management.h"
#define CreateNode(p) p=(Book *)malloc(sizeof(Book));
#define DeleteNode(p)   free((void *)p);

void library_menu() {
	int option;
    Book *h;
    CreateNode(h);
    FILE *fp = fopen("books.txt","r+");
    load_books(fp,h);
	do {
		printf("\nPlease choose an option:\n1) Register an account\n2) Login\n3) Search for books\n4) Display all books\n5) Quit\n Option: ");
		option = optionChoice();
        switch (option) {
			case 1:
				register_();
				break;
			case 2:
				login(h);
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
    store_books(fp,h);
    printf("\nThank you for using the library!\nGoodbye!");
	return;
}

int register_()
{
    char username,password;
    scanf("Please enter a username: %s",&username);
    scanf("Please enter a password: %s",&password);
    for (size_t i = 0; i < count; i++)
    {
        if (username==p->username)
        {
            printf("Sorry, registration unsuccessful, the username you entered already exists.");
            return;
        }
    }
    //加信息
    printf("Registered library account successfully!");
    return;
}

int login(Book *h)
{
    char username,password;
    scanf("Please enter a username: %s",&username);
    scanf("Please enter a password: %s",&password);
    if (username="librarian"&&password==librarian)
    {
        librarian_manu(h);
        return;
    }
    
    for (Book *p=h; i < count; i++)
    {
        if (username==p->username)
        {
            user_manu(username,h);
            return;
        }
    }
    printf("Account not found.");
    return;
}

int search(Book *h){
    int option,year;
    char author,title;
    printf("\nLoading search menu...\n");
    do {
		printf("\nPlease choose an option:\n1) Find books by title\n2) Find books by author\n3) Find books by year\n4) Return to previous menu\n Option: ");
		option = optionChoice();
        switch (option) {
			case 1:
            printf("Please enter year: %d",&year);

				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			default:
				printf("Sorry, the option you entered was invalid, please try again.\n");
		}
	} while (option != 4);
    
}

int display(Book *h)
{
    Book *p;
    CreateNode(p)
    printf("ID\tTitle\tAuthors\tyear\tcopies\n");
    for (p=h->next;p;p=p->next)
    {
        if (p=NULL)
        {
            break;
        }
        printf("%5d%20s%20s%5d%5d\n",p->id,p->title,p->authors,p->year,p->copies);
    }
    return;
}
