#include <winsock2.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
main(){
        //初始化
    WORD wVersionRequested;
    WSADATA wsaData;
    int err;
    wVersionRequested = MAKEWORD(2, 2);
    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) {
        return 1;
    }
 
    if (LOBYTE(wsaData.wVersion) != 2 ||
        HIBYTE(wsaData.wVersion) != 2) {
        WSACleanup();
        return 1;
    }
 
    //1. 创建socket, 指明要使用的协议什么
    SOCKET sock = socket(
        AF_INET,    //ipv4协议族
        SOCK_DGRAM, //数据报
        IPPROTO_UDP);//udp协议
    if (sock == INVALID_SOCKET)
    {
        printf("Build Socket Failed. \r\n");
        return 0;
    }
 
 
    //3. 发数据
    string addr_UDP;
    cin>>addr_UDP;
    sockaddr_in siTo;
    siTo.sin_family = AF_INET;
    siTo.sin_port = htons(9527);
    siTo.sin_addr.S_un.S_addr = inet_addr(addr_UDP.data());
    
    char szBuff[0x1000] = {"hello socket" };
    cin>>szBuff;
    int nBytesSend = sendto(sock,
        szBuff,
        sizeof(szBuff),
        0,
        (sockaddr*)&siTo, //客户端的的目标地址和端口
        sizeof(siTo));
 
    if (nBytesSend == SOCKET_ERROR)
    {
        closesocket(sock);
        printf("Send Message Failed. \r\n");
        return 0;
    }
 
 
    //接收数据
    sockaddr_in siRecv;
    int nSizeOfSiRecv = sizeof(siRecv);
    char szBuff0[MAXWORD + 1] = { 0 };
    int nBytesRecv = recvfrom(sock,
        szBuff0,
        sizeof(szBuff0),
        0,
        (sockaddr*)&siRecv,
        &nSizeOfSiRecv);
    if (nBytesRecv == SOCKET_ERROR)
    {
        closesocket(sock);
        printf("Receive Message Failed. \r\n");
        return 0;
    }
 
 
    //清理
    WSACleanup();
 
    return 0;
}