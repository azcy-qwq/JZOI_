#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<bits/stdc++.h>
#define int long long
const int N=1e3+28;
using namespace std;
int a,b;
double ans,A=LONG_LONG_MAX,nowx,temp;
double T0=120000000,delt=0.99,Tn=0.01;
int calc()
{
	int anst=a+b;
	if(abs(temp-anst)<abs(ans-anst))ans=temp;
	return anst;
}
void SA()
{
	int T=T0;
	nowx=1;
	while(T>Tn){
		temp=nowx+rand()%T-(T/2);
//		cout<<abs(temp-a-b)<<" "<<temp<<endl;
		if(abs(temp-calc())<abs(nowx-calc()))
			nowx=temp;
		T*=delt;
	}
}
signed main()
{
//	ios::sync_with_stdio(0);
	srand(time(0));
	cin>>a>>b;
	double tim=clock();
	ans=LONG_LONG_MAX;
	SA();
	cout<<(int)ans;
	return 0;
}