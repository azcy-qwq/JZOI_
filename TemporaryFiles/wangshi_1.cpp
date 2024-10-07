#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define wang_shi return 0
#define See_Time cerr<<(clock()-Time)*1.0/CLOCKS_PER_SEC<<'\n'
#define See_Memory cerr<<abs(&M2-&M1)/1024.0/1024.0<<"MB\n"
using namespace std;
const int N=2.2e7+10;
typedef pair<int,int> PII;
bool M1;
struct Manacher
{
    int n,m,p[N];
    string s,t;
    void Work()
    {
        n=s.size(); s=' '+s; t[0]='!'; m=1;
        for(int i=1;i<=n;++i) t[++m]=s[i];
//        t[++m]='#',t[++m]='@'; int ans=0;
//        for(int i=1,d=0,r=0;i<m;++i)
//        {
//            if(i>r) p[i]=1; else p[i]=min(r-i+1,p[2*d-i]);
//            while(t[i-p[i]]==t[i+p[i]]) p[i]++;
//            if(i+p[i]-1>r) d=i,r=i+p[i]-1;
//            ans=max(ans,p[i]-1);
//        }
//        cout<<ans<<'\n';
    }    
}M;
void Solve()
{
    cin>>M.s;
    M.Work();
}
bool M2;
int main()
{
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int Time=clock();
    int t=1; //cin>>t;
    while(t--) Solve();
    See_Memory; See_Time;
    wang_shi;
}