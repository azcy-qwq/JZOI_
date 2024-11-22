#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#define ll long long
using namespace std;
const int N=1e5+10,mod=1e9;
typedef pair<int,int> PII;
int ans,n;
set<ll> s;
void solve(int b)
{
	auto l=--s.lower_bound(b),r=s.lower_bound(b);
//	cout<<"-------"<<*l<<" "<<*r<<endl;
	if(*l!=1e18&&b-*l<=*r-b)
	{
        cout<<b-*l<<' ';
		ans+=b-*l;
		ans%=mod;
		s.erase(l); 
	}
	else 
	{
        cout<<*r-b<<' ';
		ans+=*r-b;
		ans%=mod;
		s.erase(r);
	}
 } 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	s.insert(1e18);s.insert(-1e18);
	int f=0;	
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		if(s.size()==2)
		{
			f=a;
			s.insert(b);
            continue;
		}
		else if(a==f){
            s.insert(b);
            continue;
        } 
		else solve(b);
        cout<<ans<<'\n';
	}
	cout<<ans<<endl;
	return 0;
}
