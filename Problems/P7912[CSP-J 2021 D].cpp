#include<bits/stdc++.h>
using namespace std;//欲买桂花同载酒 终不似 少年游
const int N=3e5+10;
string s;
basic_string<int> s2;
char ch;
int n,top,maxm;
vector<int> ans[N];
int main(){
    // freopen("fruit3.in","r",stdin);
    // freopen("fruit3.out","w",stdout);
ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    s+='#';
    s2+=0;
    for(int i=1;i<=n;++i){
        cin>>ch;s+=ch;s2+=i;
    }
    while(s.length()>1){
        int flag=s.length();
        maxm=INT_MAX;
        for(int i=s.length()-1;i>=1;--i){
            if(s[i]!=s[i-1]){
                maxm=min(maxm,flag-i);
                flag=i;
            }
        }for(int i=s.length()-1;i>=1;--i){
            if(s[i]!=s[i-1]){
                for(int j=1;j<=maxm;++j){
                    ans[top+j].push_back(s2[i+j-1]);
                }s.erase(i,maxm);s2.erase(i,maxm);
            }
        }top+=maxm;
        // cout<<'\n';
    }for(int i=1;i<=top;++i){
        for(int j=ans[i].size()-1;j>=0;--j){
            cout<<ans[i][j]<<' ';
        }cout<<'\n';
    }
}