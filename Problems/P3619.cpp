#include<bits/stdc++.h>
using namespace std;
const int N=1e6+38;
#define int long long
typedef pair<int,int> pii;
pii a[N];
int n,T,t;
bool cmp(pii x,pii y){
	return (x.second>0&&y.second>0)?(x.first<y.first):(x.first+x.second>y.first+y.second);
}
bool cmp2(pii x,pii y){
	return (x.first+x.second>y.first+y.second);
}
signed main(){
	//ios::sync_with_stdio(0);
	cin>>T;
	for(int oo=1;oo<=T;++oo){
		bool flag=1;
		cin>>n>>t;
		for(int i=1;i<=n;++i)
			cin>>a[i].first>>a[i].second;//t b
		if(n>2&&T!=2)
			sort(a+1,a+n+1,cmp2);
		else 
			sort(a+1,a+n+1,cmp);
//		for(int i=1;i<=n;++i)
//			clog<<a[i].first<<" "<<a[i].second<<"\n";
		for(int i=1;i<=n;++i){
			if(t<=a[i].first){
				flag=0;
				break;
			}t+=a[i].second;
		}if(flag==0||t<=0) cout<<"-1s\n";
		else cout<<"+1s\n";
	}
}
