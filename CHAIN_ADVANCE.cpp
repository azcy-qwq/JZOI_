#include<iostream>

#include<cstdio>

#include<cstring>

#include<cmath>

#include<algorithm>

#include<queue>

#include<vector>

#include<bits/stdc++.h>

#include<windows.h>

#include<conio.h>

#include<mmsystem.h>

#include<dsound.h>
#include<random>
#include <stdio.h>
#pragma comment(lib, "WINMM.LIB")
#define tbl(x) ter[loc[x].terr]
const int N = 1e4 + 28;
using namespace std;
void clearScreen() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordScreen = {
        0,
        0
    }; // home for the cursor
    SetConsoleCursorPosition(hConsole, coordScreen);
}
void rgb_qset(int wr, int wg, int wb) {
    int br = 10, bg = 10, bb = 10;
    printf("\033[38;2;%d;%d;%dm\033[48;2;%d;%d;%dm", wr, wg, wb, br, bg, bb);
}
void rgb_set(int wr, int wg, int wb, int br, int bg, int bb) {
    printf("\033[38;2;%d;%d;%dm\033[48;2;%d;%d;%dm", wr, wg, wb, br, bg, bb);
}
void rgb_init() {
    HANDLE hIN = GetStdHandle(STD_INPUT_HANDLE);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwINmode, dwOutMode;
    GetConsoleMode(hIN, & dwINmode);
    GetConsoleMode(hOut, & dwOutMode);
    dwINmode |= 0x0200;
    dwOutMode |= 0x0004;
    SetConsoleMode(hIN, dwINmode);
    SetConsoleMode(hOut, dwOutMode);
}
struct info {
    double eco, eco_per_rnd, hp_recover_factor;
    int dead = 0, ownloc = 3;
    int maxr = 6, strc_ends, strc_work;
    char team;
    string name;
}
plr[N];
struct unit {
    double MaxHP, cost, Soft_Atk, Hard_atk, Soft_HP, Hard_HP, soft_atk_factor, hard_atk_factor, stratg_factor, armor_pierce, armor, defence, armor_pierce_factor, recover_hp, recover_hp_factor;
    string name;

}
un[N];
struct soldi {
    double hp;
    int to, nowloc;
    int belong;
    bool side,infl;
}
sd[N];
struct lo {
    int terr, owner, core;
    char ownteam;
    double eco;
}
loc[N];
struct te {
    double cost_cstr, combat_width, atk_factor, def_factor;
    int r, g, b;
    string name;
}
ter[N];
struct sc {
    bool is_def;
    double ofside_atk_factor, ofside_def_factor, defsd_atk_factor, defsd_def_factor;
};
struct warface {
    int frontline[2][10], fltop[2];
    bool search(bool side, int id) {
        for (int i = 1; i <= fltop[side]; ++i) {
            if (frontline[side][i] == id) return 1;
        }
        return 0;
    }
}
wf[N];
int sod_typesize;
int n, locmax, inp, sdtop;
bool DEBUG_SWITCH;
double init_consq[N];
void data_init() {
    int t = 1;
    init_consq[1] = init_consq[2] = 1;
    for (int i = 3; i <= 1000; ++i) {
        init_consq[i] = (init_consq[i - 2] + init_consq[i - 1]) * 0.55 + 0.5;
        //		cout<<init_consq[i]<<endl;
    }
    ter[1].name = "Plain   ";
    ter[1].atk_factor = 1.4;
    ter[1].def_factor = 0.9;
    ter[1].combat_width = 8;
    ter[1].cost_cstr = 1;
    ter[1].r = 143;
    ter[1].g = 196;
    ter[1].b = 72;

    ter[2].name = "Mountain";
    ter[2].atk_factor = 0.6;
    ter[2].def_factor = 1.2;
    ter[2].combat_width = 4;
    ter[2].cost_cstr = 2.2;
    ter[2].r = 94;
    ter[2].g = 160;
    ter[2].b = 150;

    ter[3].name = "Forest  ";
    ter[3].atk_factor = 1;
    ter[3].def_factor = 1;
    ter[3].combat_width = 6;
    ter[3].cost_cstr = 1.5;
    ter[3].r = 100;
    ter[3].g = 174;
    ter[3].b = 111;

    ter[4].name = "Urban   ";
    ter[4].atk_factor = 0.9;
    ter[4].def_factor = 0.7;
    ter[4].cost_cstr = 0.6;
    ter[4].r = 155;
    ter[4].g = 175;
    ter[4].b = 196;

    un[1].name = "Infantry";
    un[1].armor = 1.6;
    un[1].armor_pierce = 4.0;
    un[1].cost = 6;
    un[1].defence = 6;
    un[1].Hard_atk = 1.2;
    un[1].MaxHP = 40;
    un[1].recover_hp = 2;
    un[1].Soft_Atk = 8;
    un[1].Soft_HP = 1;
    un[1].stratg_factor = 1;

    un[2].name = "Light Infantry";
    un[2].armor = 0.2;
    un[2].armor_pierce = 2.7;
    un[2].cost = 4;
    un[2].defence = 5;
    un[2].Hard_atk = 0.4;
    un[2].MaxHP = 36;
    un[2].recover_hp = 2;
    un[2].Soft_Atk = 7;
    un[2].Soft_HP = 1;
    un[2].stratg_factor = 1.4;

    un[3].name = "Heavy Infantry";
    un[3].armor = 2.6;
    un[3].armor_pierce = 6.0;
    un[3].cost = 8;
    un[3].defence = 6;
    un[3].Hard_atk = 2.2;
    un[3].MaxHP = 45;
    un[3].recover_hp = 2.5;
    un[3].Soft_Atk = 12;
    un[3].Soft_HP = 1;
    un[3].stratg_factor = 0.8;

    un[4].name = "Elite Infantry";
    un[4].armor = 2.5;
    un[4].armor_pierce = 18.0;
    un[4].cost = 10;
    un[4].defence = 7;
    un[4].Hard_atk = 3.0;
    un[4].MaxHP = 40;
    un[4].recover_hp = 4.5;
    un[4].Soft_Atk = 12;
    un[4].Soft_HP = 1;
    un[4].stratg_factor = 1;

    un[5].name = "Artillery";
    un[5].armor = 0;
    un[5].armor_pierce = 16.0;
    un[5].cost = 10;
    un[5].defence = 2;
    un[5].Hard_atk = 4.0;
    un[5].MaxHP = 1;
    un[5].recover_hp = 1;
    un[5].Soft_Atk = 40;
    un[5].Soft_HP = 1;
    un[5].stratg_factor = 1;

    un[6].name = "Anti-Tank Artillery";
    un[6].armor = 0;
    un[6].armor_pierce = 75.0;
    un[6].cost = 10;
    un[6].defence = 2;
    un[6].Hard_atk = 35;
    un[6].MaxHP = 1;
    un[6].recover_hp = 1;
    un[6].Soft_Atk = 5;
    un[6].Soft_HP = 1;
    un[6].stratg_factor = 1;

    un[7].name = "Machanized Infantry";
    un[7].armor = 20;
    un[7].armor_pierce = 12.0;
    un[7].cost = 10;
    un[7].defence = 7;
    un[7].Hard_atk = 3.2;
    un[7].MaxHP = 45;
    un[7].recover_hp = 2;
    un[7].Soft_Atk = 8;
    un[7].Soft_HP = 0.3;
    un[7].Hard_HP = 0.7;
    un[7].stratg_factor = 1;

    un[8].name = "Midium Tank";
    un[8].armor = 45;
    un[8].armor_pierce = 50.0;
    un[8].cost = 18;
    un[8].defence = 15;
    un[8].Hard_atk = 15;
    un[8].MaxHP = 25;
    un[8].recover_hp = 2;
    un[8].Soft_Atk = 20;
    un[8].Soft_HP = 0.2;
    un[8].Hard_HP = 0.8;
    un[8].stratg_factor = 1.1;

    un[9].name = "Light Tank";
    un[9].armor = 18;
    un[9].armor_pierce = 30.0;
    un[9].cost = 1;/////
    un[9].defence = 12;
    un[9].Hard_atk = 10;
    un[9].MaxHP = 20;
    un[9].recover_hp = 2;
    un[9].Soft_Atk = 1600;/////
    un[9].Soft_HP = 0.25;
    un[9].Hard_HP = 0.75;
    un[9].stratg_factor = 1.3;

    sod_typesize = 9;
}
void create_template() {
    int temp = 0, cnt = 0;
    for (int i = 1; i <= sod_typesize; ++i) {
        cout << i << ":" << un[i].name << "\n";
    }
    cout << "Input the squads' id that included\n";
    int i = 1 + sod_typesize;
    while (temp >= 0) {
        cin >> temp;
        if (temp < 0) break;
        ++cnt;
        un[i].armor += un[temp].armor;
        un[i].cost += un[temp].cost;
        un[i].armor_pierce += un[temp].armor_pierce;
        un[i].defence += un[temp].defence;
        un[i].Hard_atk += un[temp].Hard_atk;
        un[i].Hard_HP += un[temp].Hard_HP;
        un[i].MaxHP += un[temp].MaxHP;
        un[i].recover_hp += un[temp].recover_hp;
        un[i].Soft_Atk += un[temp].Soft_Atk;
        un[i].Soft_HP += un[temp].Soft_HP;
    }
    if (cnt == 0) return;
    un[i].armor /= cnt;
    un[i].cost /= cnt;
    un[i].armor_pierce /= cnt;
    un[i].defence /= cnt;
    un[i].Hard_atk /= cnt;
    un[i].Hard_HP /= cnt;
    un[i].MaxHP /= cnt;
    un[i].recover_hp /= cnt;
    un[i].Soft_Atk /= cnt;
    un[i].Soft_HP /= cnt;
    cout << "input the template name\n";
    cin >> un[i].name;
    cout << i << endl;
    sod_typesize++;
}
mt19937 rnd(time(0));

