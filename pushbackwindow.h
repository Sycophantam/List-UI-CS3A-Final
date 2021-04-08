#ifndef PUSHBACKWINDOW_H
#define PUSHBACKWINDOW_H

#include <QDialog>
#include <string>
#include <sstream>

using namespace std;

namespace Ui {
class PushBackWindow;
}

class PushBackWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PushBackWindow(QWidget *parent = nullptr, QString name = "ADD");
    ~PushBackWindow();
    string getData();

private slots:
    void on_Input_textChanged(const QString &arg1);

private:
    Ui::PushBackWindow *ui;
    string data;
};

/*****************
 **  ACCESSORS  **
 ****************/

/*******************************************************************
* string getData()
*   Accessor function; This will return the data entered into the lineEdit
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: string->the data in the lineEdit
*******************************************************************/

/*************
 **  SLOTS  **
 ************/

/*******************************************************************
* void on_Input_textChanged(const QString &arg1)
*   Slot; This will activate whenever the text in the LineEdit is changed
*------------------------------------------------------------------
*   Parameter: arg1 (const QString) -> text entered into the lineEdit
*------------------------------------------------------------------
*   Return: none
*******************************************************************/
#endif // PUSHBACKWINDOW_H
