#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m;
LL res=0;
int cl(int a,int b){return b==0?1e9:a/b;}
void dfs(int a,int b,int c,int d,int v)
{
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<v<<"\n";
	res+=max(0,min(cl(n-a,b),cl(n-c,d))-v+1);
    cout<<min(cl(n-a,b),cl(n-c,d))<<endl;
    cout<<res<<endl;
	res+=min(cl(m-a,b),cl(n-c,d))-v+1;
    cout<<res<<endl;
	for(int u=1;;u++)
	{
		if(c+2*a*u+(d+2*b*u)*max(v,u)>m||a+b*max(v,u)>n)break;
		dfs(c+2*a*u,d+2*b*u,a,b,max(u,v));
	}
}
void dfs1(int x,int y,int v)
{
	for(int u=1;;u++)
	{
		if(x+2*max(u+1,v)*(y+2*u*x)>m||y+2*u*x>n)break;
		dfs1(y+2*u*x,x,max(v,u+1));
	}
	dfs(y,2*x,x,0,v);
}
int main()
{
	cin>>n>>m;
	if(n>m)swap(n,m);
	dfs1(1,0,1);
	cout<<res;
	return 0;
}