
#include <QApplication>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

    MainWindow mainwindow;

    mainwindow.resize(500, 300);
    mainwindow.show();

	return app.exec();
}