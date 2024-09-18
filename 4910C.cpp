#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
const int N=2e6+10;
using namespace std;
struct Node_dish{
	long long flavour;
	long long prize;
//	Node_dish(int _fl,int _pr) : flavour(_fl), prize(_pr) {}
}lis;
bool cmpl(Node_dish x,Node_dish y)
{
	if(x.prize!=y.prize)
		return x.prize<y.prize;
	else
		return x.flavour<y.flavour;
}
bool cmpg(Node_dish x,Node_dish y)
{
	if(x.flavour!=y.flavour)
		return x.flavour>y.flavour;
	else
		return x.prize>y.prize;
}
bool cmp(long long x,long long y)
{
	return x > y;
}
//struct cmpa{
//	bool operator()(Node_dish f1,Node_dish f2)
//	{
//		return f1.prize>f2.prize;
//	}
//};
vector<Node_dish> dish;
//priority_queue<Node_dish,vector<Node_dish>,cmpa> hp;

long long n,m,p,q,ans,flavour[N],prize[N];
bool check(long long date)
{long long k,cnt;
	sort(dish.begin(),dish.begin()+m,cmpg);
	k=0;
	for(int i=1;i<=p&&k<=m;i++)
	{
		for(int j=1;j<=date&&k<m;j++)
		{
			if(dish[k].flavour>=flavour[i]&&k<=m)
				k++;
			else
				break;
		}
	}
	sort(dish.begin()+k,dish.begin()+m,cmpl);
	for(int i=1;i<=q&&k<=m;i++)
	{
		for(int j=1;j<=date&&k<=m;j++)
		{
			if(dish[k].prize<=prize[i]&&k<=m)
			{
				k++;
			}
			else
				break;
		}
	}
	return (n-p-q)*date>=(m-k);
}
int limit_;
int main()
{
//	freopen("4910C_10.in","r",stdin);
//	freopen("4910C_10.out","w",stdout);
	long long l_=0,r_,mid;
	cout<<rand()%10;
	return 0;
	ios::sync_with_stdio(0);
	cin>>m>>limit_;
	int ls0,ls1;
	r_=m+1;
	for(int i=1;i<=m;i++)
	{
		cin>>lis.flavour>>lis.prize;
		dish.push_back(lis);
	}
	cin>>n>>p>>q;
	for(int i=1;i<=p;i++)
		cin>>flavour[i];
	for(int i=1;i<=q;i++)
		cin>>prize[i];
	//Input Ends Here__________________________________________________Separate Line_________________________________________ 
//	vector<Node_dish> dishc(dish);
	sort(flavour+1,flavour+p+1,cmp);
	sort(dish.begin(),dish.end(),cmpg);
	sort(prize+1,prize+q+1);
	while(l_<r_)
	{
		mid=l_+(r_-l_)/2;
		if(check(mid))
			r_=mid;
		else
			l_=mid+1;
	}
//	cout<<r_<<endl;
	//Check if it can be completely eaten	/refer to answers
		if(r_>=m+1)
		{
			cout<<"-1"<<endl;
			return 0;
		}
	if(r_<=limit_)
	cout<<r_<<endl;
//	else cout<<"-1";
	return 0;
}
/*
vector<Node_dish> st(dish);
	vector<Node_dish>::iterator st1=st.begin();
	int k,cnt;
	for(int i=1;i<=p;i++)
	{
		k=0;
		cnt=0;
		while(cnt<date&&k<st.size())
		{
			cout<<cnt<<endl;
			if(st[k].flavour==LONG_LONG_MAX-1)
			{
				continue;
			}
			if(flavour[i]<=st[k].flavour)
			{
				cnt++;
				st[k].flavour=LONG_LONG_MAX-1;
				st[k].prize=LONG_LONG_MAX-1;
			}
			k++;
		}
//		for(int j=0;j<date&&k<st.size();j)
//		{
//			if(flavour[i]<=st[k].flavour&&k<st.size())
//			{
//				st.erase(st1 + k);
//				j++;
//			}
//			k++;
//		 }
	}
	make_heap(st.begin(),st.end(),cmpl);
	k=0;
	long long aa;
	for(aa=0;st[aa].prize<=st.size();aa++)
	{
	}
	for(int i=1;i<=q;i++)
	{
		cnt=0;
		while(cnt<date&&k<aa)
		{
			if(st[k].prize==LONG_LONG_MAX-1)
				continue;
			if(prize[i]>=st[k].prize)
			{
				cnt++;
				st[k].prize=LONG_LONG_MAX-1;
			}
		}
//		for(int j=0;j<date&&k<st.size();j)
//		{
//			if(prize[i]>=st[k].prize&&k<st.size())
//			{
//				st.erase(st1+k);
//				j++;
//			}
//			k++;
//		}
	}
	make_heap(st.begin(),st.end(),cmpl);
	for(cnt=0;st[cnt].prize!=LONG_LONG_MAX;cnt++);
	if(date*(n-p-q)>=cnt)
		return 1;
	else
		return 0;
*/