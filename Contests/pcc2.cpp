#include<bits/stdc++.h>
using namespace std;
int Gcd(int x,int y){
    return __gcd(x,y);
}
template<typename First,typename... Rest>
int Gcd(First first,Rest... rest){
    return __gcd(first,Gcd(rest...));
}
int main(){
//ios::sync_with_stdio(0);
    int n,a=4,b=6,c=8,d=15;
    // cin>>n;
    // if(n<3) cout<<"-1 -1 -1";
    // else cout<<"1 2 3";
    cout<<Gcd(a*b,a*c,b*c)*Gcd(a*a,b*b,c*c)/Gcd(a*b*b,a*c*c,b*a*a,b*c*c,c*a*a,c*b*b)/Gcd(a,b,c);
}