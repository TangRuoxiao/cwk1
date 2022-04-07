#include "user_management.h"
#include<stdlib.h>
#define CreateNode(p) p=(User *)malloc(sizeof(User));
#define DeleteNode(p)   free((void *)p);   
#define N 50
int load_user(FILE *file,User *h)
{
    if (file==NULL) {
        printf("File open error.\n");
		return -1;
	}
    int numborrowed;
    char buf[200];
    User *p,*last;
    last=h;
    while(1){
		if (fgets(buf,255,file)==NULL) break;	// 检查文件是否结束
		CreateNode(p)	// 动态分配内存
        char * username=(char*) malloc(sizeof(char));
        char * password=(char*) malloc(sizeof(char));
        sscanf(buf, "%s %s %d", username, password, numborrowed);
        p->password=password;p->username=username;p->numborrowed=numborrowed;
        /*for ( int u = 0; u < p->numborrowed; u++)
        {
            sscanf(file,"%d",&p->borrowed[u]);
        }
        */
        last->next=p;
        last=p;
    }
    last->next=NULL;
    
    for (p=h->next;p;p=p->next)
    {
        if (p==NULL)
        {
            break;
        }
        printf("%s %s %d", p->username, p->password, p->numborrowed);
        for ( int u = 0; u < p->numborrowed; u++)
        {
            printf("%d",&p->borrowed[u]);
        }
    }
    return 0;
    return 0;
}

int store_user(FILE *file,User *h)
{
    if (file==NULL) {
        printf("File open error.\n");
		return -1;
	}
    User *p;
    for ( p=h->next; p!=NULL; p=p->next)
    {
        fprintf(file, "%s %s %d\n", p->username, p->password, p->numborrowed);
        for ( int u = 0; u < p->numborrowed; u++)
        {
            fprintf(file,"%d\n",&p->borrowed[u]);
        }
    }
    return 0;
}