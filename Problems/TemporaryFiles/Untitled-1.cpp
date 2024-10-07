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
int qpow(int x, int y, int pcc)
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
#define int long long
int to[16] = {0, 99, 211, 288, 376, 468, 530, 610, 670, 720, 840, 950, 1000};
int r[16] = {82, 82, 127, 80, 63, 198, 102, 34, 96, 245, 255, 237, 237};
int g[16] = {82, 82, 127, 181, 72, 53, 204, 253, 253, 232, 127, 28, 28};
int b[16] = {82, 82, 127, 49, 204, 209, 255, 223, 128, 20, 39, 36, 36};
string djc;
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
    cout << "Today's LuckyPoint of " << s << " is: ";
    _sleep(120);
    qrgb((int)(r[flag - 1] * prvp + r[flag] * lstp), (int)(g[flag - 1] * prvp + g[flag] * lstp), (int)(b[flag - 1] * prvp + b[flag] * lstp));
    cout <<setprecision(4)<<fixed<< scr << " "<<djc<<endl;
    qrgb(204,204,204);
    //rgb_set(204, 204, 204, 12, 12, 12);
}
string description[1020]={"?","¿ªµçÄÔ","³öÃÅ","Ñ§ÊýÑ§",//
                "Ñ§Ó¢Óï","Ñ§ÎïÀí","Ñ§ÉúÎï","Ñ§»¯Ñ§",//
                "Ñ§ÓïÎÄ","Ñ§ÕþÖÎ","Ñ§OI","´òÄ£ÄâÈü",//
                "GO","ÑÐ¾¿¸ßÊý","³Ô·¹","ÉÏBÕ¾",//
                "Ñ§ÐÂËã·¨","Ð´×÷Òµ","Ë¯¾õ","ÉÏ²ÞËù",//
                "¿ª·É»ú","ÉÏMC·þÎñÆ÷","¿ªÂå","ÍÚµØµÀ",//
                "ÏÂ¿ó","¾íwhk","ÉÏBlue Archieve","Ä£ÄâÍË»ð",//
                "¶ÔÏß","ÑÐ¾¿ÕÜ¡áÑ§","ÓÎÓ¾","ÍõÅÆ¿ÕÕ½",//
                "Æô¶¯OS","ÂÃÓÎ","´ò³µ","µãÍâÂô",//
                "ÇåÀíµçÄÔ","¿¼ÊÔ","¿ªV","¸É»î",//
                "³ÔÔç·¹","¶Ô¸ô±ÚËÞÉá·¢¶¯ÌØ±ð¾üÊÂÐÐ¶¯","¸ãmc½¨Öþ","´ò·½ÖÛRoughlike",//
                "´òÕ¼¸êÍÁÒ²","´òÒ°Âù6","´òHOI4","´òStellaris",//
                "Play Terraria","×°B","×°Èõ","±í°×",//
                "ÅÜ²Ù","½ÓÊÖGAL²Ð¾Ö","Ñ§Í¼ÂÛ","¼øÖ¤",//
                "µ÷´úÂë","Áìµ¼Ñ§ÉúÔË¶¯","´òÀºÇò","Ñ°ÇóÂéÒÂÑ§½ãµÄ°ïÖú",//15
                "×°Èí¼þ","ÖØ¹¹´úÂë","²¹Ìâ","×ö¸É¾»µÄ³éÇ©",
                "ÌÓ±ÜÎÄ»¯¿ÎÑ§Ï°","ÌÓ±Ü¼¯Ñµ","ÌýÐ´","½²¿Î",
                "´òÏßÉÏ¹«¿ªÈü","ÉÏÌåÓý¿Î","Ñ§Ï°½á¹¹»¯Ñ§","Ñ§Ï°ÓÐ»ú»¯Ñ§",//18
                "Ñ§Ï°ÒÅ´«Ñ§","Ñ§Ï°µçÑ§","Ñ§Ï°Á¦Ñ§","Ñ§Ï°´úÊý",
                "Ñ§Ï°¼¸ºÎ","¿ªµ¼","»ØËÞÉá","´óÐÝ",
                "ÑÐ¾¿çæÑ§","Ê¹ÓÃpair","¸ÐÊÜ¶÷Çé","¸üÐÂ",//21
                "Ñ§Ï°ÊýÂÛ","Çå¿Õ","Ä¤°Ýdalao","×ø³µ"
                };
