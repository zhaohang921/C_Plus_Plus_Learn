#include<WinSock2.h>
#include<WS2tcpip.h> 
#pragma comment(lib, "ws2_32.lib")//windwows�µ�socket��̺�����
#include<iostream>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
using namespace std;

int main()
{
	// 1. ����Socket
	WORD SocketVersion = MAKEWORD(2, 2);//windows�����̿�İ汾����Ϣ
	WSADATA wsaData;
	int a = WSAStartup(SocketVersion, &wsaData);//WSAStartup�������ڳ����г�ʼ��������Windows����
	if (a != 0)//���WSAStartup����ֵΪ1�Ļ��ͱ�ʾws2_32.lib�ļ������⣬�����˳�
	{
		cout << "�����׽��ֿ�ʧ��!" << endl;
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{
		WSACleanup();
		cout << "�����׽��ֿ�汾��һ��!" << endl;
	}
	// 2. ����Socket
	SOCKET ClientSocket = socket(AF_INET,             //InternetЭ��  ����ַ��
		SOCK_STREAM,  //��ʽ��TCPЭ��
		IPPROTO_TCP);  //���ض��ĵ�ַ����ص�Э��
	if (ClientSocket == INVALID_SOCKET)  //�ж�socket�Ƿ���Ч
	{
		cout << "�׽��ִ���ʧ�ܣ�" << endl;
	}
	// 3. �󶨷�����IP�Ͷ˿ں�
	SOCKADDR_IN Server_Address;//����һ��socket������͵������ַ���ݽṹ�Ա�connect�����Ա���������socket���ݽṹ���г�ʼ����
	Server_Address.sin_family = AF_INET;//��������Э��������
	Server_Address.sin_port = htons(6000);//���ö˿ں�
	//Server_Address.sin_addr.S_un.S_addr = inet_addr("10.99.33.229"); //���÷�������IP��ַ��һ��INADDR_ANY�ڳ�������ʱ���Զ�����ɱ��ص�IP��ַ
	inet_pton(AF_INET, "127.0.0.1", &Server_Address.sin_addr);

	a = connect(ClientSocket, (SOCKADDR*)&Server_Address, sizeof(SOCKADDR));
	if (a == SOCKET_ERROR)
	{
		cout << "����ʧ�ܣ�" << endl;
	}
	char sendInfo[100];
	cin >> sendInfo;
	send(ClientSocket, sendInfo, strlen(sendInfo), 0);

	char recvInfo[100];
	recv(ClientSocket, recvInfo, strlen(recvInfo), 0);
	cout << recvInfo << endl;


	closesocket(ClientSocket);//�ر����TCP����ͨ������
	WSACleanup();//�ͷ�ws2_32.dll��̬��

	system("pause");
	return 0;
}