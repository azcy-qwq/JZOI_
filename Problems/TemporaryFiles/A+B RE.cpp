#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    ios::sync_with_stdio(0);
    cin>>a>>b;
    c=a+b;
    try{
        if(c>1e6) throw runtime_error("Hello World!");
        cout<<c;
    }catch(runtime_error){
        cout<<c<<endl;
    }
    
}
