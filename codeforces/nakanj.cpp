#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

void vprint(vector<int>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}

bool check(lli num1, lli num2)
{
    if((num1>=1 && num1<=8)&&(num2>=1&&num2<=8))
    return true;

    return false;
}

bool visited[9][9];
int height[9][9];

int bfs(int x,int y,int x2,int y2)
{
    pair<int,int>root=make_pair(x,y);
    queue<pair<int,int>>q;
    q.push(root);
    visited[x][y]=true;
    height[x][y]=0;

    // cout<<x<<" "<<y<<" "<<x2<<" "<<y2<<endl;

    while(!q.empty())
    {
        pair<int,int>temp=q.front();
        q.pop();

        int x1=temp.first;
        int y1=temp.second;

        // cout<<x1<<" "<<y1<<endl;

        if(x1==x2 && y1==y2)
        return height[x1][y1];
        

        int a1=0;
        int b1=0;


        a1=x1-1;
        b1=y1-2;

        if(check(a1,b1)&&!visited[a1][b1])
        {
            // cout<<"hello1"<<endl;
            height[a1][b1]=height[x1][y1]+1;
            visited[a1][b1]=true;
            q.push(make_pair(a1,b1));
        }

        a1=x1-1;
        b1=y1+2;

        if(check(a1,b1)&&!visited[a1][b1])
        {
            // cout<<"hello2"<<endl;
            height[a1][b1]=height[x1][y1]+1;         
            visited[a1][b1]=true;
            q.push(make_pair(a1,b1));
        }

        a1=x1+1;
        b1=y1-2;

        if(check(a1,b1)&&!visited[a1][b1])
        {
            // cout<<"hello3"<<endl;
            height[a1][b1]=height[x1][y1]+1;
            visited[a1][b1]=true;
            q.push(make_pair(a1,b1));
        }

        a1=x1+1;
        b1=y1+2;

        if(check(a1,b1)&&!visited[a1][b1])
        {
            // cout<<"hello4"<<endl;
            height[a1][b1]=height[x1][y1]+1;           
            visited[a1][b1]=true;
            q.push(make_pair(a1,b1));
        }

        a1=x1-2;
        b1=y1-1;

        if(check(a1,b1)&&!visited[a1][b1])
        {
            // cout<<"hello5"<<endl;
            height[a1][b1]=height[x1][y1]+1;
            visited[a1][b1]=true;
            q.push(make_pair(a1,b1));
        }

        a1=x1-2;
        b1=y1+1;

        if(check(a1,b1)&&!visited[a1][b1])
        {
            // cout<<"hello6"<<endl;
            height[a1][b1]=height[x1][y1]+1;
            visited[a1][b1]=true;
            q.push(make_pair(a1,b1));
        }

        a1=x1+2;
        b1=y1-1;

        if(check(a1,b1)&&!visited[a1][b1])
        {
            // cout<<"hello7"<<endl;
            height[a1][b1]=height[x1][y1]+1;
            visited[a1][b1]=true;
            q.push(make_pair(a1,b1));
        }

        a1=x1+2;
        b1=y1+1;

        if(check(a1,b1)&&!visited[a1][b1])
        {
            // cout<<"hello8"<<endl;
            height[a1][b1]=height[x1][y1]+1;
            visited[a1][b1]=true;
            q.push(make_pair(a1,b1));
        }
    }
}

int main()
{
    lli t;
    cin>>t;
    for(lli p=0;p<t;p++)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++){
            visited[i][j]=false;
            height[i][j]=-1;
            }

        }
        string ini,des;
        cin>>ini>>des;
        int x1=ini[0];
        x1=x1-96;
        int y1=ini[1]-'0';
        int x2=des[0];
        x2=x2-96;
        int y2=des[1]-'0';
        cout<<bfs(x1,y1,x2,y2)<<endl;
    }
}