#include<bits/stdc++.h>
using namespace std;
const int N=1e6+38;
int n,a[N],b[N],dp[N],to[N],ans;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		to[a[i]]=i;
//		dp[i]=INT_MAX;
	}for(int i=1;i<=n;++i){
		cin>>b[i];
	}dp[0]=INT_MAX;
	for(int i=1,l,r,mid;i<=n;++i){
		l=0,r=ans+1;
		while(r>l+1){
			mid=(l+r)>>1;
			if(dp[mid]<to[b[i]]) l=mid;
			else r=mid;
		}if(l+1>ans){
			ans=l+1;
		}dp[l+1]=to[b[i]];
	}cout<<ans<<"\n";
}              
