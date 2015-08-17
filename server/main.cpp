/************************************************************************/
/*                     ��������������                                 */
/************************************************************************/
#include <QtCore/QCoreApplication>
#include <QTextCodec>
#include <tcpserver.h>
#include <Windows.h>
#include <DbgHelp.h>
#include "datastore.h"
#pragma comment( lib, "Dbghelp.lib" )
struct PATIENTDATA1{/*������Ϣ�ṹ��*/
	QString _patient_ID;
	QString _local_path;
	QString _timer;
};

TcpServer *tcpServer;
QSqlDatabase data_base;

/**
*  �򿪷�����
*/
bool openServer()
{
	while (!tcpServer->isListening() && !tcpServer->listen(QHostAddress::Any,19845))
	{
		qDebug()<<tcpServer->errorString();
		return false;
	}
	tcpServer->setMaxPendingConnections(100);
	qDebug()<<"�����Ѿ�������"<<" �˿ڣ�"<<19845;
	return true;
}
/**
*�����쳣����
*/
LONG ApplicationCrashHandler(EXCEPTION_POINTERS *pException){//��ʽ�쳣����  
    /* 
      ***�������ݴ���*** 
    */  
	//���� Dump �ļ�  
	HANDLE hDumpFile = CreateFile(QTime::currentTime().toString("HHʱmm��ss��zzz.dmp").utf16(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);  
	if( hDumpFile != INVALID_HANDLE_VALUE){  
		//Dump��Ϣ  
		MINIDUMP_EXCEPTION_INFORMATION dumpInfo;  
		dumpInfo.ExceptionPointers = pException;  
		dumpInfo.ThreadId = GetCurrentThreadId();  
		dumpInfo.ClientPointers = TRUE;  
		//д��Dump�ļ�����  
		MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hDumpFile, MiniDumpNormal, &dumpInfo, NULL, NULL);  
	}  
    //���ﵯ��һ������Ի����˳�����  
    EXCEPTION_RECORD* record = pException->ExceptionRecord;  
    QString errCode(QString::number(record->ExceptionCode,16)),errAdr(QString::number((uint)record->ExceptionAddress,16)),errMod;  
	qDebug()<<"������룺" + errCode<<"�����ַ��" + errAdr;
    return EXCEPTION_EXECUTE_HANDLER;  
} 

int main(int argc, char *argv[])
{
	//_CrtSetBreakAlloc(3023);
	QCoreApplication a(argc, argv);
	//��ȡϵͳ���룬������ֲ���������
	QTextCodec *codec = QTextCodec::codecForName("System"); 
	//���úͶԱ����ļ�ϵͳ��дʱ���Ĭ�ϱ����ʽ
	QTextCodec::setCodecForLocale(codec); 
	//�����ַ���������QByteArray����QString����ʱʹ�õ�һ�ֱ��뷽ʽ
	QTextCodec::setCodecForCStrings(codec); 
	//���ô���tr����ʱ��Ĭ���ַ�������
	QTextCodec::setCodecForTr(codec);
	//SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)ApplicationCrashHandler);//ע���쳣������
	//datastore *_datastore = new datastore(NULL);
	datastore _datastore;
	tcpServer = new TcpServer(NULL);
	openServer();
	if(_datastore.dataBaseConnect())
	{
		qDebug()<<"���ݿ����ӳɹ�";
		//_datastore.dataBaseClose();
	}
	else
	{
		qDebug()<<"���ݿ�����ʧ��";
	}
	return a.exec();
}


