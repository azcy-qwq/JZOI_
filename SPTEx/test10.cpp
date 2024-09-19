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
int main()
{
	ios::sync_with_stdio(0);
	for(int i=1;i<=10;i++)
	{
		ofstream f1("temp.oupt");
		for(int j=1;j<=1000000;j++)
			f1<<(char)j<<" "<<rand();
		f1.close();
	 } 
//	ofstream f2("10.txt");
	cout<<clock();
	return 0;
}

