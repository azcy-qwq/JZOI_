#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
const int N=1e4+10;
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
        cout<<x<<" ";
    }
    template<typename First,typename... Rest>
    void dbgo(First first,Rest... rest){
        cout<<first<<" ";
        dbgo(rest...);
    }  
    template<typename First,typename... Rest>
    void dbg(First first,Rest... rest){
        if(!debug_switch)return ;
        cout<<first<<" ";
        dbgo(rest...);
        cout<<"\n";
    }//made by _azcy
	template<typename T>
    void dbg(T x)
    {
        if (!debug_switch)
            return;
        cout << x << "\n";
    }
}using namespace azcy;
struct node{
    vector<pair<int,int> > nei;
    // vector<int> w;
    int len=INT_MAX,maxw;
    void srt(){
        sort(nei.front(),nei.back());
    }
}a[N];
int n,m,k,L,u,v,w;
map<pair<pair<int,int>,int>,bool> forb;
bitset<N> vis;
void spfa(){
    queue<int> q;
    q.push(1);
    a[1].len=0;
    int cur,v;
    while(!q.empty()){
        cur=q.top();
        q.pop();
        for(int i=0;i<a[cur].nei.size();++i){
            v=a[i].nei[i].second;
            if(a[i].len+a[i].nei[i].first<a[v].len){
                a[v].len=a[i].len+a[i].nei[i].first;
                if(vis[v]) continue;
                vis[v]=1;
                q.push(v);
            }
        }
    }
}
// void dfs(int from,int id,int val){
//     if(id==n)

// }
void bfs(){
    queue<int> q;
    q.push(1);
    while(q.size()){
        
    }
}
signed main(){
//	ios::sync_with_stdio(0);
    cin>>n>>m>>k>>L;
    for(int i=1;i<=m;++i){
        cin>>u>>v>>w;
        a[u].nei.push_back({w,v});
        a[v].nei.push_back({w,u});
    }
    for(int i=1;i<=k;++i){
        cin>>u>>v>>w;
        forb[{{u,v},w}]=1;
        forb[{{w,v},u}]=1;
    }
    spfa();
    L+=a[n].len;
    // for(int i=1;i<=n;++i)
    //     a[i].srt();
    bfs();
}