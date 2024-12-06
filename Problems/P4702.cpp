#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
typedef long long ll;
ll n,x;
bool ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x;
        ans^=(x&1);
    }if(ans) cout<<"Alice";
    else cout<<"Bob";
}