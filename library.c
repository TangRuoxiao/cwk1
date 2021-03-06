#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "book_management.h"
#include "utility.h"
#include "user_management.h"
#include "librarian.h"
#include "user.h"
#define CreateNode(p) p=(Book *)malloc(sizeof(Book));
#define DeleteNode(p)   free((void *)p);
char username2[50];
struct userslist list;
struct userslist *userslist = &list;

int register_()
{   int i;
    char username[50],password[50];
    //start
    printf("Please enter a username: ");
    scanf("%s",username);
    printf("Please enter a password: ");
    scanf("%s",username);
    //if exist
    for (i = 0; i <= userslist->num; i++)
    {
        if (strcmp(username, "librarian")== 0 || strcmp(username, userslist->list[i].username)  == 0)
        {
            printf("\nUser already exists.\n");
            return 1;
        }
    }
    //do
    userslist->num += 1;
    strcpy(userslist->list[userslist->num].username, username);
    strcpy(userslist->list[userslist->num].password, password);
    userslist->list[userslist->num].numborrowed = 0;
    printf("\nRegistered library account successfully!\n");
    return 0;
}

int login(Book *h,BookList bl)
{
    char username[40],password[40];
    //start
    printf("Please enter a username: ");
    scanf("%s",username);
    printf("Please enter a password: ");
    scanf("%s",password);
    strcpy(username2, username);
    //librarian
    if (strcmp(username, "librarian")==0 && strcmp(password, "librarian")==0)
    {
        librarian_menu(h,bl);
        return 0;
    }else //user
    {
    for (int i = 0; i <= userslist->num; i++) {
            if (strcmp(username, userslist->list[i].username) == 0 && strcmp(password, userslist->list[i].password) == 0) {
            user_menu(username2,h,bl);
            return 0;
        }
    }
     }
     //error
    printf("\nAccount not found or Wrong password.\n");
    return 1;
}

