#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,p[N];
int main(){
ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        bool flag=1;
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>p[i];
        }for(int i=1;i<=n;++i){
            if(p[i]==i+1||p[i]==i-1||p[i]==i) continue;
            flag=0;
        }if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
}