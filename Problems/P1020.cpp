#include<bits/stdc++.h>
using namespace std;
const int N=1e6+38;
int x,a[N],n,ans,dp[N];
int main(){
	ios::sync_with_stdio(0);
	while(cin>>x)
		a[++n]=x;
	dp[0]=INT_MAX;
	for(int i=1,l,r,mid;i<=n;++i){
		l=0,r=ans+1;
		while(r>l+1){
			mid=(l+r)>>1;
			if(dp[mid]>=a[i]) l=mid;
			else r=mid;
		}if(l+1>ans){
			ans=l+1;
		}dp[l+1]=a[i];
	}cout<<ans<<"\n";
	ans=0;
	memset(dp,0,sizeof(dp));
	for(int i=1,l,r,mid;i<=n;++i){
		l=0,r=ans+1;
		while(r>l+1){
			mid=(l+r)>>1;
			if(dp[mid]<a[i]) l=mid;
			else r=mid;
		}if(l+1>ans){
			ans=l+1;
		}dp[l+1]=a[i];
	}cout<<ans;
		
		
}
