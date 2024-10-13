#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <stdio.h>
#include <bits/stdc++.h>
// #pragma comment(lib, "ws2_32.lib")
using namespace std;
int main()
{

	_sleep(100);
	WSADATA wsaData;
	char buff[1024];
	memset(buff, 0, sizeof(buff));

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("Failed to load Winsock");
		return 0;
	}

	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(5099);
	string addrs;
	cin >> addrs;
	addrSrv.sin_addr.S_un.S_addr = inet_addr(addrs.data());
	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);
	while (1)
	{
		if (SOCKET_ERROR == sockClient)
		{
			printf("Socket() error:%d", WSAGetLastError());
			return 0;
		}
		if (connect(sockClient, (struct sockaddr *)&addrSrv, sizeof(addrSrv)) == INVALID_SOCKET)
		{
			printf("Connect failed:%d", WSAGetLastError());
			return 0;
		}
		else
		{
			recv(sockClient, buff, sizeof(buff), 0);
			printf("Received:%s\n", buff);
		}
		string s;
		cin >> s;
		char *buffSend = s.data();
		send(sockClient, buffSend, strlen(buffSend) + 1, 0);
		// closesocket(sockClient);
		WSACleanup();
		//    	printf("%d", strlen(buffSend) + 1);

		system("pause");
	}
	// 创建套接字
}