#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;


bool visited[100005];
vector<p>vect[100005];

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
  int distance[100005];

	for(int i=0;i<V;i++)
    {
        visited[i]=false;
        distance[i]=5;
    }
    for(int i=0;i<E;i++)
    {
        int a, b, w;
        cin>>a>>b>>w;
        vect[a].push_back(make_pair(w,b));
        vect[b].push_back(make_pair(w,a));
    }
    priority_queue<p, vector<p>, greater<p>>pq;
    p temp;
    temp.first =0;
    temp.second = 0;
    pq.push(temp);
    distance[0]=0;
    
    while(!pq.empty())
    {
        p temp = pq.top();
        pq.pop();
        
        if(visited[temp.second])
            continue;
        int x = temp.second;
        visited[x]=true;
        for(int i=0;i<vect[x].size();i++)
        {
            if(distance[vect[x][i].second]>distance[x]+vect[x][i].first)
            {
                distance[vect[x][i].second]=distance[x]+vect[x][i].first;
                pq.push(vect[x][i]);
            }
        }
    }
    
    for(int i=0;i<V;i++)
    {
        cout<<i<<" "<<distance[i]<<endl;
    }
    
  return 0;
}
