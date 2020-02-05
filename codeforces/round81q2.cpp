#include<bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define for1(i, n) for (int i = 1; i <= int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define ford(i, n) for (int i = int(n)-1; i >= 0; --i)
#define pb push_back
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

void vprint(vector<int>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}


int main()
{
    lli tc;
    cin>>tc;
    while(tc--)
    { 
        lli n,x;
        lli count=0;
        cin>>n>>x;
        if(x==0)
            count++;
        string s;
        cin>>s;
        vector<lli>vect1;
        vector<lli>vect0;
        forn(i,s.size()){
            if(s[i]=='0'){
                vect0.pb(1);
                vect1.pb(0);
            }else{
                vect1.pb(1);
                vect0.pb(0);
            }
        }
        for1(i,vect1.size()-1){
            vect1[i]+=vect1[i-1];
            vect0[i]+=vect0[i-1];
        }
        int final=0;
        forn(i,vect1.size()){
            vect0[i]=vect0[i]-vect1[i];
            if(i==vect1.size()-1)
                final=vect0[i];
        }
        forn(i,vect0.size())
        {
            int temp=x-vect0[i];
            if(temp==0 && final==0)
            {
                cout<<-1<<endl;
                goto next;
            }else if(temp==0 && final!=0)
                count++;
            else if(temp>0 && final>0){
                if(temp%final==0)
                count++;
            }else if(temp<0 && final<0)
                if(abs(temp)%abs(final)==0)
                count++;
        }
        cout<<count<<endl;
        next:;
    }
}