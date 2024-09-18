#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
namespace azcy{
    using namespace std;
    bool debug_switch=1;
    void auto_init(){
        ios::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
    }
    void qfopen(string INPUT_FILE_NAME,string OUTPUT_FILE_NAME){
        freopen(INPUT_FILE_NAME.data(),"r",stdin);
        freopen(OUTPUT_FILE_NAME.data(),"w",stdout);
    }
    template<typename T>
    void dbgo(T x){
        cout<<x<<" ";
    }
    template<typename First,typename... Rest>
    void dbgo(First first,Rest... rest){
        cout<<first<<" ";
        dbgo(rest...);
    }  
    template<typename First,typename... Rest>
    void dbg(First first,Rest... rest){
        if(!debug_switch)return ;
        cout<<first<<" ";
        dbgo(rest...);
        cout<<"\n";
    }//made by _azcy
	template<typename T>
    void dbg(T x)
    {
        if (!debug_switch)
            return;
        cout << x << "\n";
    }
}using namespace azcy;
const int MOD = 998244353;
#define LL long long
#define int long long
int inv(int k) {
  int res = 1;
  for (int e = MOD - 2; e; e /= 2) {
    if (e & 1) res = (LL)res * k % MOD;
    k = (LL)k * k % MOD;
  }
  return res;
}
int qpow(long long a, int b) {
  int ans = 1;
  a = (a % MOD + MOD) % MOD;
  for (; b; b >>= 1) {
    if (b & 1) ans = (a * ans) % MOD;
    a = (a * a) % MOD;
  }
  return ans;
}
int x[N],y[N],n,k,ans,temp,t2,f;
void lagr(){
    for(int i=1;i<=n;++i){
        temp=1;
        for(int j=1;j<=n;++j){
            if(i==j) continue;
            t2=x[i]-x[j];
            f=(t2>=0)?1:-1;
            t2*=f;
            t2=inv(t2);
            temp*=((k-x[j]+(LL)1000000*MOD)%MOD)*t2*f;
            temp%=MOD;
        }
        temp*=y[i];
        temp+=MOD*(LL)1000000;
        temp%=MOD;
        dbg(temp);
        ans+=temp+MOD*(LL)1000000;
        ans%=MOD;
    }
    dbg(ans);
}
main(){
//	ios::sync_with_stdio(0);
    // dbg(inv(72),qpow(72,MOD-2));
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>x[i]>>y[i];
    }
    if(n==1){
        cout<<y[1];
        return 0;
    }
    lagr();
}
/*
3 40000000
1 3
2 7
3 13
*/