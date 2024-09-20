#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
bitset<N> vis;
int n,m,tempa,tempb,tempc,t[N];
struct Node{
	vector<int> nei;
	vector<int> p;
	int id,dist;
	Node(){
		dist=INT_MIN;
	}
}graph[N];
void add_edge(int dA,int dB,int dP)
{
	graph[dA].nei.push_back(dB);
	graph[dA].p.push_back(dP);
}
pair<pair<int,int>,int> piii[N];
signed main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>tempa>>tempb>>tempc;
        piii[i]={{tempa,tempb},tempc};
		add_edge(tempa,tempb,-tempc);
	}
	
	for(int i=1;i<=n;i++)
		add_edge(0,i,0);
	
	queue<int> q;
	q.push(0);
	vis[0]=1;
	graph[0].dist=0;
	while(!q.empty())
	{
//		cout<<".";
		int cur=q.front();
		q.pop();
		vis[cur]=0;
		for(int i=0;i<graph[cur].nei.size();i++)
		{
			if(graph[cur].dist+graph[cur].p[i]>graph[graph[cur].nei[i]].dist)
			{
				graph[graph[cur].nei[i]].dist=graph[cur].dist+graph[cur].p[i];
				if(!vis[graph[cur].nei[i]]){
					vis[graph[cur].nei[i]]=1;
					q.push(graph[cur].nei[i]);
					t[graph[cur].nei[i]]++;
					if(t[graph[cur].nei[i]]>=n+1){
						cout<<"NO\n";
						return 0;
					}
				}
			}
		}
	}
    for(int i=1;i<=m;++i){
        if(graph[piii[i].first.first].dist-graph[piii[i].first.second].dist>piii[i].second)
        {
            cout<<"NO\n";
            exit(0);
        }
    }
//	cout<<".";
	for(int i=1;i<=n;i++)
	{
		cout<<graph[i].dist<<" ";
	}
}