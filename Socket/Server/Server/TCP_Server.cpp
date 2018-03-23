#include<WinSock2.h>
#include<WS2tcpip.h> //inet_pton��������ͷ�ļ�
#pragma comment(lib, "ws2_32.lib")//windwows�µ�socket��̺�����
#include<iostream>
#include<string>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define CONNECT_NUM_MAX 10
using namespace std;

int main()
{
	// 1. ����Socket
	WORD SocketVersion=MAKEWORD(2, 2);//windows�����̿�İ汾����Ϣ
	WSADATA wsaData;
	int a =WSAStartup(SocketVersion,&wsaData);//WSAStartup�������ڳ����г�ʼ��������Windows����
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
	SOCKET ServerSocket=socket(AF_INET,             //InternetЭ��  ����ַ��
												   SOCK_STREAM,  //��ʽ��TCPЭ��
												   IPPROTO_TCP);  //���ض��ĵ�ַ����ص�Э��
	if (ServerSocket == INVALID_SOCKET)  //�ж�socket�Ƿ���Ч
	{
		cout << "�׽��ִ���ʧ�ܣ�" << endl;
	}
	// 3. �󶨷�����IP�Ͷ˿ں�
	SOCKADDR_IN Server_Address;//����һ��socket������͵������ַ���ݽṹ�Ա�connect�����Ա���������socket���ݽṹ���г�ʼ����
	Server_Address.sin_family = AF_INET;//��������Э��������
	Server_Address.sin_port = htons(6000);//���ö˿ں�	
	inet_pton(AF_INET, "127.0.0.1", &Server_Address.sin_addr);																 
	a = bind(ServerSocket, (LPSOCKADDR)&Server_Address, sizeof(Server_Address));
	if (a == SOCKET_ERROR)
	{
		cout << "��ʧ�ܣ�" << endl;
	}
	// 4. ��������
	a = listen(ServerSocket, CONNECT_NUM_MAX);
	if (a == SOCKET_ERROR)
	{
		cout << "����ʧ�ܣ�" << endl;
	}
	//�ȴ�����_����_����
	SOCKADDR_IN Client_Address; //���ڴ���ͻ�����IP��ַ�Ͷ˿ں� 
	int len = sizeof(SOCKADDR_IN);
	SOCKET ConnectSocket = INADDR_ANY;//�ڷ��������ٴ���һ��socket�ṹ������������һ���ͻ��˽���ͨ�����ӵ�����ʵ��   
	while (1)
	{
		ConnectSocket = accept(ServerSocket, (SOCKADDR*)&Client_Address, &len);
		if (ConnectSocket == INVALID_SOCKET)//�������������һ���ͻ�����������ʧ�ܾ��˳�����״̬
		{
			cout << "����ʧ�ܣ�" << endl;
		}
		cout << "���ӳɹ���" << endl;
		//cout << "����Ŀͻ� IP �ǣ�" << Client_Address.sin_addr.S_un.S_addr<< endl;
		cout<<"�����룺"<<endl;

		char sendInfo[100];
		cin >> sendInfo;
		send(ConnectSocket, sendInfo, strlen(sendInfo), 0);

		char recvInfo[100];
		recv(ConnectSocket, recvInfo, strlen(recvInfo), 0);
		cout << recvInfo << endl;
		closesocket(ConnectSocket);//�ر������accept��������socket���󣬹ر���ͻ�������ͨ�š�
	}

	closesocket(ServerSocket);//�رշ������ϵ���bind����������socket���󣬹رձ����򿪵Ķ˿ڣ��رշ�����  
	WSACleanup();//�ͷ�ws2_32.dll��̬��

	system("pause");
	return 0;
}