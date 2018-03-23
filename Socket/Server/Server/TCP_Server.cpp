#include<WinSock2.h>
#include<WS2tcpip.h> //inet_pton函数所在头文件
#pragma comment(lib, "ws2_32.lib")//windwows下的socket编程函数库
#include<iostream>
#include<string>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define CONNECT_NUM_MAX 10
using namespace std;

int main()
{
	// 1. 加载Socket
	WORD SocketVersion=MAKEWORD(2, 2);//windows网络编程库的版本号信息
	WSADATA wsaData;
	int a =WSAStartup(SocketVersion,&wsaData);//WSAStartup函数是在程序中初始化并加载Windows网络
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
	SOCKET ServerSocket=socket(AF_INET,             //Internet协议  ，地址族
												   SOCK_STREAM,  //流式，TCP协议
												   IPPROTO_TCP);  //与特定的地址族相关的协议
	if (ServerSocket == INVALID_SOCKET)  //判断socket是否有效
	{
		cout << "套接字创建失败！" << endl;
	}
	// 3. 绑定服务器IP和端口号
	SOCKADDR_IN Server_Address;//创建一个socket编程类型的网络地址数据结构以便connect函数对本机创建的socket数据结构进行初始化。
	Server_Address.sin_family = AF_INET;//设置网络协议族类型
	Server_Address.sin_port = htons(6000);//设置端口号	
	inet_pton(AF_INET, "127.0.0.1", &Server_Address.sin_addr);																 
	a = bind(ServerSocket, (LPSOCKADDR)&Server_Address, sizeof(Server_Address));
	if (a == SOCKET_ERROR)
	{
		cout << "绑定失败！" << endl;
	}
	// 4. 开启监听
	a = listen(ServerSocket, CONNECT_NUM_MAX);
	if (a == SOCKET_ERROR)
	{
		cout << "监听失败！" << endl;
	}
	//等待连接_接收_发送
	SOCKADDR_IN Client_Address; //用于储存客户机的IP地址和端口号 
	int len = sizeof(SOCKADDR_IN);
	SOCKET ConnectSocket = INADDR_ANY;//在服务器上再创建一个socket结构，用来储存与一个客户端进行通信连接的连接实例   
	while (1)
	{
		ConnectSocket = accept(ServerSocket, (SOCKADDR*)&Client_Address, &len);
		if (ConnectSocket == INVALID_SOCKET)//如果服务器接受一个客户端连接请求失败就退出监听状态
		{
			cout << "接收失败！" << endl;
		}
		cout << "连接成功！" << endl;
		//cout << "连入的客户 IP 是：" << Client_Address.sin_addr.S_un.S_addr<< endl;
		cout<<"请输入："<<endl;

		char sendInfo[100];
		cin >> sendInfo;
		send(ConnectSocket, sendInfo, strlen(sendInfo), 0);

		char recvInfo[100];
		recv(ConnectSocket, recvInfo, strlen(recvInfo), 0);
		cout << recvInfo << endl;
		closesocket(ConnectSocket);//关闭这个用accept函数建立socket对象，关闭与客户端连接通信。
	}

	closesocket(ServerSocket);//关闭服务器上的由bind函数创建的socket对象，关闭本机打开的端口，关闭服务器  
	WSACleanup();//释放ws2_32.dll动态库

	system("pause");
	return 0;
}