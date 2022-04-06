#include "book_management.h"
#include<string.h>
#include <stdlib.h>
#define CreateNode(p) p=(Book *)malloc(sizeof(Book));
#define DeleteNode(p)   free((void *)p);
#define N 100

int store_books(FILE *file,Book *h)
{
    if (file==NULL) {
        printf("File open error.\n");
		return -1;
	}
    Book *p;
    for ( p=h->next; p!=NULL; p=p->next)
    {
        fprintf(file,"%d %s %s %d %d\n",p->id, p->title, p->authors, p->year, p->copies);
    }
    return 0;
}

int load_books(FILE *file,Book *h)
{
    if (file==NULL) {
        printf("File open error.\n");
		return -1;
	}
    int year,id,copies;
    char buf[200];
    Book *p,*last;
    last=h;                    
    while(1){
		if (fgets(buf,255,file)==NULL) break;	// 检查文件是否结束
		CreateNode(p)	// 动态分配内存
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
    Book *p;
    CreateNode(p);
    printf("Enter the title of the book you wish to add: ");
    scanf("%s",p->title);
    printf("Enter the author of the book you wish to add: ");
    scanf("%s",p->authors);
    printf("Enter the year of the book you wish to add was released: ");
    scanf("%d",p->year);
    printf("Enter the number of copies of the book you wish to add: ");
    scanf("%d",p->copies);
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
    printf("Enter the id of the book you wish to remove: ");
    scanf("%d",&id_removed);
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
    BookList bookList;
    bookList.list = (Book *) malloc(sizeof(Book));
    bookList.length = 0;
    Book *l = h->next;
    while (l) {
        if (strcmp(title, l->title) == 0) {
            *(bookList.list + bookList.length) = *l;
            bookList.length += 1;
        }
        l = l->next;

    }
    return bookList;
}

BookList find_book_by_author(const char *author, Book *h) {
    BookList bookList;
    bookList.list = (Book *) malloc(sizeof(Book));
    bookList.length = 0;
    Book *l = h->next;
    while (l) {
        if (strcmp(author, l->authors) == 0) {
            *(bookList.list + bookList.length) = *l;
            bookList.length += 1;
        }
        l = l->next;

    }
    return bookList;

}

BookList find_book_by_year(unsigned int year, Book *h) {

    BookList bookList;
    bookList.list = (Book *) malloc(sizeof(Book));
    bookList.length = 0;
    Book *l = h->next;
    while (l) {
        if (year == l->year) {
            *(bookList.list + bookList.length) = *l;
            bookList.length += 1;
        }
        l = l->next;

    }
    return bookList;


}
