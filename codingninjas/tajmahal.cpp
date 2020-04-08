#include <string>
#include<bits/stdc++.h>
using namespace std;

char table[10][5]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


void finalcombination(int number[],int n,vector<string>&output1,char result[],int curr)
{
    if(curr==n)
    {
        output1.push_back(result);
        return;
    }

    for(int i=0;i<strlen(table[number[curr]]);i++)
    {
        result[curr]=table[number[curr]][i];
        finalcombination(number,n,output1,result,curr+1);
    }
}

int keypad(int num, string output[]){
    int number[10];
    int n=0;
    while(num){
        number[n++]=num%10;
        num/=10;
    }

    for(int i=0,j=n-1;i<n/2;i++,j--){
        swap(number[i],number[j]);
    }
    
    char result[n+1];
    result[n]='\0';
    vector<string>output1;
    finalcombination(number,n,output1,result,0);
    for(int i=0;i<output1.size();i++)
    {
        output[i]=output1[i];
    }
    return output1.size();
}

int main()
{
    int n;
    cin>>n;
    string output[10000];
    int x=keypad(n,output);
    for(int i=0;i<x;i++)
    {
        cout<<output[i]<<" ";
    }
    cout<<endl;
    cout<<x<<endl;
}