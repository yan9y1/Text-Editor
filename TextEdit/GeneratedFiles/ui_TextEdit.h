/********************************************************************************
** Form generated from reading UI file 'TextEdit.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTEDIT_H
#define UI_TEXTEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextEditClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TextEditClass)
    {
        if (TextEditClass->objectName().isEmpty())
            TextEditClass->setObjectName(QStringLiteral("TextEditClass"));
        TextEditClass->resize(600, 400);
        menuBar = new QMenuBar(TextEditClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        TextEditClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TextEditClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TextEditClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TextEditClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TextEditClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TextEditClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TextEditClass->setStatusBar(statusBar);

        retranslateUi(TextEditClass);

        QMetaObject::connectSlotsByName(TextEditClass);
    } // setupUi

    void retranslateUi(QMainWindow *TextEditClass)
    {
        TextEditClass->setWindowTitle(QApplication::translate("TextEditClass", "TextEdit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TextEditClass: public Ui_TextEditClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTEDIT_H
