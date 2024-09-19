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
const int MX=20000000;
int *it[MX];
int main(){
	for(int i=0;i<MX;i++)it[i]=new int;
	for(int i=0;i<MX;i++)*it[i]=i;
	int ans=0;
	for(int i=0;i<MX;i++)ans^=*it[i];
	printf("%d\n",ans);
	cout<<clock();
	return 0;
}

