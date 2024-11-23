#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n;
string s;
void not_(){
    cout<<"No\n";
    exit(0);
}
int main(){
//ios::sync_with_stdio(0);
    cin>>n>>s;
    if(s.length()%2==0) not_();
    for(int i=0;i<s.length()/2;++i){
        if(s[i]!='1') not_();
    }if(s[s.length()/2]!='/') not_();
    for(int i=s.length()/2+1;i<s.length();++i){
        if(s[i]!='2') not_();
    }cout<<"Yes\n";
}