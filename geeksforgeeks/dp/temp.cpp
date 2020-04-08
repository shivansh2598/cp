#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

void vprint(vector<int>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

lli maxx=0,maxy=0;

struct mystr{
    pair<lli,lli>p;
    string s="";
    int cnt=0;
};

// struct mark{
//     bool visit=false;
//     int cunt=0;
// };

bool check(lli x,lli y)
{
    if(x<=maxx && y<=maxy)
    return true;
    return false;
}   

bool visited[1002][1002];

string traverse(unordered_map<pair<lli,lli>,int,hash_pair>&m,lli count)
{
    queue<mystr*>st;
    mystr *block = new mystr();
    block->p=make_pair(0,0);
    st.push(block);
    while(!st.empty())
    {
        mystr *f=st.front();
        st.pop();
        lli x=f->p.first;
        lli y=f->p.second;
        visited[x][y]=true;
        pair<lli,lli>r=make_pair(x+1,y);
        pair<lli,lli>u=make_pair(x,y+1);
        if(check(x+1,y))
        {
            // cout<<"Inside 1"<<endl;
            int cnt=f->cnt;
            string str=f->s;
            str+="R";
            if(m.find(r)!=m.end())
            {
                cnt++;
                if(cnt==count)
                return str;
            }
            bool already=false;
            if(visited[x+1][y].first && cnt==visited[x+1][y].second)
            already=true;

            if(!already){
            mystr *sth = new mystr();
            sth->p=r;
            sth->s=str;
            sth->cnt=cnt;
            st.push(sth);
            }
            // cout<<sth->p.first<<" "<<sth->p.second<<" "<<sth->s<<" "<<sth->cnt<<endl;
        }

        if(check(x,y+1))
        {
            // cout<<"Inside 2"<<endl;
            int cnt=f->cnt;
            string str=f->s;
            str+="U";
            if(m.find(u)!=m.end())
            {
                cnt++;
                if(cnt==count)
                return str;
            }
            bool already=false;
            if(visited[x][y+1].first && cnt==visited[x][y+1].second)
            already=true;

            if(!already){
            mystr *sth1 = new mystr();
            sth1->p=u;
            sth1->s=str;
            sth1->cnt=cnt;
            st.push(sth1);
            }
            // cout<<sth1->p.first<<" "<<sth1->p.second<<" "<<sth1->s<<" "<<sth1->cnt<<endl;
        }

        delete f;
        
    }

    return "NO";
}

int main()
{
    lli t;
    cin>>t;
    for(lli p=0;p<t;p++)
    { 
        lli n;
        cin>>n;
        unordered_map<pair<lli,lli>,int,hash_pair>m;
        for(int j=0;j<n;j++)
        {
            lli x,y;
            cin>>x>>y;
            pair<lli,lli>p=make_pair(x,y);
            m.insert({p,1});
            if(x>maxx)
            maxx=x;
            if(y>maxy)
            maxy=y;
        }

        for(int j=0;j<maxx+2;j++)
            for(int k=0;k<maxy+2;k++)
                visited[j][k]=make_pair(false,0);
        string temp=traverse(m,n);
        if(temp=="NO")
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            cout<<temp<<endl;
        }
        
    }
}