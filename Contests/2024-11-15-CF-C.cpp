#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int t,n;
int main(){
ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        cin>>n;
        if(n%2==0){
            for(int i=1,opt=1;i<=n;i+=2,++opt)
                cout<<opt<<" "<<opt<<" ";
        }else{
            if(n<27){
                cout<<"-1";
                // continue;
            }else{
                cout<<"1 3 3 4 4 5 5 6 6 1 7 7 8 8 9 9 10 10 11 11 12 12 2 13 13 1 2 ";
                for(int opt=14,i=28;i<=n;i+=2,++opt){
                    cout<<opt<<" "<<opt<<" ";
                }
            }
        }cout<<"\n";
    }
}