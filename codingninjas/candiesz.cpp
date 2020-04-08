#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define forn(i, n) for (lli i = 0; i < lli(n); ++i)
#define for1(i, n) for (lli i = 1; i <= lli(n); ++i)
#define fore(i, l, r) for (lli i = lli(l); i <= lli(r); ++i)
#define ford(i, n) for (lli i = lli(n) - 1; i >= 0; --i)
#define pb push_back
#define vectvalue lli x;cin >> x;vect.pb(x)
using namespace std;

vector<string>vect;
vector<pair<int,string>>word;
int len1=0;
int len2=0;


void splitintovect(string s)
{
    int i=0;
    string w="";
    while(i<s.length())
    {
        if(s[i]==';')
        {
            word.push_back(make_pair(0,w));
            w="";
        }
        
        else{
            w+=s[i];
        }
        
        i++;
    }
    
    word.push_back(make_pair(0,w));
}

vector<int>check(int x, int y, int n, string word)
{
    vector<int>vect1;
    int x1=1;
    int x2=1;
    int up=1;
    int lt=1;
    while(x-up>=0 && vect[x-up][y]!='+')
    up++;
    
    while(y-lt>=0 && vect[x][y-lt]!='+')
    lt++;

    len1=lt-1;
    len2=up-1;

    int xx=x-len2;
    int yy=y-len1;
    
    int cntr=0;    
    bool ltrt=false;
    for(int i=yy;i<y;i++)
    {
        if(word[cntr++]!=vect[x][yy])
        {
            x1=0;
            ltrt=true;
            break;
        }
    }

    cntr=0;
    bool updw=false;
    for(int i=xx;i<x;i++)
    {
        if(word[cntr++]!=vect[xx][y])
        {
            x2=0;
            updw=true;
            break;
        }
    }


    //right
    int i=0;
    if(!ltrt){
    for(;i<word.length()-len1;i++)
    {
        if(y+i>=n || vect[x][y+i]=='+' || (vect[x][y+i]!='-' && vect[x][y+i]!=word[i+len1]))
        {
            x1=0;
            break;
        }
    }
    // if(y+i<n && vect[x][y+i]!='+')
    // x1=0;
    }
    vect1.push_back(x1);
    
    //bottom
    if(!updw){
    i=0;
    for(;i<word.length()-len2;i++)
    {
        if(x+i>=n || vect[x+i][y]=='+' || (vect[x+i][y]!='-' && vect[x+i][y]!=word[i+len2]))
        {
            x2=0;
            break;
        }
    }
    // if(x+i<n && vect[x+i][y]!='+')
    //     x2=0;
    }
    vect1.push_back(x2);
    
    return vect1;
}

pair<int,int>findpos(int n)
{
    pair<int,int>x=make_pair(-1,-1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(vect[i][j]=='-')
            {
                x.first=i;
                x.second=j;
                return x;
            }
        }
    }

    return x;
}

bool crossword(int n)
{
    pair<int,int>p=findpos(n);
    if(p.first==-1 && p.second==-1)
        return true;
    
    for(int i=0;i<word.size();i++)
    {
        if(word[i].first==0){
            
            word[i].first=1;

            vector<int>v=check(p.first,p.second,n,word[i].second);
            int x1=v[0];
            int x2=v[1];
            int x=p.first;
            int y=p.second;
            string wordz=word[i].second;
            
            //check right
            if(x1==1)
            {
                string str="";
                for(int j=0;j<wordz.length()-len1;j++)
                {
                    str+=vect[x][y+j];
                    vect[x][y+j]=wordz[j+len1];
                }
                bool ret=crossword(n);

                if(ret)
                return true;

                for(int j=0;j<str.length();j++)
                {
                    vect[x][y+j]=str[j];
                }
                
            }
            //check bottom
            if(x2==1)
            {
                string str="";
                for(int j=0;j<wordz.length()-len2;j++)
                {
                    str+=vect[x+j][y];
                    vect[x+j][y]=wordz[j+len2];
                }
                bool ret=crossword(n);

                if(ret)
                return true;
                
                for(int j=0;j<str.length();j++)
                {
                    vect[x+j][y]=str[j];
                }
            }
            word[i].first=0;
        }
    }
    
    return false;
}


int main() { 
    int n=10;
    for(int i=0;i<n;i++)
    {
        string x="";
        for(int j=0;j<n;j++)
        {
            char c;
            cin>>c;
            x+=c;
        }
        vect.push_back(x);
    }
    string p;
    cin>>p;
   
    splitintovect(p);
    bool ret=crossword(n);
    if(ret){
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cout<<vect[i][j];
            cout<<endl;
        }
    }
}