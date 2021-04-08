#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "linkedlist.h"
#include "vector.h"
#include "complex.h"
#include "date.h"
#include "rational.h"
#include <cstdlib>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_NewListButton_clicked();

    void on_DisplayButton_clicked();

    void on_PushBackButton_clicked();

    void on_PushFrontButton_clicked();

    void on_PopFrontButton_clicked();

    void on_DisplayPartofList_clicked();

    void on_ChangeListButton_clicked();

    void on_SortButton_clicked();

    void on_RemoveDuplicatesButton_clicked();

    void on_CopyListButton_clicked();

    void on_InsertSortedButton_clicked();

    void on_InsertButton_clicked();

    void on_DeleteListButton_clicked();

private:

    Ui::MainWindow *ui;

    ///Vectors of linkedLists
    Vector< LinkedList<int>*        > IntListVector;
    Vector< LinkedList<double>*     > DoubleListVector;
    Vector< LinkedList<string>*     > StringListVector;
    Vector< LinkedList<Complex>*    > ComplexListVector;
    Vector< LinkedList<Date>*       > DateListVector;
    Vector< LinkedList<Rational>*   > RationalListVector;

    ///Pointers to LinkedLists
    /// -The List that these point to will be the active list
    LinkedList<int>* activeIntList;
    LinkedList<double>* activeDoubleList;
    LinkedList<string>* activeStringList;
    LinkedList<Complex>* activeComplexList;
    LinkedList<Date>* activeDateList;
    LinkedList<Rational>* activeRationalList;

    ///Vectors of the names of each lists
    Vector<string> namesofIntLists, namesofDoubleLists, namesofStringLists,
    namesofComplexLists, namesofDateLists, namesofRationalLists;

    ///Numbers of lists
    int numIntLists, numDoubLists, numStrLists, numCompLists, numDateLists,
    numRatLists;

    string AskForList(QString reason);
    unsigned getIndexofVector(QString reason);

    string activeListName;  //Name of the active list
    unsigned whichList;          //index of the active list in the specific vector

    void enableOne(string which);   //Which combobox to enable


};

/*****************
 **  ACCESSORS  **
 ****************/

/*******************************************************************
* string AskForList(QString reason)
*   Accessor function; This will create a PushBackWindow with title
*       of reason
*------------------------------------------------------------------
*   Parameter: reason->Text to display at the top of the PushBackList
*------------------------------------------------------------------
*   Return: string->the name of the list to activate
*******************************************************************/

/*******************************************************************
* unsigned getIndexofVector(QString reason)
*   Accessor function; This will create a PushBackWindow with title
*       of reason
*------------------------------------------------------------------
*   Parameter: reason->Text to display at the top of the PushBackList
*------------------------------------------------------------------
*   Return: unsigned->index of a vector that corresponds to a List
*******************************************************************/

/****************
 **  MUTATORS  **
 ***************/

/*******************************************************************
* void enableOne(string which)
*   Mutator function; This will disable all comboboxes except for one
*       of reason
*------------------------------------------------------------------
*   Parameter: which->Combobox to enable
*------------------------------------------------------------------
*   Return: nothing
*******************************************************************/

/*************
 **  SLOTS  **
 *************/

/*******************************************************************
* void on_NewListButton_clicked();
*   Slot; This will activate whenever the NewListButton button is pressed.
*       This function will generate a new list
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: nothing
*******************************************************************/

/*******************************************************************
* void on_DisplayButton_clicked();
*   Slot; This will activate whenever the DisplayButton button is pressed.
*       This function will display a list
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: nothing
*******************************************************************/

/*******************************************************************
* void on_PushBackButton_clicked();
*   Slot; This will activate whenever the PushBackButton button is pressed.
*       This function will add a new item to the back of the list
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: nothing
*******************************************************************/

/*******************************************************************
* void on_PushFrontButton_clicked();
*   Slot; This will activate whenever the PushFrontButton button is pressed.
*       This function will add a new item to the front of the list
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: nothing
*******************************************************************/

/*******************************************************************
* void on_PopFrontButton_clicked();
*   Slot; This will activate whenever the PopFrontButton button is pressed.
*       This function will delete the item at the front of the list
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: nothing
*******************************************************************/

/*******************************************************************
* void on_DisplayPartofList_clicked();
*   Slot; This will activate whenever the DisplayPartofList button is pressed.
*       This function will display the list from certain indices that the
*       user enters
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: nothing
*******************************************************************/

/*******************************************************************
* void on_ChangeListButton_clicked();
*   Slot; This will activate whenever the ChangeListButton button is pressed.
*       This function will change the active list
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: nothing
*******************************************************************/

/*******************************************************************
* void on_SortButton_clicked();
*   Slot; This will activate whenever the SortButton button is pressed.
*       This function will sort an active list
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: nothing
*******************************************************************/

/*******************************************************************
* void on_RemoveDuplicatesButton_clicked();
*   Slot; This will activate whenever the RemoveDuplicatesButton
*           button is pressed.
*       This function will remove the duplicates in a list
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: nothing
*******************************************************************/

/*******************************************************************
* void on_CopyListButton_clicked();
*   Slot; This will activate whenever the CopyListButton button is pressed.
*       This function will create a new list which is a copy of the active list
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: nothing
*******************************************************************/

/*******************************************************************
* void on_InsertSortedButton_clicked();
*   Slot; This will activate whenever the InsertSortedButton button is pressed.
*       This function will assume the list is sorted and insert a value
*       in the appropriate location
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: nothing
*******************************************************************/

/*******************************************************************
* void on_InsertButton_clicked();
*   Slot; This will activate whenever the InsertButton button is pressed.
*       This function will insert an item into an index specified by the user
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: nothing
*******************************************************************/

/*******************************************************************
* void on_DeleteListButton_clicked();
*   Slot; This will activate whenever the DeleteListButton button is pressed.
*       This function will delete a list
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: nothing
*******************************************************************/




#endif // MAINWINDOW_H