pair<string,string> pss[1020]={{".report","WDNMD"},{"speedtest3000·Ö",":("},{"³©Í¨ÎÞ×è","Åöµ½¹ùÁÁ"},{"Ò»¸öÊýÒ²Ã»Ëã´í","Ö»»áPµã½¨Ïµ"},
                {"ÐÂÊ±´úÍò´ÊÍõ","×ó¹Õ¶íÓï,ÓÒ¹ÕÈÕÓï"},{"µ±´úÅ£¶Ù","Ð´³ö»ùÓÚÊ¸Á¿·Ö½âµÄ¶¯ÄÜ¶¨Àí"},{"µ±´úÃÏµÂ¶û","ÒÅ´«ÌâÉ¶Ò²²»»á"},{"ÎÞÇéÌúÊÖ","°Ñ½ÌÑ§Â¥Õ¨ÁË"},//2
                {"ÞñÖîµ±ÏÂ","LPºÜ¿ì¾Íµ½Äã¼ÒÃÅ¿Ú"},{"ÀÏÂíÖÕÓÚÐÀÎ¿µØÐ¦ÁË","µ±´ú²¨¶û²¼ÌØ"},{"AK IOI","Êý×é¿ªÐ¡µ÷Á©Ð¡Ê±"},{"AK±ÈÈüÅ°È«³¡","400pts->0pts"},//3
                {"Rating 1.96","±»Ò°Å£À­±¬"},{"Ò»ÌìÈýÕÂÏß´ú","±ä³ÉÐ¡wqh"},{"Ê³ÌÃÓÐºÜ¶àºÃ³ÔµÄ","ºÃ³ÔµÄ·¹±»´ò¹âÁË"},{"¹Ø×¢µÄÊ§×ÙÈË¿Ú»Ø¹é","Åö×ÅJoker"},//4
                {"ÌýÒ»±é¾Í¶®ÁË","Ñ§²»»á"},{"ÎÒÒàÎÞËû,Î¨ÊÖÊì¶û","±»ÊýÑ§Ó²¿ØÁ©Ð¡Ê±"},{"Ñø¾«ÐîÈñ,Ã÷ÈÕÔÙÕ½","ÄãËµËûÔõÃ´¾Í[CENSORED]"},{"Ïë³öÁËºÚÌâµÄË¼Â·","Íü¼ÇÄÃÖ½"},//5
                {"ÍõÅÆ·ÉÐÐÔ±ÏÞÊ±ÌåÑé","pull¨Kup¡ü"},{"Ë¢Ìú»ú¶¼ÂúÁË","Íü¹ØË¢É³»ú"},{"ÓäÔÃÉíÐÄ","±»CN_ZhoucyÈñÆÀ"},{"ÀÏ±±¾©µÄ¾ÈÊê","¶ÔÃæÏ£ÌØÀÕ"},//6
                {"diamond++;","creeper~"},{"±ä³ÉÎÄ»¯¿ÎÏÉÈË","±»PÄ³±¡É´"},{"³ö×Å²ÊÓ¢Óï¾Í141+ÁË","Ò»ÉÏºÅ·¢ÏÖ²»½ö¾ÅÀ¶Ò»»Æ,¶øÇÒ¸ßÈýµÄÍ¬Ñ§ÃÇ±ÏÒµÁË"},{"dpÊÇÊ²Ã´À¬»ø","99pts Unaccepted"},//7
                {"ÑÔÖ®ÓÐÎï,Ö¤¾ÝÈ·Ôä","¶ÔÃæÈýÄê¼¶"},{"ÅÁÇïÀò¡áGO","¶ÔÃæ½Ü¸ç,ÄãÊÇ°¢Î°"},{"¶ÍÁ¶ÉíÌå","Ë®ÎÂ12¡ãC"},{"ÔÚ²»ÁÐµß¿ÕÕ½ÖÐÁÁ³öÁË¹âµç×·×Ù","±»µ¼µ¯×·ÁËÒ»ËÞ"},//8
                {"³ö½ð","±»ÂîÔ­Åú"},{"Ì¤±éÊÀ½çÉÏµÄÃ¿Ò»´ç·çÍÁ","µ½ÁËÄ¿µÄµØ·¢ÏÖÊÇ³¯ÏÊ"},{"ÓÖ¿ìÓÖ±ãÒË","±»À­µ½ÁËÃå±±"},{"×ÝÏíÃÀÎ¶","ÍâÂôÔ±·­ÏÂË®µÀÀïÁË"},//9
                {"Á÷³©¶È++","°Ñ¿ì½Ý·½Ê½ÈÓ½øÁË»ØÊÕÕ¾"},{"Õ¹ÏÖ³öÕæÊµÊµÁ¦","´ÓÍ·¼Äµ½Î²"},{"MikuÒôÖÊ¼«¼Ñ","²»ÖªµÀÎªÉ¶½ñÌìMiku²»ÄñÄã"},{"ÊÜµ½Í¬Ñ§×ð¾´","µ±ÍêN***er»ØÀ´·¢ÏÖ±»»ú²ÒÁË"},//10
                {"²¹³äÉÏÎçËùÐèµÄÓªÑø","Ê³ÌÃÈ«ÊÇ¶¹Ö­"},{"ÁìÍÁ++","±»¸ô±ÚÀÏKÄÃÒ°Å£´ò±¬ÁË"},{"ÊñÉ½Ø£,°¢·¿³ö","¼×ÒÒÁ½¶ÓÍ¬Ê±Ê©¹¤(to be continued"},{"ºú·ÉÁË","½ô¼± Ê§¿Ø ºÎ´¦ÎÞÉ½º£ Ë®»ðÏàÈÝ"},//11
                {"ÀÌÊíÀÌ·èÁË","±»×ö³ÉÈü²©çúçê"},{"ÓÈÀï¿¨!´åÃñÏòÄú·ÖÏíÁËÒ»ÏîÉñÃØµÄ¿Æ¼¼ÃØÃÜ Äã¶ÔºËÁÑ±äµÄÈÏÊ¶ÓÐÁË¼«´óÌáÉý","ÁÚ¾ÓÊÇ×æÂ³"},{"É¡µçÕ½ Æô¶¯!","TNO µ«ÄãÍæµÄÊÇËÕÁª"},{"Õâ(»¯ÉíÌìÔÖ)ÊÇ¼Æ»®µÄÒ»²¿·Ö","59!¹¥»÷ÎïÊÇ59!"},//12
                {"¿ª³öÌ©À­½£","Äã¼Ò³ÉÏµÊØÁË"},{"»ñµÃÖÚÈË¾°Ñö","±»´óÀÐÈñÆÀ"},{"Ç«ÐéÊ¹ÈË½ø²½,Ç«ÐéÊ¹±ðÈËÂäºó","±»µ±³ÉFvCC"},{"ÈËÉú×Ô´ËÔ²Âú","JOKER~"}//13
                ,{"¶ÍÁ¶×îºÃÁË","³é½î¾¯¸æ"},{"¡°The Morphy's Law doesn't mean something bad will happen, what it means is something may happen will happen.¡±","BE"},{"·ÇÏßÐÔ¹æ»®Ì«¼òµ¥À²","¹ØÓÚ____ ËýËÀÁË"},{"Á¢³¡¿Í¹Û ±íÊö¾ßÌå ¿ÉÐÐÐÔÇ¿ ÀûÓÚÃñÉú","Íø¡ûÊÇÕâÑùµÄ"},//14
                {"Ò»±é¾Í¹ýÁË","Runtime Error 11:Segementary Fault"},{"»ñµÃ·Å¼ÙÊ±³¤","²ÒÔâÐ£Áìµ¼ÕòÑ¹"},{"º¢×ÓÃÇ,ÎÒÀ´°ïÄã¡ª¡ªKobe Bryant","ÄãÊÇºØÑô,Í¶µÄÊÇÖâ×Ó¿­µÄ±Ê´ü,ÏÖÔÚËüÔÚµÆÉÏ,ÁõÆ¼ÔÚºóÍ·Ö±¼Ü"},{"µ±¶ÔÃæ¿ÛezµÄÊ±ºò,ËýÖªµÀÊÇÊ±ºòÁË¡£","È»¶øËýÔÚÄã¶ÔÃæ"},//15
                {"¿ìËÙ°²×°","»·¾³ÀÏÊÇ³öÎÊÌâ»¹±¨´í"},{"´úÂëÖÊÁ¿ÏÔÖøÌá¸ß","ÈÃ±¾²»Õû½àµÄÂë·çÊ·ÉÏ¼ÓÊ·"},{"Ð¡´í¸Ä¸Ä¾Í¹ýÁË","²»¸øÏÂ²âÊÔµã,¶ÔÅÄ»¹¶Ô²»³öÀ´"},{"³É¹¦°ÑÔðÈÎÍÆ¸ø±ðÈË","ÌìÆúÖ®×Ó"},
                {"ÉÏÁËÒ»½Ú¿Î×ÔÏ°","±»×¥×¡"},{"zcyÃ»À´","zcyÕýÔÚ·¢±íÑÝ½²,·¢ÏÖÉÙ¸öÈË"},{"100pts","·¢ÏÖÖ®Ç°±³´íµØ·½ÁË"},{"½ÌÑ§Ïà³¤","¢áÊÇ×îÇ¿µÄ!"},
                {"¼ÓÁËºÜ¶àRating","±»×¥ctj"},{"Ç¿Éí½¡Ìå","ÌåÓý¹ÝÃ»¿ª"},{"×´Ì¬ºÜºÃ","ºúÂÒ³É¼ü"},{"ÓÐ»ú×îÃ»ÄÔ×ÓÁË","±»´óÓÐ»úÅ°´ý"},
                {"À­Í¬Ñ§30·Ö","±»ÂäÍ¬Ñ§30·Ö"},{"broÔÚÑ§·ÑÓÃÁ÷","´Å:ÄãºÃ"},{"¶¯Á¦Ñ§´óÊ¦","²»»á,¾ÍÊÇ²»»á"},{"×îÓÐË¼Î¬µÄÒ»¼¯","µÉÁËÒ»½Ú¿ÎÑÛ"},
                {"½¨Ïµ´ó·¨ºÃ","Pµã½¨Ïµ½â²»³ö·½³ÌÁË"},{"´úÊý¿ÉÃë","±»Âîwqh"},{"»ñµÃÐÝÏ¢","³Ùµ½ÔÚÍâÍ·Á¢ÕýÁË"},{"¿ªºÚ","±»GLÀ­È¥²¹¿Î"},
                {"»ñµÃçæ¶äÀòµÄ×£¸£","ODT±»¿¨ÁË"},{"pairÌ«Î°´óÁË!","²»Î°´óÁË"},{"ÑÛÀïÉä¼¤¹â","Àû¹öÀû,Ô½¹öÔ½¶à"},{"Ô­Éñ¸üÐÂÁË!","À¬»øÔ­Éñ"},
                {"ÎÒºÃÏñ°®ÉÏÊýÂÛÁË¡ª¡ªPCC","Ïë¼ÙÁË"},{"ÇåµÄ·Ç³£³¹µ×","ºÃ°ÉÎÒÓÖÃ»Çç¿Õ,ÎÒÊÇÈôÖÁ¡ª¡ªwangshi"},{"»ñµÃ¼Ó³É","±»±ÉÊÓ"},{"Óö×ÅÀÏË¾»ú","I drive."}
                };
