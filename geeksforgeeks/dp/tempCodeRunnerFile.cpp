#include <bits/stdc++.h>
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

struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

lli maxx = 0, maxy = 0;

struct mystr
{
    pair<lli, lli> p;
    string s = "";
    int cnt = 0;
};

// struct mark{
//     bool visit=false;
//     int cunt=0;
// };

bool check(lli x, lli y)
{
    if (x <= maxx && y <= maxy)
        return true;
    return false;
}

bool visited[1002][1002];

string traverse(unordered_map<pair<lli, lli>, int, hash_pair> &m, lli count)
{
    queue<mystr *> st;
    mystr *block = new mystr();
    block->p = make_pair(0, 0);
    st.push(block);
    while (!st.empty())
    {
        mystr *f = st.front();
        st.pop();
        lli x = f->p.first;
        lli y = f->p.second;
        visited[x][y] = true;
        string str = f->s;
        lli cnt = f->cnt;
        pair<lli, lli> r = make_pair(x + 1, y);
        pair<lli, lli> u = make_pair(x, y + 1);
        bool right = false;
        bool up = false;
        if (check(x + 1, y))
        {
            if (m.find(r) != m.end())
            {
                right = true;
            }
        }

        if (check(x, y + 1))
        {
            if (m.find(u) != m.end())
            {
                up = true;
            }
        }

        if (right && up)
            return "NO";

        else if (!(right | up))
        {
            if (check(x+1,y)&&!visited[x + 1][y])
            {
                mystr *sth = new mystr();
                sth->p = r;
                sth->s = str + "R";
                sth->cnt = cnt;
                st.push(sth);
            }

            if (check(x,y+1)&&!visited[x][y + 1])
            {
                mystr *sth1 = new mystr();
                sth1->p = u;
                sth1->s = str+ "U";
                sth1->cnt = cnt;
                st.push(sth1);
            }
        }

        else
        {
            cnt++;
            if(cnt == count)
            {
                string str1=right?"R":"U";
                str+=str1;
                return str;
            }
            else if(right && !visited[x+1][y])
            { 
                mystr *sth = new mystr();
                sth->p = r;
                sth->s = str + "R";
                sth->cnt = cnt;
                st.push(sth);
            }

            else if(up && !visited[x][y+1])
            {
                mystr *sth1 = new mystr();
                sth1->p = u;
                sth1->s = str+ "U";
                sth1->cnt = cnt;
                st.push(sth1);
            }
        }
        

        delete f;
    }

    return "NO";
}

int main()
{
    lli t;
    cin >> t;
    for (lli p = 0; p < t; p++)
    {
        lli n;
        cin >> n;
        unordered_map<pair<lli, lli>, int, hash_pair> m;
        for (int j = 0; j < n; j++)
        {
            lli x, y;
            cin >> x >> y;
            pair<lli, lli> p = make_pair(x, y);
            m.insert({p, 1});
            if (x > maxx)
                maxx = x;
            if (y > maxy)
                maxy = y;
        }

        for (int j = 0; j < maxx + 2; j++)
            for (int k = 0; k < maxy + 2; k++)
                visited[j][k] = false;

        string temp = traverse(m, n);
        if (temp == "NO")
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            cout << temp << endl;
        }
    }
}