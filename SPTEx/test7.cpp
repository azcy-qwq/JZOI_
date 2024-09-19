#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
int P=1000000007;
const int MX=100000000;

int main(){
    ull ans=1;
    for(int i=1;i<MX;i++)ans=ans*i%P;
    printf("%llu\n",ans);
    cout<<clock();
    return 0;
}