bitset<10200> vis;
int n=87;
int qqq;
main()
{
    rgb_init();
    // cout<<sin(1);
	cout<<"ÊäÈëÐÕÃû/Input the name.\n±ê×¼/Standard:¶ÔÓÚÖÐÎÄÃû,ÊäÈëÐÕ+ÃûÏÖ´úººÓïÆ´Òô\nWhen it comes to others(English,French,Russian,Japanese etc.):\n\tUse the LASTNAME(or the ones commonly used)'s English version.\nNo matter whether the character is capitalized./²»Çø·Ö´óÐ¡Ð´ \nAvoid using the nickname instead of the realname.\n";
    cin >> s;
    day_ = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] - 'A' + 'a';
        day_ += qpow(s[i]*(s[i]+3)+i*6, s[i] * 3+5+2*i+4*i*i, s.length() + 1145141);
        day_+=s[i]*i;
    }
    day_ += floor(time(0) / 86400) - 18000;
    cin>>qqq;
    day_+=qqq;
    score = 248 * (0.8 * sin(0.3 * day_ - 5) + 0.4 * sin(0.25 * day_ + 2) + 0.5 * sin(0.5 * day_ + 2) + 0.9 * sin(0.5 * day_ + 4) + 0.7 * sin(0.8 * day_) + 2.52) + 50.0 * (2.0 * qpow(day_, day_ * 2, 91) / 91 - 1.0); //
    score = max(0.0, score);
    score = min(1000.0, score);
	mt19937 rnd2(score);
//	cout<<rnd2()<<"\n";
    display2(score);
     display(score);
    for(int i=1;i<=10;++i){
        int t=rnd2()%n+1;
        if(!vis[t]){
            vis[t]=1;
            bool f=((double)rnd2()/INT_MAX/2<score/1000)?1:0;
            if(f){
                qrgb(237,28,36);
                cout<<"ÒË: ";
                qrgb(204,204,204);
                cout<<description[t]<<"   "<<pss[t].first;
            }else{
                qrgb(102,102,102);
                cout<<"¼É: ";
                qrgb(204,204,204);
                cout<<description[t]<<"   "<<pss[t].second;
            }
            cout<<endl;
        }else --i;
    }
    system("pause");
    return 0;
}