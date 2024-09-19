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
const int MX=1000000;
int sed=0;
inline int rand(){return sed=(sed*sed*73+sed*233+19260817);}
int main(){
	set<int>S;
	for(int i=0;i<MX;i++)S.insert(rand());
	int ans=0;
	for(set<int>::iterator it=S.begin();it!=S.end();it++)ans^=*it;
	printf("%d\n",ans);
	cout<<clock();
	return 0;
}

