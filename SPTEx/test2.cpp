#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<bits/stdc++.h>
const int N=1e3+28;
using namespace std;
const int MX=50000000;
int p[MX],m[MX],pc;
int main(){
	double d=clock();
	for(int i=2;i<MX;i++){
		if(!m[i])p[++pc]=m[i]=i;
		static int k;
		for(int j=1;j<=pc&&p[j]<=m[i]&&(k=p[j]*i)<MX;j++)m[k]=p[j];
	}
	int ans=0;
	for(int i=1;i<=pc;i++)ans^=p[i];
	printf("%d\n",ans);
	cout<<clock()-d;
	return 0;
}

