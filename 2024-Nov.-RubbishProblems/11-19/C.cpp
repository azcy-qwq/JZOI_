#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline T maxm(T a,T b){
    return (a>b)?a:b;
}
template<typename First,typename... Rest>
inline First maxm(First first,Rest... rest){
    return maxm(first,maxm(rest...));
}
template<typename T>
inline T minm(T a,T b){
    return (a<b)?a:b;
}
template<typename First,typename... Rest>
inline First minm(First first,Rest... rest){
    return minm(first,minm(rest...));
}
const int N=2e6+10;
const int PCC=10000;
#define int long long
class mult{
    protected:
        int data[2];
    public:
        int top=0;
        inline void update(){
            for(int i=0;i<=this->top;++i)
                this->data[i]+=PCC*PCC,this->data[i]%=PCC;
            while(this->data[this->top]==0)
                this->top--;
        }
        inline void setd(int x){data[0]=x;top=0;}
        inline void setx(int x){data[1]=x;data[0]=0;top=1;}
        mult operator*(const mult x){// Slow Luotian1 Transform
            mult temp;
            for(int i=0;i<=this->top+x.top+1;++i){
                temp.data[i]=0;
            }temp.top=x.top+this->top;
            for(int i=0;i<=this->top;++i){
                for(int j=0;j<=x.top;++j){
                    temp.data[i+j]+=this->data[i]*x.data[j];
                }
            }
            temp.update();
            return temp;
        }mult operator+(const mult x){
            mult temp;
            temp.top=maxm(this->top,x.top);
            int minn=minm(this->top,x.top);
            for(int i=0;i<=minn;++i)
                temp.data[i]=x.data[i]+this->data[i];
            if(this->top>x.top){
                for(int i=minn+1;i<=temp.top;++i)
                    temp.data[i]=this->data[i];
            }else{
                for(int i=minn+1;i<=temp.top;++i)
                    temp.data[i]=x.data[i];
            }
            temp.update();
            return temp;
        }mult operator+=(const mult x){
            this->top=maxm(this->top,x.top);
            for(int i=0;i<=this->top;++i)
                this->data[i]=x.data[i]+this->data[i];
            this->update();
            return *this;
        }mult operator*=(const mult x){
            // mult temp=*this;
            *this=(*this)*x;
            this->update();
            return *this;
        }friend ostream &operator<<(ostream &output,const mult &x){
            for(int i=0;i<=x.top;++i)
                output<<(x.data[i]+PCC*PCC)%PCC<<'\n';
            return output;
        }mult operator-(const mult x){
            mult y=x;
            for(int i=0;i<=x.top;++i)
                y.data[i]*=-1;
            return *this+y;
        }
        
}tx,ty,tz;
int otop,ntop,stktop;
mult stk_num[N],stk[N];
char stk_op[N],op[N];
string s;
signed main(){
    // freopen("P1981_2.in","r",stdin);
	// freopen("simplify.out","w",stdout);
ios::sync_with_stdio(0);
    cin>>s;
    int x=0;
    for(int i=0;i<s.length();++i){
        if(isdigit(s[i])){
            x*=10;
            x+=s[i]-'0';
            // x%=PCC;
        }else {
            if(x){
                x%=PCC;
                stk_num[++ntop].setd(x);
                x=0;
            }if(s[i]=='x'){
                stk_num[++ntop].setx(1);
            }else if(s[i]=='('){
                stk_op[++otop]='(';
            }else if(s[i]==')'){
                while(stk_op[otop]!='('&&otop>0){//???????
                    op[++ntop]=stk_op[otop--];
                }--otop;
            }else if(s[i]=='+'||s[i]=='-'){
                while(otop>0&&(stk_op[otop]=='+'||stk_op[otop]=='-'||stk_op[otop]=='*')){
                    op[++ntop]=stk_op[otop--];
                }stk_op[++otop]=s[i];
            }else{
                while(stk_op[otop]=='*'&&otop>0){
                    op[++ntop]=stk_op[otop--];
                }
                stk_op[++otop] =s[i];
            }
        }
    }
    if(x)
        stk_num[++ntop].setd(x);
    while(otop){
        op[++ntop]=stk_op[otop];
        --otop;
    }
    for(int i=1;i<=ntop;++i){
        if(op[i]){
            if(op[i]=='+'){
                stk[stktop-1]=stk[stktop]+stk[stktop-1];
                --stktop;stk[stktop].update();
            }else if(op[i]=='-'){
                stk[stktop-1]=stk[stktop-1]-stk[stktop];
                --stktop;stk[stktop].update();
            }else if(op[i]=='*'){
                stk[stktop-1]=stk[stktop-1]*stk[stktop];
                --stktop;stk[stktop].update();
            }else 
                cerr<<"Error!\n";
        }else{
            stk_num[i].update();
            stk[++stktop]=stk_num[i];
        }
    }
    stk[1].update();
    // cout<<stk[1].top<<'\n';
    cout<<stk[1];

}
/*
998+765*432+711+568+813
(1+2-3*4)*5-6*7+8-9
(x-9)+(7-3*x)*((5+x))
(5+12)+7+3-4-11-3
*/