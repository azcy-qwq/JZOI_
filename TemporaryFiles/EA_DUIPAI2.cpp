#include<bits/stdc++.h>
using namespace std;
const int N=1e3+38;
int maxn,t,cnt,a[202][120];
string name,equip;
long long qpow(long long x, long long y, long long pcc)
{	
    long long t = x, ans = 1;
    while (y)
    {
        if (y & 1)
            ans *= t, ans %= pcc;
        t *= t;
        t %= pcc;
        y >>= 1;
    }
    return ans;
}
void init(){
	for(int i=1;i<=n;++i){
		for(char j='a';j<='z';++j){
			
		}
	}
}
unsigned int hash1;
double calc(){
	
	unsigned int hash2=0;
//	cout<<equip.length()<<endl;
    for(int i=0;i<maxn;++i){
//    	cout<<i<<" ";
        hash2+=qpow(equip[i],equip[i]+i*i*5,998244353);
        hash2+=qpow(equip[i]*equip[i],equip[i]*i+i*i*3,1145141);
    }
//	cout<<equip.data()<<" "<<hash2<<endl;
    double kkk=(double)(22.0-log(1+abs((int)hash2-(int)hash1)))/21*1000;
    kkk+=100;
    return kkk;
}
mt19937 rnd(time(0));
int main(){
	//ios::sync_with_stdio(0);
	cin>>name>>maxn;
	for(int i=0;i<name.length();++i)
        hash1+=qpow(name[i],name[i]+i*i*3,(int)(1e9+7));
	while(1){
		++cnt;
		string s;
		for(int i=0;i<maxn;++i){
			equip[i]='a'+(rnd()%22);
		}
//		cout<<equip.data()<<" "<<calc(s)<<endl;
		if(calc()>900){
			cout<<equip.data()<<" "<<calc()<<" "<<cnt<<endl;
            if(calc()>960)
			system("pause");
		}
	}
}
