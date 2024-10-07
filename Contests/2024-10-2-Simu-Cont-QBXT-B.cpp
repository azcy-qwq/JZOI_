#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
// #define int long long
struct dir{
	int x,y;
	bool operator <(const dir a)const{
		return (a.x==x)?(a.y>y):(a.x>x);
	}
}a[N];
int n,n1,m1;
long long ans;
inline bool cmp(dir a,dir b){
	return (a.y==b.y)?(a.x<b.x):(a.y<b.y);
}
vector<int> v[N];
signed main(){
	
//	init();
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	m1=n1=1;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;++i){
		if(a[i].y!=a[i-1].y) ++m1;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i){
		if(a[i].x!=a[i-1].x)++n1;
	}
	if(m1<n1){
		swap(m1,n1);
		for(int i=1;i<=n;++i)
			swap(a[i].x,a[i].y);
		sort(a+1,a+n+1);
	}
	for(int i=1,top=0;i<=n;++i){
		if(a[i].x!=a[i-1].x)++top;
		v[top].push_back(i);
	}
	for(int i=1;i<=n1;++i){
		for(int j=i+1;j<=n1;++j){
			int cur1=0,cur2=0,cnt=0;
			while(cur1<v[i].size()&&cur2<v[j].size()){
				if(cur1>=v[i].size()||cur2>=v[j].size()) break;
				while(a[v[i][cur1]].y<a[v[j][cur2]].y){
					++cur1;
					if(cur1>=v[i].size()) break;
				}
				if(cur1>=v[i].size()) break;
				while(a[v[j][cur2]].y<a[v[i][cur1]].y){
					++cur2;
					if(cur2>=v[j].size())break;
				}
				if(cur2>=v[j].size()) break;
				if(a[v[i][cur1]].y==a[v[j][cur2]].y)
					++cnt,++cur1,++cur2;
			}
//			ans+=jc[cnt]/2;
			ans+=cnt*(cnt-1)/2;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
