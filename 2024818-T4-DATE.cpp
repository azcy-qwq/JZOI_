#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
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

// C++
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
#define int long long
namespace azcy
{
    using namespace std;
    bool debug_switch = 1;
    void auto_init()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    void qfopen(string INPUT_FILE_NAME, string OUTPUT_FILE_NAME)
    {
        freopen(INPUT_FILE_NAME.data(), "r", stdin);
        freopen(OUTPUT_FILE_NAME.data(), "w", stdout);
    }
    template <typename T>
    void dbgo(T x)
    {
        cout << x << " ";
    }
    template <typename First, typename... Rest>
    void dbgo(First first, Rest... rest)
    {
        cout << first << " ";
        dbgo(rest...);
    }
    template <typename First, typename... Rest>
    void dbg(First first, Rest... rest)
    {
        if (!debug_switch)
            return;
        cout << first << " ";
        dbgo(rest...);
        cout << "\n";
    } // made by _azcy
    template <typename T>
    void dbg(T x){
    	cout<<x<<"\n";
	}

}
using namespace azcy;
const int N=1e3+10;
using namespace std;
int n,k,xmin,xmax,ymin,ymax,prv=INT_MAX,ans=LONG_LONG_MAX,prvx,prvy,x,y;
pair<int,int> a[N],s[N],prva[N],prvs[N];
int flag;
#define pii pair<int,int>
mt19937 rnd(time(0));
double rd(){
	return (double)rnd()/INT_MAX/2;
}
bool cmp1(pii d1,pii d2){
	return d1.first>d2.first;
}
bool cmp2(pii d1,pii d2){
	return d1.second>d2.second;
}
int calc(){
	int temp=0;
	for(int i=1;i<=k;++i){
		temp+=abs(s[i].first-x)+abs(s[i].second-y);
	}
	return temp;
}
int SA2(){
	sort(s+1,s+1+k,cmp1);
	x=s[k/2+1].first;
	sort(s+1,s+1+k,cmp2);
	y=s[k/2+1].second;
	return calc();
}
void SA(){
	qfopen("dating.in","dating.out");
	double t=0.9;
//	if(flag>3)t=0.1;
	prv=LONG_LONG_MAX;
//	int rod=0;
	while(t>0.08){
//		++rod;
		if((double)clock()/CLOCKS_PER_SEC>1.96) break;
		
		for(int i=1;i<=n;++i) a[i]=prva[i];
		for(int i=1;i<=k;++i) s[i]=prvs[i];
//		if(t!=0.8)
		for(int i=1;i<=k;++i){
			if(rd()<=t) swap(s[i],a[rnd()%n+1]);
		}
		int temp=SA2();
		if(prv>temp){
			prv=temp;
			prvx=x,prvy=y;
			for(int i=1;i<=n;++i) prva[i]=a[i];
			for(int i=1;i<=k;++i) prvs[i]=s[i];
		}
//		if(rod%1000000&&t<=0.02) dbg(temp);
		t*=0.9999;
	}
	for(int i=1;i<=400;++i){
		if((double)clock()/CLOCKS_PER_SEC>1.96) break;
		
		for(int i=1;i<=n;++i) a[i]=prva[i];
		for(int i=1;i<=k;++i) s[i]=prvs[i];
//		if(t!=0.8)
		for(int i=1;i<=k;++i){
			if(rd()<=t) swap(s[i],a[rnd()%n+1]);
		}
		int temp=SA2();
		if(prv>temp){
			prv=temp;
			prvx=x,prvy=y;
			for(int i=1;i<=n;++i) prva[i]=a[i];
			for(int i=1;i<=k;++i) prvs[i]=s[i];
		}
	}
}
signed main(){
//	auto_init();
	freopen("dating3.in","r",stdin);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i].first>>a[i].second;
		prva[i]=a[i];
	}
	for(int i=1;i<=k;++i){
		prvs[i]=s[i]=a[n-i+1];
	}
//	for(int i=1;i<=n;++i)
//		dbgo(a[i].first);
//		cout<<endl;
//	for(int i=1;i<=k;++i)
//		dbgo(s[i].first);
	n-=k;
	while((double)clock()/CLOCKS_PER_SEC<1.95){
		SA();
//		cout<<"b";
		ans=min(ans,prv);
//		dbg(prvx,prvy,prv);
		++flag;
//		if(prv<3)cout<<"a";
	}
	cout<<ans;
}
