#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

void vprint(vector<int>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}

vector<lli>vect;

//trie implementation
struct trieNode{
    lli value;
    trieNode *arr[26];
};


trieNode* getnode()
{
    trieNode *node=new trieNode();
    node->value=0;
    for(int i=0;i<26;i++)
    node->arr[i]=NULL;
    return node;
}


void insert(trieNode *root,string key)
{
    trieNode *temp=root;
    for(lli i=0;i< key.length();i++)
    {
        int index=key[i]-'a';
        if(temp->arr[index]==NULL)
        {
            temp->arr[index]=getnode();
        }
        temp=temp->arr[index];
        temp->value++;
    }
}

lli driverfunc(trieNode *root,lli height)
{
    if(root==NULL)
    return 0;

    if(root->value==1 || root->value==0)
    return 0;


    lli tpair=0;
    for(int i=0;i<26;i++)
    {
        if(root->arr[i]!=NULL)
        {
            lli pairz=driverfunc(root->arr[i],height+1);
            root->value=root->value-(2*pairz);
            tpair+=pairz;
            if(root->value<=1)
            break;
        }
    }

    lli tmp=tpair;
    lli samp=0;
    if(root->value>1)
    {
        samp=(root->value)/2;
        for(lli i=0;i<samp;i++)
        vect.push_back(height);
    }

    return tmp+samp;
}


void dfs(trieNode *root)
{
    if(root==NULL)
    return;

    cout<<root->value<<endl;

    for(int i=0;i<26;i++)
    {
        dfs(root->arr[i]);
    }
}

int main()
{
    lli t;
    cin>>t;
    for(lli p=0;p<t;p++)
    { 
        lli n;
        cin>>n;
        trieNode *root=getnode();
        root->value=-1;
        for(lli i=0;i<n;i++)
        {
            string s;
            cin>>s;
            insert(root,s);
        }
        // dfs(root);
        lli ans=0;
        for(int j=0;j<26;j++){
            driverfunc(root->arr[j],1);
        }

        for(lli i=0;i<vect.size();i++)
        {
            ans+=vect[i]*vect[i];
        }
        cout<<ans<<endl;
    }
}