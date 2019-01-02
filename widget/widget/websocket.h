#pragma once
#include <QWebSocket>
#include<QWebSocketServer>
/*
@breaf:����websocket����
@note:ʵ�ַ������˵Ĺ���
@author:xw
@date:2018.10.24
*/
class WebsocketServer :public QObject
{
	Q_OBJECT
public:
	WebsocketServer() { 
		m_pServer = new QWebSocketServer(QStringLiteral("Hello fear"), QWebSocketServer::NonSecureMode);
		Text = QStringLiteral("����Ĭ��ֵ");
		connect(m_pServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));
	
		QObject* parent = 0;
	}
	void ServerStart() { 
		m_pServer->listen(QHostAddress::Any, 3333);
	}
	void GetText(QString setence) { Text = setence; }
	~WebsocketServer() {}
public slots:
	
private:
	QWebSocketServer *m_pServer;
	QString Text;
private slots:
	void slotNewConnection() {
		QWebSocket* pSocket = m_pServer->nextPendingConnection();//���һ��websocket����
		pSocket->sendTextMessage(Text);//��ͻ��˷�����Ϣ
	}

};