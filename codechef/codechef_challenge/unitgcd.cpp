#include <iostream>
typedef long long int lli;
using namespace std;

void print(lli n, lli k)
{
    bool sth = true;
    if (n % 2 != 0)
    {
        sth = false;
        k = 2;
    }
    for (lli i = k; i <= n; i += 2)
    {
        if (!sth)
        {
            cout << 3 << " " << 1 << " " << 2 << " " << 3 << endl;
            sth = true;
        }
        else
            cout << 2 << " " << i << " " << i + 1 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli tc;
    cin >> tc;
    while (tc--)
    {
        lli n;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
            cout << 1 << " " << 1 << endl;
        }
        else
        {
            cout << n / 2 << endl;
            print(n, 1);
        }
    }
}