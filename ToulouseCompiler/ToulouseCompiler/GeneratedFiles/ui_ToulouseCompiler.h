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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionPoints;
    QAction *actionLines;
    QAction *actiontriangles;
    QAction *actionRender;
    QAction *actionModeMarterial;
    QAction *actionModeTexture;
    QAction *actionUniform_Table;
    QAction *actionPeon;
    QAction *actioncopa;
    QAction *actionjoy;
    QAction *actionEnglish;
    QAction *actionEspanol;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *separador;
    QVBoxLayout *central;
    QGridLayout *gridLayout;
    QVBoxLayout *OpenglLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *widgetLayout;
    QWidget *openglwidget;
    QHBoxLayout *opengl_layout;
    QVBoxLayout *EditorLayout;
    QTabWidget *tabWidget;
    QWidget *VertexS;
    QWidget *FragmentS;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *OutPutLayout;
    QPlainTextEdit *OutPut;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTools;
    QMenu *menuLanguage;
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
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        MainWindowClass->setFont(font);
        actionNew = new QAction(MainWindowClass);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/Resources/img/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindowClass);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/Resources/img/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MainWindowClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/Resources/img/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionSave_As = new QAction(MainWindowClass);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/Resources/img/saveAs.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon3);
        actionPoints = new QAction(MainWindowClass);
        actionPoints->setObjectName(QString::fromUtf8("actionPoints"));
        actionPoints->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/Resources/img/points.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/img/Resources/img/points_activate.png"), QSize(), QIcon::Normal, QIcon::On);
        actionPoints->setIcon(icon4);
        actionLines = new QAction(MainWindowClass);
        actionLines->setObjectName(QString::fromUtf8("actionLines"));
        actionLines->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/Resources/img/line.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QString::fromUtf8(":/img/Resources/img/line_activate.png"), QSize(), QIcon::Normal, QIcon::On);
        actionLines->setIcon(icon5);
        actiontriangles = new QAction(MainWindowClass);
        actiontriangles->setObjectName(QString::fromUtf8("actiontriangles"));
        actiontriangles->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/Resources/img/triangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QString::fromUtf8(":/img/Resources/img/triangle_activate.png"), QSize(), QIcon::Normal, QIcon::On);
        actiontriangles->setIcon(icon6);
        actionRender = new QAction(MainWindowClass);
        actionRender->setObjectName(QString::fromUtf8("actionRender"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/Resources/img/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRender->setIcon(icon7);
        actionModeMarterial = new QAction(MainWindowClass);
        actionModeMarterial->setObjectName(QString::fromUtf8("actionModeMarterial"));
        actionModeMarterial->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/Resources/img/material.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon8.addFile(QString::fromUtf8(":/img/Resources/img/Material_activate.png"), QSize(), QIcon::Normal, QIcon::On);
        actionModeMarterial->setIcon(icon8);
        actionModeTexture = new QAction(MainWindowClass);
        actionModeTexture->setObjectName(QString::fromUtf8("actionModeTexture"));
        actionModeTexture->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/img/Resources/img/textures.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon9.addFile(QString::fromUtf8(":/img/Resources/img/textures_activate.png"), QSize(), QIcon::Normal, QIcon::On);
        actionModeTexture->setIcon(icon9);
        actionUniform_Table = new QAction(MainWindowClass);
        actionUniform_Table->setObjectName(QString::fromUtf8("actionUniform_Table"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/img/Resources/img/loupe.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUniform_Table->setIcon(icon10);
        actionUniform_Table->setFont(font);
        actionUniform_Table->setIconVisibleInMenu(true);
        actionPeon = new QAction(MainWindowClass);
        actionPeon->setObjectName(QString::fromUtf8("actionPeon"));
        actionPeon->setCheckable(true);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/img/Resources/img/pawn.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon11.addFile(QString::fromUtf8(":/img/Resources/img/Active pawn.png"), QSize(), QIcon::Normal, QIcon::On);
        actionPeon->setIcon(icon11);
        actioncopa = new QAction(MainWindowClass);
        actioncopa->setObjectName(QString::fromUtf8("actioncopa"));
        actioncopa->setCheckable(true);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/img/Resources/img/wine.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon12.addFile(QString::fromUtf8(":/img/Resources/img/wine_activate.png"), QSize(), QIcon::Normal, QIcon::On);
        actioncopa->setIcon(icon12);
        actionjoy = new QAction(MainWindowClass);
        actionjoy->setObjectName(QString::fromUtf8("actionjoy"));
        actionjoy->setCheckable(true);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/img/Resources/img/circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon13.addFile(QString::fromUtf8(":/img/Resources/img/circle_activate.png"), QSize(), QIcon::Normal, QIcon::On);
        actionjoy->setIcon(icon13);
        actionEnglish = new QAction(MainWindowClass);
        actionEnglish->setObjectName(QString::fromUtf8("actionEnglish"));
        actionEnglish->setCheckable(true);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/translattions/Languages/en.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnglish->setIcon(icon14);
        actionEspanol = new QAction(MainWindowClass);
        actionEspanol->setObjectName(QString::fromUtf8("actionEspanol"));
        actionEspanol->setCheckable(true);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/translattions/Languages/es.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEspanol->setIcon(icon15);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_5 = new QVBoxLayout(centralWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        separador = new QHBoxLayout();
        separador->setSpacing(6);
        separador->setObjectName(QString::fromUtf8("separador"));

        verticalLayout_5->addLayout(separador);

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
        openglwidget->setMouseTracking(false);
        opengl_layout = new QHBoxLayout(openglwidget);
        opengl_layout->setSpacing(0);
        opengl_layout->setContentsMargins(11, 11, 11, 11);
        opengl_layout->setObjectName(QString::fromUtf8("opengl_layout"));
        opengl_layout->setContentsMargins(0, 0, 0, 0);

        widgetLayout->addWidget(openglwidget);


        verticalLayout->addLayout(widgetLayout);


        horizontalLayout->addLayout(verticalLayout);


        OpenglLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(OpenglLayout, 1, 1, 1, 1);

        EditorLayout = new QVBoxLayout();
        EditorLayout->setSpacing(6);
        EditorLayout->setObjectName(QString::fromUtf8("EditorLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        tabWidget->setFont(font1);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        VertexS = new QWidget();
        VertexS->setObjectName(QString::fromUtf8("VertexS"));
        tabWidget->addTab(VertexS, QString());
        FragmentS = new QWidget();
        FragmentS->setObjectName(QString::fromUtf8("FragmentS"));
        tabWidget->addTab(FragmentS, QString());

        EditorLayout->addWidget(tabWidget);


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
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(OutPut->sizePolicy().hasHeightForWidth());
        OutPut->setSizePolicy(sizePolicy2);

        OutPutLayout->addWidget(OutPut);


        verticalLayout_5->addLayout(OutPutLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);


        verticalLayout_5->addLayout(horizontalLayout_2);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1113, 21));
        menuBar->setFont(font);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuTools->setFont(font);
        menuLanguage = new QMenu(menuBar);
        menuLanguage->setObjectName(QString::fromUtf8("menuLanguage"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuLanguage->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionNew);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuTools->addAction(actionUniform_Table);
        menuLanguage->addAction(actionEspanol);
        menuLanguage->addAction(actionEnglish);
        mainToolBar->addAction(actionSave);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionPoints);
        mainToolBar->addAction(actionLines);
        mainToolBar->addAction(actiontriangles);
        mainToolBar->addAction(actionModeMarterial);
        mainToolBar->addAction(actionModeTexture);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionPeon);
        mainToolBar->addAction(actioncopa);
        mainToolBar->addAction(actionjoy);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionRender);

        retranslateUi(MainWindowClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "ToulouseCompiler", nullptr));
        actionNew->setText(QApplication::translate("MainWindowClass", "New", nullptr));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindowClass", "This create two new shader program", nullptr));
#endif // QT_NO_TOOLTIP
        actionOpen->setText(QApplication::translate("MainWindowClass", "Open", nullptr));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindowClass", "This is for open a shader program", nullptr));
#endif // QT_NO_TOOLTIP
        actionSave->setText(QApplication::translate("MainWindowClass", "Save", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindowClass", "For save the actual shader program", nullptr));
#endif // QT_NO_TOOLTIP
        actionSave_As->setText(QApplication::translate("MainWindowClass", "Save As", nullptr));
        actionPoints->setText(QApplication::translate("MainWindowClass", "Mode Points", nullptr));
#ifndef QT_NO_TOOLTIP
        actionPoints->setToolTip(QApplication::translate("MainWindowClass", "<html><head/><body><p>This activate the<span style=\" font-weight:600;\"> IBO</span> in mode points</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        actionLines->setText(QApplication::translate("MainWindowClass", "Mode Lines", nullptr));
#ifndef QT_NO_TOOLTIP
        actionLines->setToolTip(QApplication::translate("MainWindowClass", "<html><head/><body><p>This activate the<span style=\" font-weight:600;\"> IBO</span> in mode lines</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        actiontriangles->setText(QApplication::translate("MainWindowClass", "Mode triangles", nullptr));
#ifndef QT_NO_TOOLTIP
        actiontriangles->setToolTip(QApplication::translate("MainWindowClass", "<html><head/><body><p>This activate the<span style=\" font-weight:600;\"> IBO</span> in mode triangles</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        actionRender->setText(QApplication::translate("MainWindowClass", "Render", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRender->setToolTip(QApplication::translate("MainWindowClass", "<html><head/><body><p>this is for<span style=\" font-weight:600;\"> execute</span> the shader program</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        actionModeMarterial->setText(QApplication::translate("MainWindowClass", "ModeMarterial", nullptr));
#ifndef QT_NO_TOOLTIP
        actionModeMarterial->setToolTip(QApplication::translate("MainWindowClass", "<html><head/><body><p>this activate the <span style=\" font-weight:600;\">uniforms</span> for material</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        actionModeTexture->setText(QApplication::translate("MainWindowClass", "ModeTexture", nullptr));
#ifndef QT_NO_TOOLTIP
        actionModeTexture->setToolTip(QApplication::translate("MainWindowClass", "<html><head/><body><p>this activate the <span style=\" font-weight:600;\">uniforms</span> for textures</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        actionUniform_Table->setText(QApplication::translate("MainWindowClass", "Uniform Table", nullptr));
#ifndef QT_NO_TOOLTIP
        actionUniform_Table->setToolTip(QApplication::translate("MainWindowClass", "this show the table for the uniforms", nullptr));
#endif // QT_NO_TOOLTIP
        actionPeon->setText(QApplication::translate("MainWindowClass", "Peon", nullptr));
#ifndef QT_NO_TOOLTIP
        actionPeon->setToolTip(QApplication::translate("MainWindowClass", "<html><head/><body><p>this change the <span style=\" font-weight:600;\">object</span> to pawn</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        actioncopa->setText(QApplication::translate("MainWindowClass", "copa", nullptr));
#ifndef QT_NO_TOOLTIP
        actioncopa->setToolTip(QApplication::translate("MainWindowClass", "<html><head/><body><p>this change the<span style=\" font-weight:600;\"> object</span> to cup</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        actionjoy->setText(QApplication::translate("MainWindowClass", "joy", nullptr));
#ifndef QT_NO_TOOLTIP
        actionjoy->setToolTip(QApplication::translate("MainWindowClass", "<html><head/><body><p>this change the<span style=\" font-weight:600;\"> object</span> to joy</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        actionEnglish->setText(QApplication::translate("MainWindowClass", "English", nullptr));
        actionEspanol->setText(QApplication::translate("MainWindowClass", "Spanish", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(VertexS), QApplication::translate("MainWindowClass", "Vertex Shader", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(FragmentS), QApplication::translate("MainWindowClass", "Fragment Shader", nullptr));
        OutPut->setPlainText(QString());
        label->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p><span style=\" font-weight:600;\">Author:</span>  Antonio Jes\303\272s Viso S\303\241nchez</p></body></html>", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", nullptr));
        menuTools->setTitle(QApplication::translate("MainWindowClass", "Tools", nullptr));
        menuLanguage->setTitle(QApplication::translate("MainWindowClass", "Language", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOULOUSECOMPILER_H
