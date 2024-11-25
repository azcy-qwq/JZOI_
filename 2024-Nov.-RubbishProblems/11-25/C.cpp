#include<bits/stdc++.h>
using namespace std;
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
        cerr<<x<<" ";
    }
    template<typename First,typename... Rest>
    void dbgo(First first,Rest... rest){
        cerr<<first<<" ";
        dbgo(rest...);
    }  
    template<typename First,typename... Rest>
    void dbg(First first,Rest... rest){
        if(!debug_switch)return ;
        cerr<<first<<" ";
        dbgo(rest...);
        cerr<<"\n";
    }//made by _azcy
    template<typename T>
    void dbg(T x)
    {
        if (!debug_switch)
            return;
        cerr << x << "\n";
    }
    template<typename T>
    inline T maxm(T a,T b){
        return (a>b)?a:b;
    }template<typename T1,typename T2>
    inline T1 maxm(T1 a,T2 b){
        return (a>b)?(a):(a=b,a);
    }
    template<typename First,typename... Rest>
    inline First maxm(First first,Rest... rest){
        return maxm(first,maxm(rest...));
    }
    template<typename T>
    inline T minm(T a,T b){
        return (a<b)?a:b;
    }template<typename T1,typename T2>
    inline T1 minm(T1 a,T2 b){
        return (a<b)?a:(a=b,a);
    }
    template<typename First,typename... Rest>
    inline First minm(First first,Rest... rest){
        return minm(first,minm(rest...));
    }
}using namespace azcy;
const int N=1e4+10;
template<const int PCC>
class ModInt{
    public:
        long long data;
        ModInt(){data=0;}
        ModInt(const ModInt& x){data=x.data%PCC;}
        template<typename T> ModInt(T x) {data=(x%PCC+PCC)%PCC;}
        ModInt operator+(const ModInt& x){ModInt y;y.data=(x.data+this->data)%PCC;return y;}
        ModInt operator-(const ModInt& x){ModInt y;y.data=((this->data-x.data)%PCC+PCC)%PCC;return y;}
        ModInt operator*(const ModInt& x){ModInt y;y.data=((this->data*x.data)%PCC+PCC)%PCC;return y;}
        template<typename T> ModInt operator+(const T& x){ModInt y;y.data=(this->data+(x%PCC))%PCC;return y;}
                     ModInt operator+(const long long& x){ModInt y;y.data=(this->data+(x%PCC))%PCC;return y;}
        template<typename T> ModInt operator*(const T& x){ModInt y;y.data=(this->data*(x%PCC))%PCC;return y;}
                          void operator=(const ModInt& x){data=x.data;}
        template<typename T>   void operator=(const T& x){data=(x%PCC+PCC)%PCC;}
        template<typename T> ModInt operator/(const T& x){ModInt y=x;y.data/=x;return y;}
        friend ostream &operator<<(ostream &output,const ModInt &D ){ 
            output<<D.data%PCC;
            return output;            
        }friend istream &operator>>(istream &input,ModInt &x){
            input>>x.data;
            x.data%=PCC;
            return input;
        }template<typename T>
        void operator+=(const T& x)     {*this=*this+x;}template<typename T>
        void operator*=(const T& x)     {*this=*this*x;}template<typename T>
        void operator-=(const T& x)     {*this=*this-x;}
        bool operator< (const ModInt &x){return data<x.data;}template<typename T>
        bool operator< (const T &x)     {return data<x;}
        bool operator> (const ModInt &x){return data>x.data;}template<typename T>
        bool operator> (const T &x)     {return data>x;}
        bool operator==(const ModInt &x){return data==x.data;}template<typename T>
        bool operator==(const T &x)     {return data==x;}
        bool operator<=(const ModInt &x){return data<=x.data;}template<typename T>
        bool operator<=(const T &x)     {return data<=x;}
        bool operator>=(const ModInt &x){return data>=x.data;}template<typename T>
        bool operator>=(const T &x)     {return data>=x;}
        bool operator!=(const ModInt &x){return data!=x.data;}template<typename T>
        bool operator!=(const T &x)     {return data!=x;}
        void operator++(){++data;data%=PCC;}
        void operator--(){--data;data=(data+PCC)%PCC;}
        template<typename T> friend bool operator< (T x,ModInt y) {return x< y.data;}
        template<typename T> friend bool operator> (T x,ModInt y) {return x> y.data;}
        template<typename T> friend bool operator==(T x,ModInt y) {return x==y.data;}
        template<typename T> friend bool operator<=(T x,ModInt y) {return x<=y.data;}
        template<typename T> friend bool operator>=(T x,ModInt y) {return x>=y.data;}
};
typedef ModInt<(int)1e9+7> mi;
typedef long long ll;
mi ans;
int n,m,p[N],step[N],cnt;
ll lcm(ll x,ll y){
    return x/__gcd(x,y)*y;
}
void cnm(int stp,ll val,int cur){
    if(stp>n){
        ans+=val;
        return ;
        ++cnt;
    }
    for(int i=cur;i<=m;++i){
        cnm(stp+1,lcm(val,step[i]),1);
    }
}
int main(){
//ios::sync_with_stdio(0);
    auto_init();
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>p[i];
    for(int i=1;i<=n;++i){
        step[i]=1;
        int cur=p[i];
        while(cur!=i){
            ++step[i];
            cur=p[cur];
        }
    }
    cnm(1,1,1);
    cout<<ans;
}