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

bool prime[10000];

unordered_map<lli, int> primez;

void initialize()
{
    for (int i = 0; i < 10000; i++)
        prime[i] = true;
}

void seive()
{
    lli n = 10000;
    for (int i = 2; i < sqrt(n); i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < n; j += i)
                prime[j] = false;
        }
    }
}

int height[10000];
bool visited[10000];

int bfs(int a, int b)
{
    queue<int> q;
    q.push(a);
    visited[a] = true;
    height[a] = 0;

    // int tempz = b;
    // int bunit = tempz % 10;
    // tempz /= 10;
    // int btens = tempz % 10;
    // tempz /= 10;
    // int bhundreds = tempz % 10;
    // tempz /= 10;
    // int bthousands = tempz % 10;

    while (!q.empty())
    {
        int temp1 = q.front();
        // cout<<temp1<<endl;
        int temp=temp1;
        q.pop();
        if (temp == b)
            return height[b];

        int unit = temp % 10;
        temp /= 10;
        int tens = temp % 10;
        temp /= 10;
        int hundreds = temp % 10;
        temp /= 10;
        int thousands = temp % 10;

        int i=0;
        while(i<=9){
            int numb=(temp1-unit)+i;
            i++;
            if(!visited[numb] && primez.find(numb)!=primez.end())
            {
                q.push(numb);
                visited[numb]=true;
                height[numb]=height[temp1]+1;
            }
        }

        i=0;
        while(i<=9){
            int numb=(temp1-(10*tens))+(10*i);
            i++;
            if(!visited[numb] && primez.find(numb)!=primez.end())
            {
                q.push(numb);
                visited[numb]=true;
                height[numb]=height[temp1]+1;
            }
        }

        i=0;
        while(i<=9){
            int numb=(temp1-(100*hundreds))+(100*i);
            i++;
            if(!visited[numb] && primez.find(numb)!=primez.end())
            {
                q.push(numb);
                visited[numb]=true;
                height[numb]=height[temp1]+1;
            }
        }

        i=1;
        while(i<=9){
            int numb=(temp1-(1000*thousands))+(1000*i);
            i++;
            if(!visited[numb] && primez.find(numb)!=primez.end())
            {
                q.push(numb);
                visited[numb]=true;
                height[numb]=height[temp1]+1;
            }
        }
    }
}

int main()
{
    lli t;
    cin >> t;
    initialize();
    seive();
    for (int i = 2; i <= 9999; i++)
    {
        if (prime[i])
            primez.insert({i, 1});
    }
    for (lli p = 0; p < t; p++)
    {
        for (int i = 0; i < 10000; i++)
        {
            visited[i] = false;
            height[i] = -1;
        }
        lli a, b;
        cin >> a >> b;
        cout << bfs(a, b) << endl;
    }
}