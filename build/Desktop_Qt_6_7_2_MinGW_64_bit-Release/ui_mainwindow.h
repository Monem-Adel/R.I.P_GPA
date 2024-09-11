/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *gpaTermGB;
    QWidget *layoutWidget;
    QHBoxLayout *HL_top;
    QVBoxLayout *VL_obtion;
    QLabel *whatLbl;
    QVBoxLayout *VL_rbBtns;
    QRadioButton *gpaTermRB;
    QRadioButton *cgpaRB;
    QRadioButton *newCgpaRB;
    QLabel *hintLbl;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *resultLbl;
    QTextBrowser *desplayResultTxt;
    QPushButton *calBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(350, 547);
        MainWindow->setMinimumSize(QSize(350, 547));
        MainWindow->setMaximumSize(QSize(350, 547));
        MainWindow->setStyleSheet(QString::fromUtf8("/*QMainWindow {\n"
"background-color: #414141;\n"
"border-radius: 25px;\n"
"}*/"));
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gpaTermGB = new QGroupBox(centralwidget);
        gpaTermGB->setObjectName("gpaTermGB");
        gpaTermGB->setGeometry(QRect(10, 107, 331, 285));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gpaTermGB->sizePolicy().hasHeightForWidth());
        gpaTermGB->setSizePolicy(sizePolicy);
        gpaTermGB->setMaximumSize(QSize(510, 303));
        gpaTermGB->setContextMenuPolicy(Qt::NoContextMenu);
        gpaTermGB->setAcceptDrops(false);
        gpaTermGB->setAutoFillBackground(false);
        gpaTermGB->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    /* Make the group box flat with only a top border */\n"
"    border: 1px solid transparent; /* Initially transparent border */\n"
"    border-top-color: #df5324; /* White top border */\n"
"  border-bottom-color: #df5324; /* White top border */\n"
"    border-radius: 5px; /* Optional: rounded corners */\n"
"    margin-top: 20px; /* Space for the title text */\n"
"	font-weight: bold\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    /* Style the title text */\n"
"    color: #ffffff; /* White title text */\n"
"    subcontrol-origin: margin; /* Title text starts from margin */\n"
"    subcontrol-position: top center; /* Center the title text */\n"
"    padding: 0 10px; /* Optional: some padding around the title */\n"
"    background-color: transparent; /* No background color for the title */\n"
"}\n"
"QGroupBox QLabel {\n"
"    /* Style the labels inside the group box */\n"
"    color: #ffffff; /* White text for labels */\n"
"}\n"
"\n"
"QGroupBox QPushButton {\n"
" background-color: #df5324; \n"
"color:"
                        " white; \n"
"border-radius: 4px; \n"
"padding: 4px 8px; }\n"
"QGroupBox QPushButton:hover { \n"
"background-color: #cc481b; }\n"
"\n"
"QGroupBox QCheckBox {\n"
"    color: white; /* Set the label text color to white */\n"
"}\n"
"\n"
"QGroupBox QCheckBox::indicator {\n"
"    width: 11px; /* Default checkbox size */\n"
"    height: 11px; /* Default checkbox size */\n"
"    border-radius: 2px; /* Rounded corners */\n"
"    border: 1px solid gray; /* Default border color */\n"
"    background-color: white; /* Background color when not checked */\n"
"}\n"
"\n"
"QGroupBox QCheckBox::indicator:checked {\n"
"    background-color: #df5324; /* Color of the check sign */\n"
"    border: 1px solid #df5324; /* Border color when checked */\n"
"}\n"
"\n"
"QGroupBox QCheckBox::indicator:hover {\n"
"    border: 1px solid #df5324; /* Hover border color */\n"
"}\n"
"\n"
"/*QGroupBox QComboBox{\n"
"	background-color: #df5324;\n"
"	border-radius: 2px;\n"
"}*/\n"
"\n"
"QGroupBox #hLine{\n"
"color:#df5324;\n"
" border: 2px solid #df"
                        "5324;;\n"
