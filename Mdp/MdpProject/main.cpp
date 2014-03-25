#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	printf("123\n");

    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
