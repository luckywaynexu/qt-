#include "widget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	widget w;
	//设置窗口标题
	w.setWindowTitle(QStringLiteral("随机抽奖"));
	w.show();
	return a.exec();
}
