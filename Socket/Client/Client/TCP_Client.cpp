#include<WinSock2.h>
#include<WS2tcpip.h> 
#pragma comment(lib, "ws2_32.lib")//windwows下的socket编程函数库
#include<iostream>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
using namespace std;

int main()
{
	// 1. 加载Socket
	WORD SocketVersion = MAKEWORD(2, 2);//windows网络编程库的版本号信息
	WSADATA wsaData;
	int a = WSAStartup(SocketVersion, &wsaData);//WSAStartup函数是在程序中初始化并加载Windows网络
	if (a != 0)//如果WSAStartup返回值为1的话就表示ws2_32.lib文件有问题，程序退出
	{
		cout << "加载套接字库失败!" << endl;
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{
		WSACleanup();
		cout << "加载套接字库版本不一致!" << endl;
	}
	// 2. 创建Socket
	SOCKET ClientSocket = socket(AF_INET,             //Internet协议  ，地址族
		SOCK_STREAM,  //流式，TCP协议
		IPPROTO_TCP);  //与特定的地址族相关的协议
	if (ClientSocket == INVALID_SOCKET)  //判断socket是否有效
	{
		cout << "套接字创建失败！" << endl;
	}
	// 3. 绑定服务器IP和端口号
	SOCKADDR_IN Server_Address;//创建一个socket编程类型的网络地址数据结构以便connect函数对本机创建的socket数据结构进行初始化。
	Server_Address.sin_family = AF_INET;//设置网络协议族类型
	Server_Address.sin_port = htons(6000);//设置端口号
	//Server_Address.sin_addr.S_un.S_addr = inet_addr("10.99.33.229"); //设置服务器的IP地址，一般INADDR_ANY在程序运行时会自动计算成本地的IP地址
	inet_pton(AF_INET, "127.0.0.1", &Server_Address.sin_addr);

	a = connect(ClientSocket, (SOCKADDR*)&Server_Address, sizeof(SOCKADDR));
	if (a == SOCKET_ERROR)
	{
		cout << "连接失败！" << endl;
	}
	char sendInfo[100];
	cin >> sendInfo;
	send(ClientSocket, sendInfo, strlen(sendInfo), 0);

	char recvInfo[100];
	recv(ClientSocket, recvInfo, strlen(recvInfo), 0);
	cout << recvInfo << endl;


	closesocket(ClientSocket);//关闭这个TCP网络通信连接
	WSACleanup();//释放ws2_32.dll动态库

	system("pause");
	return 0;
}