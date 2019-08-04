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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QVBoxLayout *layoutVerticalOpengl;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QWidget *openglwidget;
    QHBoxLayout *opengl_layout;
    QTableView *tableView;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_4;
    QPushButton *changePage;
    QHBoxLayout *horizontalLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *VertexShader;
    QPushButton *pushButton_2;
    QWidget *FragmentShader;
    QRadioButton *radioButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(1071, 697);
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
        layoutVerticalOpengl = new QVBoxLayout();
        layoutVerticalOpengl->setSpacing(6);
        layoutVerticalOpengl->setObjectName(QString::fromUtf8("layoutVerticalOpengl"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        openglwidget = new QWidget(centralWidget);
        openglwidget->setObjectName(QString::fromUtf8("openglwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(openglwidget->sizePolicy().hasHeightForWidth());
        openglwidget->setSizePolicy(sizePolicy1);
        openglwidget->setMaximumSize(QSize(600, 480));
        opengl_layout = new QHBoxLayout(openglwidget);
        opengl_layout->setSpacing(0);
        opengl_layout->setContentsMargins(11, 11, 11, 11);
        opengl_layout->setObjectName(QString::fromUtf8("opengl_layout"));
        opengl_layout->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(openglwidget);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setMinimumSize(QSize(100, 10));
        pushButton->setMaximumSize(QSize(100, 20));

        verticalLayout->addWidget(pushButton, 0, Qt::AlignHCenter);


        horizontalLayout->addLayout(verticalLayout);


        layoutVerticalOpengl->addLayout(horizontalLayout);


        gridLayout->addLayout(layoutVerticalOpengl, 0, 2, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        changePage = new QPushButton(centralWidget);
        changePage->setObjectName(QString::fromUtf8("changePage"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(changePage->sizePolicy().hasHeightForWidth());
        changePage->setSizePolicy(sizePolicy3);
        changePage->setMinimumSize(QSize(0, 23));
        changePage->setStyleSheet(QString::fromUtf8("QPushButton#evilButton {\n"
"    background-color: red;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}"));
        changePage->setAutoDefault(false);

        verticalLayout_4->addWidget(changePage, 0, Qt::AlignRight|Qt::AlignVCenter);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        VertexShader = new QWidget();
        VertexShader->setObjectName(QString::fromUtf8("VertexShader"));
        pushButton_2 = new QPushButton(VertexShader);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 230, 75, 23));
        stackedWidget->addWidget(VertexShader);
        FragmentShader = new QWidget();
        FragmentShader->setObjectName(QString::fromUtf8("FragmentShader"));
        radioButton = new QRadioButton(FragmentShader);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(230, 190, 82, 17));
        stackedWidget->addWidget(FragmentShader);

        horizontalLayout_4->addWidget(stackedWidget);


        verticalLayout_4->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1071, 21));
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
        pushButton->setText(QApplication::translate("MainWindowClass", "Render", nullptr));
        changePage->setText(QApplication::translate("MainWindowClass", "Fragment Shader", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindowClass", "PushButton", nullptr));
        radioButton->setText(QApplication::translate("MainWindowClass", "RadioButton", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOULOUSECOMPILER_H