" width: 50%;}"));
        gpaTermGB->setAlignment(Qt::AlignCenter);
        gpaTermGB->setFlat(true);
        gpaTermGB->setCheckable(false);
        gpaTermGB->setChecked(false);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 2, 331, 102));
        HL_top = new QHBoxLayout(layoutWidget);
        HL_top->setSpacing(7);
        HL_top->setObjectName("HL_top");
        HL_top->setSizeConstraint(QLayout::SetMinimumSize);
        HL_top->setContentsMargins(0, 0, 0, 1);
        VL_obtion = new QVBoxLayout();
        VL_obtion->setSpacing(0);
        VL_obtion->setObjectName("VL_obtion");
        VL_obtion->setSizeConstraint(QLayout::SetMinAndMaxSize);
        VL_obtion->setContentsMargins(-1, 0, -1, 6);
        whatLbl = new QLabel(layoutWidget);
        whatLbl->setObjectName("whatLbl");
        whatLbl->setMaximumSize(QSize(145, 30));
        whatLbl->setLayoutDirection(Qt::LeftToRight);
        whatLbl->setStyleSheet(QString::fromUtf8("QLabel {color:white;font-weight:bold}"));
        whatLbl->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        whatLbl->setIndent(1);

        VL_obtion->addWidget(whatLbl, 0, Qt::AlignVCenter);

        VL_rbBtns = new QVBoxLayout();
        VL_rbBtns->setSpacing(5);
        VL_rbBtns->setObjectName("VL_rbBtns");
        VL_rbBtns->setSizeConstraint(QLayout::SetMinimumSize);
        VL_rbBtns->setContentsMargins(8, -1, -1, -1);
        gpaTermRB = new QRadioButton(layoutWidget);
        gpaTermRB->setObjectName("gpaTermRB");
        gpaTermRB->setMaximumSize(QSize(110, 30));
        gpaTermRB->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"	color:white;\n"
"}\n"
"QRadioButton::indicator:checked {\n"
"    /* Style the radio button when checked */\n"
"    width: 10px;  /* Ensure the same size when checked */\n"
"    height: 10px;  /* Ensure the same size when checked */\n"
"    border-radius: 5px;  /* Maintain the same radius */\n"
"    background-color: #df5324;  \n"
"    border: px solid #df5324;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:hover {\n"
"    /* Style the radio button when hovered */\n"
"	width: 10px;  /* Ensure the same size when checked */\n"
"    height: 10px;  /* Ensure the same size when checked */\n"
"    border-radius: 5px;  /* Maintain the same radius */\n"
"    background-color: #edbcac; \n"
"}\n"
""));
        gpaTermRB->setCheckable(true);
        gpaTermRB->setChecked(false);

        VL_rbBtns->addWidget(gpaTermRB);

        cgpaRB = new QRadioButton(layoutWidget);
        cgpaRB->setObjectName("cgpaRB");
        cgpaRB->setMaximumSize(QSize(110, 30));
        cgpaRB->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"	color:white;\n"
"}\n"
"QRadioButton::indicator:checked {\n"
"    /* Style the radio button when checked */\n"
"    width: 10px;  /* Ensure the same size when checked */\n"
"    height: 10px;  /* Ensure the same size when checked */\n"
"    border-radius: 5px;  /* Maintain the same radius */\n"
"    background-color: #df5324;  \n"
"    border: px solid #df5324;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:hover {\n"
"    /* Style the radio button when hovered */\n"
"	width: 10px;  /* Ensure the same size when checked */\n"
"    height: 10px;  /* Ensure the same size when checked */\n"
"    border-radius: 5px;  /* Maintain the same radius */\n"
"    background-color: #edbcac; \n"
"}\n"
""));

        VL_rbBtns->addWidget(cgpaRB);

        newCgpaRB = new QRadioButton(layoutWidget);
        newCgpaRB->setObjectName("newCgpaRB");
        newCgpaRB->setMaximumSize(QSize(180, 30));
        newCgpaRB->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"	color:white;\n"
