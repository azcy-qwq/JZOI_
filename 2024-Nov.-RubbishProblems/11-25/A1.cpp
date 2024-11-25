#include<bits/stdc++.h>
using namespace std;
struct time_helper
{
#ifdef LOCAL
	clock_t time_last;
#endif
	time_helper()
	{
#ifdef LOCAL
		time_last=clock();
#endif
	}
	void test()
	{
#ifdef LOCAL
		auto time_now=clock();
		std::cerr<<"time:"<<1.*(time_now-time_last)/CLOCKS_PER_SEC<<";all_time:"<<1.*time_now/CLOCKS_PER_SEC<<std::endl;
		time_last=time_now;
#endif
	}
	~time_helper()
	{
		test();
	}
}time_helper;
#ifdef LOCAL
#include"dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
namespace Fread{const int SIZE=1<<16;char buf[SIZE],*S,*T;inline char getchar(){if(S==T){T=(S=buf)+fread(buf,1,SIZE,stdin);if(S==T)return'\n';}return *S++;}}namespace Fwrite{const int SIZE=1<<16;char buf[SIZE],*S=buf,*T=buf+SIZE;inline void flush(){fwrite(buf,1,S-buf,stdout);S=buf;}inline void putchar(char c){*S++=c;if(S==T)flush();}struct NTR{~NTR(){flush();}}ztr;}
#define getchar Fread::getchar
#define putchar Fwrite::putchar
#define Setprecision 10
#define between ' '
#define __int128 long long
template<typename T>struct is_char{static constexpr bool value=(std::is_same<T,char>::value||std::is_same<T,signed char>::value||std::is_same<T,unsigned char>::value);};template<typename T>struct is_integral_ex{static constexpr bool value=(std::is_integral<T>::value||std::is_same<T,__int128>::value)&&!is_char<T>::value;};template<typename T>struct is_floating_point_ex{static constexpr bool value=std::is_floating_point<T>::value||std::is_same<T,__float128>::value;};namespace Fastio{struct Reader{template<typename T>typename std::enable_if_t<std::is_class<T>::value,Reader&>operator>>(T&x){for(auto &y:x)*this>>y;return *this;}template<typename T>typename std::enable_if_t<is_integral_ex<T>::value,Reader&>operator>>(T&x){char c=getchar();short f=1;while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}x=0;while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}x*=f;return *this;}template<typename T>typename std::enable_if_t<is_floating_point_ex<T>::value,Reader&>operator>>(T&x){char c=getchar();short f=1,s=0;x=0;T t=0;while((c<'0'||c>'9')&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else return x*=f,*this;while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}template<typename T>typename std::enable_if_t<is_char<T>::value,Reader&>operator>>(T&c){c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();return *this;}Reader&operator>>(char*str){int len=0;char c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();while(c!='\n'&&c!=' '&&c!='\r')str[len++]=c,c=getchar();str[len]='\0';return*this;}Reader&operator>>(std::string&str){str.clear();char c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();while(c!='\n'&&c!=' '&&c!='\r')str.push_back(c),c=getchar();return*this;}Reader(){}}cin;const char endl='\n';struct Writer{typedef __int128 mxdouble;template<typename T>typename std::enable_if_t<std::is_class<T>::value,Writer&>operator<<(T x){for(auto &y:x)*this<<y<<between;*this<<'\n';return *this;}template<typename T>typename std::enable_if_t<is_integral_ex<T>::value,Writer&>operator<<(T x){if(x==0)return putchar('0'),*this;if(x<0)putchar('-'),x=-x;static int sta[45];int top=0;while(x)sta[++top]=x%10,x/=10;while(top)putchar(sta[top]+'0'),--top;return*this;}template<typename T>typename std::enable_if_t<is_floating_point_ex<T>::value,Writer&>operator<<(T x){if(x<0)putchar('-'),x=-x;x+=pow(10,-Setprecision)/2;mxdouble _=x;x-=(T)_;static int sta[45];int top=0;while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');while(top)putchar(sta[top]+'0'),--top;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top)putchar(sta[top]+'0'),--top;return*this;}template<typename T>typename std::enable_if_t<is_char<T>::value,Writer&>operator<<(T c){putchar(c);return*this;}Writer&operator<<(char*str){int cur=0;while(str[cur])putchar(str[cur++]);return *this;}Writer&operator<<(const char*str){int cur=0;while(str[cur])putchar(str[cur++]);return*this;}Writer&operator<<(std::string str){int st=0,ed=str.size();while(st<ed)putchar(str[st++]);return*this;}Writer(){}}cout;}
#define cin Fastio::cin
#define cout Fastio::cout
#define endl Fastio::endl
template<class Fun>class y_combinator_result{Fun fun_;public:template<class T>explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}template<class ...Args>decltype(auto) operator()(Args &&...args){return fun_(std::ref(*this), std::forward<Args>(args)...);}};template<class Fun>decltype(auto) y_combinator(Fun &&fun){return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));}

void solve();
main()
{
	int t=1;
	// cin>>t;
	while(t--)solve();
}
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<tuple<int,int,int>>e(m);
	for(auto &[w,u,v]:e)cin>>u>>v>>w;
	sort(e.begin(),e.end());
	vector<int>fa(n+1);
	for(int x=1;x<=n;x++)
	fa[x]=x;
	auto find=y_combinator([&](auto find,int x)->int
	{
		return fa[x]==x?x:fa[x]=find(fa[x]);
	});
	vector<vector<pair<int,int>>>e2(n+1);
	for(auto &[w,u,v]:e)
	if(find(u)!=find(v))
	{
		fa[find(u)]=find(v);
		e2[u].emplace_back(v,w);
		e2[v].emplace_back(u,w);
	}
	vector<int>dis1(n+1),dis2(n+1);
	auto dfs=y_combinator([&](auto dfs,int u,int f)->void
	{
		for(auto [v,w]:e2[u])
		if(v!=f)
		{
			dis1[v]=max(dis1[u],w);
			dfs(v,u);
		}
	});
	dfs(1,0);
	swap(dis2,dis1);
	dfs(n,0);
	int ans=2e9;
	for(auto &[w,u,v]:e)
	{
		if(dis1[u]<=w&&dis2[v]<=w)ans=min(ans,max(dis1[u],dis2[v])+w);
		if(dis2[u]<=w&&dis1[v]<=w)ans=min(ans,max(dis1[v],dis2[u])+w);
	}
	cout<<ans<<endl;
}