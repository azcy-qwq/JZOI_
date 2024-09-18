#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<bits/stdc++.h>
#define P_ 1000000007
#define int long long
const int N=1e3+28;
using namespace std;
int n,cnt;
struct Martrix{
	int a[4][4],x1,x2;
	Martrix()
	{
		memset(a,0,sizeof(a));
	}
	void init()
	{
		a[1][2]=1;
		a[2][1]=1;
		a[2][2]=1;
	}
}M,ans,O;
Martrix operator *(const Martrix &x,const Martrix &y){     //ÖØÔØÔËËã·û
	Martrix z;
	for(int k=1;k<=2;++k)
		for(int i=1;i<=2;++i)
			for(int j=1;j<=2;++j)
				z.a[i][j]=(z.a[i][j]%P_+(x.a[i][k]%P_)*(y.a[k][j]%P_)%P_)%P_;
	return z;
}
int Fib(int x){
//	cout<<"B";
	do{
//		cout<<x<<endl;
		if(x&1)M=M*O;
		O=O*O;
		x>>=1;
	}while(x>0);
	ans=ans*M;
	return ans.a[1][1];
} 
signed main()
{
//	ios::sync_with_stdio(0);
	cin>>n;
	M.init();
	O.init();
	
	ans.a[1][1]=1;
	ans.a[1][2]=1;
//	            cout<<"A";
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	cnt=Fib(n-2);
	cout<<cnt;
	return 0;
}