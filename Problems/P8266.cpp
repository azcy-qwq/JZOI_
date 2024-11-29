#include<bits/stdc++.h>
using namespace std;
const int N=1e6+38;
int n,cnt,a[N],ans;
char ch[N];
int main(){
	//ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>ch[i];
	for(int i=1;i<=n;i+=2){
		if(ch[i]=='H'&&ch[i+1]=='G') a[++cnt]=0;
		if(ch[i]=='G'&&ch[i+1]=='H') a[++cnt]=1;
	}for(int i=2;i<=cnt;++i){
		if(a[i]!=a[i-1]) ++ans;
	}cout<<((cnt==0)?(0):(ans+a[cnt]))<<"\n";
}
