#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int dp[50][50][2];

lli maxprofit(vector<int> &vect, int n, int k, int i, int t, int mode)
{
    // cout<<n<<" "<<k<<" "<<i<<" "<<t<<" "<<mode<<endl;
    if (t > k)
        return 0;
    if (i >= n)
        return 0;
    if (dp[i][t][mode] != -1)
        return dp[i][t][mode];

    if (mode == 0)
    {
        // cout << "hello1" << endl;
        int z = -(vect[i]) + maxprofit(vect, n, k, i + 1, t, 1);
        int y = maxprofit(vect, n, k, i + 1, t, 0);
        dp[i][t][mode]=max(y,z);
    }
    else
    {
        // cout << "hello2" << endl;
        int z=vect[i] + maxprofit(vect, n, k, i + 1, t + 1, 0);
        int y= maxprofit(vect, n, k, i + 1, t, 1);
        // cout<<y<<" "<<z<<endl;
        dp[i][t][mode]=max(z,y);
    }

    return dp[i][t][mode];

    // cout << "hey" << dp[i][t] << endl;

    // return dp[i][t];
}

int main()
{
    lli q;
    cin >> q;
    while (q--)
    {
        memset(dp, -1, sizeof(int) * 50 * 50 *2);
        int k;
        cin >> k;
        lli n;
        cin >> n;
        vector<int> vect;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            vect.push_back(x);
        }
        cout << maxprofit(vect, n, k, 0, 0, 0) << endl;
    }
    return 0;
}
