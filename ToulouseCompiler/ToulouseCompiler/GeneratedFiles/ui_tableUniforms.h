/********************************************************************************
** Form generated from reading UI file 'tableUniforms.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEUNIFORMS_H
#define UI_TABLEUNIFORMS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tableUniforms
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *addUniform;
    QPushButton *help;
    QHBoxLayout *horizontalLayout;
    QTableWidget *table;
    QVBoxLayout *verticalLayout_4;
    QPushButton *aceptar;

    void setupUi(QWidget *tableUniforms)
    {
        if (tableUniforms->objectName().isEmpty())
            tableUniforms->setObjectName(QString::fromUtf8("tableUniforms"));
        tableUniforms->resize(895, 523);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        tableUniforms->setFont(font);
        verticalLayout_2 = new QVBoxLayout(tableUniforms);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));

        horizontalLayout_2->addLayout(verticalLayout_3);

        addUniform = new QPushButton(tableUniforms);
        addUniform->setObjectName(QString::fromUtf8("addUniform"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/Resources/img/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addUniform->setIcon(icon);

        horizontalLayout_2->addWidget(addUniform, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        help = new QPushButton(tableUniforms);
        help->setObjectName(QString::fromUtf8("help"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(help->sizePolicy().hasHeightForWidth());
        help->setSizePolicy(sizePolicy);
        help->setMaximumSize(QSize(30, 40));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/Resources/img/information.png"), QSize(), QIcon::Normal, QIcon::Off);
        help->setIcon(icon1);

        horizontalLayout_2->addWidget(help);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        table = new QTableWidget(tableUniforms);
        table->setObjectName(QString::fromUtf8("table"));
        table->setFont(font);
        table->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(table);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        aceptar = new QPushButton(tableUniforms);
        aceptar->setObjectName(QString::fromUtf8("aceptar"));

        verticalLayout_4->addWidget(aceptar, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout_2->addLayout(verticalLayout_4);


        retranslateUi(tableUniforms);

        QMetaObject::connectSlotsByName(tableUniforms);
    } // setupUi

    void retranslateUi(QWidget *tableUniforms)
    {
        tableUniforms->setWindowTitle(QApplication::translate("tableUniforms", "tableUniforms", nullptr));
        addUniform->setText(QString());
        help->setText(QString());
        aceptar->setText(QApplication::translate("tableUniforms", "Accept", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tableUniforms: public Ui_tableUniforms {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEUNIFORMS_H
