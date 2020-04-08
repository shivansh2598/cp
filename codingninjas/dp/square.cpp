#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef long double ld;
#define fr(i,k,n) for(lli i=k;i<n;i++)

ld dp[3005][3005];
struct det
{
    ld x;
    ld y;
    ld hp;
};

int main()
{
    lli n;
    cin>>n;
    vector<det>vect;

    fr(i,0,n){
        det var;
        cin>>var.x>>var.y>>var.hp;
        vect.push_back(var);
    }
    
    fr(i,0,3005)
    {
        fr(j,0,3005)
        {
            if(j>=i)
            dp[i][j]=INT_MIN;

            else
            {
                dp[i][j]=0;
            }
            
        }
    }
    
    dp[0][0]=vect[0].hp;

    fr(i,0,n)
    {
        fr(j,1,n)
        {
            if(i>=j)
            continue;

            dp[i][j]=
        }
    }

    fr(i,0,n)
    {
        det var;
        cin>>var.x>>var.y>>var.hp;
        vect.push_back(var);
    }



}
