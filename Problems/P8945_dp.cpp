#include<bits/stdc++.h>
using namespace std;
#define ll long long
int read(){
    int x;
    cin>>x;
    return x;
}
const int N=1e7+10;
int n,k,a[N],bel[N],cnt,pos[N],ans,pm[N],sm[N],p0[N],p1[N];
struct node{
	int v,p;
}stk[N];
int hd=1,tl;
int main(){
	n=read(),k=read();
	for(int i=1,las=0;i<=n;i++){
		a[i]=read();
		bel[i]=las;
		if(a[i]){
			p0[i]=p0[i-1]+a[i];
			p1[i]=p1[i-1]+a[i];
		}else{
			p0[i]=p0[i-1]-1;
			p1[i]=p1[i-1]+1;
			pos[++cnt]=i,las=cnt;
		}
	}
	pm[n+1]=sm[n+1]=-2e9;
	for(int i=n;i>=1;i--)
		pm[i]=max(pm[i+1],p1[i]),
		sm[i]=max(sm[i+1],p0[i]);
	for(int i=0,lp=1;i<=n;i++){
		while(hd<=tl&&stk[hd].p<i) hd++;
		int id=bel[i]+k+1;
		if(id>cnt) ans=max(ans,pm[i+1]-p1[i]);
		else{
			int np=pos[id];
			for(;lp<=np-1;lp++){
				while(hd<=tl&&stk[tl].v<p1[lp]) tl--;
				stk[++tl]={p1[lp],lp};
			}
			ans=max({ans,stk[hd].v-p1[i],sm[np]-p0[i]+2*k});
		}
	}
    cout<<ans;
	// write(ans);
	// flush();
}