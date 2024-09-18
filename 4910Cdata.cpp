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
#define pcc 100000
using namespace std;
const int N=1e3+38;
mt19937 rnd(time(0));
int y=100,k=998244353,x=50,n,m=100000;
ofstream f("4910C_1.in");
int main(){
	//ios::sync_with_stdio(0);
	n=(rnd()%x);
	m=(rnd()%(x-n));
	f<<y<<" "<<k<<"\n";
	for(int i=1;i<=y;++i){
		f<<(rnd()%pcc)<<" "<<(rnd()%pcc)<<"\n";
	}
	f<<x<<" "<<n<<" "<<m<<endl;
	for(int i=1;i<=n;++i){
		f<<pcc-(rnd()%pcc)/3<<endl;
//		f<<(rnd()%pcc)/10<<" "<<pcc-(rnd()%pcc)/10<<endl;
	}
	for(int i=1;i<=m;++i){
		f<<(rnd()%pcc)/4<<endl;
	}
}
