#include "book_management.h"
#include "user_management.h"
void library_menu();
int register_(User *hu);
int login(Book *h,User *hu,BookList bl);
int search(Book *h,BookList bl);
int display(Book *h);