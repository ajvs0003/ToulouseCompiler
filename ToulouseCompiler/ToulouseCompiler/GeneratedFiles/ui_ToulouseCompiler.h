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
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QColumnView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
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
    QAction *actionPoints;
    QAction *actionLines;
    QAction *actiontriangles;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *barraHerramientas;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *central;
    QGridLayout *gridLayout;
    QVBoxLayout *OpenglLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *widgetLayout;
    QWidget *openglwidget;
    QHBoxLayout *opengl_layout;
    QHBoxLayout *uniformLayouts;
    QColumnView *columnView;
    QVBoxLayout *EditorLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *vistaActivada;
    QPushButton *changePage;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *VertexShader;
    QVBoxLayout *vertexLayout;
    QWidget *FragmentShader;
    QVBoxLayout *FragmentLayout;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *OutPutLayout;
    QPlainTextEdit *OutPut;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(1113, 891);
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/Resources/img/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_2->setIcon(icon);
        actionSave_As = new QAction(MainWindowClass);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionPoints = new QAction(MainWindowClass);
        actionPoints->setObjectName(QString::fromUtf8("actionPoints"));
        actionPoints->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/Resources/img/points.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPoints->setIcon(icon1);
        actionLines = new QAction(MainWindowClass);
        actionLines->setObjectName(QString::fromUtf8("actionLines"));
        actionLines->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/Resources/img/line.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLines->setIcon(icon2);
        actiontriangles = new QAction(MainWindowClass);
        actiontriangles->setObjectName(QString::fromUtf8("actiontriangles"));
        actiontriangles->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/Resources/img/triangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actiontriangles->setIcon(icon3);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_5 = new QVBoxLayout(centralWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        barraHerramientas = new QHBoxLayout();
        barraHerramientas->setSpacing(6);
        barraHerramientas->setObjectName(QString::fromUtf8("barraHerramientas"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));

        barraHerramientas->addLayout(horizontalLayout_3);


        verticalLayout_5->addLayout(barraHerramientas);

        central = new QVBoxLayout();
        central->setSpacing(6);
        central->setObjectName(QString::fromUtf8("central"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(6);
        OpenglLayout = new QVBoxLayout();
        OpenglLayout->setSpacing(6);
        OpenglLayout->setObjectName(QString::fromUtf8("OpenglLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widgetLayout = new QHBoxLayout();
        widgetLayout->setSpacing(6);
        widgetLayout->setObjectName(QString::fromUtf8("widgetLayout"));
        openglwidget = new QWidget(centralWidget);
        openglwidget->setObjectName(QString::fromUtf8("openglwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(openglwidget->sizePolicy().hasHeightForWidth());
        openglwidget->setSizePolicy(sizePolicy1);
        openglwidget->setMaximumSize(QSize(16777215, 16777215));
        opengl_layout = new QHBoxLayout(openglwidget);
        opengl_layout->setSpacing(0);
        opengl_layout->setContentsMargins(11, 11, 11, 11);
        opengl_layout->setObjectName(QString::fromUtf8("opengl_layout"));
        opengl_layout->setContentsMargins(0, 0, 0, 0);

        widgetLayout->addWidget(openglwidget);


        verticalLayout->addLayout(widgetLayout);

        uniformLayouts = new QHBoxLayout();
        uniformLayouts->setSpacing(6);
        uniformLayouts->setObjectName(QString::fromUtf8("uniformLayouts"));
        columnView = new QColumnView(centralWidget);
        columnView->setObjectName(QString::fromUtf8("columnView"));
        sizePolicy1.setHeightForWidth(columnView->sizePolicy().hasHeightForWidth());
        columnView->setSizePolicy(sizePolicy1);

        uniformLayouts->addWidget(columnView);


        verticalLayout->addLayout(uniformLayouts);


        horizontalLayout->addLayout(verticalLayout);


        OpenglLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(OpenglLayout, 1, 1, 1, 1);

        EditorLayout = new QVBoxLayout();
        EditorLayout->setSpacing(6);
        EditorLayout->setObjectName(QString::fromUtf8("EditorLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        vistaActivada = new QLabel(centralWidget);
        vistaActivada->setObjectName(QString::fromUtf8("vistaActivada"));
        vistaActivada->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setBold(true);
        font.setWeight(75);
        vistaActivada->setFont(font);

        horizontalLayout_2->addWidget(vistaActivada);

        changePage = new QPushButton(centralWidget);
        changePage->setObjectName(QString::fromUtf8("changePage"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(changePage->sizePolicy().hasHeightForWidth());
        changePage->setSizePolicy(sizePolicy2);
        changePage->setMinimumSize(QSize(0, 23));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        changePage->setFont(font1);
        changePage->setAutoFillBackground(false);
        changePage->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/Resources/img/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        changePage->setIcon(icon4);
        changePage->setAutoDefault(false);

        horizontalLayout_2->addWidget(changePage, 0, Qt::AlignRight|Qt::AlignVCenter);


        EditorLayout->addLayout(horizontalLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        VertexShader = new QWidget();
        VertexShader->setObjectName(QString::fromUtf8("VertexShader"));
        sizePolicy1.setHeightForWidth(VertexShader->sizePolicy().hasHeightForWidth());
        VertexShader->setSizePolicy(sizePolicy1);
        vertexLayout = new QVBoxLayout(VertexShader);
        vertexLayout->setSpacing(6);
        vertexLayout->setContentsMargins(11, 11, 11, 11);
        vertexLayout->setObjectName(QString::fromUtf8("vertexLayout"));
        stackedWidget->addWidget(VertexShader);
        FragmentShader = new QWidget();
        FragmentShader->setObjectName(QString::fromUtf8("FragmentShader"));
        FragmentLayout = new QVBoxLayout(FragmentShader);
        FragmentLayout->setSpacing(6);
        FragmentLayout->setContentsMargins(11, 11, 11, 11);
        FragmentLayout->setObjectName(QString::fromUtf8("FragmentLayout"));
        stackedWidget->addWidget(FragmentShader);

        horizontalLayout_4->addWidget(stackedWidget);


        verticalLayout_2->addLayout(horizontalLayout_4);


        EditorLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(EditorLayout, 1, 0, 1, 1);


        central->addLayout(gridLayout);


        verticalLayout_5->addLayout(central);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_5->addItem(verticalSpacer_2);

        OutPutLayout = new QVBoxLayout();
        OutPutLayout->setSpacing(6);
        OutPutLayout->setObjectName(QString::fromUtf8("OutPutLayout"));
        OutPut = new QPlainTextEdit(centralWidget);
        OutPut->setObjectName(QString::fromUtf8("OutPut"));
        sizePolicy2.setHeightForWidth(OutPut->sizePolicy().hasHeightForWidth());
        OutPut->setSizePolicy(sizePolicy2);

        OutPutLayout->addWidget(OutPut);


        verticalLayout_5->addLayout(OutPutLayout);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1113, 21));
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
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_2);
        menuFile->addAction(actionSave_As);
        mainToolBar->addAction(actionSave_2);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionPoints);
        mainToolBar->addAction(actionLines);
        mainToolBar->addAction(actiontriangles);

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
        actionPoints->setText(QApplication::translate("MainWindowClass", "Points", nullptr));
        actionLines->setText(QApplication::translate("MainWindowClass", "Lines", nullptr));
        actiontriangles->setText(QApplication::translate("MainWindowClass", "triangles", nullptr));
        vistaActivada->setText(QApplication::translate("MainWindowClass", "Vertex Shader", nullptr));
        changePage->setText(QString());
        OutPut->setPlainText(QString());
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOULOUSECOMPILER_H
