#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
typedef pair<int,int> PII;
int n,m,q,a[N],b[N],lg[N],s1[N],s2[N],s3[N],s4[N],s5[N],s6[N];
int st1[N][21],st2[N][21],st3[N][21],st4[N][21];
int st5[N][21],st6[N][21],st7[N][21],st8[N][21];
int query(int l,int r,int st[][21],bool f)
{
	int w=log2(r-l+1); 
	if(f) return max(st[l][w],st[r-(1<<w)+1][w]);
	else return min(st[l][w],st[r-(1<<w)+1][w]);
}
void calc(int st[][21],bool f,int n)
{
	for(int i=1;i<=log2(n);i++)
		for(int j=1;j<=n;j++)
			if(f) st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
			else st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>q;lg[1]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];s1[i]+=s1[i-1],s2[i]+=s2[i-1],s5[i]+=s5[i-1];
		if(a[i]==0) s5[i]++;
		else if(a[i]>0) st1[i][0]=st2[i][0]=a[i],st3[i][0]=0,st4[i][0]=-1e9,s1[i]++;
		else st3[i][0]=st4[i][0]=a[i],st1[i][0]=1e9,st2[i][0]=0,s2[i]++;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];s3[i]+=s3[i-1],s4[i]+=s4[i-1],s6[i]+=s6[i-1];
		if(b[i]==0) s6[i]++;
		else if(b[i]>0) st5[i][0]=st6[i][0]=b[i],st7[i][0]=0,st8[i][0]=-1e9,s3[i]++;
		else st7[i][0]=st8[i][0]=b[i],st5[i][0]=1e9,st6[i][0]=0,s4[i]++;
	}
	calc(st1,0,n),calc(st2,1,n),calc(st3,0,n),calc(st4,1,n);
	calc(st5,0,m),calc(st6,1,m),calc(st7,0,m),calc(st8,1,m);
	while(q--)
	{
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		ll ans=-1e18;
		if(s5[r1]-s5[l1-1]) ans=0;
		if(s1[r1]-s1[l1-1])
		{
			if(s4[r2]-s4[l2-1]) ans=max(ans,1ll*query(l1,r1,st2,1)*query(l2,r2,st7,0));
			else ans=max(ans,1ll*query(l1,r1,st2,1)*query(l2,r2,st5,0));
			if(s4[r2]-s4[l2-1]) ans=max(ans,1ll*query(l1,r1,st1,0)*query(l2,r2,st7,0));
			else ans=max(ans,1ll*query(l1,r1,st1,0)*query(l2,r2,st5,0));			
		}
		if(s2[r1]-s2[l1-1])
		{
			if(s3[r2]-s3[l2-1]) ans=max(ans,1ll*query(l1,r1,st4,1)*query(l2,r2,st6,1));
			else ans=max(ans,1ll*query(l1,r1,st4,1)*query(l2,r2,st8,1));
			if(s3[r2]-s3[l2-1]) ans=max(ans,1ll*query(l1,r1,st3,0)*query(l2,r2,st6,10));
			else ans=max(ans,1ll*query(l1,r1,st3,0)*query(l2,r2,st8,1));			
		}
		cout<<ans<<'\n';
	}
	return 0;
}