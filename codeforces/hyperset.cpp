#include<bits/stdc++.h>
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
   lli n,k;
   cin>>n>>k;
   unordered_map<string,int>m;
   vector<string>vect;
   for(int i=0;i<n;i++)
   {
       string temp;
       cin>>temp;
       vect.push_back(temp);
       m.insert({temp,1});
   }

    int count=0;

   for(int i=0;i<vect.size();i++)
   {
       for(int j=i+1;j<vect.size();j++)
       {
           if(i==j)
           continue;

           string sth="";
           for(int p=0;p<k;p++)
           {
               if(vect[i][p]==vect[j][p])
               {
                   sth+=vect[i][p];
               }

               else if(vect[i][p]=='S' && vect[j][p]=='E')
               sth+='T';
               else if(vect[i][p]=='S' && vect[j][p]=='T')
               sth+='E';
               else if(vect[i][p]=='E' && vect[j][p]=='S')
               sth+='T';
               else if(vect[i][p]=='E' && vect[j][p]=='T')
               sth+='S';
               else if(vect[i][p]=='T' && vect[j][p]=='E')
               sth+='S';
               else if(vect[i][p]=='T' && vect[j][p]=='S')
               sth+='E';
           }

        //    cout<<sth<<endl;
           if(m.find(sth)!=m.end())
           count++;
       }
   }

   cout<<count/3<<endl;
}