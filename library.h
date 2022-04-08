#include "book_management.h"
#include "user_management.h"
void library_menu();
int register_();
int login(Book *h,BookList bl);
int search(Book *h,BookList bl);
int display(Book *h);
int borrow(Book *h);
int return_(Book *h);
int load_user(FILE *file);
int store_user(FILE *file);
