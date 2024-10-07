#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
namespace azcy
{
    using namespace std;
    bool debug_switch = 1;
    void auto_init()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    void qfopen(string INPUT_FILE_NAME, string OUTPUT_FILE_NAME)
    {
        freopen(INPUT_FILE_NAME.data(), "r", stdin);
        freopen(OUTPUT_FILE_NAME.data(), "w", stdout);
    }
    template <typename T>
    void dbgo(T x)
    {
        cout << x << " ";
    }
    template <typename First, typename... Rest>
    void dbgo(First first, Rest... rest)
    {
        cout << first << " ";
        dbgo(rest...);
    }
    template <typename First, typename... Rest>
    void dbg(First first, Rest... rest)
    {
        if (!debug_switch)
            return;
        cout << first << " ";
        dbgo(rest...);
        cout << "\n";
    }
    template <typename T>
    void dbg(T x)
    {
        if (!debug_switch)
            return;
        cout << x << "\n";
    } // made by _azcy

}

mt19937 rnd(0721);
double urd1()
{
    return (double)rnd() / INT_MAX / 2;
}
string s;
double day_, score;

void rgb_init() // ANSIµÄº¯Êý
{
    HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwInMode, dwOutMode;
    GetConsoleMode(hIn, &dwInMode);
    GetConsoleMode(hOut, &dwOutMode);
    dwOutMode |= 0x0004;
    SetConsoleMode(hIn, dwInMode);
    SetConsoleMode(hOut, dwOutMode);
}
void rgb_set(int wr, int wg, int wb, int br, int bg, int bb)
{
    printf("\033[38;2;%d;%d;%dm\033[48;2;%d;%d;%dm", wr, wg, wb, br, bg, bb);
}
void qrgb(int r,int g,int b){
    printf("\033[38;2;%d;%d;%dm",r,g,b);
}
unsigned int hash1,hash2;

long long qpow(long long x, long long y, long long pcc)
{	
    long long t = x, ans = 1;
    while (y)
    {
        if (y & 1)
            ans *= t, ans %= pcc;
        t *= t;
        t %= pcc;
        y >>= 1;
    }
    return ans;
}
int to[16] = {0, 99, 211, 288, 376, 468, 530, 610, 670, 720, 840, 950, 1000};
int r[16] = {82, 82, 127, 80, 63, 198, 102, 34, 96, 245, 255, 237, 237};
int g[16] = {82, 82, 127, 181, 72, 53, 204, 253, 253, 232, 127, 28, 28};
int b[16] = {82, 82, 127, 49, 204, 209, 255, 223, 128, 20, 39, 36, 36};
string name,equip,djc;
int n=87;
void display2(double scr){
    char ch='H';
    double prv, lst, sum, prvp, lstp;
    int flag;
    bool ff=0;
    for(int i=150;i<=1000;i+=50){
        for (int j = 1; j <= 12; ++j)
        {
            if (to[j - 1] <= i && to[j] >= i)
            {
                flag = j;
                break;
            }
        }
        prv = i - to[flag - 1], lst = to[flag] - i;
        sum = prv + lst;
        prvp = lst / sum, lstp = prv / sum;
        qrgb((int)(r[flag - 1] * prvp + r[flag] * lstp), (int)(g[flag - 1] * prvp + g[flag] * lstp), (int)(b[flag - 1] * prvp + b[flag] * lstp));
        if(ch<'A')ch='S';
        if(i>=scr&&i<scr+50)
            printf("\033[1;4m"),djc=ch;;
        cout<<ch;
        if(ff){
            if(i>=scr&&i<scr+50)
                djc+='+';
            cout<<"+";
            ch--;
            ff=0;
        }else ff=1;
        printf("\033[0m");
        cout<<" ";
    }
    cout<<endl;
    qrgb(204,204,204);
}
void display(double scr)
{
    double prv, lst, sum, prvp, lstp;
    int flag;
    for (int i = 1; i <= 12; ++i)
    {
        if (to[i - 1] <= scr && to[i] >= scr)
        {
            flag = i;
            break;
        }
    }
    prv = scr - to[flag - 1], lst = to[flag] - scr;
    sum = prv + lst;
    prvp = lst / sum, lstp = prv / sum;
    cout << "This equipment's quality of " << name << " is: ";
    _sleep(120);
    qrgb((int)(r[flag - 1] * prvp + r[flag] * lstp), (int)(g[flag - 1] * prvp + g[flag] * lstp), (int)(b[flag - 1] * prvp + b[flag] * lstp));
    cout <<setprecision(4)<<fixed<< scr << " "<<djc<<endl;
    qrgb(204,204,204);
    //rgb_set(204, 204, 204, 12, 12, 12);
}
int main(int argc,char *argv[]){
	rgb_init();
	if(argc>1){
		name=argv[1];
		equip=argv[2];
	}
	else{
		cout<<"Please enter your name and equipment's name that you will acquire.\n";
		cin>>name>>equip;
	}
    
    for (int i = 0; i < name.length(); ++i)
    {
        if (name[i] >= 'A' && name[i] <= 'Z')
            name[i] = name[i] - 'A' + 'a';
    }
    for(int i=0;i<name.length();++i){
        hash1+=qpow(name[i],name[i]+i*i*3,(int)(1e9+7));
    }for(int i=0;i<equip.length();++i){
        hash2+=qpow(equip[i],equip[i]+i*i*5,998244353);
        hash2+=qpow(equip[i]*equip[i],equip[i]*i+i*i*3,1145141);
    }
    // cout<<log((int)INT_MAX-(int)1e9-7)<<endl;
    double kkk=(double)(22.0-log(1+abs((int)hash2-(int)hash1)))/21*1000;
    kkk+=100;
    display2(kkk);
    display(kkk);
    if(argc<=1)
    system("pause");
    return (int)kkk;
}
/*
zangchengyu

*/