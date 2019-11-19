#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

bool visited[100][100];

bool isvalid(int i,int j,int size)
{
    if(i>=0 && i<size)
    {
        if(j>=0&& j<size)
        {
            // cout<<i<<" "<<j<<endl;
            return true;
        }
    }
    return false;
}


bool isattacked(int i,int j,vector<vector<int>>&board, int n)
{   
    for(int k=0;k<board.size();k++)
    {
        if(board[i][k]==1)
        return true;

        else if(board[k][j]==1)
        return true;    

    }

    //for diagonally up
    int k=1;
    while(isvalid(i+k,j+k,board.size()))
    {
        if(board[i+k][j+k]==1)
        return true;

        k++;
    }

    //for diagonally downwards
    k=1;
    while(isvalid(i-k,j-k,board.size()))
    {
        if(board[i-k][j-k]==1)
        return true;

        k++;
    }

    //for diagonally upwards for the other diagonal
    k=1;
    while(isvalid(i+k,j-k,board.size()))
    {
        if(board[i+k][j-k]==1)
        return true;

        k++;
    }

    //for diagonally downwards for the other diagonal
    k=1;
    while(isvalid(i-k,j+k,board.size()))
    {
        if(board[i-k][j+k]==1)
        return true;

        k++;
    }

    // cout<<i<<" "<<j<<endl;
    return false;

}

void nqueans(vector<vector<int>>&board,int n,int i,int j)
{
    if(n==0)
    {
        for(int t=0;t<board.size();t++)
        {
            for(int u=0;u<board.size();u++)
            {
                cout<<board[t][u]<<" ";
            }

            cout<<endl;
        }

        cout<<endl;    
        return;
    }


    if(i>=board.size() || j>=board.size())
    return;

    
    if(isattacked(i,j,board,n)==false)
    {
        // cout<<"not "<<p<<" "<<q<<endl;
        board[i][j]=1;
        if(j==board.size()-1)
        {
            nqueans(board,n-1,i+1,0);
        }
        else
        {
            nqueans(board,n-1,i,j+1);
        }

        board[i][j]=0;
        if(j==board.size()-1)
        {
            nqueans(board,n,i+1,0);
        }
        else
        {
            nqueans(board,n,i,j+1);
        }
        
        
    }

    else
    {
        board[i][j]=0;
        if(j==board.size()-1)
        {
            nqueans(board,n,i+1,0);
        }
        else
        {
            nqueans(board,n,i,j+1);
        }
    }
    

    // for(int p=i;p<board.size();p++)
    // {
    //     for(int q=0;q<board[p].size();q++)
    //     {
    //             if(p==i && q<j)
    //             continue;

    //             if(isattacked(p,q,board,n))
    //             {
    //                 // cout<<"not "<<p<<" "<<q<<endl;
    //                 continue;
    //             }
    //             else
    //             {
    //                 if(visited[p][q]==false)
    //                 {
    //                     // cout<<p<<" "<<q<<endl;
    //                     visited[p][q]=true;
    //                     board[p][q]=1;
    //                     nqueans(board,n-1,p,q);
                    

    //                 board[p][q]=0;

    //                 if(q==board.size()-1)
    //                 nqueans(board,n,p+1,0);
                    
    //                 else
    //                 {
    //                     nqueans(board,n,p,q+1);
    //                 }
    //                 }
                    
    //             }
                
                
    //     }

    // }

    return;
}

int main()
{
    lli t;
    cin>>t;
    for(lli l=0;l<t;l++)
    { 
        cout<<"enter the size of the board"<<endl;
        int size;
        cin>>size;
        vector<vector<int>>board;

        for(int i=0;i<size;i++)
        {
            vector<int>temp;

            for(int j=0;j<size;j++)
            {
                temp.push_back(0);                
            }

            board.push_back(temp);
        }

        cout<<"enter the number of queans"<<endl;
        int n;
        cin>>n;

        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                visited[i][j]=false;
            }
        }
        nqueans(board,n,0,0);

        // for(int s=0;s<size;s++)
        // {
        //     for(int i=0;i<size;i++)
        //     {


        //         for(int j=0;j<size;j++)
        //         {
        //             board[i][j]=0;              
        //         }

         
        //     }

        //     board[0][s]=1;

        //     if(nqueans(board,n-1))
        //     {
        //         cout<<"possible"<<endl;
        //             for(int i=0;i<size;i++)
        //             {
        //                 for(int j=0;j<size;j++)
        //                 {
        //                     cout<<board[i][j]<<" ";
        //                 }

        //                 cout<<endl;
        //             }
        //     }

        //     else
        //     {
        //         cout<<"Not possible"<<endl;
        //     }
        // }
        


    }
}