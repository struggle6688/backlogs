/********************************************************************************
** Form generated from reading UI file 'backlogs.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKLOGS_H
#define UI_BACKLOGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_backlogs
{
public:
    QAction *actionClear;
    QAction *actionIntroduction;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuEdit;
    QMenu *menuHelp;

    void setupUi(QMainWindow *backlogs)
    {
        if (backlogs->objectName().isEmpty())
            backlogs->setObjectName(QStringLiteral("backlogs"));
        backlogs->resize(454, 598);
        actionClear = new QAction(backlogs);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        actionIntroduction = new QAction(backlogs);
        actionIntroduction->setObjectName(QStringLiteral("actionIntroduction"));
        centralWidget = new QWidget(backlogs);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        backlogs->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(backlogs);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        backlogs->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(backlogs);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        backlogs->setStatusBar(statusBar);
        menuBar = new QMenuBar(backlogs);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 454, 23));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        backlogs->setMenuBar(menuBar);

        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuEdit->addAction(actionClear);
        menuHelp->addAction(actionIntroduction);

        retranslateUi(backlogs);

        QMetaObject::connectSlotsByName(backlogs);
    } // setupUi

    void retranslateUi(QMainWindow *backlogs)
    {
        backlogs->setWindowTitle(QApplication::translate("backlogs", "backlogs", 0));
        actionClear->setText(QApplication::translate("backlogs", "clear", 0));
        actionIntroduction->setText(QApplication::translate("backlogs", "\350\257\264\346\230\216", 0));
        menuEdit->setTitle(QApplication::translate("backlogs", "\347\274\226\350\276\221", 0));
        menuHelp->setTitle(QApplication::translate("backlogs", "\345\270\256\345\212\251", 0));
    } // retranslateUi

};

namespace Ui {
    class backlogs: public Ui_backlogs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKLOGS_H
