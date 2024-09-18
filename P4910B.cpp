#include<bits/stdc++.h>
using namespace std;
const int N=1e3+38;
#define int long long
int n,op,x,y;
map<int,int> mp;
signed main(){
	ios::sync_with_stdio(0);
//	freopen("4910B_6.in","r",stdin);
//	freopen("4910B_6.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>op>>x;
//		cout<<op<<" "<<x<<"\n";
		switch(op){
			case 1:
				cin>>y;
//				cout<<y<<"\n";
				mp[x]=y;
				break;
			case 2:
				cin>>y;
//				cout<<y<<"\n";
				mp[x]+=y;
				break;
			case 3:
				cout<<mp[x]<<"\n";
				break;
			case 4:
				if(mp.empty())break;
//				cout<<mp.empty();
//				auto temp=mp.lower_bound(x);
//				pair<int,int> pii=*temp;
				cout<<mp.lower_bound(x)->second<<"\n";
				mp.erase(mp.lower_bound(x)->second);
//				cout<<"a";
				break;
			default:
				break;
		}
	}
}
