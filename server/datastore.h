#pragma once
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QDateTime>
#include <QDebug>
#include <QStringList>
#include <QMutex>
#include <QSqlError>
#define CURRENT_PATH "G:\\TEEData\\Huaxi\\"
struct PATIENTDATA{
	QString _patient_ID;   //����id��סԺ��
	QString _local_path;   //����ͼ���ڱ���·��
	QString _timer;       //ͼ�����ʱ��
};

class datastore
{
public:
	datastore(void);
	~datastore(void);
	bool dataBaseConnect();      //�������ݿ�
	QSqlDatabase sqlConnect();  //�������ݿ�
	void dataBaseClose();        //�ر�����������
	bool execsql(QString _sql);
	bool insertDataToSql(QString _username, QString _server_path, QString _localfile,double _sieze, QString _md5, QString _timer);
	bool insertUserFeedback(QString _user, QString _feedback, QString _ip_address, int _port);
	bool insertSystrmErrorInfo(QString _systrmerror, QString _ip_address, int _port);
	QString searchPatientDataName(QString _patientName);//�����ݿ��в�ѯ��������
	QStringList searchPatientID(QString _patientName);   //��ȡ���������Ĳ���סԺ��
	QSqlDatabase getdatabase();
	bool searchUserAndPwd(QString _username, QString _password);  //��ѯ�û���������
	PATIENTDATA searchPatientData(QString _patientName);   //������������
	bool insertTestData(QString _tableName);    //�������ݲ���
private:
	QSqlDatabase data_base;
	struct PATIENTDATA m_patientdata1;
	//QString upload_AND_download_Path;
	QMutex m_mutex;
};

