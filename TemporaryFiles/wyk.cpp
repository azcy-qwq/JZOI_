#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct node{
    int num,use;
}cnt[500005];
int ch[500005][27],id;
inline void insert(string s)
{
    int p=0,len=s.length();
    for(int i=0;i<len;i++)
    {
        int j=s[i]-'a';
        if(!ch[p][j]) ch[p][j]=++id;
        p=ch[p][j];
    }
    // cnt[p].num++;
}
inline int query(string s)
{
    int p=0,len=s.size();
    for(int i=0;i<len;i++)
    {
        int j=s[i]-'a';
        if(!ch[p][j]) return 0;
        p=ch[p][j];
    }
//    int flag=0;
    if(cnt[p].use==0) 
    {
        cnt[p].use++;
        return 2;
    }
    else return 1;
}
signed main()
{
//    freopen(".in","r",stdin);
//    freopen(".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string x;
        cin>>x;
        insert(x);
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        string x;
        cin>>x;
        int flag=query(x);
        if(flag==0) cout<<"WRONG"<<'\n';
        else if(flag==2) cout<<"OK"<<'\n';
        else if(flag==1)cout<<"REPEAT"<<'\n'; 
    }
     return 0;
}/*
1 ab
1 a


*/