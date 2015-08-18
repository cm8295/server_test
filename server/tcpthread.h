#ifndef TCPTHREAD_H
#define TCPTHREAD_H

#define CRTDBG_MAP_ALLOC//�ڴ�������
#include <stdlib.h>
#include <crtdbg.h>

#include <QThread>
#include <QTcpSocket>
#include <QtNetwork/QHostAddress>
#include "tcpserver.h"
#include "datachange.h"
#include "datastore.h"
#include <QtSql/QSqlDatabase>
#include <QtXml/QtXml> 
#include <QDomDocument>  
#include <QDateTime>
#include <QMutex>
#include <QMutexLocker>

enum DATA_FORMAT
{
	DOWN_FILEDOWN_END = 1,
	UP_FILEUP_END = 2,
	FILENAME_BEGINFILENAME_END = 3,
	SEARCH_PATIENT_DATA = 4         //���������ӿ�
};

class TcpThread : public QThread
{
	Q_OBJECT

public:
	TcpThread(int socketDescriptor);
	~TcpThread();
	void run();
	QFileInfoList GetFileList(QString path);   //��ȡ�ļ��б�
	QString FileDigest(QString FilePath);   //��ȡ�ļ�MD5��
	double fileSize(QString _filepath);
	QString search_List_End(QString _patient_Name);   //��ȡ�ò������������в�������
	void sendDataToClient(QString _currentData);/*��������*/
	void sendUserLoginAndRegisterCheck(int _check);//�û���Ϣ�����
signals:
	void error(QTcpSocket::SocketError socketError);
	void bytesArrived(qint64,qint32,int);
	void sendtransferinfo();
	void disconnectedSignal(int);
	//void connectDis();
	public slots:
		void receiveData();  //���տͻ��˷��������ļ�����
		void updateClientProgress(qint64 numBytes);
		void displayError(QAbstractSocket::SocketError socketError);  
		void connectError();   //���ӶϿ�����ֹ���߳�
private:
	/*����*/
	int socketDescriptor;
	QTcpSocket *tcpServerConnection;  
	/**/
	qint64 TotalBytes;     //file�ܴ�С
	qint64 bytesReceived;  //�յ������ֽ�
	qint64 fileNameSize;  //׼����ȡ���ֽ�
	QString fileName;  //�ļ�·������
	QFile *localFile;  
	QFile m_localFile;
	QByteArray inBlock;
	QByteArray outBlock;
	qint64 bytesToWrite;
	qint64 bytesWritten;
	qint64 loadSize;
	//��������
	QString message;  //��Ŵӷ��������յ����ַ���  
	quint16 blockSize;  //����ļ��Ĵ�С��Ϣ 
	QFileInfoList m_qfileinfolist;
	QString sFileName;    //��ʵ�ļ���
	QString sFile;      //�ļ����ͱ�ʶ,�ϴ���������
	QString m_filePath;  //�ļ��洢·��
	QString m_serverPath;//�ļ��ķ���·��
	QString clientip;    //�ͻ���ip
	QHostAddress qip;
	bool blFileOpen;
	bool blDownLoadFileOpen;
	QString currenttime;
	QString upload_AND_download_Path;
	QString download_Path;
	//datachange *_datachange;
	bool blerror;
	QString serverMessage;  
	QString serverData;
	QByteArray block;
	//download
	QStringList string_list;
	QString path;
	QFileInfo dir;
	//upload
	QFileInfo qfilecheck;
	QString tempPathstory;
	QString _username;/*�û���*/
	QString _currentFilename ;/*�ļ���*/

	//database
	QSqlDatabase data_base;
	datastore _datastore;
	QMutex _qmutex;
	struct PATIENTDATA m_patientdata3;    
};

#endif // TCPTHREAD_H
