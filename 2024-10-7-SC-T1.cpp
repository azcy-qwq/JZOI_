#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
namespace azcy{
    using namespace std;
    bool debug_switch=1;
    void auto_init(){
        ios::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
    }
    void qfopen(string INPUT_FILE_NAME,string OUTPUT_FILE_NAME){
        freopen(INPUT_FILE_NAME.data(),"r",stdin);
        freopen(OUTPUT_FILE_NAME.data(),"w",stdout);
    }
    template<typename T>
    void dbgo(T x){
        cerr<<x<<" ";
    }
    template<typename First,typename... Rest>
    void dbgo(First first,Rest... rest){
        cerr<<first<<" ";
        dbgo(rest...);
    }  
    template<typename First,typename... Rest>
    void dbg(First first,Rest... rest){
        if(!debug_switch)return ;
        cerr<<first<<" ";
        dbgo(rest...);
        cerr<<"\n";
    }//made by _azcy
template<typename T>
    void dbg(T x)
    {
        if (!debug_switch)
            return;
        cerr << x << "\n";
    }
}using namespace azcy;
inline int w2(int x1,int x2){return (x1<<3)+x2;}
inline int w3(int x1,int x2,int x3){return (x1<<6)+(x2<<3)+x3;}
inline int w4(int x1,int x2,int x3,int x4){return (x1<<9)+(x2<<6)+(x3<<3)+x4;}
inline int w5(int x1,int x2,int x3,int x4,int x5){return (x1<<12)+(x2<<9)+(x3<<6)+(x4<<3)+x5;};
int n[N],m[N],k,a[N],ans;
char s1[N],s2[N];
void solve1(){
    cin>>n[1]>>s1>>m[1]>>s2;
    for(int i=0;i<n[1];++i){
        bool flag=1;
        for(int j=i;j<=i+m[1]-1;++j){
            if(j>=n[1]||j-i>=m[1]){
                flag=0;break;
            }
            if(s1[j]!=s2[j-i]){
                flag=0;break;
            }
        }if(flag){
            ++ans;
        } 
    }
}
void solve2(){
    cin>>n[1]>>n[2];
    for(int i=0;i<n[1];++i)
        for(int j=0;j<n[2];++j)
            cin>>s1[w2(i,j)];
    cin>>m[1]>>m[2];
    for(int i=0;i<m[1];++i)
        for(int j=0;j<m[2];++j)
            cin>>s2[w2(i,j)];
    for(int i1=0;i1<n[1];++i1)
        for(int i2=0;i2<n[2];++i2){
            bool flag=1;
            for(int j1=i1;j1<=i1+m[1]-1;++j1)
                for(int j2=i2;j2<=i2+m[2]-1;++j2){
                    if(j1>=n[1]||j1-i1>=m[1]||j2>=n[2]||j2-i2>=m[2]){
                        flag=0;
                        break;
                    }if(s1[w2(j1,j2)]!=s2[w2(j1-i1,j2-i2)]){
                        flag=0;
                        break;
                    }
            }
            if(flag)
                ++ans;
        }
}
void solve3(){
    cin>>n[1]>>n[2]>>n[3];
        for(int i=0;i<n[1];++i)
            for(int j=0;j<n[2];++j)
                for(int k=0;k<n[3];++k)
                    cin>>s1[w3(i,j,k)];
    cin>>m[1]>>m[2]>>m[3];
    for(int i=0;i<m[1];++i)
        for(int j=0;j<m[2];++j)
            for(int k=0;k<m[3];++k)
                cin>>s2[w3(i,j,k)];
    for(int i1=0;i1<n[1];++i1)
        for(int i2=0;i2<n[2];++i2)
            for(int i3=0;i3<n[3];++i3){
                bool flag=1;
                for(int j1=i1;j1<=i1+m[1]-1;++j1){if(j1>=n[1]||j1-i1>=m[1]){flag=0;break;}
                    for(int j2=i2;j2<=i2+m[2]-1;++j2){if(j2>=n[2]||j2-i2>=m[2]){flag=0;break;}
                        for(int j3=i3;j3<=i3+m[3]-1;++j3){if(j3>=n[3]||j3-i3>=m[3]){flag=0;break;}
                            if(s1[w3(j1,j2,j3)]!=s2[w3(j1-i1,j2-i2,j3-i3)]){
                                flag=0;
                                break;
                            }
                        }
                    }
                }
                if(flag)
                    ++ans;
            }
}
void solve4(){
    cin>>n[1]>>n[2]>>n[3]>>n[4];
        for(int i=0;i<n[1];++i)
            for(int j=0;j<n[2];++j)
                for(int k=0;k<n[3];++k)
                    for(int l=0;l<n[4];++l)
                        cin>>s1[w4(i,j,k,l)];
    cin>>m[1]>>m[2]>>m[3]>>m[4];
    for(int i=0;i<m[1];++i)
        for(int j=0;j<m[2];++j)
            for(int k=0;k<m[3];++k)
                for(int l=0;l<m[4];++l)
                    cin>>s2[w4(i,j,k,l)];
    for(int i1=0;i1<n[1];++i1)
        for(int i2=0;i2<n[2];++i2)
            for(int i3=0;i3<n[3];++i3)
                for(int i4=0;i4<n[4];++i4){
                    bool flag=1;
                    for(int j1=i1;j1<=i1+m[1]-1;++j1){if(j1>=n[1]||j1-i1>=m[1]){flag=0;break;}
                        for(int j2=i2;j2<=i2+m[2]-1;++j2){if(j2>=n[2]||j2-i2>=m[2]){flag=0;break;}
                            for(int j3=i3;j3<=i3+m[3]-1;++j3){if(j3>=n[3]||j3-i3>=m[3]){flag=0;break;}
                                for(int j4=i4;j4<=i4+m[4]-1;++j4){if(j4>=n[4]||j4-i4>=m[4]){flag=0;break;}
                                    if(s1[w4(j1,j2,j3,j4)]!=s2[w4(j1-i1,j2-i2,j3-i3,j4-i4)]){
                                        flag=0;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    if(flag)
                        ++ans;
                }
}
void solve5(){
    cin>>n[1]>>n[2]>>n[3]>>n[4]>>n[5];
        for(int i=0;i<n[1];++i)
            for(int j=0;j<n[2];++j)
                for(int k=0;k<n[3];++k)
                    for(int l=0;l<n[4];++l)
                        for(int o=0;o<n[5];++o)
                            cin>>s1[w5(i,j,k,l,o)];
    cin>>m[1]>>m[2]>>m[3]>>m[4]>>m[5];
    for(int i=0;i<m[1];++i)
        for(int j=0;j<m[2];++j)
            for(int k=0;k<m[3];++k)
                for(int l=0;l<m[4];++l)
                    for(int o=0;o<m[5];++o)
                        cin>>s2[w5(i,j,k,l,o)];
    for(int i1=0;i1<n[1];++i1)
        for(int i2=0;i2<n[2];++i2)
            for(int i3=0;i3<n[3];++i3)
                for(int i4=0;i4<n[4];++i4)
                    for(int i5=0;i5<n[5];++i5){
                        bool flag=1;
                        for(int j1=i1;j1<=i1+m[1]-1;++j1){if(j1>=n[1]){flag=0;break;}
                            for(int j2=i2;j2<=i2+m[2]-1;++j2){if(j2>=n[2]){flag=0;break;}
                                for(int j3=i3;j3<=i3+m[3]-1;++j3){if(j3>=n[3]){flag=0;break;}
                                    for(int j4=i4;j4<=i4+m[4]-1;++j4){if(j4>=n[4]){flag=0;break;}
                                        for(int j5=i5;j5<=i5+m[5]-1;++j5){if(j5>=n[5]){flag=0;break;}
                                            
                                            if(s1[w5(j1,j2,j3,j4,j5)]!=s2[w5(j1-i1,j2-i2,j3-i3,j4-i4,j5-i5)]){
//                                                dbg(s1[w5(j1,j2,j3,j4,j5)],s2[w5(j1-i1,j2-i2,j3-i3,j4-i4,j5-i5)]);
                                                flag=0;
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if(flag){
//                            dbg(i1,i2,i3,i4,i5);
                            ++ans;
                        }
                            
                    }
}
int main(){
//     freopen("1.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>k;
//    cout<<k<<endl;
    switch(k){
        case 1:
            solve1();
            break;
        case 2:
            solve2();
            break;
        case 3:
            solve3();
            break;
        case 4:
            solve4();
            break;
        case 5:
            solve5();
            break;
        default:
            break;
    }
    cout<<ans;
    return 0;
}
/*
5
2 2 2 2 2
abababababababababababababababab
1 2 1 1 1 
aa
*/