class CData
{
public:
    CData();							//���캯��
   void bind();						//���������׽��ֺ���
   void sevsend(SOCKET&,char*,int,int);	//���������ͺ���	
   void sevrecv(SOCKET&,char*,int,int);   	//���������պ���
   void connect();						//�ͻ������Ӻ���
   void send(SOCKET&,char*,int,int);		//�ͻ��˷��ͺ���	
   void recv(SOCKET&,char*,int,int);	   	//�ͻ��˽��պ���
~CData();	
   };
