#include "book_management.h"
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#define CreateNode(p) p=(Book *)malloc(sizeof(Book));
#define DeleteNode(p)   free((void *)p);
#define N 100

int store_books(FILE *file,Book *h)
{   //check if fail
    if (file==NULL) {
        printf("File open error.\n");
		return -1;
	}
    //new pointer
    Book *p;
    for ( p=h->next; p!=NULL; p=p->next)
    {
        fprintf(file,"%d %s %s %d %d\n",p->id, p->title, p->authors, p->year, p->copies);
    }
    return 0;
}

int load_books(FILE *file,Book *h)
{   //check if fail
    if (file==NULL) {
        printf("File open error.\n");
		return -1;
	}
    int year,id,copies;
    char buf[200];
    //new pointer
    Book *p,*last;
    last=h;                    
    while(1){
		if (fgets(buf,255,file)==NULL) break;	// check end
		CreateNode(p)	
        char * authors=(char*) malloc(sizeof(char));
        char * title=(char*) malloc(sizeof(char));
        sscanf(buf,"%d %s %s %d %d",&id,title,authors,&year,&copies);
        p->id=id;p->title=title;p->authors=authors;p->year=year;p->copies=copies;
        
        last->next=p;
        last=p;
        }

        last->next=NULL;
        return 0;
}

int add_book(Book *h){
    //new pointer
    Book *p;
    CreateNode(p);
    char buf[50];
    //start
    printf("Enter the title of the book you wish to add: ");
    memset(buf, '\0', 50);
    scanf("%s",buf);
    p->title= (char *)malloc(sizeof(strlen(buf)));
    strcpy(p->title, buf);
    printf("Enter the author of the book you wish to add: ");
    memset(buf, '\0', 50);
    scanf("%s",buf);
    p->authors= (char *)malloc(sizeof(strlen(buf)));
    strcpy(p->authors, buf);
    printf("Enter the year of the book you wish to add was released: ");
    scanf("%d",&p->year);
    getchar();
    printf("Enter the number of copies of the book you wish to add: ");
    scanf("%d",&p->copies);
    getchar();
    p->next=NULL;
    Book *q;
    q=h;
    while (q->next!=NULL)
    {
        q=q->next;
    }
    q->next=p;
    p->id=q->id+1;
    printf("Book was successfully added!");
    return 0;
}

int remove_book(Book *h){
    int id_removed;
    //start
    printf("Enter the id of the book you wish to remove: ");
    scanf("%d",&id_removed);
    //new pointer
    Book *p = NULL;
    p = h->next;
    Book *a = h;
    while (p) {
        if (p->id == id_removed) {
            a->next = p->next;
            DeleteNode(p)
            printf("Successfully removed a book\n");
            return 0;
        }
        p = p->next;
        a = a->next;
    }
    printf("Book not found\n");
    return -1;
}

BookList find_book_by_title(const char *title, Book *h) {
    Book *p;
    BookList bl;
    bl.length = 0;
    //malloc
    CreateNode(bl.list)
    for (p = h->next;p!=NULL;p=p->next) {
        if (strcmp(title, p->title) == 0) {
            *(bl.list + bl.length) = *p;
            bl.length ++;}
    }
    return bl;
}

BookList find_book_by_author(const char *author, Book *h) {
    Book *p;
    BookList bl;
    bl.length = 0;
    //malloc
    CreateNode(bl.list)
    for (p = h->next;p!=NULL;p=p->next) {
        if (strcmp(author, p->authors) == 0) {
            *(bl.list + bl.length) = *p;
            bl.length ++;}
    }
    return bl;

}

BookList find_book_by_year(unsigned int year, Book *h) {
    Book *p;
    BookList bl;
    bl.length = 0;
    //malloc
    CreateNode(bl.list)
    for (p = h->next;p!=NULL;p=p->next) {
        if (p->year==year) {
            *(bl.list + bl.length) = *p;
            bl.length ++;}
    }
    return bl;


}
