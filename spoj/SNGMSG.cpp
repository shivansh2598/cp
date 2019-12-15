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
       string a;
       cin>>a;
       string s;
       cin>>s;
       int arr[10]={0};
       int arr1[10]={0};
       int count=0;
      //  while(a)
      //  {
      //     arr1[count++]=a%10;
      //     a=a/10;
      //  }
      for(lli j=a.length()-1;j>=0;j--)
      {
          arr1[count++]=a[j]-'0';
      }
       for(lli j=count-1;j>=0;j--)
       {
           arr[count-1-j]=arr1[j];
       }

       for(lli j=0;j<s.length();j++)
       {
          if((j/(count))%2==0)
          {
             s[j]=s[j]-arr[j%count];
             if(s[j]<97)
             s[j]+=26;
          }
          else
          {
              s[j]=s[j]-arr1[j%count];
             if(s[j]<97)
             s[j]+=26;
          }
          

       }

       cout<<s<<endl;
   }
}