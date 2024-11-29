#include<bits/stdc++.h>
using namespace std;
const int N=1e6+38;
int n,m,p,q,fa[N],en[N],cnt;
bitset<N> vis;
char opt;
int getfa(int x){
	if(fa[x]==x) return x;
	return fa[x]=getfa(fa[x]);
}void merge(int x,int y){
	x=getfa(x),y=getfa(y);
	fa[x]=y;
}
int main(){
	//ios::sync_with_stdio(0);
	cin>>n>>m;
	iota(fa+1,fa+n+1,1);
	for(int opp=1;opp<=m;opp++){
		cin>>opt>>p>>q;
		if(opt=='F'){
			merge(p,q);
		}else{
			if(en[p]==0) en[p]=getfa(q);
			else merge(en[p],q);
			if(en[q]==0) en[q]=getfa(p);
			else merge(en[q],p);
		}
	}for(int i=1;i<=n;++i){
		if(vis[getfa(i)]) continue;
		vis[getfa(i)]=1;
		++cnt;
	}cout<<cnt;
}
