#include<stdio.h>


    union udata{
        int adata;
        int bdata;
        char e;
    } u;

int main()
{
    u.adata=10;
    u.bdata=20;
    u.e='a';
    printf("%d %d %c",u.adata,u.bdata,u.e);
    return 0;
}