#include<bits/stdc++.h>
using namespace std;
const int N=1e4+38;
const long long inf=LONG_LONG_MAX;
typedef long long ll;
int n,aa,bb;
pair<ll,ll> dot[N];
long long dis[N];
bitset<N> vis;
template<typename A,typename B>
inline A minm(A x,B y){
	return (x<=y)?x:(A)y;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>dot[i].first>>dot[i].second;
	}for(int i=2;i<=n;++i){
		dis[i]=inf;
	}
	for(int i=1,cur;i<=n-1;++i){
		cur=0;
		for(int j=1;j<=n;++j)
			if(vis[j]==0&&(cur==0||dis[j]<dis[cur]))
				cur=j;
		vis[cur]=1;
		for(int j=1;j<=n;++j)
			if(vis[j]==0) dis[j]=minm(dis[j],(dot[cur].first-dot[j].first)*(dot[cur].first-dot[j].first)
								+(dot[cur].second-dot[j].second)*(dot[cur].second-dot[j].second));
	}long double temp=0;
	for(int i=1;i<=n;++i) 
		temp+=sqrt((double)dis[i]);
	cout<<fixed<<setprecision(2)<<temp;
}
