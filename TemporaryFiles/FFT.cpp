#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
const int N=1e7+10;
double ax[N],ay[N],bx[N],by[N];
int sum[N],x1[N],x2[N];
namespace HAI{
	#define L(x) (1 << (x))
	string add(string a,string b)//只限两个非负整数相加
	{
    	const int L=1e5;
    	string ans;
    	int na[L]={0},nb[L]={0};
    	int la=a.size(),lb=b.size();
    	for(int i=0;i<la;i++) na[la-1-i]=a[i]-'0';
    	for(int i=0;i<lb;i++) nb[lb-1-i]=b[i]-'0';
    	int lmax=la>lb?la:lb;
   	 	for(int i=0;i<lmax;i++) na[i]+=nb[i],na[i+1]+=na[i]/10,na[i]%=10;
    	if(na[lmax]) lmax++;
   		for(int i=lmax-1;i>=0;i--) ans+=na[i]+'0';
    	return ans;
	}
		string sub(string a,string b)//只限大的非负整数减小的非负整数
	{
    	const int L=1e5;
   		string ans;
    	int na[L]={0},nb[L]={0};
   		int la=a.size(),lb=b.size();
   		for(int i=0;i<la;i++) na[la-1-i]=a[i]-'0';
  		for(int i=0;i<lb;i++) nb[lb-1-i]=b[i]-'0';
    	int lmax=la>lb?la:lb;
    	for(int i=0;i<lmax;i++)
    	{
        	na[i]-=nb[i];
        	if(na[i]<0) na[i]+=10,na[i+1]--;
    	}
    	while(!na[--lmax]&&lmax>0)  ;lmax++;
    	for(int i=lmax-1;i>=0;i--) ans+=na[i]+'0';
    	return ans;
	}
	int revv(int x,int bits){
		int ret=0;
		for(int i=0;i<bits;i++)
			ret<<=1,ret|=x&1,x>>=1;
		return ret;
	}
	void fft(double *a ,double *b ,int n,bool rev){
		int bits=0;
		while(1<<bits<n)++bits;
		for(int i=1;i<=n;i++){
			int j=revv(i,bits);
			if(i<j)
				swap(a[i],a[j]),swap(b[i],b[j]);
		}
		for(int len=2;len<=n;len<<=1){
			int half=len>>1;
			double wmx=cos(2*M_PI/len);
			double wmy=sin(2*M_PI/len);
			if(rev) wmy=-wmy;
			for(int i=0;i<n;i+=len){
				double wx=1,wy=0;
				for(int j=0;j<half;j++)
				{
					double cx=a[i+j],cy=b[i+j],dx=a[i+j+half],dy=b[i+j+half],ex=dx*wx-dy*wy,ey=dx*wy+dy*wx;
					a[i+j]=cx+ex,b[i+j]=cy+ey, a[i+j+half]=cx-ex,b[i+j+half]=cy-ey;
					double wnx=wx*wmx-wy*wmy,wny=wx*wmy+wy*wmx;
					wx=wnx,wy=wny;
				}
			}
		}
		if(rev){
			for(int i=0;i<n;i++)
				a[i]/=n,b[i]/=n;
		}
	}
	int solve(int a[],int na,int b[],int nb,int ans[]){
		int len=max(na,nb),ln;
		for(ln=0;L(ln)<len;++ln);
		len=L(++ln);
		for(int i=0;i<len;++i){
			if(i>=na)ax[i]=0,ay[i]=0;
			else ax[i]=a[i],ay[i]=0;
		}
		fft(ax,ay,len,0);
		for(int i=0;i<len;++i){
			if(i>=nb)bx[i]=0,by[i]=0;
			else bx[i]=b[i],by[i]=0;
		}
		fft(bx,by,len,0);
		for(int i=0;i<len;++i){
			double cx=ax[i]*bx[i]-ay[i]*by[i],cy=ax[i]*by[i]+ay[i]*bx[i];
			ax[i]=cx,ay[i]=cy;
		}
		fft(ax,ay,len,1);
		for(int i=0;i<len;++i)
			ans[i]=(int)(ax[i]+0.5);
		return len;
	}
	string mul(string sa,string sb)
	{
		int l1,l2,l;
		int i;
		string ans;
		memset(sum,0,sizeof(sum));
		l1=sa.size();
		l2=sb.size();
		for(i=0;i<l1;i++)
			x1[i]=sa[l1-i-1]-'0';
		for(i=0;i<l2;i++)
			x2[i]=sb[l2-i-1]-'0';
		l=solve(x1,l1,x2,l2,sum);
		for(i=0;i<l||sum[i]>=10;i++){
			sum[i+1]+=sum[i]/10;
			sum[i]%=10;
		}
		l=i;
		while(sum[l]<=0&&l>0)l--;
		for(int i=l;i>=0;i--)ans+=sum[i]+'0';
		return ans;
	}
}
//const int N=1e4+10;
int n,m;
int main()
{
	ios::sync_with_stdio(0);
	string a,b;
	cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<m;++i)
        cin>>b[i];
    
	a=HAI::mul(a,b);
}