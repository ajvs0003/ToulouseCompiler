/********************************************************************************
** Form generated from reading UI file 'tableUniforms.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
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
    QPushButton *addUniform;
    QHBoxLayout *horizontalLayout;
    QTableWidget *table;

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

        addUniform = new QPushButton(tableUniforms);
        addUniform->setObjectName(QString::fromUtf8("addUniform"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/Resources/img/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addUniform->setIcon(icon);

        horizontalLayout_2->addWidget(addUniform, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        table = new QTableWidget(tableUniforms);
        table->setObjectName(QString::fromUtf8("table"));
        table->setFont(font);

        horizontalLayout->addWidget(table);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(tableUniforms);

        QMetaObject::connectSlotsByName(tableUniforms);
    } // setupUi

    void retranslateUi(QWidget *tableUniforms)
    {
        tableUniforms->setWindowTitle(QApplication::translate("tableUniforms", "tableUniforms", nullptr));
        addUniform->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class tableUniforms: public Ui_tableUniforms {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEUNIFORMS_H
