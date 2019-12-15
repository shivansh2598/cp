#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

int main()
{
   lli t;
   cin>>t;
   for(lli i=0;i<t;i++)
   {
       lli n;
       cin>>n;
       int a1[n-1];
       int a2[n-2];
       lli count1=0;
       lli count2=0; 
       for(lli j=0;j<(2*n-2);j++)
       {
           if(j%2==0)
           {
               char d;
               cin>>d;
               a1[count1++]=d-32;
           }
           else
           {
               char d;
               cin>>d;
               a2[count2++]=d;
           }
           
       }
       
    //    for(int k=0;k<count1;k++)
    //    {
    //        cout<<"a1["<<k<<"] ="<<a1[k]<<endl;
    //        cout<<"a2["<<k<<"] ="<<a2[k]<<endl;
    //    }

       lli count=0;
       for(lli j=0;j<count2;j++)
       {
           bool check=false;
           for(lli k=0;k<=j;k++)
           {
               if(a1[k]==a2[j])
               {
                   a1[k]=-1;
                   check=true;
                   break;
               }
           }
           if(!check)
           count++;

       }

       cout<<count<<endl;
   }
}