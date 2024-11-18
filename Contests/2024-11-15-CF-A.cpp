#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,h[N],t,ans;
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>h[i];
        ans=INT_MAX;
        for(int i=1;i<=n;++i)
        {
            int cnt=0;
            for(int j=1;j<=n;++j){
                if(i==j) continue;
                if(i>j&&h[j]>h[i]) ++cnt;
                if(i<j&&h[j]<h[i]) 
                    ++cnt;
                // ++cnt;
            }
            ans=min(cnt,ans);
        }cout<<ans<<"\n";
    }
}