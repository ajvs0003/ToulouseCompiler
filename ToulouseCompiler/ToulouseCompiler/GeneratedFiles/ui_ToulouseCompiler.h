/********************************************************************************
** Form generated from reading UI file 'ToulouseCompiler.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOULOUSECOMPILER_H
#define UI_TOULOUSECOMPILER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionSave_2;
    QAction *actionSave_As;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QStackedWidget *stackedWidget;
    QWidget *VertexShader;
    QLabel *label;
    QWidget *FragmentShader;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout;
    QWidget *openglwidget;
    QHBoxLayout *opengl_layout;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(1122, 782);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindowClass->sizePolicy().hasHeightForWidth());
        MainWindowClass->setSizePolicy(sizePolicy);
        actionSave = new QAction(MainWindowClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionLoad = new QAction(MainWindowClass);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionSave_2 = new QAction(MainWindowClass);
        actionSave_2->setObjectName(QString::fromUtf8("actionSave_2"));
        actionSave_As = new QAction(MainWindowClass);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(tableView, 1, 2, 1, 1);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        VertexShader = new QWidget();
        VertexShader->setObjectName(QString::fromUtf8("VertexShader"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(VertexShader->sizePolicy().hasHeightForWidth());
        VertexShader->setSizePolicy(sizePolicy2);
        label = new QLabel(VertexShader);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 81, 21));
        stackedWidget->addWidget(VertexShader);
        FragmentShader = new QWidget();
        FragmentShader->setObjectName(QString::fromUtf8("FragmentShader"));
        label_2 = new QLabel(FragmentShader);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 101, 16));
        stackedWidget->addWidget(FragmentShader);

        gridLayout->addWidget(stackedWidget, 0, 1, 2, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        openglwidget = new QWidget(centralWidget);
        openglwidget->setObjectName(QString::fromUtf8("openglwidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(openglwidget->sizePolicy().hasHeightForWidth());
        openglwidget->setSizePolicy(sizePolicy3);
        openglwidget->setMaximumSize(QSize(480, 480));
        opengl_layout = new QHBoxLayout(openglwidget);
        opengl_layout->setSpacing(0);
        opengl_layout->setContentsMargins(11, 11, 11, 11);
        opengl_layout->setObjectName(QString::fromUtf8("opengl_layout"));
        opengl_layout->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(openglwidget);


        verticalLayout_8->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_8, 0, 2, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy4);
        pushButton->setMinimumSize(QSize(100, 10));
        pushButton->setMaximumSize(QSize(100, 20));

        gridLayout->addWidget(pushButton, 2, 2, 1, 1, Qt::AlignHCenter);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1122, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionSave_2);
        menuFile->addAction(actionSave_As);

        retranslateUi(MainWindowClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "ToulouseCompiler", nullptr));
        actionSave->setText(QApplication::translate("MainWindowClass", "New", nullptr));
        actionLoad->setText(QApplication::translate("MainWindowClass", "Open", nullptr));
        actionSave_2->setText(QApplication::translate("MainWindowClass", "Save", nullptr));
        actionSave_As->setText(QApplication::translate("MainWindowClass", "Save As", nullptr));
        label->setText(QApplication::translate("MainWindowClass", "Vertex Shader", nullptr));
        label_2->setText(QApplication::translate("MainWindowClass", "Fragment Shader", nullptr));
        pushButton->setText(QApplication::translate("MainWindowClass", "Render", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOULOUSECOMPILER_H