string com;
void terrain_init() {
    int cur = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 5; ++j) {
            loc[cur].core = i;
            loc[cur].terr = (j == 3) ? 4 : (rnd() % 7) / 2 + 1;
            loc[cur].owner = i;
            loc[cur].ownteam = plr[i].team;
            loc[cur].eco = (j == 3) ? 4 : 1;
            locmax = cur;
            ++cur;
        }

    }
}
void display() {
    for (int i = 1; i <= locmax; ++i) {
        rgb_set(220, 220, 220, tbl(i).r, tbl(i).g, tbl(i).b);
        cout.setf(ios::left);
        cout.width(4);
        cout << i << " " << tbl(i).name;
        printf("  %d(%c)/%d  ECO:%.2f\n", loc[i].owner, loc[i].ownteam, loc[i].core, loc[i].eco);
    }
    rgb_set(220, 220, 220, 10, 10, 10);
}
void update() {
    for (int i = 1; i <= n; ++i) {
        plr[i].ownloc = 0;
        plr[i].eco_per_rnd = 0;
    }
    for (int i = 1; i <= locmax; ++i) {
        plr[loc[i].owner].ownloc++;
        plr[loc[i].owner].eco_per_rnd += loc[i].eco * ((loc[i].owner == loc[i].core) ? 1 : 0.3);
    }
}
void del(int id) {
    int cloc = sd[id].nowloc;
    int sid = 0;
    for (int i = 1; i <= wf[cloc].fltop[sid]; ++i) {
        if (wf[cloc].frontline[sid][i] == inp) {
            for (int j = i; j <= 9; ++j) {
                wf[cloc].frontline[sid][j] = wf[cloc].frontline[sid][j + 1];
            }
            wf[cloc].fltop[sid]--;
            break;
        }
    }
    sid = 1;
    for (int i = 1; i <= wf[cloc].fltop[sid]; ++i) {
        if (wf[cloc].frontline[sid][i] == inp) {
            for (int j = i; j <= 9; ++j) {
                wf[cloc].frontline[sid][j] = wf[cloc].frontline[sid][j + 1];
            }
            wf[cloc].fltop[sid]--;
            break;
        }
    }
    sd[id].nowloc = 0;
    sd[id].belong = 0;
}
void show_unit(int id) {
    printf("id:%d  Belong:%d Type:%s HP:%.1f/%.1f Soft Attack:%.1f Hard Attack:%.1f Defence:%.1f Pierce:%.1f Armor:%.1f\n", id, sd[id].belong, un[sd[id].to].name.data(), sd[id].hp, un[sd[id].to].MaxHP, un[sd[id].to].Soft_Atk, un[sd[id].to].Hard_atk, un[sd[id].to].defence, un[sd[id].to].armor_pierce, un[sd[id].to].armor);
}
double hit(int from, int to) {
    int f = sd[from].to, t = sd[to].to;
    cout<<"--------------------------"<<f<<" "<<t<<endl;
    return ((un[f].armor_pierce >= un[t].armor) ? 1 : 0.4) *
        (((un[f].Soft_Atk * (sd[from].side == 1 ? 1 : 0.8) - un[t].defence * (sd[to].side == 1 ? 0.6 : 1)) * (un[f].Soft_Atk * (sd[from].side == 1 ? 1 : 0.8) >= un[t].defence * (sd[to].side == 1 ? 0.6 : 1)) +
                min(un[t].defence * (sd[to].side == 1 ? 0.6 : 1), un[f].Soft_Atk * (sd[from].side == 1 ? 1 : 0.8)) * 0.3) * un[t].Soft_HP +
            ((un[f].Hard_atk * (sd[from].side == 1 ? 1 : 0.8) - un[t].defence * (sd[to].side == 1 ? 0.6 : 1)) * (un[f].Hard_atk * (sd[from].side == 1 ? 1 : 0.8) >= un[t].defence * (sd[to].side == 1 ? 0.6 : 1)) +
                min(un[t].defence * (sd[to].side == 1 ? 0.6 : 1), un[f].Hard_atk * (sd[from].side == 1 ? 1 : 0.8)) * 0.3) * un[t].Hard_HP);
}
double HIT(int f,int t){
	return ((un[f].armor_pierce >= un[t].armor) ? 1 : 0.4) *
        (((un[f].Soft_Atk  - un[t].defence ) * (un[f].Soft_Atk  >= un[t].defence ) +
                min(un[t].defence , un[f].Soft_Atk ) * 0.3) * un[t].Soft_HP +
            ((un[f].Hard_atk  - un[t].defence ) * (un[f].Hard_atk  >= un[t].defence ) +
                min(un[t].defence , un[f].Hard_atk ) * 0.3) * un[t].Hard_HP);
}
void calc(int id) {
    if (wf[id].fltop[0] == 0 && wf[id].fltop[1] > 0) {
        loc[id].owner = sd[wf[id].frontline[1][1]].belong;
        loc[id].ownteam = plr[loc[id].owner].team;
        for (int i = 1; i <= wf[id].fltop[1]; ++i) {
            wf[id].frontline[0][i] = wf[id].frontline[1][i];
            wf[id].frontline[1][i] = 0;
        }
        wf[id].fltop[0] = wf[id].fltop[1];
        wf[id].fltop[1] = 0;
        return;
    }
    for (int i = 1; i <= wf[id].fltop[0]; ++i)
        sd[wf[id].frontline[0][i]].side = 0;
    for (int j = 1; j <= wf[id].fltop[1]; ++j)
        sd[wf[id].frontline[1][j]].side = 1;
    for (int i = 1; i <= wf[id].fltop[0]; ++i) {
        for (int j = 1; j <= wf[id].fltop[1]; ++j) {
            sd[wf[id].frontline[1][j]].hp -= hit(wf[id].frontline[1][i], wf[id].frontline[1][j]);
        }
    }
    for (int i = 1; i <= wf[id].fltop[0]; ++i) {
        for (int j = 1; j <= wf[id].fltop[1]; ++j) {
            sd[wf[id].frontline[0][i]].hp -= hit(wf[id].frontline[1][j], i);
        }
    }
    for (int i = 1; i <= wf[id].fltop[0]; ++i) {
        if (sd[wf[id].frontline[0][i]].hp < 0) del(wf[id].frontline[0][i]);
    }
    for (int i = 1; i <= wf[id].fltop[1]; ++i) {
        if (sd[wf[id].frontline[1][i]].hp < 0) del(wf[id].frontline[1][i]);
    }
}
bitset < N > vis;
int main() {
    //	ios::sync_with_stdio(0);
    rgb_init();
    data_init();
//    cout<<HIT(7,2)<<" "<<HIT(2,7);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> plr[i].name;
        cin >> plr[i].team;
    }
    terrain_init();
    cout << locmax << endl;
    //	display();
    //	return 0;
    while (1) {
        int new_round = 1;
        for (int id = 1; id <= n;) {
            //			clearScreen();
            system("cls");
            
            if (new_round) {
            	for(int i=1;i< sdtop;++i){
            		if(sd[i].hp<=0)continue;
            		if(plr[loc[sd[i].nowloc].owner].team!=plr[sd[i].belong].team)
            		{
            			if(plr[loc[sd[i].nowloc-1].owner].team==plr[sd[i].belong].team)
            				sd[i].nowloc--;
            			else if(plr[loc[sd[i].nowloc+1].owner].team==plr[sd[i].belong].team)
            				sd[i].nowloc++;
            			else del(i);
					}
				}
            	
				for (int i = 1; i <= locmax; ++i) {
                //				cout<<i<<" ";
                	if (wf[i].fltop[1] != 0) {
                    //					cout<<"calc:"<<i<<endl;
                    	calc(i);
                	}
            	}
				
				update();
                new_round = 0;
                for (int i = 1; i <= n; ++i) {
                    plr[i].eco += plr[i].eco_per_rnd;
                }
            }
			display();
            cout << endl << "Now:" << id << " " << plr[id].name << "(" << plr[id].team << ")" << " eco:" << plr[id].eco << "/" << plr[id].eco_per_rnd << endl;
            cin >> com;
            if (plr[id].eco < 0) {
                id++;
                new_round = 1;
                continue;
            }
            if (com == "create_template" || com == "ct") {
                create_template();
            } else if (com == "cst" || com == "construct") {
                cin >> inp;
                if (loc[inp].ownteam != plr[id].team || plr[id].eco < ter[loc[inp].terr].cost_cstr * init_consq[(int) floor(loc[inp].eco)]) continue;
                plr[id].eco -= ter[loc[inp].terr].cost_cstr * init_consq[(int) floor(loc[inp].eco)];
                loc[inp].eco++;
            } else if (com == "deploy" || com == "dpl") {
                for (int i = 1; i <= sod_typesize; ++i) {
                    cout << i << " " << un[i].name << endl;
                }
                cin >> inp;
                if (plr[id].eco < un[inp].cost || inp > sod_typesize) continue;
                sd[++sdtop].to = inp;
                sd[sdtop].nowloc = id * 5 - 2;
                sd[sdtop].hp = un[sd[sdtop].to].MaxHP;
                sd[sdtop].belong = id;
                plr[id].eco -= un[inp].cost;
            } else if (com == "show") {
                cin >> inp;
                vis.reset();
                cout << "Defence Frontline:\n";
                for (int i = 1; i <= wf[inp].fltop[0]; ++i) {
                    show_unit(wf[inp].frontline[0][i]);
                    vis[wf[inp].frontline[0][i]] = 1;
                }
                cout << "Offensive Frontline:\n";
                //				cout<<wf[inp].fltop[1]<<endl;
                for (int i = 1; i <= wf[inp].fltop[1]; i++) {
                    show_unit(wf[inp].frontline[1][i]);
                    vis[wf[inp].frontline[1][i]] = 1;
                }
                cout << "Others:\n";
                for (int i = 1; i <= sdtop; i++) {
                    if (sd[i].hp > 0 && vis[i] == 0 && sd[i].nowloc == inp) {
                        show_unit(i);
                    }
                }
                system("pause");
            } else if (com == "end") {
                id++;
                continue;
            } else if (com == "move_up" || com == "mu") {
                cin >> inp;
                if (sd[inp].belong != id || loc[sd[inp].nowloc].ownteam != plr[id].team) continue;
                if(sd[inp].infl){
                	int cloc = sd[inp].nowloc;
               		 int sid = (plr[id].team != loc[cloc].ownteam);
                	for (int i = 1; i <= wf[cloc].fltop[sid]; ++i) {
                	
                    	if (wf[cloc].frontline[sid][i] == inp) {
							sd[inp].infl=0;
                        	for (int j = i; j <= 9; ++j) {
                            	wf[cloc].frontline[sid][j] = wf[cloc].frontline[sid][j + 1];
                        	}
                        	wf[cloc].fltop[sid]--;
                      	  break;
                    	}
                	}
				}
				if(sd[inp].nowloc-1==0)continue;
                sd[inp].nowloc--;
                if (loc[sd[inp].nowloc].ownteam != plr[id].team) {
                    if (wf[sd[inp].nowloc].fltop[1] <= ter[loc[sd[inp].nowloc].terr].combat_width) {
                        wf[sd[inp].nowloc].frontline[1][++wf[sd[inp].nowloc].fltop[1]] = inp;
                    }
                }
            } else if (com == "move_down" || com == "md") {
                cin >> inp;
                if (sd[inp].belong != id || loc[sd[inp].nowloc].ownteam != plr[id].team) continue;
                if(sd[inp].infl){
                	int cloc = sd[inp].nowloc;
               		 int sid = (plr[id].team != loc[cloc].ownteam);
                	for (int i = 1; i <= wf[cloc].fltop[sid]; ++i) {
                	
                    	if (wf[cloc].frontline[sid][i] == inp) {
							sd[inp].infl=0;
                        	for (int j = i; j <= 9; ++j) {
                            	wf[cloc].frontline[sid][j] = wf[cloc].frontline[sid][j + 1];
                        	}
                        	wf[cloc].fltop[sid]--;
                      	  break;
                    	}
                	}
				}
				if(sd[inp].nowloc+1>5*n)continue;
                sd[inp].nowloc++;
                if (loc[sd[inp].nowloc].ownteam != plr[id].team) {


                    if (wf[sd[inp].nowloc].fltop[1] <= ter[loc[sd[inp].nowloc].terr].combat_width) {
                        ++wf[sd[inp].nowloc].fltop[1];

                        wf[sd[inp].nowloc].frontline[1][wf[sd[inp].nowloc].fltop[1]] = inp;
                        //						cout<<sd[inp].nowloc<<" "<<wf[sd[inp].nowloc].fltop[1]<<" "<<wf[sd[inp].nowloc].frontline[1][wf[sd[inp].nowloc].fltop[1]];
                    }

                    //					system("pause");
                }
            } else if (com == "turn_to" || com == "tt") {
                cin >> inp;
                id = inp;
            } else if (com == "DEBUG_MODE_SWITCH") {
                int temp = rnd() % 10;
                cout << DEBUG_SWITCH << " " << temp << endl;
                cin >> inp;
                if (inp == temp * temp + 233000)
                    DEBUG_SWITCH |= 1;
            } else if (com == "_ADD_MONEY_TO_PLAYER" && DEBUG_SWITCH == 1) {
                int inp2;
                cin >> inp >> inp2;
                plr[inp].eco += inp2;
            } else if (com == "_ADD_ECO_TO_LOCATION" && DEBUG_SWITCH == 1) {
                int temp;
                cin >> inp >> temp;
                loc[inp].eco += temp;
            } else if (com == "fl" || com == "frontline") {
                cin >> inp;
                if (sd[inp].belong != id) continue;
                if (loc[sd[inp].nowloc].ownteam == id) {
                    if (wf[sd[inp].nowloc].fltop[0] <= ter[loc[sd[inp].nowloc].terr].combat_width) {
                        wf[sd[inp].nowloc].frontline[0][++wf[sd[inp].nowloc].fltop[0]] = inp;
                        sd[inp].infl=1;
                    }
                } else {
                    if (wf[sd[inp].nowloc].fltop[1] <= ter[loc[sd[inp].nowloc].terr].combat_width) {
                        wf[sd[inp].nowloc].frontline[1][++wf[sd[inp].nowloc].fltop[1]] = inp;
                        sd[inp].infl=1;
                    }
                }
            } else if (com == "out_to_backline" || com == "otb") {
                cin >> inp;
                if (sd[inp].belong != id) continue;
                int cloc = sd[inp].nowloc;
                int sid = (plr[id].team != loc[cloc].ownteam);
                for (int i = 1; i <= wf[cloc].fltop[sid]; ++i) {
                	
                    if (wf[cloc].frontline[sid][i] == inp) {
						sd[inp].infl=0;
                        for (int j = i; j <= 9; ++j) {
                            wf[cloc].frontline[sid][j] = wf[cloc].frontline[sid][j + 1];
                        }
                        wf[cloc].fltop[sid]--;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
/*
2
a a
b b
dpl 2
md 1
md 1
md 1
show 6
*/
