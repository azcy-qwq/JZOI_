#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#define int long long
using namespace std;
const int N=1e3+100;
inline int read(){
	int f=1,c=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){c=c*10+ch-'0';ch=getchar();}
	return c*f;
}
int n,m;
int c[N][N],a,b,w[N][N];
map<int,set<int>>q;
int getsum(int x,int y,int nx,int ny){ 
	return c[nx][ny]-c[x-1][ny]-c[nx][y-1]+c[x-1][y-1];
}
int ans=-1e9-10,ansx,ansy;
signed main(){
	// freopen("matrix.in","r",stdin);
	// freopen("matrix.out","w",stdout);
	n=read();m=read();a=read();b=read(); 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			w[i][j]=read();
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			c[i][j]=c[i][j-1]+c[i-1][j]-c[i-1][j-1]+w[i][j];
		}
	}
	swap(a,b);//a是行，b是列 
	for(int i=1;i+a-1<=n;i++){
		for(int j=1;j+b-1<=m;j++){
			q[getsum(i,j,i+a-1,j+b-1)].insert(w[i][j]);
		} 
	}
	bool f=false;
	swap(a,b);
	for(int i=1;i+a-1<=n;i++){
		for(int j=1;j+b-1<=m;j++){
			int k=getsum(i,j,i+a-1,j+b-1);
			if(q[k].find(w[i][j])!=q[k].end()){
				ans=max(ans,k);
				f=true;
			}
		} 
	}
	if(!f){
		cout<<"Chinese_zjc_ L";
	}
	else cout<<ans<<endl;
	return 0;
}