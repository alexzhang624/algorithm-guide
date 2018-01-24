#include <stdio.h>
#include <stdlib.h>

#include <winsock2.h>
//#pragma comment(lib, "ws2_32.a")

#define BUF_SIZE 1024

int main()
{


    WSADATA wsaData;
    SOCKET  socketC;
    SOCKADDR_IN serverAddr;
    char sendbuf[BUF_SIZE] = "Hello UDP World!";

    WSAStartup(MAKEWORD(1,1), &wsaData);

    socketC = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5679);
    serverAddr.sin_addr.s_addr = inet_addr("192.168.2.3");

    sendto(socketC, sendbuf, sizeof(sendbuf), 0, (SOCKADDR*)&serverAddr, sizeof(serverAddr));

    closesocket(socketC);

    WSACleanup();

    printf("Hello world!\n");
    return 0;
}

/*
//文件:tcp_c.c
//描述:tcp客户端源程序
#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "WS2_32.lib")

#define BUF_SIZE 1024
int main(int argc, char* argv)
{
    WSADATA wsaData;
    SOCKADDR_IN serverAddr;
    SOCKET socketC;
    char sendbuf[BUF_SIZE] = "Hello TCP World!";

    WSAStartup(MAKEWORD(1,1), &wsaData);

    socketC = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5678);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(socketC, (SOCKADDR*)&serverAddr, sizeof(serverAddr));

    send(socketC, sendbuf,sizeof(sendbuf), 0);

    closesocket(socketC);

    WSACleanup();
}
//文件:tcp_s.c
//描述:tcp服务器端源程序
#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "WS2_32.lib")

#define BUF_SIZE 1024
int main(int argc, char** argv)
{
    WSADATA wsaData;
    SOCKET  socketL;  // socket for listening
    SOCKET  socketC;  // socket for Communication
    SOCKADDR_IN serverAddr;
    int nRet = -1;
    char recvbuf[BUF_SIZE];

    WSAStartup(MAKEWORD(1,1), &wsaData);

    socketL = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    serverAddr.sin_family      = AF_INET;
    serverAddr.sin_port        = htons(5678);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(socketL, (SOCKADDR*)&serverAddr, sizeof(serverAddr));

    listen(socketL, 5);

    socketC = accept(socketL, NULL, NULL);
    if (socket != INVALID_SOCKET)
    {
        nRet = recv(socketC, recvbuf, sizeof(recvbuf), 0);
        if (nRet > 0)
            printf("%s ", recvbuf);
    }

    closesocket(socketC);
    closesocket(socketL);

    WSACleanup();
}
//文件:udp_c.c
//描述:udp客户端源程序
#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "WS2_32.lib")

#define BUF_SIZE 1024
int main(int argc, char** argv)
{
    WSADATA wsaData;
    SOCKET  socketC;
    SOCKADDR_IN serverAddr;
    char sendbuf[BUF_SIZE] = "Hello UDP World!";

    WSAStartup(MAKEWORD(1,1), &wsaData);

    socketC = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5679);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    sendto(socketC, sendbuf, sizeof(sendbuf), 0, (SOCKADDR*)&serverAddr, sizeof(serverAddr));

    closesocket(socketC);

    WSACleanup();
}
//文件:udp_s.c
//描述:udp服务器端源程序
#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "WS2_32.lib")

#define BUF_SIZE 1024
int main(int argc, char** argv)
{
    WSADATA wsaData;
    SOCKET  socketC;
    SOCKADDR_IN serverAddr;
    char recvbuf[BUF_SIZE];

    WSAStartup(MAKEWORD(1,1), &wsaData);

    socketC = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5679);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(socketC, (SOCKADDR*)&serverAddr, sizeof(serverAddr));

    int nRet = recvfrom(socketC, recvbuf, sizeof(recvbuf), 0, 0, 0);
    if (nRet > 0)
        printf("%s ", recvbuf);

    closesocket(socketC);

    WSACleanup();
}
*/
