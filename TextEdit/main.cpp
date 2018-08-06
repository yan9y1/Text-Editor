#include "TextEdit.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TextEdit w;
	w.show();
	return a.exec();
}
