#include<bits/stdc++.h>
using namespace std;
int main(){
	int a=1000000000,b=1;
	double c=clock();
	while(a)b<<=1,a--;
	printf("%d\n",b);
	cout<<clock()-c;
	return 0;
}
