#include "book_management.h"
#define CreateNode(p) p=(Book *)malloc(sizeof(Book));
#define DeleteNode(p)   free((void *)p);    
#define alloc(p) p=(char *)malloc(sizeof(char)*50); 
#define N 100

int store_books(FILE *file,Book *h)
{
    return 0;
}

int load_books(FILE *file,Book *h)
{
    if (file==NULL) {
        printf("File open error.\n");
		return -1;
	}
Book *p,*last;
   last=h;                    
while(1){
		if (feof(file)) break;	// 检查文件是否结束
		CreateNode(p);	// 动态分配内存
    
        fscanf(file, "%d\n", p->id);
        alloc(p->title)
        fgets(p->title, N, file);
        alloc(p->authors)
        fgets(p->authors, N, file);
        fscanf(file, "%d\n", p->year);
        fscanf(file, "%d\n", p->copies);
        
			// 将数据插入到链表
        last->next=p;
        last=p;
        }
        last->next=NULL;
        return 0;
}

int add_book(Book book,Book *h){
    Book *p;
    CreateNode(p);
    scanf("Enter the title of the book you wish to add: %s",book.title);
    scanf("Enter the author of the book you wish to add: %s",book.authors);
    scanf("Enter the year of the book you wish to add was released: %d",book.year);
    scanf("Enter the number of copies of the book you wish to add: %d",book.copies);
    book.next=NULL;
    p=h;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    p->next=&book;
    book.id=p->id+1;
    printf("Book was successfully added!");
    return 0;
}

int remove_book(Book book,Book *h){
    Book *p;
    CreateNode(p);
    char id_removed;
    scanf("Enter the id of the book you wish to remove: %d",&id_removed);
    p=h;
    while (p->next!=NULL)
    {
        if (p->next->id==id_removed)
        {
            break;
        }
        if (p->next=NULL)
        {
            printf("invalid id");
            return;
        }
        p=p->next;
    }
    if (p->next->copies>1)
    {
        p->next->copies-1;
    }
    else if (p->next->copies==1)
    {
        p->next->copies-1;
        p->next=p->next->next;
    }
    return;
}

BookList find_book_by_title (const char *title,Book *h);
BookList find_book_by_author (const char *author,Book *h);
BookList find_book_by_year (unsigned int year,Book *h);