#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define wang_shi return 0
#define See_Time cerr<<(clock()-Time)*1.0/CLOCKS_PER_SEC<<'\n'
#define See_Memory cerr<<abs(&M2-&M1)/1024.0/1024.0<<"MB\n"
using namespace std;
const int N=1e5+10;
typedef pair<int,int> PII;
bool M1;
mt19937 rng(time(0)); 
struct Treap
{
    int cnt,rt;
    struct tree
    {
        int son[2],val,rd,siz;
    }t[N];
    #define ls(x) (t[x].son[0])
    #define rs(x) (t[x].son[1])
    void pushup(int p){t[p].siz=t[ls(p)].siz+t[rs(p)].siz+1;}
    void Split(int p,int v,int &x,int &y)
    {
        if(!p) return x=y=0,void();
        if(t[x].val<=v) Split(rs(p),v,rs(x=p),y);
        else Split(ls(p),v,x,ls(y=p));
        pushup(p);
    }
    int Merge(int x,int y)
    {
        if(!x||!y) return x|y;
        if(t[x].rd<t[y].rd) return ls(y)=Merge(x,ls(y)),pushup(y),y;
        return rs(x)=Merge(rs(x),y),pushup(x),x;
    }
    int Nw(int v)
    {
        int x=++cnt;
        t[x].val=v,t[x].rd=rng(),t[x].siz=1;
        return x;
    }
    void Insert(int v)
    {
        int x=0,y=0;
        Split(x,v-1,x,y),rt=Merge(Merge(x,Nw(v)),y);
    }
    void Delete(int v)
    {
        int x=0,y=0,z=0;
        Split(rt,v,x,z); Split(x,v-1,x,y);
        rt=Merge(Merge(x,y=Merge(ls(y),rs(y))),z);
    }
    int Kth(int k)
    {
        int p=rt;
        while(1)
        {
            if(k<=t[ls(p)].siz) p=ls(p);
            else if(k==t[ls(p)].siz+1) return t[p].val;
            else k-=(t[ls(p)].siz+1),p=rs(p);
        }
    }
}T;
bool M2;
int main()
{
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int Time=clock();
    int t=1; //cin>>t;
    // while(t--) solve();
    See_Memory; See_Time;
    wang_shi;
}