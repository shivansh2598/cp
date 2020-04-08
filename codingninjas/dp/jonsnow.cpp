#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int farray[1025], sarray[1025];

void copy()
{
    for (int i = 0; i < 1025; i++)
    {
        farray[i] = sarray[i];
    }
}

void clear()
{
    for (int i = 0; i < 1025; i++)
    {
        sarray[i] = 0;
    }
}

int main()
{
    lli n, k, x;
    cin >> n >> k >> x;

    for (int i = 0; i < 1025; i++)
    {
        farray[i] = 0;
        sarray[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sarray[x]++;
    }

    for (int j = 0; j < k; j++)
    {
        copy();
        clear();
        bool even = true;
        bool turn = true;
        for (int i = 0; i < 1025; i++)
        {
            if (farray[i] == 0)
                continue;

            if (!turn)
            {
                sarray[i]=farray[i];
                turn = true;
                continue;
            }

            else
            {
                turn = false;
            }

            if (farray[i] % 2 == 0)
            {
                int temp = farray[i] / 2;
                int index = i ^ x;
                sarray[i] += farray[i] - temp;
                sarray[index] += temp;
            }
            else
            {
                int temp = farray[i] / 2;
                int index = i ^ x;
                if (even)
                {
                    temp++;
                    sarray[i] += farray[i] - temp;
                    sarray[index] += temp;
                    even = false;
                }
                else
                {
                    sarray[i] += farray[i] - temp;
                    sarray[index] += temp;
                    even = true;
                }
            }
        }
    }

    int minz, maxz;
    bool first = false;
    for (int i = 0; i < 1025; i++)
    {
        if (sarray[i] != 0)
        {
            // cout << sarray[i] << " ";
            if (!first)
            {
                minz = i;
                maxz = i;
                first = true;
            }
            else
                maxz = i;
        }
    }
    cout << endl;

    cout << maxz << " " << minz << endl;

    return 0;
}
