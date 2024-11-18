#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int a=0,f=1;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar())if(ch=='-')f=-1;
	for(;ch<='9'&&ch>='0';ch=getchar())a=a*10+ch-'0';
	return a*f;
}
inline void write(int x){
    if(x<0){
        putchar('-');
        x=-x;}
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
const int N=1e6+10; 
int T,p[N],b[N],n,m,l,v,ans,sum,now;
struct Node{
	int d,a,v;
}s[N];
vector<int>e,q;
int pr(int i){
	int res=s[i].d+(v*v-s[i].v*s[i].v)/(2*s[i].a);
	if((v*v-s[i].v*s[i].v)%(2*s[i].a)==0)res--;
	if(res>l)res=l;
	return res;
}
bool cmp(int x,int y){
	int px=pr(x),py=pr(y);
	if(b[px]==b[py])return s[x].d<s[y].d;
	return px<py;
}
void Solve(){
	e.clear(),q.clear();
	memset(b,0,sizeof(b));
	n=read(),m=read(),l=read(),v=read(),sum=0,ans=m,now=-1;
	for(int i=1;i<=n;i++)
		s[i].d=read(),s[i].v=read(),s[i].a=read();
	for(int i=1;i<=m;i++)p[i]=read();
	sort(p+1,p+1+m);
	if(p[1]==0)b[0]=1;
	else b[0]=0;
	for(int i=1,j=1;j<=l;){
		if(p[i]==0)i++;
		if(j==p[i])i++,b[j]=b[j-1]+1;
		else b[j]=b[j-1];
		j++;
	}
	for(int i=1;i<=n;i++){
		if(s[i].a>=0&&s[i].d<=p[m]&&(p[m]-s[i].d)*s[i].a*2+s[i].v*s[i].v>v*v)
			sum++,e.push_back(i);
		if(s[i].a<0){
			if(s[i].v<=v)continue;
			if(b[pr(i)]-b[s[i].d-1]>0)
				sum++,q.push_back(i);
		}
	}
	sort(q.begin(),q.end(),cmp);
	for(auto ed:q){
		if(now>=s[ed].d&&now<=pr(ed))continue;
		ans--,now=p[b[pr(ed)]];
	}
	for(auto ed:e){
		if(now<s[ed].d){
			ans--;break;
		}
		if((now-s[ed].d)*s[ed].a*2+s[ed].v*s[ed].v<=v*v){
			ans--;break;
		}
	}
	cout<<sum<<" "<<ans<<"\n";
}
signed main(){
	T=read();
	while(T--)Solve();
	return 0;
}