#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRadioButton>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QFrame>
#include <QStringList>
#include <QVector>
#include <QCheckBox>
#include <QPushButton>
#include <QGridLayout>
#include <QFormLayout>
#include <QMap>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void on_addBtn_gpaOfTerm();
    void on_addBtn_cgpa();
    void on_cnclBtn_gpaOfTerm();
    void on_cnclBtn_cgpa();
    void on_calBtn_gpaOfTerm();
    void on_calBtn_cgpa();
    void on_calBtn_newCgpa();

private slots:
    void on_gpaTermRB_toggled(bool checked);
    void on_addBtn_clicked();
    void on_cnclBtn_clicked();

    void on_cgpaRB_toggled(bool checked);

    void on_newCgpaRB_toggled(bool checked);

    void on_calBtn_clicked();

private:
    Ui::MainWindow *ui;

    QGroupBox *gBox;
    // QStringList gradeList = {"A","A-","B+","B","C+","C","D"};
    QMap <QString,double> gradeMap = {
        {"A",4.00},
        {"A-",3.67},
        {"B+",3.33},
        {"B",3.00},
        {"C+",2.67},
        {"C",2.33},
        {"D",2.00},
        {"F",0.00}
    };

//GPA's term group box
    //a vectors for ui components
    QVector <QLabel*> lbls;
    QVector <QLineEdit*> lineEdits;
    QVector <QComboBox*> grdCbs;
    QVector <QFrame*> frames;
    // QVector <QRadioButton*> y_nRBtns;
    QVector <QCheckBox*>  reCbs;
    QPushButton *addBtn;
    QPushButton *cnclBtn;

    QGridLayout *g_layout;

    int count_line;
    /*
    widgets [c-1]
    cnclbtn [c]
    addbtn [c+1]
    */

    QSize size;

    //declaration header widgets
    QLabel *remainH_L;
    QLineEdit *remainH_E;
    QLabel *lbl1;
    QLabel *lbl2;
    QLabel *scndRgLbl;

    QFrame *f;
    QLabel *hLine;
    QFormLayout *f_layout;

};
#endif // MAINWINDOW_H
