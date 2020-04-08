#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

void vprint(vector<pair<int, int>> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i].first << ' ' << v[i].second << endl;
    cout << endl;
}

void aprint(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;

    return a.first < b.first;
}

int main()
{
    lli t;
    cin >> t;
    for (lli p = 0; p < t; p++)
    {
        lli n;
        cin >> n;
        vector<pair<int, int>> vect;
        vect.push_back(make_pair(0, 0));
        for (int w = 0; w < n; w++)
        {
            int a, b;
            cin >> a >> b;
            vect.push_back(make_pair(a, b));
        }

        sort(vect.begin(), vect.end(), compare);
        // vprint(vect);

        bool ans = true;
        string str = "";
        for (int i = 1; i < vect.size(); i++)
        {
            if (vect[i].first >= vect[i - 1].first && vect[i].second < vect[i - 1].second)
            {
                ans = false;
                break;
            }

            else
            {
                for (int j = vect[i - 1].first; j < vect[i].first; j++)
                {
                    str += "R";
                }
                for (int j = vect[i - 1].second; j < vect[i].second; j++)
                {
                    str += "U";
                }
            }
        }

        if (ans)
        {
            cout << "YES" << endl;
            cout << str << endl;
        }

        else
        {
            cout << "NO" << endl;
        }
    }
}