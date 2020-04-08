#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define forn(i, n) for (lli i = 0; i < lli(n); ++i)
#define for1(i, n) for (lli i = 1; i <= lli(n); ++i)
#define fore(i, l, r) for (lli i = lli(l); i <= lli(r); ++i)
#define ford(i, n) for (lli i = lli(n) - 1; i >= 0; --i)
#define pb push_back
#define vectvalue lli x;cin >> x;vect.pb(x)
#include<chrono>
using namespace std::chrono; 
using namespace std;
void vprint(vector<int>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}


int main()
{
    lli tc;
    cin>>tc;
    auto start = high_resolution_clock::now(); 
    while(tc--)
    { 
        lli n,k;
        cin>>n>>k;
        lli tot=((n)*(n-1))/2;
        lli tm=tot-(k-1);
        string s="";
        lli i=1;
          
        while(true)
        {
            lli temp=tm-(n-i);
            if(temp>0)
            {
                s+='a';
            }
            else
            {
                s+='b';
                if(tm==0)
                tm=n-i;

                for(int i=1;i<tm;i++)
                {
                    s+='a';
                }
                s+='b';
                break;
            }
            tm=tm-(n-i);
            i++;
            
        }
        string tempz=s;
        for(int i=0;i<n-tempz.length();i++)
        s+='a';

        cout<<s<<endl;
    }

       auto stop = high_resolution_clock::now(); 
     auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
}