int search(Book *h,BookList bl){
    int option,year;
    char author[50],title[50];
    bl.list = (Book *) malloc(sizeof(Book));
    bl.length = 0;
    //start
    printf("\nLoading search menu...\n");
    do {
		printf("\nPlease choose an option:\n1) Find books by title\n2) Find books by author\n3) Find books by year\n4) Return to previous menu\n Option: ");
		option = optionChoice();
        switch (option) {
			case 1:
            printf("Please enter title: ");
            scanf("%s",title);
            bl=find_book_by_title(title,h);
            if (bl.length==0)
            {
                printf("\nBook not found\n");
                break;
            }
            //printf
            printf("ID           Title           Authors           Year           Copies           \n");
            for (int i = 0; i < bl.length; i++)
            {
                printf("%-12d %-15s %-17s %-14d %-14d\n",(bl.list)->id,(bl.list)->title,(bl.list)->authors,(bl.list)->year,(bl.list)->copies);bl.list++;
            }
                break;
			case 2:
            printf("Please enter author: ");
            scanf("%s",author);
            bl=find_book_by_author(author,h);
                if (bl.length==0)
            {
                printf("book not found\n");
                break;
            }
            printf("ID           Title           Authors           Year           Copies           \n");
            for (int i = 0; i < bl.length; i++)
            {
                printf("%-12d %-15s %-17s %-14d %-14d\n",(bl.list)->id,(bl.list)->title,(bl.list)->authors,(bl.list)->year,(bl.list)->copies);bl.list++;
            }
                break;
			case 3:
            printf("Please enter year: ");
            scanf("%d",&year);
            bl=find_book_by_year(year,h);
				if (bl.length==0)
            {
                printf("book not found\n");
                break;
            }
            printf("ID           Title           Authors           Year           Copies           \n");
            for (int i = 0; i < bl.length; i++)
            {
                printf("%-12d %-15s %-17s %-14d %-14d\n",(bl.list)->id,(bl.list)->title,(bl.list)->authors,(bl.list)->year,(bl.list)->copies);bl.list++;
            }
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
    //start
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



int load_user(FILE *file)
{
    //if fail
    if (file==NULL) {
        printf("File open error.\n");
		return -1;
	}
    int u;
    //start
    for (u = 0; !feof(file); u++) {
        fscanf(file, "%s %s %d", userslist->list[u].username, userslist->list[u].password, &userslist->list[u].numborrowed);
        for (int k = 0; k < userslist->list[u].numborrowed; k++) {
            fscanf(file, "%d", &userslist->list[u].borrowed[k]);
        }
    }
    userslist->num = u - 1;
    return 0;
}

int store_user(FILE *file)
{
    //if fail
    if (file==NULL) {
        printf("File open error.\n");
		return -1;
	}
    int u;
    //start
    for (u = 0; u < userslist->num; u++) {
        fprintf(file, "%s %s %d\n", userslist->list[u].username, userslist->list[u].password, userslist->list[u].numborrowed);
        for (int k = 0; k < userslist->list[u].numborrowed; k++) {
            fprintf(file, "%d\n", userslist->list[u].borrowed[k]);
        }
    }
    fprintf(file, "%s %s %d\n", userslist->list[u].username, userslist->list[u].password, userslist->list[u].numborrowed);
    int k;
    for (k = 0; k < userslist->list[u].numborrowed - 1; k++) {
        fprintf(file, "%d\n", userslist->list[u].borrowed[k]);
    }
    fprintf(file, "%d", userslist->list[u].borrowed[k]);
    return 0;
}
int borrow(Book *h){
    int id_borrowed,u;
    printf("Enter the ID number of the book you wish to borrow: ");
    scanf("%d",&id_borrowed);getchar();
    for (u = 0; u <= userslist->num; u++) {
        if (id_borrowed>0 && strcmp(username2, userslist->list[u].username) == 0 ) {
            //user
            Book *p;
            CreateNode(p)
            //book
            for ( p = h; p->next!=NULL ; p=p->next)
            {
                if (p->id==id_borrowed)
                {
                    //no book
                    if (p->copies==0)
                    {
                        printf("\nBook not found\n");
                        return 1;
                    }
                    //already
                    for (int i = 0; i < userslist->list[u].numborrowed; i++)
                    {
                        if (userslist->list[u].borrowed[i]==id_borrowed)
                        {
                        printf("\nSorry, you already have a copy of this book on loan.\n");
                        return 1;
                        }
                    }
                    //do
                    userslist->list[u].borrowed[userslist->list[u].numborrowed] = id_borrowed;
                    userslist->list[u].numborrowed++;
                    printf("\nSuccessfully borrowed.\n");
                    return 0;
                }
                printf("\nBook not found.\n");
                return 1;
                
            }
            
        }
    
        
    }
    
    
}
int return_(Book *h){
    int id_returned,l,nb;
    l=1;
    nb=1;
    //start
    for (int u = 0; u <=userslist->num ; u++)
    {
        if (strcmp(username2, userslist->list[u].username) == 0)
        {
            //if no
        if (userslist->list[u].numborrowed==0)
            {
            printf("You have not borrowed any book.");
            return 1;
            }
        //CLI
        printf("Below is the list of Books you are currently borrowing:\n");
        printf("ID           Title           Authors           Year           Copies           \n");
            for (int j = 0; j < userslist->list[u].numborrowed; j++) {
                Book *p;
                CreateNode(p);
                p=h;
                while (p ->next!= NULL) {
                    if (p->id == userslist->list[u].borrowed[j]) {
                        printf("%-12d %-15s %-17s %-14d %-14d\n",p->id,p->title,p->authors,p->year,p->copies);
                        nb++;
                    }
                    p = p->next;
                    l++;
                }
            }
        
    //option
        printf("Enter the ID number of the book you wish to return: ");
        scanf("%d",&id_returned);
        getchar();
    int i, n = 0;
            for (int j = 0; j < userslist->list[u].numborrowed; j++) {
                if (userslist->list[u].borrowed[j] == id_returned) {
                    for (int k = j; k < userslist->list[u].numborrowed - 1; k++) {
                        userslist->list[u].borrowed[k] = userslist->list[u].borrowed[k + 1];
                    }
                    userslist->list[i].numborrowed--;
                    Book *p;
                    CreateNode(p)
                    for ( p=h; p->next!=NULL; p=p->next)
                    {
                        if (p->id==id_returned)
                        {
                            //if no
                            if (p->copies==0)
                            {
                                printf("There is no more copies.");
                                return 1;
                            }
                        p->copies++;       
                        }
                    }
                printf("\nReturned book successfully\n");
                return 0;
                }
            }
    }
    //fail
    printf("\nReturned book not successfully\n");
        return 0;
        
    
    }

        }
void library_menu() 
{
	int option;
    //book
    Book *h=NULL;
    CreateNode(h);
    FILE *fp = fopen("books.txt","r");
    load_books(fp,h);
    fclose(fp);
    //booklist
    BookList bl;
    bl.list = (Book *) malloc(sizeof(Book));
    bl.length = 0;
    //user
    FILE *fpu = fopen("users.txt","r+");
    load_user(fpu);
    fclose(fpu);
    //CLI
	do {
		printf("\nPlease choose an option:\n1) Register an account\n2) Login\n3) Search for books\n4) Display all books\n5) Quit\n Option: ");
		option = optionChoice();
        switch (option) {
			case 1:
				register_();
				break;
			case 2:
				login(h,bl);
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
    //book
    FILE *fpc=fopen("books.txt","w+");
    store_books(fpc,h);
    fclose(fpc);
    //user
    FILE *fpuc=fopen("users.txt","w+");
    store_user(fpuc);
    fclose(fpuc);
    //bye
    printf("\nThank you for using the library!\nGoodbye!");
	return;
}