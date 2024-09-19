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
const int MX=1<<25;
int a[MX];

inline unsigned int Rand(){static unsigned int sed=0;return (sed=(sed*233+19260421))&(MX-1);}

int main(){
    for(int i=0;i<MX;i++)a[Rand()]=i;
    cout<<a[2334]<<endl;
    cout<<clock();
    return 0;
}
