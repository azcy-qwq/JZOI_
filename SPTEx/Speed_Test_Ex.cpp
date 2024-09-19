#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<bits/stdc++.h>
#include<windows.h>
const int N=1e3+28;
using namespace std;
double utd[10];
string temp;
void rgb_init()
{
	HANDLE hIN=GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwINmode,dwOutMode;
	GetConsoleMode(hIN,&dwINmode);
	GetConsoleMode(hOut,&dwOutMode);
	dwINmode |=0x0200;
	dwOutMode |=0x0004;
	SetConsoleMode(hIN,dwINmode);
	SetConsoleMode(hOut,dwOutMode);
 } 
 void rgb_set(int wr,int wg,int wb,int br,int bg,int bb){
 	printf("\033[38;2;%d;%d;%dm\033[48;2;%d;%d;%dm",wr,wg,wb,br,bg,bb);
 }
void autorgb(int x){
	if(x<350)rgb_set(166,166,166,0,0,0);
		else if(x<650)rgb_set(210,210,210,20,20,20);
		else if(x<830)rgb_set(30,187,32,20,20,20);
		else if(x<1050)rgb_set(0,128,255,20,20,20);
		else if(x<1220)rgb_set(134,31,209,20,20,20);
		else if(x<1400)rgb_set(102,204,255,20,20,20);
		else if(x<1660)rgb_set(245,245,20,20,20,20);
		else if(x<2000)rgb_set(255,160,19,20,20,20);
		else rgb_set(255,20,20,20,20,20);
	if(x<0)rgb_set(235,235,235,20,20,20);
}
void disp(int id)
{
	rgb_set(235,235,235,15,15,15);
	cout<<"test "<<id<<": ";
	autorgb(utd[id]);
	cout<<utd[id]<<"\n";
 } 
int main()
{
//	ios::sync_with_stdio(0);
//	double START_COSTS_TIME=clock()/CLOCKS_PER_SEC;
//	cout<<START_COSTS_TIME;
	cout<<"Close other unnecessary processes to get higher rate.\nPress any key to continue.\n";
	system("pause");
	system("cls");
	cout<<"Expected taking about 6 seconds in the standart environment.\nÉÙÅ®Æíµ»ÖÐ...\n";
	 
	system("test1.exe > 1.txt");
	ifstream f1("1.txt");
	f1>>temp>>utd[1];
	utd[1]=265000/utd[1];
	f1.close();
	disp(1);
	
	system("test2.exe > 2.txt");
	ifstream f2("2.txt");
	f2>>temp>>utd[2];
	utd[2]=374000/utd[2];
	f2.close();
	disp(2);
	
	system("test3.exe > 3.txt");
	ifstream f3("3.txt");
	f3>>temp>>utd[3];
	utd[3]=1171000/utd[3];
	f3.close();
	disp(3);
	
	system("test4.exe > 4.txt");
	ifstream f4("4.txt");
	f4>>temp>>utd[4];
	utd[4]=827000/utd[4];
	f4.close();
	disp(4);
	
	system("test5.exe > 5.txt");
	ifstream f5("5.txt");
	f5>>temp>>utd[5];
	utd[5]=931000/utd[5];
	f5.close();
	disp(5);
	
	system("test6.exe > 6.txt");
	ifstream f6("6.txt");
	f6>>temp>>utd[6];
	utd[6]=487000/utd[6];
	f6.close();
	disp(6);
	
	system("test7.exe > 7.txt");
	ifstream f7("7.txt");
	f7>>temp>>utd[7];
	utd[7]=978000/utd[7];
	f7.close();
	disp(7);
	
	system("test8.exe > 8.txt");
	ifstream f8("8.txt");
	f8>>temp>>utd[8];
	utd[8]=762000/utd[8];
	f8.close();
	disp(8);
	
	system("test9.exe > 9.txt");
	ifstream f9("9.txt");
	f9>>temp>>utd[9];
	utd[9]=327000/utd[9];
	f9.close();
	disp(9);
	
	system("test10.exe > 10.txt");
	ifstream f10("10.txt");
	f10>>utd[10];
	utd[10]=1710000/utd[10];
	f10.close();
	disp(10);
	
	system("del temp.oupt");
	rgb_set(235,235,235,20,20,20);
	printf("\n------------------------------------\nSimplified CPU Speed: ");
	autorgb((int)(0.4*utd[9]+0.35*utd[8]+0.15*utd[7]+0.05*utd[1]+0.05*utd[2]));
	printf("%.1f\n",0.4*utd[9]+0.35*utd[8]+0.15*utd[7]+0.05*utd[1]+0.05*utd[2]);
	autorgb(-2);
	printf("Simplified Memory R/W Speed: ");
	autorgb((int)(0.45*utd[6]+0.45*utd[5]+0.1*utd[4]));
	printf("%.1f\n",0.45*utd[6]+0.45*utd[5]+0.1*utd[4]);
	autorgb(-2);
	printf("Released v1.4.0 by_azcy\n");
	autorgb((int)(0.6*(int)(0.4*utd[9]+0.35*utd[8]+0.15*utd[7]+0.05*utd[1]+0.05*utd[2])+0.6*(int)(0.45*utd[6]+0.45*utd[5]+0.1*utd[4])));
	system("pause");
	system("systeminfo");
	system("pause");
	return 0;
}
