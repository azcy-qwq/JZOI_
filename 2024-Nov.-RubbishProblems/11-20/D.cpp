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
    }template<typename T>
    inline T maxm(T a,T b){
        return (a>b)?a:b;
    }
    template<typename First,typename... Rest>
    inline First maxm(First first,Rest... rest){
        return maxm(first,maxm(rest...));
    }
    template<typename T>
    inline T minm(T a,T b){
        return (a<b)?a:b;
    }
    template<typename First,typename... Rest>
    inline First minm(First first,Rest... rest){
        return minm(first,minm(rest...));
    }
}using namespace azcy;
const int N=4e3+10;
template<const int PCC>
class ModInt{
    public:
        long long data;
        ModInt(){
            data=0;
        }
        ModInt operator+(const ModInt& x){
            ModInt y;
            y.data=(x.data+this->data)%PCC;
            return y;
        }ModInt operator-(const ModInt& x){
            ModInt y;
            y.data=(this->data-x.data+PCC*2)%PCC;
            return y;
        }ModInt operator*(const ModInt& x){
            ModInt y;
            y.data=(this->data*x.data)%PCC;
            return y;
        }template<typename T>
        ModInt operator+(const T& x){
            ModInt y;
            y.data=(this->data+(x%PCC))%PCC;
            return y;
        }ModInt operator+(const long long& x){
            ModInt y;
            y.data=(this->data+(x%PCC))%PCC;
            return y;
        }template<typename T>
        ModInt operator*(const T& x){
            ModInt y;
            y.data=(this->data*(x%PCC))%PCC;
            return y;
        }
        void operator=(const ModInt& x){
            data=x.data;
        }template<typename T>
        void operator=(const T& x){
            data=x%PCC;
        }template<typename T>
        ModInt operator/(const T& x){
            ModInt y=x;
            y.data/=x;
            return y;
        }friend ostream &operator<<(ostream &output,const ModInt &D ){ 
            output<<D.data%PCC;
            return output;            
        }friend istream &operator>>(istream &input,ModInt &x){
            input>>x.data;
            x.data%=PCC;
            return input;
        }template<typename T>
        void operator+=(const T& x){
            *this=*this+x;
        }template<typename T>
        void operator*=(const T& x){
            *this=*this*x;
        }
};
ModInt<998244353> c[N][N],p[N*N],a[N],f[N],d[N];
int n;
void Initialiization(){
    p[0].data=c[0][0].data=1;
    for(int i=1;i<=N-10;++i){
        c[i][0]=1;
        for(int j=1;j<=i;++j)
            // dbg(i,j),
            c[i][j]=c[i-1][j-1]+c[i-1][j];
    }for(int i=1;i<=(N-10)*(N-10);++i)
        p[i]=p[i-1]*2;
}template<typename T>
T qpow(T d,long long k){
    T temp;
    // temp=1;
    temp.data=1;
    while(k){
        if(k&1) temp=temp*d;
        d*=d;
        k>>=1;
    }return temp;
}
int main(){
// ios::sync_with_stdio(0);
    qfopen("tournament.in","tournament.out");
    auto_init();
    Initialiization();
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>d[i];
    a[1]=1;
    for(int i=2;i<=n;++i){
        for(int j=1;j<i;++j)
            a[i]=a[i]-p[(i-j)*(i-j-1)/2]*c[i][j]*a[j];
        a[i]+=p[i*(i-1)/2];
    }for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j)
            f[i]+=c[i][j]*a[j]*(f[i-j]+d[j]
            *p[(i-j)*(i-j-1)/2]*j);
    }
    for(int i=1;i<=n;++i){
        cout<<f[i]*qpow(p[i*(i-1)/2]*i,998244351)<<'\n';
    }
}