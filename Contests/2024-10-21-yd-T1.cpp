#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,a[N],b[N],ans;
unordered_map<int,bool> m;
int main(){
    // freopen("arrow5.in","r",stdin);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }for(int i=1;i<n;++i){
        cin>>b[i];
    }
    b[0]=0,b[n]=1;
    for(int i=1;i<=n;++i){
        if(b[i-1]==0&&b[i]==1){
            if(m[a[i]]==0)
                ++ans,m[a[i]]=1;
            
        }
    }
    cout<<ans;
}