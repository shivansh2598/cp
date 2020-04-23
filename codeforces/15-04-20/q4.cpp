#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define fr(i, k, n) for (lli i = k; i < lli(n); ++i)
#define pb push_back
using namespace std;

void vprint(vector<lli>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}

ulli power(lli a, lli n)
{
    if(n==0)
    return 1;

    if(n%2==0)
    return power(a*a,n/2);
    else
    {
        return a*power(a*a,n/2);
    }
    
}

int main()
{
    lli tc;
    cin>>tc;
    while(tc--)
    { 
        lli nr, ng, nb;
        cin>>nr>>ng>>nb;
        vector<lli>red, green, blue;
        fr(i,0,nr)
        {
            lli x;
            cin>>x;
            red.push_back(x);
        }
        fr(i,0,ng)
        {
            lli x;
            cin>>x;
            green.pb(x);
        }
        fr(i,0,nb)
        {
            lli x;
            cin>>x;
            blue.pb(x);
        }
        sort(red.begin(),red.end());
        sort(green.begin(),green.end());
        sort(blue.begin(), blue.end());

        // vprint(blue);

        ulli minz=8999999999999999999;
        //case 1 r<=g<=b
        for(int i=0;i<ng;i++)
        {
            lli x = green[i];
            auto ptr = lower_bound(red.begin(),red.end(), x);
            int ind = ptr - red.begin();
            if(ind == nr || red[ind]>x)
            ind--;
            if(ind<0)
            continue;
            auto ptr1 = lower_bound(blue.begin(), blue.end(), x);
            int ind1 = ptr1-blue.begin();
            if(ind1 == nb)
            break;
            ulli a = power((x-red[ind]),2)+power(blue[ind1]-x,2)+power(blue[ind1]-red[ind],2);
            minz = min(minz, a);
        }
        // cout<<minz<<endl;
        //case2 r<=b<=g
        for(int i=0;i<nb;i++)
        {
            lli x = blue[i];
            // cout<<x<<" ";
            auto ptr = lower_bound(red.begin(),red.end(), x);
            int ind = ptr - red.begin();
            if(ind == nr || red[ind]>x)
            ind--;
            if(ind<0)
            continue;
            auto ptr1 = lower_bound(green.begin(), green.end(), x);
            int ind1 = ptr1-green.begin();
            if(ind1 == ng)
            break;
        
            ulli a = power((x-red[ind]),2)+power(green[ind1]-x,2)+power(green[ind1]-red[ind],2);
            if(x==5)
            {
                // cout<<ind<<" "<<ind1<<" "<<red[ind]<<" "<<green[ind1]<<" "<<a<<endl;
            }
            minz = min(minz, a);
        }
        // cout<<minz<<endl;
        //case3 b<=r<=g
        for(int i=0;i<nr;i++)
        {
            lli x = red[i];
            auto ptr = lower_bound(blue.begin(),blue.end(), x);
            int ind = ptr - blue.begin();
            if(ind == nb || blue[ind]>x)
            ind--;
            if(ind<0)
            continue;
            auto ptr1 = lower_bound(green.begin(), green.end(), x);
            int ind1 = ptr1-green.begin();
            if(ind1 == ng)
            break;

            ulli a = power((x-blue[ind]),2)+power(green[ind1]-x,2)+power(blue[ind]-green[ind1],2);
            minz = min(minz, a);
        }
        //  cout<<minz<<endl;
        //case4 b<=g<=r
        for(int i=0;i<ng;i++)
        {
            lli x = green[i];
            auto ptr = lower_bound(blue.begin(),blue.end(), x);
            int ind = ptr - blue.begin();
            if(ind == nb || blue[ind]>x)
            ind--;
            if(ind<0)
            continue;
            auto ptr1 = lower_bound(red.begin(), red.end(), x);
            int ind1 = ptr1-red.begin();
            if(ind1 == nr)
            break;

            ulli a = power((x-red[ind1]),2)+power(blue[ind]-x,2)+power(blue[ind]-red[ind1],2);
            minz = min(minz, a);
        }
        //  cout<<minz<<endl;
        //case5 g<=r<=b
        for(int i=0;i<nr;i++)
        {
            lli x = red[i];
            auto ptr = lower_bound(green.begin(),green.end(), x);
            int ind = ptr - green.begin();
            if(ind == ng || green[ind]>x)
            ind--;
            if(ind<0)
            continue;
            auto ptr1 = lower_bound(blue.begin(), blue.end(), x);
            int ind1 = ptr1-blue.begin();
            if(ind1 == nb)
            break;

            ulli a = power((x-green[ind]),2)+power(blue[ind1]-x,2)+power(blue[ind1]-green[ind],2);
            minz = min(minz, a);
        }
        //  cout<<minz<<endl;
        //case6 g<=b<=r
        for(int i=0;i<nb;i++)
        {
            lli x = blue[i];
            auto ptr = lower_bound(green.begin(),green.end(), x);
            int ind = ptr - green.begin();
            if(ind == ng || green[ind]>x)
            ind--;
            if(ind<0)
            continue;
            auto ptr1 = lower_bound(red.begin(), red.end(), x);
            int ind1 = ptr1-red.begin();
            if(ind1 == nr)
            break;

            ulli a = power((x-red[ind1]),2)+power(green[ind]-x,2)+power(green[ind]-red[ind1],2);
            minz = min(minz, a);
        }


        cout<<minz<<endl;
    }
}