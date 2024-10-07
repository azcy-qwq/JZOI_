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
#include <cwchar>
#include <cwctype>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cuchar>
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
#include <codecvt>
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
#if __cplusplus >= 201402L
#include <shared_mutex>
#endif
#if __cplusplus >= 201703L
#include <any>
#include <charconv>
#include <filesystem>
#include <optional>
#include <memory_resource>
#include <string_view>
#include <variant>
#endif
#if __cplusplus > 201703L
#include <bit>
#include <version>
#endif
#define int long long
const int maxx=1e8;
using namespace std;
const int N=1e6+38;
vector<long long> v;
long long temp;
mt19937 rnd(time(0));
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ofstream f("4910B_6.in");
	f.tie(0);
	int n=(int)8e5,op;
	f<<n<<"\n";
	for(int i=1;i<=n;++i){
		op=rnd()%4+1;
		temp=rnd()%maxx+1;
		if(op>=3){
			if(rnd()>=INT_MAX/2&&v.size()>1)
				temp=v[rnd()%(v.size()/2)];
		}
		f<<op<<" "<<temp;
		if(op<=2){
			v.push_back(temp);
			f<<" "<<rnd();
		}
		f<<"\n";
	}
	return 0;
}
