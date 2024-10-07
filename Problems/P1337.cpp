#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
#define double long double
int n,w[N];
double ansx,ansy,ans,prv,prvx,prvy;
pair<int,int> a[N];
double calc(double x,double y){
    double tempx=0,tempy=0,temp,dx,dy;
    for(int i=1;i<=n;++i){
        dx=a[i].first-x,dy=a[i].second-y;
        temp=sqrt(dx*dx+dy*dy);
        if(temp==0)continue;
        tempx+=dx/temp*w[i];
        tempy+=dy/temp*w[i];
    }
    return sqrt(tempx*tempx+tempy*tempy);
}
mt19937 rnd(time(0));
double rd(){
    return (double)rnd()/INT_MAX;
}
void Simulated_Annealing_(){
    double t=2000,curx,cury,cur;
    prv=INT_MAX;
    while(t>0.0002){
        if((double)clock()/CLOCKS_PER_SEC>0.96)
            break;
        curx=prvx+(rd()-1.0)*t;
        cury=prvy+(rd()-1.0)*t;
        cur=calc(curx,cury);
        if(cur<prv){
            prv=cur;
            prvx=curx,prvy=cury;
        }
        t*=0.9995;
    }
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i].first>>a[i].second>>w[i];
    }
    // dbg(calc(0,0),calc(1000,1000));
    ans=INT_MAX;
    while((double)clock()/CLOCKS_PER_SEC<0.96){
        // dbg("a");
        Simulated_Annealing_();
        if(prv<=ans)
            ansx=prvx,ansy=prvy,ans=prv;
    }
    // for(double i=ansx-0.8;i<=ansx+0.8;i+=0.001){
    //     for(double j=ansy-0.8;j<=ansy+0.8;j+=0.001){
    //         double t=calc(i,j);
    //         if(t<ans){
    //             ans=t;
    //             ansx=i;
    //             ansy=j;
    //         }
    //     }
    // }
    // ansx=round(ansx*1000)/1000;
    // ansy=round(ansy*1000)/1000;
    cout<<fixed<<setprecision(3)<<ansx<<" "<<fixed<<setprecision(3)<<ansy<<"\n";
}