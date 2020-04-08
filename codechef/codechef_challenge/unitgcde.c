#include<stdio.h>
typedef long long int lli;

int main()
{
    lli tn;
    scanf("%lld",&tn);
    while(tn--){
        lli n;
        scanf("%lld", &n);

        if(n==1)
        {
            printf("%d\n", 1);
            printf("%d %d \n",1,1);
        }
        else
        {
            printf("%lld\n", n/2);
            if(n%2==0)
            {
                for(lli i=1;i<=n/2;i++)
                {
                    printf("%d %lld %lld \n", 2, i, (n+1)-i);
                }
            }
            else
            {
                printf("%d %d %d %lld \n", 3, 1, 2, n);
                for(lli i=2;i<=(n/2);i++)
                printf("%d %lld %lld \n", 2, i+1, n+1-i);
            }
            
        }
    }
    return 0;
}