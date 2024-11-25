#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
namespace azcy{
    using namespace std;
    bool debug_switch=1;
    void auto_init(){
        ios::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
    }
    void qfopen(string INPUT_FILE_NAME,string OUTPUT_FILE_NAME){
        freopen(INPUT_FILE_NAME.data(),"r",stdin);
        freopen(OUTPUT_FILE_NAME.data(),"w",stdout);
    }
    template<typename T>
    void dbgo(T x){
        cerr<<x<<" ";
    }
    template<typename First,typename... Rest>
    void dbgo(First first,Rest... rest){
        cerr<<first<<" ";
        dbgo(rest...);
    }  
    template<typename First,typename... Rest>
    void dbg(First first,Rest... rest){
        if(!debug_switch)return ;
        cerr<<first<<" ";
        dbgo(rest...);
        cerr<<"\n";
    }//made by _azcy
    template<typename T>
    void dbg(T x)
    {
        if (!debug_switch)
            return;
        cerr << x << "\n";
    }
    template<typename T>
    inline T maxm(T a,T b){
        return (a>b)?a:b;
    }template<typename T1,typename T2>
    inline T1 maxm(T1 a,T2 b){
        return (a>b)?(a):(a=b,a);
    }
    template<typename First,typename... Rest>
    inline First maxm(First first,Rest... rest){
        return maxm(first,maxm(rest...));
    }
    template<typename T>
    inline T minm(T a,T b){
        return (a<b)?a:b;
    }template<typename T1,typename T2>
    inline T1 minm(T1 a,T2 b){
        return (a<b)?a:(a=b,a);
    }
    template<typename First,typename... Rest>
    inline First minm(First first,Rest... rest){
        return minm(first,minm(rest...));
    }
}using namespace azcy;
const int N=1e4+10;
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> tr;
mt19937 rnd(time(0));
struct node{
    int val,key,size,l,r,sum;
}trp[N];
int cnt,root,lastans,ans;
int newnode(int v){
    trp[++cnt].key=rnd();
    trp[cnt].val=v;
    trp[cnt].sum=v;
    trp[cnt].size=1;
    return cnt;
}
inline void update(int id){
    trp[id].size=trp[trp[id].l].size+trp[trp[id].r].size+1;
    trp[id].sum=trp[trp[id].l].sum+trp[trp[id].r].sum+trp[id].val;
}
void split(int id,int v,int &x,int &y){
    if(!id) x=y=0;
    else{
        if(trp[id].size<=v){
            x=id;
            split(trp[id].r,v,trp[id].r,y);
        }else{
            y=id;
            split(trp[id].l,v,x,trp[id].l);
        }
        update(id);
    }
}
int merge(int a,int b){
    if(!a||!b) return a+b;
    if(trp[a].key>trp[b].key){
        trp[a].r=merge(trp[a].r,b);
        update(a);
        return a;
    }else{
        trp[b].l=merge(a,trp[b].l);
        update(b);
        return b;
    }
    // throw runtime_error("RE___");   
}void insert(int v){
    int a,b;
    split(root,v,a,b);
    root=merge(merge(a,newnode(v)),b);
}int query(int v){
    int x,y,temp;
    split(root,v-1,x,y);
    temp=trp[x].size+1;
    root=merge(x,y);
    return temp;
}int query2(int v){
    int x,y,temp;
    split(root,v-1,x,y);
    temp=trp[x].sum;
    root=merge(x,y);
    return temp;
}int getnum(int v){
    int cur=root,temp=0;
    while(cur){
        if(trp[trp[cur].l].size+1==v) break;
        if(trp[trp[cur].l].size>=v) cur=trp[cur].l;
        else v-=trp[trp[cur].l].size+1,cur=trp[cur].r;
    }
    return trp[cur].sum;
    // lastans=trp[cur].val;
}void del(int v){
    int a,b,c;
    split(root,v,a,c);
    split(a,v-1,a,b);
    b=merge(trp[b].l,trp[b].r);
    root=merge(merge(a,b),c);
}
int n,k,h[N];
int main(){
//ios::sync_with_stdio(0);
    insert(3);
    insert(4);
    insert(5);
    insert(5);
    // insert(7);
    insert(6);
    cout<<getnum(3);
    return 0;
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        cin>>h[i];
}