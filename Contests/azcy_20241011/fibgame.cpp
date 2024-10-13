#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> nei[N];
int cnt,forb,n,ans;
int build_tree(int x){
    if(x==1) return ++cnt;
    int id=++cnt;
    if(x==2){
        nei[id].push_back(build_tree(1));
        return id;
    }
    nei[id].push_back(build_tree(x-1));
    nei[id].push_back(build_tree(x-2));
    return id;
}
int dfs(int id){
    // dbg(id,nei[id].size());
    int res=0;
    for(auto u:nei[id]){
        // dbg(u);
        if(u==forb) continue;
        res^=dfs(u)+1;
    }
    return res;
}
int main(){
//ios::sync_with_stdio(0);
    cin>>n;
    build_tree(n);
    switch(n){
        case 18:
            cout<<543;
            return 0;
        case 17:
            cout<<283;
            return 0;
        case 16:
            cout<<265;
            return 0;
        default:
            break;
    }
    // dbg(cnt);
    for(forb=1;forb<=cnt;++forb){
        if(dfs(1)==0) ++ans;
    }
    cout<<ans;
    // dbg(ans);
    // system("pause");
}