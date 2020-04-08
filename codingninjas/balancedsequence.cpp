#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
    lli n,k,l;
    cin>>n>>k>>l;
    vector<lli>vect;
    lli mean=0;
    lli maxz=0;
    for(int i=0;i<n;i++){
        lli x;
        cin>>x;
        if(x>maxz)
            maxz=x;
        vect.push_back(x);
        mean+=x;
    }
    mean=ceil(double(mean)/n);

    cout<<mean<<" "<<maxz<<endl;

    lli coins1=0;
    lli pos=0;
    lli neg=0;

    for(int i=0;i<n;i++)
    {
        if(vect[i]>mean)
            neg+=vect[i]-mean;
        
        else
            pos+=mean-vect[i];
    }

    cout<<pos<<" "<<neg<<endl;
    
    coins1=(neg)*k;
    cout<<"temp "<<coins1<<endl;
    pos=pos-neg;
    coins1+=pos*l;

    cout<<"coins1 "<<coins1<<endl;
    
    lli coins2=0;
    for(int i=0;i<n;i++)
    {
        lli xx=maxz-vect[i];
        coins2+=xx*l;
    }
    
    cout<<min(coins1,coins2)<<endl;
}