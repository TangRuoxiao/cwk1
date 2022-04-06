#include <stdio.h>
#include<stdlib.h>
#include "book_management.h"
#include "utility.h"
#include "user_management.h"
#include "librarian.h"
#include "user.h"
#define CreateNode(p) p=(Book *)malloc(sizeof(Book));
#define DeleteNode(p)   free((void *)p);



int register_(User *hu)
{
    User *p;
    p=(User *)malloc(sizeof(User));
    printf("Please enter a username: ");
    scanf("%s",p->username);
    printf("Please enter a password: ");
    scanf("%s",p->password);
    for (User *i=hu; i!=NULL; i=i->next)
    {
        if (i->username==p->username)
        {
            printf("user already exists.");
            return 1;
        }
    }
    //加信息
    p->next=NULL;
    User *q;
    q=hu;
    while (q->next!=NULL)
    {
        q=q->next;
    }
    q->next=p;
    printf("\nRegistered library account successfully!\n");
    return 0;
}


int login(Book *h,User *hu,BookList bl)
{
    char username[40],password[40];
    printf("Please enter a username: ");
    scanf("%s",&username);
    printf("Please enter a password: ");
    scanf("%s",&password);
    if (username=="librarian"&&password=="librarian")
    {
        librarian_menu(h,bl);
        return 0;
    }
    
    for (User *p=hu; p!=NULL; p=p->next)
    {
        if (username==p->username)
        {
            user_menu(username,h,hu,bl);
            return 0;
        }
    }
    printf("\nAccount not found.\n");
    return 1;
}

int search(Book *h,BookList bl){
    int option,year;
    char author[50],title[50];
    bl.list = (Book *) malloc(sizeof(Book));
    bl.length = 0;
    printf("\nLoading search menu...\n");
    do {
		printf("\nPlease choose an option:\n1) Find books by title\n2) Find books by author\n3) Find books by year\n4) Return to previous menu\n Option: ");
		option = optionChoice();
        switch (option) {
			case 1:
            bl=find_book_by_title(title,h);
                break;
			case 2:
            printf("Please enter author: ");
            scanf("%s",&author);
            bl=find_book_by_author(author,h);
                
				break;
			case 3:
            printf("Please enter year: ");
            scanf("%d",&year);
            bl=find_book_by_year(year,h);
				break;
			case 4:
            printf("Returning to the previous menu...\n");
				break;
			default:
				printf("Sorry, the option you entered was invalid, please try again.\n");
                break;
        }
	} while (option != 4);
    return 0;
}

int display(Book *h)
{
    Book *p;
    CreateNode(p)
    printf("ID           Title           Authors           Year           Copies           \n");
    for (p=h->next;p;p=p->next)
    {
        if (p==NULL)
        {
            break;
        }
        printf("%-12d %-15s %-17s %-14d %-14d\n",p->id,p->title,p->authors,p->year,p->copies);
    }
    return 0;
}

void library_menu() {
	int option;
    Book *h=NULL;
    CreateNode(h);
    FILE *fp = fopen("books.txt","r");
    load_books(fp,h);
    fclose(fp);
    BookList bl;
    bl.list = (Book *) malloc(sizeof(Book));
    bl.length = 0;
    FILE *fpu = fopen("users.txt","r+");
    User *hu=NULL;
    hu = (User*) malloc(sizeof(User));
    load_user(fpu,hu);

	do {
		printf("\nPlease choose an option:\n1) Register an account\n2) Login\n3) Search for books\n4) Display all books\n5) Quit\n Option: ");
		option = optionChoice();
        switch (option) {
			case 1:
				register_(hu);
				break;
			case 2:
				login(h,hu,bl);
				break;
			case 3:
				search(h,bl);
				break;
			case 4:
				display(h);
				break;
			case 5:
				break;
			default:
				printf("Sorry, the option you entered was invalid, please try again.\n");
                break;
		}
	} while (option != 5);
    FILE *fpc=fopen("books.txt","w+");
    store_books(fpc,h);
    fclose(fpc);
    FILE *fpuc=fopen("users.txt","w+");
    store_user(fpuc,hu);
    fclose(fpuc);
    free(h);
    free(hu);
    printf("\nThank you for using the library!\nGoodbye!");
	return;
}