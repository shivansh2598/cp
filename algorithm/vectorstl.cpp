#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;


int main()
{
    int t; 
    cin>>t;
    for(int i=0; i<t;i++)
    {
        int n;
        cin>>n;
        vector<int>vect;
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            vect.push_back(x);
        }
        vector<int>::iterator lower,upper;
        int k;
        cin>>k;
        lower=lower_bound(vect.begin(),vect.end(),k);
        upper=upper_bound(vect.begin(),vect.end(),k);

        cout<<"lower position "<<lower-vect.begin()<<endl;
        cout<<"upper position "<<upper-vect.begin()<<endl;
    }
}