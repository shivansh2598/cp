#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


int allposs(vector<int>&vect,int i,int n)
{
    if(i==n)
        return 1;
    
    int k=allposs(vect,i+1,n);
    int l=0;
    if(i!=n-1){
        int a=vect[i];
        int b=vect[i+1];
        int c = 10*a + b;
        if(c<=26)
            l=allposs(vect,i+2,n);
    }
    
    return k+l;
    
}

int main()
{
   
    while(true)
    {
        string s;
        cin>>s;
        if(s[0]=='0')
        break;

        vector<int>vect;
        for(int i=0;i<s.length();i++)
        {
            int x=s[i]-'0';
            vect.push_back(x);
        }

        cout<<allposs(vect,0,s.length())<<endl;
    }
    return 0;
}
