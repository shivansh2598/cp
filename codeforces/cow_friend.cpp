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

int main()
{
    string str;
    getline(cin,str);
    unordered_map<string,lli>m;
    vector<string>vect;
    forn(i,str.length())
    {
        string temp="";
        while(i<str.length()&&str[i]!=' ')
        {
            temp+=str[i];
            i++;
        }
        if(m.find(temp)!=m.end())
        {
            m[temp]++;
        }
        else{
            m.insert({temp,1});
            vect.pb(temp);
        }    
    }
    
    bool none=true;
    forn(i,vect.size())
    {
        if(m[vect[i]]>1)
        {
            cout<<vect[i]<<" "<<m[vect[i]]<<endl;
            none=false;
        }
    }
    
    if(none)
        cout<<-1<<endl;
}