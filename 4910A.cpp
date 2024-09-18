#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
struct Node{
    int father;
    int self,sum;
    double data;
}tree[N];
int n,m,a,b,to[N];
char op;
double x[N];
int cnt;
double k;
void init()
{
    for(int i=1;i<=n;i++)
    {
        tree[i].father=i;
        tree[i].self=i;
        tree[i].data=x[i];
        to[i]=i;
        tree[i].sum=1;
    }
}
int findfa(int id){
	while(tree[id].father!=id)
		id=tree[id].father;
	return id;
}
void bond(int x,int y)
{
    int f1=tree[x].father,f2=tree[y].father;
    while(tree[f1].father!=f1)
    {
        f1=tree[f1].father;
        tree[x].father=f1;
    }
    while(tree[f2].father!=f2)
    {
        f2=tree[f2].father;
        tree[y].father=f2;
    }
    if(f1==f2)return;
    tree[f2].data+=tree[f1].data;
    tree[f2].sum+=tree[f1].sum;
    tree[f1].father=f2;
}
bool find(int x,int y)
{
    int f1=tree[x].father,f2=tree[y].father;
    while(tree[f1].father!=f1)
    {
        f1=tree[f1].father;
        tree[x].father=f1;
    }
    while(tree[f2].father!=f2)
    {
        f2=tree[f2].father;
        tree[y].father=f2;
    }
    return f1==f2;
}
void display(int i1,int i2){
	cout<<i1<<" "<<i2<<" "<<(findfa(to[i1])==findfa(to[i2]))<<endl;
}
int main()
{
	ios::sync_with_stdio(0);
	freopen("4910A_8.in","r",stdin);
	freopen("4910A_8.out","w",stdout);
    cin>>n>>m;
    cnt=n+1;
    for(int i=1;i<=n;++i)
    	cin>>x[i];
    init();
    for(int i=1;i<=m;i++)
    {
        cin>>op>>a>>b;
        if(op=='1')
        {
        	cin>>k;
        	int f1=findfa(to[a]),f2=findfa(to[b]);
        	if(f1==f2){
        		cout<<"Illegal\n";
        		continue;
			}
        	double delta=tree[f1].data/tree[f1].sum-tree[f2].data/tree[f2].sum;
        	
            if(delta==0){
            	cout<<"same\n";
			}else if(delta<0){
				cout<<"lst\n";
				if(delta<-1*k)//a->b
				{
					tree[++cnt].data=-1*x[a];
					tree[cnt].self=cnt;
					tree[cnt].father=cnt;
					tree[cnt].sum=-1;
					bond(cnt,a);
					to[a]=++cnt;
					tree[cnt].data=x[a];
					tree[cnt].self=cnt;
					tree[cnt].father=cnt;
					tree[cnt].sum=1;
					bond(cnt,b);
				}
			}else if(delta>0){
				cout<<"prv\n";
				if(delta>k){
					tree[++cnt].data=-1*x[b];
					tree[cnt].self=cnt;
					tree[cnt].father=cnt;
					tree[cnt].sum=-1;
					bond(cnt,b);
					to[b]=++cnt;
					tree[cnt].data=x[b];
					tree[cnt].self=cnt;
					tree[cnt].father=cnt;
					tree[cnt].sum=1;
					bond(cnt,a);
				}
			}
			
        }
        if(op=='2')
            bond(a,b);
        
    }
}