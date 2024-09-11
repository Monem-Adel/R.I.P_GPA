#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QObject>
#include <QRadioButton>
#include <QGroupBox>
#include <QPushButton>
#include <QGridLayout>
#include <QFrame>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QDebug>
#include <QFormLayout>
#include <QSplashScreen>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainWindow::setWindowTitle("R.I.P GPA");
    MainWindow::setWindowIcon(QPixmap(":/icon/iconRIPGPA2.png"));

    MainWindow::setStyleSheet("QMainWindow {"
                              "background-color: #414141;"
                              "}");
    // qApp->setStyleSheet("QApplication{border-radius:5px;}");

    size = ui->gpaTermGB->size();

    ui->newCgpaRB->setChecked(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//helpful inline methods
inline void setLineEditProperties(QLineEdit *e, int mode){
    QRegularExpression regExp;
    e->setStyleSheet("QLineEdit { border: 1px solid gray; border-radius: 4px; padding: 4px; }");
    switch(mode){
        case 1:
            e->setFixedSize(50,23);
            e->setPlaceholderText("00");
            e->setAlignment(Qt::AlignCenter);
            e->setMaxLength(2);
            // e->setCursorPosition(0);
            regExp.setPattern("\\d{2}");
            e->setValidator(new QRegularExpressionValidator(regExp));
            e->setDragEnabled(true);
            break;
        case 2:
            e->setFixedSize(80,25);
            regExp.setPattern("\\d+|\\d?\\.\\d+");
            e->setValidator(new QRegularExpressionValidator(regExp));
            e->setDragEnabled(true);
            break;
        case 3:
            e->setFixedSize(100,25);
            regExp.setPattern("\\d+|\\d?\\.\\d+");
            e->setValidator(new QRegularExpressionValidator(regExp));
            e->setDragEnabled(true);
            break;
    }

}

// deleting used vectors contents
template <class T>
inline void deletingVectorContent(QVector<T*> &v){
    qDeleteAll(v);
    v.clear();
}

inline QString specifyGrade(double r){
    if(r == 4)
        return "A";
    else if (r >= 3.67)
        return "A-";
    else if(r >=3.33)
        return "B+";
    else if(r >= 3)
        return "B";
    else if(r >= 2.67)
        return "C+";
    else if(r >= 2.33)
        return "C";
    else if(r >= 2)
        return "D";
    else
        return "F";
}

// ### implementing slots ###

//add btn for gpa's term
void MainWindow::on_addBtn_gpaOfTerm(){

    if(count_line == 8) addBtn->setHidden(true);
    if(count_line == 9) return;

    //course label
    lbls.append(new QLabel(QString("Course  %1").arg(count_line+1),gBox));
    g_layout->addWidget(lbls.at(count_line),count_line+2,0);

    //credit hour line edit
    lineEdits.append(new QLineEdit(gBox));
    g_layout->addWidget(lineEdits.at(count_line),count_line+2,1,Qt::AlignCenter);
    lineEdits.at(count_line)->setFocus();

    //properties
    setLineEditProperties(lineEdits[count_line],1);

    //grade combo boxes
    grdCbs.append(new QComboBox(gBox));
    // grdCbs.at(count_line)->addItems(gradeList);
    grdCbs.at(count_line)->addItems(gradeMap.keys());
    g_layout->addWidget(grdCbs.at(count_line),count_line+2,2);

    //check bos yes
    reCbs.append(new QCheckBox("YES",gBox));
    g_layout->addWidget(reCbs.at(count_line),count_line+2,3,Qt::AlignCenter);

    //cancel push button

    // if(count_line != 3)
    cnclBtn->setHidden(false);

    g_layout->addWidget(cnclBtn,count_line+2,4);

    g_layout->addWidget(addBtn,count_line+3,4);

    count_line++;
}

void MainWindow::on_addBtn_cgpa(){

    if(count_line == 4) addBtn->setHidden(true);
    if(count_line == 5) return;

    lbls.append(new QLabel(QString("Level %1").arg(count_line+1),gBox));
    //widget[count_line] => cause you still don't update the count_line number
    g_layout->addWidget(lbls.at(count_line),count_line+1,0,Qt::AlignCenter);

    //for gpa's term
    lineEdits.append(new QLineEdit(gBox));
    g_layout->addWidget(lineEdits.at(count_line*2),count_line+1,1,Qt::AlignLeft);

    //for total ch
    lineEdits.append(new QLineEdit(gBox));
    g_layout->addWidget(lineEdits.at(count_line*2+1),count_line+1,2,Qt::AlignLeft);

    setLineEditProperties(lineEdits[count_line*2],2);
    setLineEditProperties(lineEdits[count_line*2+1],2);

    lineEdits.at(count_line*2)->setFocus();

    cnclBtn->setHidden(false);
    g_layout->addWidget(cnclBtn,count_line+2,0,1,3);

    g_layout->addWidget(addBtn,count_line+3,0,1,3);

    count_line++;

}

void MainWindow::on_cnclBtn_gpaOfTerm(){

    delete lbls.takeLast();
    // qDebug()<< lbls.last()->text();
    // lbls[count_line-1]->~QLabel();
    delete lineEdits.takeLast();
    delete grdCbs.takeLast();
    delete reCbs.takeLast();

    g_layout->addWidget(cnclBtn,count_line,4);

    if(count_line == 9)
        addBtn->setHidden(false);

    g_layout->addWidget(addBtn,count_line+1,4);

    count_line--;

    if(count_line < 4)
        cnclBtn->setHidden(true);

}

void MainWindow::on_cnclBtn_cgpa(){

    delete lbls.takeLast();
    //for total CH
    delete lineEdits.takeLast();
    //for gpa's term
    delete lineEdits.takeLast();

    g_layout->addWidget(cnclBtn,count_line,0,1,3);

    if(count_line == 5)
        addBtn->setHidden(false);

    g_layout->addWidget(addBtn,count_line+1,0,1,3);

    count_line--;

    if(count_line < 3)
        cnclBtn->setHidden(true);

}

void MainWindow::on_addBtn_clicked(){
    if(ui->gpaTermRB->isChecked())
        on_addBtn_gpaOfTerm();
    else if(ui->cgpaRB->isChecked())
        on_addBtn_cgpa();
}

void MainWindow::on_cnclBtn_clicked(){

    //QVector::removeLast()
    /*Calling a destructor releases the resources owned by the object,
        but it does not release the memory allocated to the object itself.

    However, suppose you use new in a function. If the
    function uses a local variable as a pointer to this memory, the pointer will be destroyed when
    the function terminates, but the memory will be left as an orphan, taking up space that is inaccessible to the rest of the program. Thus it is always good practice, and often essential, to
    delete memory when you’re through with it.
    */

    if(ui->gpaTermRB->isChecked())
        on_cnclBtn_gpaOfTerm();
    else if(ui->cgpaRB->isChecked())
        on_cnclBtn_cgpa();

}

void MainWindow::on_calBtn_gpaOfTerm(){
    //taking inputs
    //check the 2nd registration
    //calculation

    //declarations
    int remainCH;
    int *crsCH = new int[count_line];
    bool *scndRg = new bool[count_line];
    double *crsGrd = new double[count_line];

    int sumCHs = 0;
    double sumQPoints = 0;
    double result;

    //taking inputs
    if(remainH_E->text().isEmpty())
        remainH_E->setStyleSheet("QLineEdit{background-color: rgba(255, 0, 0, 0.2); border: 1px solid red; border-radius: 4px; padding: 4px; }");
    else {
        remainCH = remainH_E->text().toInt();
        remainH_E->setStyleSheet("QLineEdit { border: 1px solid gray; border-radius: 4px; padding: 4px; }");
    }
    for(int i=0;i<count_line;i++){
        if(lineEdits.at(i)->text().isEmpty())
            lineEdits.at(i)->setStyleSheet("QLineEdit{background-color: rgba(255, 0, 0, 0.2); border: 1px solid red; border-radius: 4px; padding: 4px; }");
        else {
            crsCH[i] = lineEdits.at(i)->text().toInt();
            lineEdits.at(i)->setStyleSheet("QLineEdit { border: 1px solid gray; border-radius: 4px; padding: 4px; }");
        }
        crsGrd[i] = gradeMap[grdCbs.at(i)->currentText()];
        scndRg[i] = reCbs.at(i)->isChecked();

        //check the 2nd registration
        // scndRg[i] ? (remainCH != 0 ? (crsGrd[i]; remainCH--; : crsGrd[i] = 2.00) : crsGrd[i];
        if(scndRg[i]){
            if(remainCH == 0)
                crsGrd[i] = 2.00;
            else
                remainCH-=crsCH[i];
        }
        // qDebug()<<"remainCH"<<remainCH;
        // qDebug()<<"\ncrsCH"<<crsCH[i];
        // qDebug()<<"\ncrsGrd"<<crsGrd[i];
        // qDebug()<<"\nscndRg"<<scndRg[i];
    }

    //calculation
    // Result GPA = sum(crsCH[i]*crsGrd[i])/sum(crsCH[i])
    int i=0;
    while(i<count_line){
        sumCHs+=crsCH[i];
        sumQPoints+= crsCH[i]*crsGrd[i];
        i++;
    }

    if(sumCHs != 0)
        result = sumQPoints / sumCHs ;
    else
        result = 0;

    //display
    if(remainH_E->text().isEmpty()
        || std::any_of(lineEdits.begin(), lineEdits.end(), [](QLineEdit* lineEdit) {return lineEdit->text().isEmpty();}))
        ui->desplayResultTxt->setText("<b><p style=\"color: red;\">Some Required fields are empty, should be filld</p></b>");
    else
    ui->desplayResultTxt->setText("<b>Your GPA = "+QString::number(result)+"</b><br>"
                                  +"<b>Your Grade is "+specifyGrade(result)+"</b><br>"
                                +"<b> Your Remaining Credit Hours from 12 CH = "+QString::number(remainCH)+"</b>");

    //releasing memory
    delete[] crsCH;
    delete[] crsGrd;
    delete[] scndRg;
}

void MainWindow::on_calBtn_cgpa(){
    //takes inputs level 1,2,3,4,5
    //takes inputs of levels' CH

    double *CGPAs = new double[count_line];
    int *levelCHs = new int[count_line];
    double result;

    double sumQPoints = 0;
    int sumHours = 0;

    //take inputs
    for(int i=0;i<count_line;i++){
        if(lineEdits.at(i*2)->text().isEmpty())
            lineEdits.at(i*2)->setStyleSheet("QLineEdit{background-color: rgba(255, 0, 0, 0.2); border: 1px solid red; border-radius: 4px; padding: 4px; }");
        else {
            lineEdits.at(i*2)->setStyleSheet("QLineEdit { border: 1px solid gray; border-radius: 4px; padding: 4px; }");
            CGPAs[i] = lineEdits.at(i*2)->text().toDouble();
        }

        if(lineEdits.at(i*2+1)->text().isEmpty())
            lineEdits.at(i*2+1)->setStyleSheet("QLineEdit{background-color: rgba(255, 0, 0, 0.2); border: 1px solid red; border-radius: 4px; padding: 4px; }");
        else {
            lineEdits.at(i*2+1)->setStyleSheet("QLineEdit { border: 1px solid gray; border-radius: 4px; padding: 4px; }");
            levelCHs[i] = lineEdits.at(i*2+1)->text().toInt();
        }
    }

    //calculation
    // Result CGPA = sum(CGPAs[i]*levelCHs[i])/sum(levelCHs[i])
    int i=0;
    while(i<count_line){
        sumQPoints+= CGPAs[i]*levelCHs[i];
        sumHours+= levelCHs[i];
        i++;
    }

    if(sumHours != 0)
        result = sumQPoints / sumHours;
    else
        result = 0;
    if(std::any_of(lineEdits.begin(), lineEdits.end(), [](QLineEdit* lineEdit) {return lineEdit->text().isEmpty();}))
        ui->desplayResultTxt->setText("<b><p style=\"color: red;\">Some Required fields are empty, should be filld</p></b>");
    else
        ui->desplayResultTxt->setText("<b>Your CGPA = "+QString::number(result)+"</b><br>"
                                +"<b>Your Grade is "+specifyGrade(result)+"</b>");

    //release memory
    delete[] CGPAs;
    delete[] levelCHs;
}

void MainWindow::on_calBtn_newCgpa(){
    //take the cgpa input from the line edit
    //take the total CH input
    //take the new gpa semester
    //take the CH's semester
    //calculate the new CGPA
    //display the result in the text browser

    //lineEdits[0]=> old cgpa
    //lineEdits[1]=> total ch
    //lineEdits[2]=> semester's gpa
    //lineEdits[3]=> ch's semester

    //declarations
    double cgpa;
    int totalCH;
    double newGpa;
    int newCH;
    double result;

    //check if empty
    for(QLineEdit* LE : lineEdits){
        if(LE->text().isEmpty())
            LE->setStyleSheet("QLineEdit{background-color: rgba(255, 0, 0, 0.2); border: 1px solid red; border-radius: 4px; padding: 4px; }");
        else
            LE->setStyleSheet("QLineEdit { border: 1px solid gray; border-radius: 4px; padding: 4px; }");
    }
    //taking input & assigning it to variables
    if(!lineEdits.at(0)->text().isEmpty())
        cgpa = lineEdits.at(0)->text().toDouble();

    // qDebug()<<lineEdits.at(0)->text();
    // qDebug()<<"cgpa "<<cgpa;

    if(!lineEdits.at(1)->text().isEmpty())
        totalCH = lineEdits.at(1)->text().toInt();

    // qDebug()<<lineEdits.at(1)->text();
    // qDebug()<<"totalCH "<<totalCH;

    if(!lineEdits.at(2)->text().isEmpty())
        newGpa = lineEdits.at(2)->text().toDouble();

    // qDebug()<<lineEdits.at(2)->text();
    // qDebug()<<"newGpa "<<newGpa;

    if(!lineEdits.at(3)->text().isEmpty())
        newCH = lineEdits.at(3)->text().toInt();

    // qDebug()<<lineEdits.at(3)->text();
    // qDebug()<<"newCH "<<newCH;

    //Result CGPA = ((old CGPA*total CH)+(new GPA*new CH))/(total CH+new CH)
    if(totalCH+newCH !=0)
        result = ((cgpa * totalCH)+(newGpa * newCH))/(totalCH+newCH);
    else
        result = 0;

    if(std::any_of(lineEdits.begin(), lineEdits.end(), [](QLineEdit* lineEdit) {return lineEdit->text().isEmpty();}))
        ui->desplayResultTxt->setText("<b><p style=\"color: red;\">Some Required fields are empty, should be filld</p></b>");
    else
        ui->desplayResultTxt->setText("<b>Your New CGPA = "+QString::number(result)+"</b><br>"
                                +"<b>Your Grade is "+specifyGrade(result)+"</b>");

}

void MainWindow::on_gpaTermRB_toggled(bool checked)
{
    //prepare the gpa's term group box & its layout
    gBox = ui->gpaTermGB;

    gBox->setTitle(" GPA's for a Semester ");

    gBox->setFixedSize(size);

    if(checked){
        g_layout = new QGridLayout(gBox);
        g_layout->setOriginCorner(Qt::TopLeftCorner);
        gBox->setLayout(g_layout);

        // g_layout->setSizeConstraint(QLayout::SetMinAndMaxSize);


        remainH_L = new QLabel("Remaining Credit Hours from 12 CH ",gBox);
        // remainH_L->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        // remainH_L->setFixedSize(210,45);
        remainH_E = new QLineEdit(gBox);
        remainH_E->setPlaceholderText("0 - 12");
        remainH_E->setFixedSize(80,25);
        remainH_E->setStyleSheet("QLineEdit { border: 1px solid gray; border-radius: 4px; padding: 4px; }");
        QRegularExpression regExp("\\d\\d");
        remainH_E->setValidator(new QRegularExpressionValidator(regExp));

        remainH_E->setFocus();


        //first row in grid layout; credit hours , grade , second registration
        lbl1 = new QLabel("Credit Hour",gBox);
        lbl2 = new QLabel("Grade",gBox);
        scndRgLbl = new QLabel("Is it Repeated ?",gBox);
        scndRgLbl->setFixedSize(110,15);
        // scndRgLbl->setAlignment(Qt::AlignLeft);

        g_layout->setHorizontalSpacing(5);
        g_layout->setVerticalSpacing(1);

        g_layout->setRowMinimumHeight(0,22);
        g_layout->setRowStretch(0,0);
        g_layout->setRowMinimumHeight(1,22);
        g_layout->setRowStretch(1,0);

        // g_layout->setSizeConstraint(QLayout::SetNoConstraint);

        g_layout->addWidget(remainH_L,0,0,1,3);
        g_layout->addWidget(remainH_E,0,3);

        g_layout->addWidget(lbl1,1,1);
        g_layout->addWidget(lbl2,1,2,Qt::AlignCenter);
        g_layout->addWidget(scndRgLbl,1,3);

        //Course labels
        lbls.reserve(8);

        for(int i=0; i<3; i++){
            // lbls[i] = new QLabel(QString("Course  %1").arg(i + 1),gBox);
            lbls.append(new QLabel(QString("Course %1").arg(i+1),gBox));
            g_layout->addWidget(lbls.at(i),i+2,0);
        }

        //credit hour line edits
        lineEdits.reserve(8);

        for(int i=0; i<3; i++){
            lineEdits.append(new QLineEdit(gBox));
            g_layout->addWidget(lineEdits.at(i),i+2,1,Qt::AlignCenter);

            //properties
            setLineEditProperties(lineEdits[i],1);
        }

        //grade combo boxes
        grdCbs.reserve(8);

        for(int i=0;i<3;i++){
            grdCbs.append(new QComboBox(gBox));
            // grdCbs.at(i)->addItems(gradeList);
            grdCbs.at(i)->addItems(gradeMap.keys());
            g_layout->addWidget(grdCbs.at(i),i+2,2);
        }

        reCbs.reserve(8);

        for(int i=0; i<3; i++){
            reCbs.append(new QCheckBox("YES",gBox));
            g_layout->addWidget(reCbs.at(i),i+2,3,Qt::AlignCenter);
        }

        cnclBtn = new QPushButton("×",gBox);
        //properties
        cnclBtn->setFixedSize(40,23);

        addBtn = new QPushButton("+",gBox);
        addBtn->setFixedSize(40,23);
        g_layout->addWidget(addBtn,5,4);

        //connection the add button
        connect(addBtn,&QPushButton::clicked,this,&MainWindow::on_addBtn_clicked);

        //connection the cancel button
        connect(cnclBtn,&QPushButton::clicked,this,&MainWindow::on_cnclBtn_clicked);

        count_line = 3;

    }

    else if (!checked){
        //deleting some header widgets
        delete remainH_L;
        delete remainH_E;
        delete lbl1;
        delete lbl2;
        delete scndRgLbl;

        //deleting the labels objects from vectors
        deletingVectorContent(lbls);

        //deleting line edits
        deletingVectorContent(lineEdits);

        //deleting combo boxes
        deletingVectorContent(grdCbs);

        //deleting check box yes
        deletingVectorContent(reCbs);

        //deleting cancel buttons
        delete cnclBtn;

        delete addBtn;

        delete gBox->layout();

    }
}

void MainWindow::on_cgpaRB_toggled(bool checked)
{
    gBox = ui->gpaTermGB;

    gBox->setTitle(" Cumulative GPA for Levels ");


    if(checked){

        g_layout = new QGridLayout(gBox);
        gBox->setLayout(g_layout);

        lbl1 = new QLabel("GPA's Level",gBox);
        lbl2 = new QLabel("Level's Credit Hours",gBox);
        lbl1->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        lbl2->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

        g_layout->setHorizontalSpacing(3);
        g_layout->setVerticalSpacing(5);

        g_layout->setSizeConstraint(QLayout::SetMinAndMaxSize);

        g_layout->setRowMinimumHeight(0,45);
        g_layout->setRowStretch(0,0);
        // g_layout->setRowStretch(3,50);

        // g_layout->setColumnMinimumWidth(0,10);
        // g_layout->setColumnMinimumWidth(2,100);

        //1st row
        g_layout->addWidget(lbl1,0,1);
        g_layout->addWidget(lbl2,0,2);

        //1st column
        lbls.reserve(8);
        for(int i=0;i<2;i++){
            lbls.append(new QLabel(QString("Level %1").arg(i+1),gBox));
            // lbls[i]->setFixedSize(100,25);
            g_layout->addWidget(lbls.at(i),i+1,0,Qt::AlignCenter);

        }

        //lineEdits
        lineEdits.reserve(16);
        for(int i=0;i<2;i++){
            //for gpa's term
            lineEdits.append(new QLineEdit(gBox));
            g_layout->addWidget(lineEdits.at(i*2),i+1,1,Qt::AlignLeft);

            //for total ch
            lineEdits.append(new QLineEdit(gBox));
            g_layout->addWidget(lineEdits.at(i*2+1),i+1,2,Qt::AlignLeft);

            setLineEditProperties(lineEdits[i*2],2);
            setLineEditProperties(lineEdits[i*2+1],2);

        }

        lineEdits.first()->setFocus();

        addBtn = new QPushButton("Add a New Level",gBox);
        g_layout->addWidget(addBtn,3,0,1,3);

        cnclBtn = new QPushButton("Cancel a Level",gBox);

        //connection the add button
        connect(addBtn,&QPushButton::clicked,this,&MainWindow::on_addBtn_clicked);

        //connection the cancel button
        connect(cnclBtn,&QPushButton::clicked,this,&MainWindow::on_cnclBtn_clicked);

        count_line = 2;
    }

    else if(!checked){
        delete lbl1;
        delete lbl2;

        deletingVectorContent(lbls);

        deletingVectorContent(lineEdits);

        delete addBtn;
        delete cnclBtn;
        delete gBox->layout();

    }
}

void MainWindow::on_newCgpaRB_toggled(bool checked)
{

    gBox = ui->gpaTermGB;
    gBox->setTitle(" Adding New Semester to CGPA ");

    gBox->setFixedSize(size);

    if(checked){
        f_layout = new QFormLayout(gBox);
        gBox->setLayout(f_layout);

        lbl1 = new QLabel("The CGPA :",gBox);
        lbl2 = new QLabel("New Semester GPA :",gBox);

        lbls.reserve(2);
        lbls.append(new QLabel("  Total Registered Credit Hours :",gBox));
        lbls.append(new QLabel("  New Semester's Credit Hours :"));

        lineEdits.reserve(4);
        for(int i=0 ; i<4;i++){
            lineEdits.append(new QLineEdit(gBox));
            setLineEditProperties(lineEdits[i],3);
        }

        lbl1->setBuddy(lineEdits.at(0));
        lbls.first()->setBuddy(lineEdits.at(1));
        lbls.last()->setBuddy(lineEdits.at(2));
        lbl2->setBuddy(lineEdits.at(3));

        // lbl1->setAlignment(Qt::AlignCenter);
        // lbl2->setAlignment(Qt::AlignCenter);

        lineEdits.first()->setFocus();

        f_layout->setFormAlignment(Qt::AlignHCenter);
        f_layout->setLabelAlignment(Qt::AlignCenter);
        f_layout->setHorizontalSpacing(15);
        f_layout->setVerticalSpacing(10);
        // f_layout->setRowWrapPolicy(QFormLayout::DontWrapRows);
        f_layout->setSizeConstraint(QLayout::SetNoConstraint);

        f = new QFrame(gBox);
        hLine = new QLabel("<hr style=\"color:#df5324; border: 2px solid #df5324; width: 50%;\">",gBox);

        f->setFixedSize(150,20);

        f_layout->addRow(f);
        f_layout->addRow(lbl1,lineEdits.at(0));
        f_layout->addRow(lbls.first(),lineEdits.at(1));
        f_layout->addRow(hLine);
        f_layout->addRow(lbl2,lineEdits.at(2));
        f_layout->addRow(lbls.last(),lineEdits.at(3));


    }

    else if(!checked){
        delete lbl1;
        delete lbl2;
        delete f;
        delete hLine;

        deletingVectorContent(lbls);
        deletingVectorContent(lineEdits);


        delete gBox->layout();
        // delete f_layout;

    }
}


void MainWindow::on_calBtn_clicked()
{
    if(ui->gpaTermRB->isChecked())
        on_calBtn_gpaOfTerm();

    else if(ui->cgpaRB->isChecked())
        on_calBtn_cgpa();

    else if(ui->newCgpaRB->isChecked())
        on_calBtn_newCgpa();
}

