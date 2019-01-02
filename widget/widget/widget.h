#pragma once

#include <QtWidgets/QWidget>
#include "ui_widget.h"
#include "AlgorithmClass.h"
#include"websocket.h"

class widget : public QWidget
{
	Q_OBJECT

public:
	widget(QWidget *parent = Q_NULLPTR);
	
private slots:
	void on_pushButton_clicked();
	void numberChangeSlot();
	
private:
	Ui::widgetClass ui;
	AlgorithmClass ALGO;
	WebsocketServer server;
};
