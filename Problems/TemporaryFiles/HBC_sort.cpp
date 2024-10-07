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

namespace IN
{
#define MAX_INPUT 25000003
#define getc() (p1 == p2 && (p2 = (p1 = buf) + inbuf->sgetn(buf, MAX_INPUT), p1 == p2) ? EOF : *p1++)
	char buf[MAX_INPUT], *p1, *p2;
	template <typename T>
	inline bool redi(T &x)
	{
		static std::streambuf *inbuf = cin.rdbuf();
		x = 0;
		register int f = 0, flag = false;
		register char ch = getc();
		while (!std::isdigit(ch))
		{
			if (ch == '-')
				f = 1;
			ch = getc();
		}
		if (std::isdigit(ch))
			x = x * 10 + ch - '0', ch = getc(), flag = true;
		while (std::isdigit(ch))
		{
			x = x * 10 + ch - 48;
			ch = getc();
		}
		x = f ? -x : x;
		return flag;
	}
	template <typename T, typename... Args>
	inline bool redi(T &a, Args &...args)
	{
		return redi(a) && redi(args...);
	}
#undef getc
}

namespace OUT
{
	template <typename T>
	inline void put(T x)
	{
		static std::streambuf *outbuf = cout.rdbuf();
		static char stack[21];
		static int top = 0;
		if (x < 0)
		{
			outbuf->sputc('-');
			x = -x;
		}
		if (!x)
		{
			outbuf->sputc('0');
			outbuf->sputc('\n');
			return;
		}
		while (x)
		{
			stack[++top] = x % 10 + '0';
			x /= 10;
		}
		while (top)
		{
			outbuf->sputc(stack[top]);
			--top;
		}
		outbuf->sputc('\n');
	}
	inline void putc(const char ch)
	{
		static std::streambuf *outbuf = cout.rdbuf();
		outbuf->sputc(ch);
	}
	template <typename T>
	inline void put(const char ch, T x)
	{
		static std::streambuf *outbuf = cout.rdbuf();
		static char stack[21];
		static int top = 0;
		if (x < 0)
		{
			outbuf->sputc('-');
			x = -x;
		}
		if (!x)
		{
			outbuf->sputc('0');
			outbuf->sputc(ch);
			return;
		}
		while (x)
		{
			stack[++top] = x % 10 + '0';
			x /= 10;
		}
		while (top)
		{
			outbuf->sputc(stack[top]);
			--top;
		}
		outbuf->sputc(ch);
	}
	template <typename T, typename... Args>
	inline void put(T a, Args... args)
	{
		put(a);
		put(args...);
	}
	template <typename T, typename... Args>
	inline void put(const char ch, T a, Args... args)
	{
		put(ch, a);
		put(ch, args...);
	}
}
using IN::redi;
using OUT::put;
using OUT::putc;
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
	void dbg(T x)
	{
		if (!debug_switch)
			return;
		cout << x << "\n";
	}
}
using namespace azcy;
const int N = 1e3 + 38;
int n, a[N], b[N], u, v, cnt;
bool check()
{
	for (int i = 2; i <= n; ++i)
	{
		if (a[i] < a[i - 1])
			return 1;
	}
	return 0;
}
mt19937 rnd(time(0));
int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> b[i];
		a[i] = b[i];
	}
	sort(b + 1, b + n + 1);
	// for (int j = 1; j <= n; ++j)
	// 	a[j] = rnd() / 16;
	// a[j]=b[j];
	while (check() && (double)clock() / CLOCKS_PER_SEC < 0.98)
	{
		// dbg(cnt,u,v);
		u = rnd() % n + 1;
		v = rnd() % n + 1;
		if (u > v)
			swap(u, v);
		assert(u <= v);
		if (a[u] > a[v])
			swap(a[u], a[v]);
		++cnt;
	}
	for(int i=1;i<=n;++i)
		cout<<b[i]<<" ";
	// cout<<cnt<<"\n";
}
