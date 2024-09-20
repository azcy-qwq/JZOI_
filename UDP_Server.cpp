#include <winsock2.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
//#pragma comment(lib, "ws2_32.lib")
#define BUFFER_SIZE 1024
int main()
{
    WSADATA WSAData;
    cout<<"A";
    char receBuf[BUFFER_SIZE];
    char Response[BUFFER_SIZE];
    if (WSAStartup(MAKEWORD(2, 2), &WSAData) != 0)
    {
        printf("Failed");
        exit(1);
    }
    SOCKET sockServer = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockServer == INVALID_SOCKET)
    {
        printf("Failed socket() \n");
        return 0;
    }
    SOCKADDR_IN addr_Server; // 服务器的地址等信息
    addr_Server.sin_family = AF_INET;
    addr_Server.sin_port = htons(4567);
    addr_Server.sin_addr.S_un.S_addr = INADDR_ANY;
    if (bind(sockServer, (SOCKADDR *)&addr_Server, sizeof(addr_Server)) == SOCKET_ERROR)
    {
        // 服务器与本地地址绑定
        printf("Failed socket() %d \n", WSAGetLastError());
        return 0;
    }
    SOCKADDR_IN addr_Clt;
	cout<<"B\n";
    int fromlen = sizeof(SOCKADDR);
    while (true)
    {
        int last = recvfrom(sockServer, receBuf, 1024, 0, (SOCKADDR *)&addr_Clt, &fromlen);
        if (last > 0)
        {
            // 判断接收到的数据是否为空
            receBuf[last] = '\0'; // 给字符数组加一个'\0'，表示结束了。不然输出有乱码
            if (strcmp(receBuf, "bye") == 0)
            {
                cout << "Communication Ends." << endl;
                closesocket(sockServer);
                return 0;
            }
            else
            {
                printf("Received Data(%s):%s\n", inet_ntoa(addr_Clt.sin_addr), receBuf);
            }
        }
        cout << "Reply Message:";
        // <br> 
        // Response =" "; 
        cin >> Response; // 给客户端回复消息
        sendto(sockServer, Response, strlen(Response), 0, (SOCKADDR *)&addr_Clt, sizeof(SOCKADDR));
    }

    closesocket(sockServer);

    WSACleanup();
    return 0;
}