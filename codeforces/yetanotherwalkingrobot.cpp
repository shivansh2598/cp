#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define for1(i, n) for (int i = 1; i <= int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

void vprint(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
}

void aprint(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main()
{
    lli tc;
    cin >> tc;
    while (tc--)
    {
        lli n;
        cin >> n;
        string s;
        cin >> s;
        vector<pair<char,int>>vect;
        for(int i=0;i<s.length();i++)
        {
            int count=1;
            if(s[i]=='L'){
                while(i+1<s.length()&&s[i+1]=='L')
                {
                    count++;
                    i++;
                }
                vect.pb(make_pair('L',count));
            }else if(s[i]=='R'){
                while(i+1<s.length()&&s[i+1]=='R')
                {
                    count++;
                    i++;
                }
                vect.pb(make_pair('R',count));
            }else if(s[i]=='U'){
                while(i+1<s.length()&&s[i+1]=='U')
                {
                    count++;
                    i++;
                }
                vect.pb(make_pair('U',count));
            }else if(s[i]=='D'){
                while(i+1<s.length()&&s[i+1]=='D')
                {
                    count++;
                    i++;
                }
                vect.pb(make_pair('D',count));
            }
        }

        bool chota=false;
        bool bada=false;
        int l,r,maxl,maxr,d=INT_MAX;
        int index=0;
        for (int i = 0; i < vect.size()-1; i++)
        {   
            index+=vect[i].second;
            if((vect[i].first=='L'&&vect[i+1].first=='R')||(vect[i].first=='R'&&vect[i+1].first=='L')||(vect[i].first=='U' && vect[i+1].first=='D')||(vect[i].first=='D' && vect[i+1].first=='U'))
            {
                chota=true;
                l=index;
                r=l+1;
                break;
            }else if(i+3<vect.size()){
                // cout<<vect[i].first<<" "<<vect[i+1].first<<" "<<vect[i+2].first<<" "<<vect[i+3].first<<endl;
                if((vect[i].first=='L'&&vect[i+1].first=='U'&&vect[i+2].first=='R'&&vect[i+3].first=='D')||(vect[i].first=='L'&&vect[i+1].first=='D'&&vect[i+2].first=='R'&&vect[i+3].first=='U')||(vect[i].first=='R'&&vect[i+1].first=='U'&&vect[i+2].first=='L'&&vect[i+3].first=='D')||(vect[i].first=='R'&&vect[i+1].first=='D'&&vect[i+2].first=='L'&&vect[i+3].first=='U')||(vect[i].first=='U'&&vect[i+1].first=='R'&&vect[i+2].first=='D'&&vect[i+3].first=='L')||(vect[i].first=='U'&&vect[i+1].first=='L'&&vect[i+2].first=='D'&&vect[i+3].first=='R')||(vect[i].first=='D'&&vect[i+1].first=='R'&&vect[i+2].first=='U'&&vect[i+3].first=='L')||(vect[i].first=='D'&&vect[i+1].first=='L'&&vect[i+2].first=='U'&&vect[i+3].first=='R'))
                {
                    if((vect[i+1].second==vect[i+2].second) && (vect[i].second>=vect[i+1].second) && (vect[i+3].second>=vect[i+1].second) && (d>4*vect[i+1].second)){
                        bada=true;
                        int len=vect[i].second-vect[i+1].second;
                        int ff=index-vect[i].second;
                        ff+=len;
                        l=ff+1;
                        r=l+3*vect[i+1].second;
                        d=4*vect[i].second;
                    }
                }
            }
        }

        if(!(chota|bada))
        cout<<-1<<endl;
        else
        {
            cout<<l<<" "<<r<<endl;
        }
        
    }
}