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

int main(){
	double d=clock();
//	d=0;
    double ans=0.61234567898765,t=1,s=0;
    for(int i=1;i<MX;i++)s+=(t*=ans);
    printf("%f\n",s);
    cout<<clock()-d;
    return 0;
}

