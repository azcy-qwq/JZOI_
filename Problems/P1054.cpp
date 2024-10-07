#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
#define ers(l,r) s.erase(l,r-l+1)
const int N = 1e3 + 28;
const int PCC = 5e8 - 7;
using namespace std;
char ch;
char stk[N];
int top, x, temp, curt, end_;
bool flag;
mt19937 rnd(time(0));
basic_string<int> s;
void solve(int l,int r){
	assert((r-l+1)%2);
	int to=s.find(-1);
	while(to!=-1){
		
	}
}
int main()
{
	//	ios::sync_with_stdio(0);
	ch = 1;
	while (ch != '\n')
	{
		ch = getchar();
		stk[++top] = ch;
		cout << ch;
		//		if(top>=1) break;
	}
	//	return 0;
	top = 0;
	x = rnd() / 2;
	s+=-998244353;
	ch = '?';
	while (ch != '\n')
	{
		// if (curt > top)
			// break;
		//		ch=getchar();
		ch = stk[++curt];
		++end_;
		if (ch == ' ')
			continue;
		//			cout<<top<<" ";
		temp = 0;
		flag = 0;
		while (ch >= '0' && ch <= '9')
		{
			flag = 1;
			temp *= 10;
			temp += ch - '0';
			ch = stk[++curt];
		}
		if (flag)
			--curt;
		if (flag)
		{
			s += temp;
		}
		else
		{

			switch (ch)
			{
			case 'a':
				s += x;
				break;
			case '^':
				s += -1;
				break;
			case '*':
				s += -2;
				break;
			case '+':
				s += -3;
				break;
			case '-':
				s += 4;
				break;
			case '(':
				s += -5;
				break;
			case ')':
				s += -6;
				break;
			default:
				break;
			}
		}
	}
	stack<int> lkh;
	for(int i=1;i<=end_;++i){
		if(s[i]==-5)
			lkh.push(i);
		else if(s[i]==-6){
			// if(lkh.empty()) throw runtime_error("kuohao_mainstring_error");
			assert(!lkh.empty());
			int lt=lkh.top();
			lkh.pop();
			if(lt<i-1)
			solve(lt,i);
		}
	}
	// for (int i = 0; i < s.length(); ++i)
	// {
	// 	cout << s[i] << " ";
	// }
	return 0;
}
