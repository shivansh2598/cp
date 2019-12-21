#include<stdio.h>

typedef struct sdata{
    int adata;
    int bdata;
    union udata{
        int adata;
        int bdata;
    } u;
} data;

int main()
{
    data s;

    s.adata=10;
    s.bdata=20;
    s.u.adata=10;
    s.u.bdata=20;
    printf("%d %d %d %d", s.adata,s.bdata,s.u.adata,s.u.bdata);
    return 0;
}