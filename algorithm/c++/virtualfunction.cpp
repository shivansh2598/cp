#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

void vprint(vector<int>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}


class one
{
    public:
    virtual void show()
    {
        cout<<"In class A"<<endl;
    }

    void show2()
    {
        cout<<"In class A2"<<endl;
    }
};

class two : public one
{
    public:
    void show()
    {
        cout<<"In class B"<<endl;
    }

    void show3()
    {
        cout<<"In class B1"<<endl;
    }
};

int main()
{
    one obj1;
    two obj2;

    one *p;
    p=&obj1;

    p->show();
}