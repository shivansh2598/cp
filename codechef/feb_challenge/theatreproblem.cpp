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
    lli total=0;
    while(tc--)
    { 
        lli n;
        cin>>n;
        lli arr[4][4];
        forn(i,4){
            forn(j,4)
                arr[i][j]=0;
        }
        forn(i,n){
            char x;
            cin>>x;
            int index=x-'A';
            int p;
            cin>>p;
            p/=3;
            p--;
            arr[index][p]++;
        }

        // forn(i,4){
        //     forn(j,4)
        //         cout<<arr[i][j]<<" ";
        //     cout<<endl;
        // }
        
        lli count=0;
        lli arr1[24][4];
        forn(i,24){
            forn(j,4){
                arr1[i][j]=0;
            }
        }
        forn(i,4){
            forn(j,4){
                if(j==i)
                continue;
                forn(k,4){
                    if(k==j || k==i)
                    continue;
                    forn(l,4){
                        if(l==k || l==j || l==i)
                        continue;
                        arr1[count][0]=arr[0][i];
                        arr1[count][1]=arr[1][j];
                        arr1[count][2]=arr[2][k];
                        arr1[count][3]=arr[3][l];
                        sort(arr1[count],arr1[count]+4);
                        count++;
                    }
                }
            }
        }
        
        lli maxcost=INT_MIN;
        forn(i,24){
            lli cost=0;
            forn(j,4){
                if(arr1[i][j]==0)
                    cost-=100;
                else{
                    cost+=arr1[i][j]*25*(j+1);
                }
            }
            if(cost>maxcost)
            maxcost=cost;
        }

        cout<<maxcost<<endl;
        total+=maxcost;
    }
    cout<<total<<endl;
}