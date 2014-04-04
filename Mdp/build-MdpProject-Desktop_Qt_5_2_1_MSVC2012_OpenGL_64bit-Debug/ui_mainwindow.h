/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QProgressBar *progressBar;
    QLabel *label_2;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(548, 458);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 10, 161, 51));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI Semibold"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(210, 290, 118, 23));
        progressBar->setValue(24);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(240, 60, 51, 21));
        label_2->setFont(font);
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(120, 100, 271, 22));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 220, 121, 31));
        pushButton->setFont(font);
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(200, 180, 121, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 140, 161, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 548, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Holiday Helper", 0));
        label->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\261\320\270\321\200\320\260\320\265\320\274 \320\276\321\202\320\264\321\213\321\205", 0));
        label_2->setText(QApplication::translate("MainWindow", "\320\245\320\276\321\207\321\203: ", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "\320\222\320\260\320\273\321\217\321\202\321\214\321\201\321\217 \320\275\320\260 \320\277\320\273\321\217\320\266\320\265", 0)
         << QApplication::translate("MainWindow", "\320\236\321\201\320\274\320\260\321\202\321\200\320\270\320\262\320\260\321\202\321\214 \320\264\320\276\321\201\321\202\320\276\320\277\321\200\320\270\320\274\320\265\321\207\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\320\270", 0)
         << QApplication::translate("MainWindow", "\320\232\320\260\321\202\320\260\321\202\321\214\321\201\321\217 \320\275\320\260 \320\273\321\213\320\266\320\260\321\205 \320\270 \321\201\320\275\320\276\321\203\320\261\320\276\321\200\320\264\320\265", 0)
         << QApplication::translate("MainWindow", "\320\227\320\260\320\275\320\270\320\274\320\260\321\202\321\214\321\201\321\217 \321\210\320\276\320\277\320\270\320\275\320\263\320\276\320\274", 0)
         << QApplication::translate("MainWindow", "\320\224\321\213\321\210\320\260\321\202\321\214 \321\200\320\276\320\274\320\260\320\275\321\202\320\270\320\272\320\276\320\271", 0)
         << QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\320\273\320\260\320\261\320\273\321\217\321\202\321\214\321\201\321\217 \320\262 \321\201\320\277\320\260", 0)
         << QApplication::translate("MainWindow", "\320\227\320\260\320\275\320\270\320\274\320\260\321\202\321\214\321\201\321\217 \320\264\320\260\320\271\320\262\320\270\320\275\320\263\320\276\320\274", 0)
         << QApplication::translate("MainWindow", "\320\232\320\260\321\202\320\260\321\202\321\214\321\201\321\217 \320\275\320\260 \321\201\321\221\321\200\321\204\320\265", 0)
         << QApplication::translate("MainWindow", "\320\233\320\276\320\262\320\270\321\202\321\214 \320\262\320\265\321\202\320\265\321\200 \320\275\320\260 \320\272\320\260\320\271\321\202\320\265 \320\270 \320\262\320\270\320\275\320\264\321\201\321\221\321\200\321\204\320\265", 0)
         << QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\276\321\200\321\217\321\202\321\214 \320\264\320\270\320\272\321\203\321\216 \320\277\321\200\320\270\321\200\320\276\320\264\321\203", 0)
         << QApplication::translate("MainWindow", "\320\236\321\202\320\264\321\213\321\205\320\260\321\202\321\214 \320\262\321\201\320\265\320\271 \321\201\320\265\320\274\321\214\321\221\320\271", 0)
        );
        pushButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "\320\220\320\262\321\201\321\202\321\200\320\260\320\273\320\270\321\217", 0)
         << QApplication::translate("MainWindow", "\320\220\320\275\320\263\320\273\320\270\321\217", 0)
         << QApplication::translate("MainWindow", "\320\220\320\274\320\265\321\200\320\270\320\272\320\260", 0)
         << QApplication::translate("MainWindow", "\320\221\320\265\320\273\320\260\321\200\321\203\321\201\321\214", 0)
         << QApplication::translate("MainWindow", "\320\221\320\276\320\273\320\263\320\260\321\200\320\270\321\217", 0)
         << QApplication::translate("MainWindow", "\320\223\320\265\321\200\320\274\320\260\320\275\320\270\321\217", 0)
         << QApplication::translate("MainWindow", "\320\223\321\200\320\265\321\206\320\270\321\217", 0)
         << QApplication::translate("MainWindow", "\320\230\321\201\320\277\320\260\320\275\320\270\321\217", 0)
         << QApplication::translate("MainWindow", "\320\232\320\260\320\267\320\260\321\205\321\201\321\202\320\260\320\275", 0)
         << QApplication::translate("MainWindow", "\320\235\320\276\321\200\320\262\320\265\320\263\320\270\321\217", 0)
         << QApplication::translate("MainWindow", "\320\240\320\276\321\201\321\201\320\270\321\217", 0)
        );
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">\320\257 \320\275\320\260\321\205\320\276\320\266\321\203\321\201\321\214 \320\262 \321\201\321\202\321\200\320\260\320\275\320\265:</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
