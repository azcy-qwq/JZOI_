#include<bits/stdc++.h>
#define ll long long
#define lc p<<1
#define rc p<<1|1
using namespace std;
const int N=1e5+10;
int n,m,Q;
int a[3][N];
struct node{
	int l,r;
	int maxv,minv,aminv,amaxv;
}t[3][4*N];

void push_up(int rt,int p){
	t[rt][p].maxv=max(t[rt][lc].maxv,t[rt][rc].maxv);
	t[rt][p].minv=min(t[rt][lc].minv,t[rt][rc].minv);
	t[rt][p].aminv=min(t[rt][lc].aminv,t[rt][rc].aminv);
	t[rt][p].amaxv=max(t[rt][lc].amaxv,t[rt][rc].amaxv);
}

void build(int rt,int p,int l,int r){
	t[rt][p].l=l,t[rt][p].r=r;
	if(l == r){
		t[rt][p].maxv=t[rt][p].minv=a[rt][l];
		if(a[rt][l] >= 0){
			t[rt][p].aminv=a[rt][l];
			t[rt][p].amaxv=-2e9;
		}
		else{
			t[rt][p].amaxv=a[rt][l];
			t[rt][p].aminv=2e9;
		}
		return;
	}
	int mid=(l+r)>>1;
	build(rt,lc,l,mid);
	build(rt,rc,mid+1,r);
	push_up(rt,p);
}

int query1(int rt,int p,int l,int r){
	if(l <= t[rt][p].l && t[rt][p].r <= r) return t[rt][p].maxv;
	int mid=(t[rt][p].l+t[rt][p].r)>>1;
	int ans=-2e9;
	if(l <= mid) ans=max(ans,query1(rt,lc,l,r));
	if(mid < r) ans=max(ans,query1(rt,rc,l,r));
	return ans;
}

int query2(int rt,int p,int l,int r){
	if(l <= t[rt][p].l && t[rt][p].r <= r) return t[rt][p].minv;
	int mid=(t[rt][p].l+t[rt][p].r)>>1;
	int ans=2e9;
	if(l <= mid) ans=min(ans,query2(rt,lc,l,r));
	if(mid < r) ans=min(ans,query2(rt,rc,l,r));
	return ans;
}

int query3(int rt,int p,int l,int r){
	if(l <= t[rt][p].l && t[rt][p].r <= r) return t[rt][p].aminv;
	int mid=(t[rt][p].l+t[rt][p].r)>>1;
	int ans=2e9;
	if(l <= mid) ans=min(ans,query3(rt,lc,l,r));
	if(mid < r) ans=min(ans,query3(rt,rc,l,r));
	return ans;
}

int query4(int rt,int p,int l,int r){
	if(l <= t[rt][p].l && t[rt][p].r <= r) return t[rt][p].amaxv;
	int mid=(t[rt][p].l+t[rt][p].r)>>1;
	int ans=-2e9;
	if(l <= mid) ans=max(ans,query4(rt,lc,l,r));
	if(mid < r) ans=max(ans,query4(rt,rc,l,r));
	return ans;
}

int main(){
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=n;i++) scanf("%d",&a[1][i]);
	for(int i=1;i<=m;i++) scanf("%d",&a[2][i]);
	build(1,1,1,n),build(2,1,1,m);
	
	while(Q--){
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		int amax=query1(1,1,l1,r1),amin=query2(1,1,l1,r1);
		int bmax=query1(2,1,l2,r2),bmin=query2(2,1,l2,r2);
		ll ans=0;
		if(amin >= 0 && bmin >= 0) ans=(ll)amax*bmin;
		else if(amin >= 0 && bmax < 0) ans=(ll)amin*bmin;
		else if(amax < 0 && bmin >= 0) ans=(ll)amax*bmax;
		else if(amax < 0 && bmax < 0) ans=(ll)amin*bmax;
		else if(amax >= 0 && amin < 0 && bmin >= 0) ans=(ll)amax*bmin;
		else if(amax >= 0 && amin < 0 && bmax < 0) ans=(ll)amin*bmax;
		else if(amin >= 0 && bmax >= 0 && bmin < 0) ans=(ll)amin*bmin;
		else if(amax < 0 && bmax >= 0 && bmin < 0) ans=(ll)amax*bmax;
		else ans=max((ll)query3(1,1,l1,r1)*query2(2,1,l2,r2),(ll)query4(1,1,l1,r1)*query1(2,1,l2,r2));
		printf("%lld\n",ans);
	}
	return 0;
}