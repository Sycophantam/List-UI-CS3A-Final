#include "pushbackwindow.h"
#include "ui_pushbackwindow.h"
#include "mainwindow.h"

/**************************************************************************
* constructor PushBackWindow() : Class PushBackWindow
*--------------------------------------------------------------------------
* Constructor: creates a pushbackwindow
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   name (QString) -> reason for entering a value
*
* POST-CONDITIONS
* This will create a PushBackWindow
**************************************************************************/
PushBackWindow::PushBackWindow(QWidget *parent, QString name) :
    QDialog(parent),
    ui(new Ui::PushBackWindow)
{
    ui->setupUi(this);
    ui->label->setText(name);
}

/**************************************************************************
* destructor PushBackWindow() : Class PushBackWindow
*--------------------------------------------------------------------------
* destructor: destroys a pushbackwindow
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   none
*
* POST-CONDITIONS
* This will destroy a PushBackWindow
**************************************************************************/
PushBackWindow::~PushBackWindow()
{
    delete ui;
}

/**************************************************************************
* function getData() : Class PushBackWindow
*--------------------------------------------------------------------------
* function: returns the data
* return - string
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   none
*
* POST-CONDITIONS
* This will return a string
**************************************************************************/
string PushBackWindow::getData()
{
    return data;
}
/**************************************************************************
* slot on_Input_textChanged(const QString &arg1) : Class PushBackWindow
*--------------------------------------------------------------------------
* function: sets data to the input text
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   arg1 (QString) -> data to enter
*
* POST-CONDITIONS
* This will assign arg1 to data
**************************************************************************/
void PushBackWindow::on_Input_textChanged(const QString &arg1)  //Input data
{
    data = arg1.toStdString();
}