"}\n"
"QRadioButton::indicator:checked {\n"
"    /* Style the radio button when checked */\n"
"    width: 10px;  /* Ensure the same size when checked */\n"
"    height: 10px;  /* Ensure the same size when checked */\n"
"    border-radius: 5px;  /* Maintain the same radius */\n"
"    background-color: #df5324;  \n"
"    border: px solid #df5324;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:hover {\n"
"    /* Style the radio button when hovered */\n"
"	width: 10px;  /* Ensure the same size when checked */\n"
"    height: 10px;  /* Ensure the same size when checked */\n"
"    border-radius: 5px;  /* Maintain the same radius */\n"
"    background-color: #edbcac; \n"
"}\n"
""));

        VL_rbBtns->addWidget(newCgpaRB);


        VL_obtion->addLayout(VL_rbBtns);


        HL_top->addLayout(VL_obtion);

        hintLbl = new QLabel(layoutWidget);
        hintLbl->setObjectName("hintLbl");
        hintLbl->setMinimumSize(QSize(0, 100));
        hintLbl->setMaximumSize(QSize(140, 105));
        hintLbl->setAutoFillBackground(false);
        hintLbl->setStyleSheet(QString::fromUtf8("#hintLbl {\n"
"   background-color: white;\n"
"  	border-radius: 20px;\n"
"	border: 0.5px solid #df5324;\n"
"}"));
        hintLbl->setLineWidth(0);
        hintLbl->setMidLineWidth(0);
        hintLbl->setTextFormat(Qt::MarkdownText);
        hintLbl->setScaledContents(false);
        hintLbl->setAlignment(Qt::AlignCenter);
        hintLbl->setMargin(0);
        hintLbl->setIndent(1);

        HL_top->addWidget(hintLbl);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 400, 331, 141));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        resultLbl = new QLabel(layoutWidget1);
        resultLbl->setObjectName("resultLbl");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(resultLbl->sizePolicy().hasHeightForWidth());
        resultLbl->setSizePolicy(sizePolicy1);
        resultLbl->setMinimumSize(QSize(0, 0));
        resultLbl->setMaximumSize(QSize(80, 40));
        resultLbl->setStyleSheet(QString::fromUtf8("QLabel { font-size: 11pt; font-weight: bold; color:white; }"));
        resultLbl->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(resultLbl);


        verticalLayout->addLayout(horizontalLayout);

        desplayResultTxt = new QTextBrowser(layoutWidget1);
        desplayResultTxt->setObjectName("desplayResultTxt");
        desplayResultTxt->setMaximumSize(QSize(329, 70));
        desplayResultTxt->setStyleSheet(QString::fromUtf8("QTextBrowser { border: 1px solid #df5324; \n"
"border-radius: 4px; \n"
"padding: 4px; }"));

        verticalLayout->addWidget(desplayResultTxt);

        calBtn = new QPushButton(layoutWidget1);
        calBtn->setObjectName("calBtn");
        calBtn->setEnabled(true);
        sizePolicy1.setHeightForWidth(calBtn->sizePolicy().hasHeightForWidth());
        calBtn->setSizePolicy(sizePolicy1);
        calBtn->setMinimumSize(QSize(0, 35));
        calBtn->setMaximumSize(QSize(1150, 101));
        calBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
" background-color: #df5324; \n"
"color: white; \n"
"border-radius: 4px; \n"
"padding: 6px 12px; }\n"
"QPushButton:hover { \n"
"background-color: #cc481b; }"));

        verticalLayout->addWidget(calBtn);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        gpaTermGB->setTitle(QString());
        whatLbl->setText(QCoreApplication::translate("MainWindow", "<b>What will you calculate ?</b>", nullptr));
        gpaTermRB->setText(QCoreApplication::translate("MainWindow", "GPA's Semester", nullptr));
        cgpaRB->setText(QCoreApplication::translate("MainWindow", "CGPA for Levels", nullptr));
        newCgpaRB->setText(QCoreApplication::translate("MainWindow", "Add New Semester to CGPA", nullptr));
        hintLbl->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">HINT</span><br/>Grade Point Equivalence<br/>A \342\211\241 4.00 A- \342\211\241 3.67<br/>B+ \342\211\241 3.33 B \342\211\241 3.00<br/>C+ \342\211\241 2.67 C \342\211\241 2.33<br/>D \342\211\241 2.00</p></body></html>", nullptr));
        resultLbl->setText(QCoreApplication::translate("MainWindow", "<b> The Result </b>", nullptr));
        desplayResultTxt->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        calBtn->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
#if QT_CONFIG(shortcut)
        calBtn->setShortcut(QCoreApplication::translate("MainWindow", "Enter", nullptr));
#endif // QT_CONFIG(shortcut)
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
