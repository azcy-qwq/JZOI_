#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int T,type,flag=0;
string s;
int main(){
//ios::sync_with_stdio(0);
    cin>>T>>type;
    while(T--){
        cin>>s;
        flag=-1;
        for(int i=0;i<s.length();++i){
            if(s[i]!=s[0]&&flag==-1)
                flag=i;
        }if(type==0||type==2){
            if(flag==-1) cout<<s.length()-1<<" ";
            else cout<<2*s.length()-flag<<" ";
        }if(type==1||type==2){
            if(s[s.length()-1]==s[s.length()-2]) cout<<1;
            else if(s[s.length()-3]==s[s.length()-1]) cout<<2;
            else cout<<3;
        }
        cout<<"\n";
    }
}