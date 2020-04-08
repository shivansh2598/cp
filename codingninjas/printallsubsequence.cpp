#include<bits/stdc++.h>
using namespace std;

int ans[20][20];
bool visited[20][20];

void findpath(int i,int j,int maze[][20],int n)
{
//     if(maze[i][j]!=1)
//         return;
    
//     visited[i][j]=true;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<visited[i][j]<<" ";
    }
    cout<<endl;
    
    if(i==1 && j==1 && maze[i][j]==1)
    {
        cout<<"hey"<<endl;
        for(int p=0;p<n;p++)
        {
            for(int q=0;q<n;q++)
                cout<<ans[p][q]<<" ";
        }
        cout<<endl;
        return;
    }
    
    if(i+1<n && maze[i+1][j]==1)
    {
        // cout<<"i"<<i+1<<" "<<"j"<<j<<" "<<visited[i+1][j]<<endl;
        if(!visited[i+1][j]){
        cout<<"hey1"<<endl;
        ans[i+1][j]=1;
        findpath(i+1,j,maze,n);
        ans[i+1][j]=0;
        }
    }
    
    if(j+1<n && maze[i][j+1]==1)
    {
        cout<<"hey2"<<endl;
        if(!visited[i][j+1]){
        ans[i][j+1]=1;
        findpath(i,j+1,maze,n);
        ans[i][j+1]=0;
        }
    }
    
//     if(i-1>=0 && maze[i-1][j]==1)
//     {
//         if(!visited[i-1,j]){
//         ans[i-1][j]=1;
//         findpath(i-1,j,maze,n);
//         ans[i-1][j]=0;
//         }
//     }
    
//     if(j-1>=0 && maze[i][j-1]==1)
//     {
//         if(!visited[i,j-1]){
//         ans[i][j-1]=1;
//         findpath(i,j-1,maze,n);
//         ans[i][j-1]=0;
//         }
//     }
    
//     visited[i][j]=false;
}


void ratInAMaze(int maze[][20], int n){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            ans[i][j]=0;
            visited[i][j]=false;
        }
        
    }
    ans[0][0]=1;
    findpath(0,0,maze,n);
}

int main()
{
    int maze[20][20];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>maze[i][j];
        }
    }

    ratInAMaze(maze,n);
}