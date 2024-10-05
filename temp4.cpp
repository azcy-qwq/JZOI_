#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
using namespace std;
#define ll long long
#define ull unsigned long long
ll n,m;
bitset<N> a;
ll cnt1,cnt0;
ll temp;
char ch;
ll check() {
	ll ans=0;
	a[n+1]=0;
	for(int i=1; i<=n; ++i) {
		if(a[i]!=a[i+1])
			ans+=i;
	}
	return ans;
}
main() {
//	freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//	freopen("binary.out","w",stdout);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; ++i) {
		cin>>ch;
		a[n-i+1]=ch-'0';
		cnt1+=ch-'0';
	}
	cnt0=n-cnt1;
	for(int i=1; i<=m; ++i) {
		cin>>temp;
		if(temp>=0) {
			if(temp>=cnt0+1) {
//				temp-=cnt0+1;
//				temp%=(n+1);
				a.set();
				cnt0=0,cnt1=n;
//				for(int j=1;j<=temp;++j)
//					a[j]=1,++cnt1,--cnt0;
			} else {
				for(int j=1; j<=n; ++j) {
					if(temp==0)
						break;
					if(a[j]==0) {
//						cout<<j<<" ";
						a[j]=1;
						cnt0--;
						cnt1++;
						--temp;
					}
				}
			}
		} else {
			temp=temp*-1;
			if(temp>=cnt1+1) {
//				temp-=cnt1+1;
//				temp%=n+1;
				a.reset();
//				a.reset();
				a[n+1]=0;
				cnt1=0;
				cnt0=n;
//				for(int j=1;j<=temp;++j){
//					++cnt0,--cnt1;
//					a[j]=0;
//				}
			} else {
				for(int j=1; j<=n; ++j) {
					if(temp==0)
						break;
					if(a[j]==1) {
						++cnt0,--cnt1;
						a[j]=0;
						--temp;
					}
				}
			}
		}
//        for(int i=n;i>=1;--i)
//            cout<<a[i];
//            cout<<endl;
		cout<<check()<<'\n';
	}
	return 0;
}