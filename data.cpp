#include "Data.h"
#include <iostream.h>
CData::CData()									//���캯��
{

   }

void CData::bind()									//���������׽��ֺ���
{
  WSADATA data;								//����ṹ�����
   CString name;									//�����������ַ���
	DWORD ss=MAKEWORD(2,0);					//ָ���׽��ְ汾
   ::WSAStartup(ss,&data);							//��ʼ���׽��ֿ�
   s=::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);	//�����׽���
   sockaddr_in addr;								//�����ַ�ṹ����
::gethostname((char*)&name,(int)sizeof(name));			//�����������
	hostent *p=::gethostbyname((char*)&name);			//����������ȡ������ַ
	 in_addr *a=(in_addr*)*p->h_addr_list;				//��ñ���IP��ַ
	 CString str14=::inet_ntoa(a[0]);					//ת���ַ���IP��ַ
   addr.sin_family=AF_INET;						//����ַ�ṹ
	addr.sin_port=htons(80);							//ָ�������˿�Ϊ80
	addr.sin_addr.S_un.S_addr=inet_addr(str14);			//ָ������IP��ַ
	::bind(s,(sockaddr*)&addr,sizeof(addr));				//��������Ϣ�󶨵��׽���
	::listen(s,5);									//����
WSAAsyncSelect(s,this->m_hWnd,WM_SOCK,FD_ACCEPT|FD_READ);
												//���׽�������Ϊ�첽ģʽ
}

void CData::sevsend(SOCKET s,char* buff,int len,int flags)	//�Զ�����������ͺ���
{
            send(s,buff,len,flags);					//����API���ͺ���
}

void CData::sevrecv(SOCKET s,char* buff,int len,int flags)	//�Զ�����������պ���
{
 recv(s,buff,len,flags);								//����API���պ���
  }

void CData::connect()
{
sockaddr_in addr;						//�����ַ�ṹ����
 addr.sin_family=AF_INET;							//����ַ�ṹ
addr.sin_port=htons(80);					//ָ�������˿�Ϊ80
addr.sin_addr.S_un.S_addr=inet_addr(str14);	//ָ������IP��ַ
 if(connect(s,( sockaddr*)addr,sizeof(addr),NULL)==-1)		//���ӷ�����
{
  MessageBox("���ӷ�����ʧ�ܣ�");					//��ʾ�û����ӷ�����ʧ��
  }
}

void CData::send(SOCKET s,char* buff,int len,int flags)		//�Զ���ͻ��˷��ͺ���
{
  GetDlgItem(IDC_EDIT1)->GetWindowText(str);			//��ȡ�û����������
send(s,str.GetBuffer(1),sizeof(str),NULL);				//������Ϣ
GetDlgItem(IDC_EDIT2)->GetWindowText(str1);			//��ȡ��Ϣ��ʾ���е�����
str1+="\r\n";										//��ӻس����з�
str1+=str;										//�����ַ���	
GetDlgItem(IDC_EDIT2)->SetWindowText(str1);			//������Ϣ��ʾ�������
}

void CData::recv(SOCKET s,char* buff,int len,int flags)		//�Զ���ͻ��˽��պ���
{
  char buff[1024];									//�����ַ�������
 memset(&buff,0,1024);							//��ʼ���ַ�������
 recv(s,&buff,1024,NULL);							//��������
}

void CData::~CData()								//��������
{
  }
