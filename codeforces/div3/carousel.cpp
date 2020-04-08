
#include <bits/stdc++.h>
#define ll long long 
#define lli long long int
#define pb push_back
#define cl(a) cout<<a<<"\n"
#define cp(a) cout<<a
#define cs(a) cout<<a<<" "
#define fr(a,n,i) for(ll i=a; i<n; i++ )
#define frn(a,n,i) for(ll i=a; i>=n; i--)
#define fre(a,n,i) for(ll i=a; i<=n; i++)
#define vll vector < ll >
using namespace std;

int main()
{

ll t;
cin>>t;
while(t--)
{
    ll n,g=1;
    cin>>n;
   ll s[n];
   fr(0,n,i)
   {
   cin>>s[i]; if(i!=0 && s[i]!=s[i-1]) g=0;
   }
    
    if(g)
    {
        cout<<"1\n";
        fr(0,n,i)
        cout<<1<<" ";
    }
    
    
    else
    {
    
    if(n%2==0 || (s[0]==s[n-1]))
    {
        cout<<"2\n";
        for(ll i=1; i<=n; i++)
        {
            if(i%2==0)
            cout<<1<<" ";
            else
            cout<<2<<" ";
        }
        
        
    }
    else
    { 
        ll j=-1,f;
        fr(0,n-1,i)
       {
           if(s[i]==s[i+1])
           {
               j=i; break;
           }
           
       }
       
       if(j!=-1)
       {
           cout<<"2\n";
           
       ll i;
       for( i=0; i<j; i++)
        {
         if(i%2==0)
            cout<<1<<" ";
            else
            cout<<2<<" ";
        }
        
        if(j%2!=0)
        {
             cout<<"2 2 ";
            
            for(ll k=j+2; k<n; k++)
            {
                 if(k%2==0)
            cout<<2<<" ";
            else
            cout<<1<<" ";
            }
            
        }
        else
        {
           
         cout<<"1 1 ";
            
            for(ll k=j+2; k<n; k++)
            {
                 if(k%2==0)
            cout<<2<<" ";
            else
            cout<<1<<" ";
            }
            
        }
       }
       else
       {cout<<"3\n";
           for(ll i=1; i<n; i++)
        {
            if(i%2==0)
            cout<<1<<" ";
            else
            cout<<2<<" ";
        }
           cout<<3;
           
       }
    }
    }
    cout<<"\n";
}

 return 0;
}
