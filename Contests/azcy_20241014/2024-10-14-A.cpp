#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
double a,b,c;
double calc(double x){
    return a*x*x+b*x+c;
}
int main(){
ios::sync_with_stdio(0);
    cin>>a>>b>>c;
    if(a==0&&b==0) cout<<"Max: "<<fixed<<setprecision(5)<<c<<"\nMin: "<<setprecision(5)<<c;
    else if(a==0&&b!=0) cout<<"Max: +inf\nMin: -inf";
    else if(a>0) cout<<"Max: +inf\n"<<"Min: "<<fixed<<setprecision(5)<<calc(-0.5*b/a);
    else cout<<"Max: "<<fixed<<setprecision(5)<<calc(-0.5*b/a)<<"\nMin: -inf";
}