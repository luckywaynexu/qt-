#include "widget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	widget w;
	//���ô��ڱ���
	w.setWindowTitle(QStringLiteral("����齱"));
	w.show();
	return a.exec();
}
