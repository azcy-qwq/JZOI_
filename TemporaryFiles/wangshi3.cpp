#include<bits/stdc++.h>
// #include<iostream>
#define ll long long
#define fi first
#define se second
#define I_Will_Win return 0
#define sz(a) ((int)a.size())
#define See_Time cerr<<(clock()-Time)*1.0/CLOCKS_PER_SEC<<'\n'
#define See_Memory cerr<<abs(&M2-&M1)/1024.0/1024.0<<"MB\n"
using namespace std;
typedef pair<int,int> PII;
const int N=5e5+10;
bool M1;
int n,m,b[N]; 
template<typename T>
inline void  Swap(T a,T b){
    T c=a;
    a=b;
    b=c;
}
namespace wang_shi{
	int l[N<<2],r[N<<2];
	int val1[N<<2],val0[N<<2],tag[N<<2],cov[N<<2];
	// cov 1为推平为 0 ， 2为推平为1  
	#define ls(x) (x<<1)
	#define rs(x) (x<<1|1) 
	void Pushup(int p)
	{	
		val0[p]=val0[ls(p)]+val0[rs(p)];
		val1[p]=val1[ls(p)]+val1[rs(p)];
	}
	void Pushdown(int p)
	{
		if(!tag[p]&&!cov[p]) return;
		if(cov[p])
		{
			if(cov[p]==1) //0 
			{
				cov[ls(p)]=cov[rs(p)]=cov[p];
				if(l[ls(p)]==r[ls(p)]) cov[ls(p)]=0;
				if(l[rs(p)]==r[rs(p)]) cov[rs(p)]=0;
				tag[ls(p)]=tag[rs(p)]=0;
				val1[ls(p)]=val1[rs(p)]=0;
				val0[ls(p)]=r[ls(p)]-l[ls(p)]+1;
				val0[rs(p)]=r[rs(p)]-l[rs(p)]+1;
			}
			else //1
			{	
				cov[ls(p)]=cov[rs(p)]=cov[p];
				if(l[ls(p)]==r[ls(p)]) cov[ls(p)]=0;
				if(l[rs(p)]==r[rs(p)]) cov[rs(p)]=0;
				tag[ls(p)]=tag[rs(p)]=0;
				val0[ls(p)]=val0[rs(p)]=0;
				val1[ls(p)]=r[ls(p)]-l[ls(p)]+1;
				val1[rs(p)]=r[rs(p)]-l[rs(p)]+1;
			}
			cov[p]=0; tag[p]=0;
		}
		else if(tag[p])
		{ 
			 Swap(val0[ls(p)],val1[ls(p)]);
			 Swap(val0[rs(p)],val1[rs(p)]);
			if(cov[ls(p)])
			{
				if(cov[ls(p)]==1) cov[ls(p)]=2;
				else cov[ls(p)]=1;
				tag[ls(p)]=0;
			}
			else tag[ls(p)]^=1;
			if(cov[rs(p)])
			{
				if(cov[rs(p)]==1) cov[rs(p)]=2;
				else cov[rs(p)]=1;
				tag[rs(p)]=0;
			}
			else tag[rs(p)]^=1;			
			tag[p]=0;
		}
	}
	void Build(int p,int x,int y)
	{
		l[p]=x,r[p]=y;
		if(x==y) 
		{
			if(b[x]) val1[p]++;
			else val0[p]++;
			return;
		}
		int mid=(x+y)>>1;
		Build(ls(p),x,mid); Build(rs(p),mid+1,y);
		Pushup(p);
	}
	void Cover(int p,int c)
	{
		if(c) //1
		{
			cov[p]=2; val0[p]=0;
			val1[p]=r[p]-l[p]+1;
			tag[p]=0;
		}
		else //0
		{
			cov[p]=1; val1[p]=0;
			val0[p]=r[p]-l[p]+1;
			tag[p]=0;
		}
	}
	void Modify(int p,int x,int y)
	{
		if(x<=l[p]&&r[p]<=y)
		{
			if(cov[p])
			{
				if(cov[p]==1)
				{
					cov[p]=2; tag[p]=0;
					 Swap(val1[p],val0[p]);
				}
				else
				{
					cov[p]=1; tag[p]=0;
					 Swap(val1[p],val0[p]);
				} 
			}
			else
			{
				tag[p]^=1; 
				 Swap(val0[p],val1[p]);	
			} 
			return;
		}
		Pushdown(p); int mid=(l[p]+r[p])>>1;
		if(x<=mid) Modify(ls(p),x,y);
		if(y>mid) Modify(rs(p),x,y);
		Pushup(p); 
	}
	int Ask(int p,int x,int y,bool fl)
	{
		if(x<=l[p]&&r[p]<=y) return fl?val1[p]:val0[p];
		Pushdown(p);
		int mid=(l[p]+r[p])>>1,res=0;
		if(x<=mid) res+=Ask(ls(p),x,y,fl);
		if(y>mid) res+=Ask(rs(p),x,y,fl);
		return res; 
	}
	void Print(int p,int x,int y)
	{
	//	cout<<p<<' '<<"----"<<cov[p]<<' '<<tag[p]<<' '<<val1[p]<<' '<<val0[p]<<' '<<l[p]<<' '<<r[p]<<'\n';
		if(l[p]==r[p]) return cout<<val1[p]<<' ',void();
		int mid=(l[p]+r[p])>>1; Pushdown(p);
		if(x<=mid) Print(ls(p),x,y); 
		if(y>mid) Print(rs(p),x,y);
	}
}
void Solve()
{
	cin>>n>>m; ll ans=0; 
	string s; cin>>s;
	for(int i=1;i<=n;++i)
	{ 
		b[i]=(s[i-1]-'0');
		if(b[i]!=b[i-1]) ans+=(n-i+1);
 	}
	wang_shi::Build(1,1,n);
    int mid,x,y,pos,v,sum0,val,sum1,r,idx;
	for(int i=1;i<=m;++i)
	{
		cin>>v;
		if(v>0) // 0 -> 1
		{
			sum0=wang_shi::Ask(1,1,n,0);
			if(sum0<=v)
			{
				wang_shi::Cover(1,1); ans=n;
				cout<<ans<<'\n'; continue;
				wang_shi::Print(1,1,n); cout<<'\n';	
			} 
			val=wang_shi::Ask(1,n,n,0),r=n;
			if(!val)
			{
				x=1,y=r,pos=r;
				while(x<=y)
				{
					mid=(x+y)>>1;
					if(!wang_shi::Ask(1,mid,n,0)) y=mid-1,pos=mid;
					else x=mid+1;
				}
				r=pos;
			}
			if(!val) r--;  
			idx=1; 
			while(r>1)
			{
				if(idx&1)//0000
				{
					x=1,y=r,pos=r;
					while(x<=y)
					{
						mid=(x+y)>>1;
						if(!wang_shi::Ask(1,mid,r,1)) y=mid-1,pos=mid;
						else x=mid+1; 
					}
					if(r-pos+1<=v)
					{
						ans-=(n-pos+1);
						ans-=(n-(r+1)+1);
						wang_shi::Modify(1,pos,r);
						v-=(r-pos+1); r=pos; 
					}
					else 
					{
						pos=r-v+1;
						ans+=(n-pos+1);
						ans-=(n-(r+1)+1);
						wang_shi::Modify(1,pos,r);
						break;
					}
					if(!v) break;
					r--;
				}
				else//1111
				{
					x=1,y=r,pos=r;
					while(x<=y)
					{
						mid=(x+y)>>1;
						if(!wang_shi::Ask(1,mid,r,0)) y=mid-1,pos=mid;
						else x=mid+1; 
					}
					r=pos-1;
				}
				idx++;
			}
		}
		else// 1 -> 0
		{	
			v=-v;
			sum1=wang_shi::Ask(1,1,n,1);
			if(sum1<=v)
			{
				wang_shi::Cover(1,0); ans=0;
				cout<<ans<<'\n'; 	continue;
				wang_shi::Print(1,1,n); cout<<'\n';
			} 
			val=wang_shi::Ask(1,n,n,1),r=n;
			if(!val)
			{
				x=1,y=r,pos=r;
				while(x<=y)
				{
					mid=(x+y)>>1;
					if(!wang_shi::Ask(1,mid,n,1)) y=mid-1,pos=mid;
					else x=mid+1;
				}
				r=pos;
			}
			if(!val) r--;
			idx=1; 
			while(r>1)
			{
				if(idx&1)//1111
				{
					x=1,y=r,pos=r;
					while(x<=y)
					{
						mid=(x+y)>>1;
						if(!wang_shi::Ask(1,mid,r,0)) y=mid-1,pos=mid;
						else x=mid+1; 
					}
					if(r-pos+1<=v)
					{
						ans-=(n-pos+1);
						ans-=(n-(r+1)+1);
						wang_shi::Modify(1,pos,r);
						v-=(r-pos+1); r=pos; 
					}
					else 
					{
						pos=r-v+1;
						ans+=(n-pos+1);
						ans-=(n-(r+1)+1);
						wang_shi::Modify(1,pos,r);
						break;
					}
					if(!v) break;
					r--;
				}
				else//0000
				{
					int x=1,y=r,pos=r;
					while(x<=y)
					{
						mid=(x+y)>>1;
						if(!wang_shi::Ask(1,mid,r,1)) y=mid-1,pos=mid;
						else x=mid+1; 
					}
					r=pos-1;
				}
				idx++;
			}
		}
		cout<<ans<<'\n';  //T.Print(1,1,n); cout<<'\n';	
	}
}
bool M2;
int main()
{
//	freopen("binary.in","r",stdin);
//	freopen("binary.out","w",stdout);
	// int Time=clock();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t=1; //cin>>t;
	while(t--) Solve();
	// See_Memory; See_Time;
	I_Will_Win;
}
/*
11....1111000...00111...1111 --->  11...1111111...11111...1111  ans=ans-pos-r
11....1111000...00111...1111 --->  11...1111000..111111...1111  ans=ans+pos-r
*/