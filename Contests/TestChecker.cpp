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
using namespace std;
const int N=1e3+38;
int n,rt;
string s,s2;
long long tim,tim2,dt,TL;
int main(){
	//ios::sync_with_stdio(0);
	cout<<"Input the name of the problem.\n";
	cin>>s;
	cout<<"Input the Time Limit of the problem\n";
	cin>>TL;
	cout<<"Input the num of test data.\n";
	cin>>n;
	
	while(1){
		s2="g++ "+s+".cpp -O2 -Wl,--stack=33554432";
		system(s2.c_str());
		for(int i=1;i<=n;++i){
			s2=s+".exe < "+s+to_string(i)+".in > "+s+".out";
			tim=clock();
			rt=system(s2.c_str());
			if(rt!=0){
				system("color 0D");
				cout<<"Runtime Error on test #"<<i<<" :Returned with value "<<rt<<" .\n";
				system("color 07");
				system("pause");
			}
			tim2=clock();
			dt=tim2-tim;
			s2="fc "+s+".out "+s+to_string(i)+".ans";
			if(system(s2.c_str())){
				system("color 04");
				cout<<"Wrong Answer on test #"<<i<<"\n";
				system("color 07");
				system("pause");
			}else if(dt>TL){
				system("color 03");
				cout<<"Time Limit Exceeded on test #"<<i<<",\n   Expected Time Limit:"<<TL<<" ms,\n   But used "<<dt<<"ms.\n";
				system("color 07");
				system("pause");
			}else{
				system("color 02");
				cout<<"Accepted.\n   Test #"<<i<<": "<<dt<<"ms.\n";
				system("color 07");
			}
		}
		
		system("pause");
	}
}
