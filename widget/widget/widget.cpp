#include "widget.h"
#include <QTimer>
#include <QVector>
widget::widget(QWidget *parent)
	: QWidget(parent)
{
	
	server.ServerStart();

	ui.setupUi(this);
	//抽取范围初始值
	//ui.label_2->setFont(QFont("Timers",20,QFont::Bold));
	//ui.label_2->setText("*");
}

void widget::on_pushButton_clicked()//开始按钮响应的槽
{
	QTimer* timer1 = new QTimer(this);//两个定时器
	QTimer* timer2 = new QTimer(this);
//	connect(timer1,SIGNAL(timeout()),this,SLOT(numberChangeSlots()));
	
	connect(timer1, SIGNAL(timeout()), this, SLOT(numberChangeSlot()));
	connect(timer2, SIGNAL(timeout()), timer1, SLOT(stop()));
	timer1->start(80);
	timer2->start(2000);
	QString temp=ui.lineEdit_7->text();
	server.GetText(temp);
}

void widget::numberChangeSlot()
{
	//随机产生一组组合数：
	//前五位数
	QVector<int> LotteryFrontRange;
	QVector<int> lotteryFrontValue;
	int numMax = 35;
	int SelectNUM = 5;
	for (int i = 0; i < numMax; i++)
		LotteryFrontRange.append(i + 1);
	
	ALGO.Combination(lotteryFrontValue,LotteryFrontRange,SelectNUM);
	ui.lineEdit->setText(QString::number(lotteryFrontValue[0]));
	ui.lineEdit_2->setText(QString::number(lotteryFrontValue[1]));
	ui.lineEdit_3->setText(QString::number(lotteryFrontValue[2]));
	ui.lineEdit_4->setText(QString::number(lotteryFrontValue[3]));
	ui.lineEdit_5->setText(QString::number(lotteryFrontValue[4]));
	//后两位数
	QVector<int> LotteryBackRange;
	QVector<int> lotteryBackValue;
	numMax = 12;
	SelectNUM = 2;
	for (int i = 0; i < numMax; i++)
		LotteryBackRange.append(i + 1);
	ALGO.Combination(lotteryBackValue, LotteryBackRange, SelectNUM);
	ui.lineEdit_6->setText(QString::number(lotteryBackValue[0]));
	ui.lineEdit_7->setText(QString::number(lotteryBackValue[1]));
	////产生[num,num2]的随机数
	//QString num1 = ui.lineEdit_2->text();
	//int a=num1.toInt();
	//int b;
	//QString num2=ui.lineEdit->text();
	//if ((num2.toInt() - a) == 0)
	//	 b = 0;
	//else
	//	 b =qrand()%(num2.toInt()-a);
	//ui.label_2->setText(QString::number(b+a));

}
