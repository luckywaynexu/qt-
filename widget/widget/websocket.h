#pragma once
#include <QWebSocket>
#include<QWebSocketServer>
/*
@breaf:创建websocket连接
@note:实现服务器端的功能
@author:xw
@date:2018.10.24
*/
class WebsocketServer :public QObject
{
	Q_OBJECT
public:
	WebsocketServer() { 
		m_pServer = new QWebSocketServer(QStringLiteral("Hello fear"), QWebSocketServer::NonSecureMode);
		Text = QStringLiteral("我是默认值");
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
		QWebSocket* pSocket = m_pServer->nextPendingConnection();//获得一个websocket连接
		pSocket->sendTextMessage(Text);//向客户端返回消息
	}

};