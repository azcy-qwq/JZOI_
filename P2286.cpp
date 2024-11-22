#include<bits/stdc++.h>
#include<bits/extc++.h>
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
        template<typename T> friend bool operator<(T x,ModInt y)  {return x<y.data; }
        template<typename T> friend bool operator>(T x,ModInt y)  {return x>y.data; }
        template<typename T> friend bool operator==(T x,ModInt y) {return x==y.data;}
        template<typename T> friend bool operator<=(T x,ModInt y) {return x<=y.data;}
        template<typename T> friend bool operator>=(T x,ModInt y) {return x>=y.data;}
};
const int N=1e4+10;
typedef long long ll;
ll n,a,b;
using namespace __gnu_pbds;
tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> tr;
ModInt<(int)1e6> ans(0);
const ll inf=(ll)INT_MAX<<1;
int main(){
//ios::sync_with_stdio(0);
    auto_init();
    tr.insert(-inf);
    tr.insert(inf);
    cin>>n;
    bool f=0;
    for(int i=1;i<=n;++i){
        cin>>a>>b;
        if(tr.size()==2){
            f=a;
            tr.insert(b);
        }else if(a==f){
            tr.insert(b);
        }else {
            auto x=tr.lower_bound(b),y=x;--x;
            if(*x==-inf&&*y==inf){
                continue;
            }if(b-*x<=*y-b){
                ans+=b-*x;
                tr.erase(x);
            }else{
                ans+=*y-b;
                tr.erase(y);
            }
        }
    }
    cout<<ans;
}/*10
0 0//
0 10//
1 312//
1 10000000//
0 7124//
1 114//
1 1248
0 412241//
1 421//
1 51215

10
0 0
0 10
1 312
1 10000000
0 7124
1 114
1 1248
0 41222
1 421
1 51215
*/