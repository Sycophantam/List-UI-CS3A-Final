#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pushbackwindow.h"
#include <QMessageBox>

/**************************************************************************
* constructor MainWindow() : Class MainWindow
*--------------------------------------------------------------------------
* Constructor: creates a mainwindow
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   none
*
* POST-CONDITIONS
* This will create a MainWindow
**************************************************************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    numIntLists = numDoubLists = numStrLists = numCompLists = numDateLists
            = numRatLists = 0;

    ///All lists will be shown as false
    ui->BoxofInts->setEnabled(false);
    ui->BoxofDoubles->setEnabled(false);
    ui->BoxofStrings->setEnabled(false);
    ui->BoxofComplexes->setEnabled(false);
    ui->BoxofDates->setEnabled(false);
    ui->BoxofRationals->setEnabled(false);

}

/**************************************************************************
* destructor ~MainWindow() : Class MainWindow
*--------------------------------------------------------------------------
* Destructor: destroys a mainwindow
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   none
*
* POST-CONDITIONS
* This will destroy a MainWindow
**************************************************************************/
MainWindow::~MainWindow()
{
    delete ui;
}

/**************************************************************************
* slot on_NewListButton_clicked() : Class MainWindow
*--------------------------------------------------------------------------
* Activates: when NewListButton is clicked
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   none
*
* POST-CONDITIONS
* This will create a new list
**************************************************************************/
void MainWindow::on_NewListButton_clicked()
{

    string List_Name;                           //Name of the list

    if(ui->IntList->isChecked())
    {
        ///Enabling the list of IntLists
        ui->BoxofInts->setEnabled(true);

        ///Creating a new LinkedList
        LinkedList<int> *L = new LinkedList<int>;

        List_Name = AskForList("Add List");
        IntListVector.push_back(L);
        numIntLists++;

        ui->BoxofInts->addItem(QString::fromStdString(List_Name));
        ui->ActiveListLabel->setText(QString::fromStdString(List_Name));
        namesofIntLists.push_back(List_Name);
        activeIntList = IntListVector.at(IntListVector.size() - 1);

    }
    else if(ui->DoubleList->isChecked())
    {
        ///Enabling the list that holds the name of lists, creating a new
        /// list, then adding the list to a vector and adding the name
        /// of the list to another vector
        ui->BoxofDoubles->setEnabled(true);
        LinkedList<double> *L = new LinkedList<double>;

        List_Name = AskForList("Add List");

        DoubleListVector.push_back(L);
        numDoubLists++;

        ui->BoxofDoubles->addItem(QString::fromStdString(List_Name));
        ui->ActiveListLabel->setText(QString::fromStdString(List_Name));
        namesofDoubleLists.push_back(List_Name);

        activeDoubleList = DoubleListVector.at(DoubleListVector.size() - 1);
    }
    else if(ui->StringList->isChecked())
    {
        ///Enabling the list that holds the name of lists, creating a new
        /// list, then adding the list to a vector and adding the name
        /// of the list to another vector
        ui->BoxofStrings->setEnabled(true);
        LinkedList<string> *L = new LinkedList<string>;

        List_Name = AskForList("Add List");

        StringListVector.push_back(L);
        numStrLists++;

        ui->BoxofStrings->addItem(QString::fromStdString(List_Name));
        ui->ActiveListLabel->setText(QString::fromStdString(List_Name));
        namesofStringLists.push_back(List_Name);

        activeStringList = StringListVector.at(StringListVector.size() - 1);

    }
    else if(ui->ComplexList->isChecked())
    {
        ///Enabling the list that holds the name of lists, creating a new
        /// list, then adding the list to a vector and adding the name
        /// of the list to another vector
        ui->BoxofComplexes->setEnabled(true);
        LinkedList<Complex> *L = new LinkedList<Complex>;

        List_Name = AskForList("Add List");

        ComplexListVector.push_back(L);
        numCompLists++;

        ui->BoxofComplexes->addItem(QString::fromStdString(List_Name));
        ui->ActiveListLabel->setText(QString::fromStdString(List_Name));
        namesofComplexLists.push_back(List_Name);

        activeComplexList = ComplexListVector.at(ComplexListVector.size()- 1);
    }
    else if(ui->DateList->isChecked())
    {
        ///Enabling the list that holds the name of lists, creating a new
        /// list, then adding the list to a vector and adding the name
        /// of the list to another vector
        ui->BoxofDates->setEnabled(true);
        ui->Calendar->setEnabled(true);
        LinkedList<Date> *L = new LinkedList<Date>;

        List_Name = AskForList("Add List");

        DateListVector.push_back(L);
        numDateLists++;

        ui->BoxofDates->addItem(QString::fromStdString(List_Name));
        ui->ActiveListLabel->setText(QString::fromStdString(List_Name));
        namesofDateLists.push_back(List_Name);

        activeDateList = DateListVector.at(DateListVector.size() - 1);
    }
    else if(ui->RationalList->isChecked())
    {
        ///Enabling the list that holds the name of lists, creating a new
        /// list, then adding the list to a vector and adding the name
        /// of the list to another vector
        ui->BoxofRationals->setEnabled(true);
        LinkedList<Rational> *L = new LinkedList<Rational>;

        List_Name = AskForList("Add List");

        RationalListVector.push_back(L);
        numRatLists++;

        ui->BoxofRationals->addItem(QString::fromStdString(List_Name));
        ui->ActiveListLabel->setText(QString::fromStdString(List_Name));
        namesofRationalLists.push_back(List_Name);

        activeRationalList = RationalListVector.at
                (RationalListVector.size() - 1);
        QMessageBox::information(this, "", "List created");
    }
    else
    {
        QMessageBox::critical(this, "Error",
                              "Must select a type before you create a list");
    }
}

/**************************************************************************
* slot on_DisplayButton_clicked() : Class MainWindow
*--------------------------------------------------------------------------
* Activates: when DisplayButton is clicked
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   none
*
* POST-CONDITIONS
* This will display the list
**************************************************************************/
void MainWindow::on_DisplayButton_clicked()
{
    try
    {
        if(ui->IntList->isChecked())
        {
            ui->OutputDisplay->setText
                    (QString::fromStdString(activeIntList->display()));
        }
        else if(ui->DoubleList->isChecked())
        {
            ui->OutputDisplay->setText
                    (QString::fromStdString(activeDoubleList->display()));
        }
        else if(ui->StringList->isChecked())
        {
            ui->OutputDisplay->setText
                    (QString::fromStdString(activeStringList->display()));
        }
        else if(ui->ComplexList->isChecked())
        {
            ui->OutputDisplay->setText
                    (QString::fromStdString(activeComplexList->display()));
        }
        else if(ui->DateList->isChecked())
        {
            ui->OutputDisplay->setText
                    (QString::fromStdString(activeDateList->display()));
        }
        else if(ui->RationalList->isChecked())
        {
            ui->OutputDisplay->setText
                    (QString::fromStdString(activeRationalList->display()));
        }
    }
    catch (ListEmpty)
    {
        QMessageBox::critical(this, "Error", "Cannot display empty list");

    }
    catch (out_of_range)
    {
        QMessageBox::critical(this, "Error", "List does not exist");
    }

}

/**************************************************************************
* slot on_PushBackButton_clicked() : Class MainWindow
*--------------------------------------------------------------------------
* Activates: when PushBackButton is clicked
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   none
*
* POST-CONDITIONS
* This will add a node to the back of the list
**************************************************************************/
void MainWindow::on_PushBackButton_clicked()
{

    if(!ui->IntList->isChecked() && !ui->DoubleList->isChecked() &&
            !ui->StringList->isChecked() && !ui->ComplexList->isChecked() &&
            !ui->DateList->isChecked() && !ui->RationalList->isChecked())
    {
        QMessageBox::critical(this, "ERROR",
                              "Cannot add values to uninitialized list");
    }
    else
    {
        try
        {
            if(!(ui->DateList->isChecked()))
            {
                ///PushBackWindow will return the value entered into the line
                /// edit
                ///
                ///
                /// Depending on which radio button is pressed, the active list
                /// of a type will call the push_back function and add the
                /// value entered into the PushBackWindow



                PushBackWindow PushBack(this, "PUSH_BACK");
                PushBack.setModal(true);
                PushBack.exec();
                if(ui->IntList->isChecked())
                {
                    if(!IntListVector.empty())
                        activeIntList->push_back
                                (atoi(PushBack.getData().c_str()));
                }


                else if(ui->DoubleList->isChecked())
                {
                    if(!DoubleListVector.empty())
                        activeDoubleList->
                                push_back(atof(PushBack.getData().c_str()));
                }

                else if(ui->StringList->isChecked())
                {
                    if(!StringListVector.empty())
                        activeStringList->push_back(PushBack.getData());
                }

                else if(ui->ComplexList->isChecked())
                {
                    if(!ComplexListVector.empty())
                    {
                        Complex c;
                        c.fromString(PushBack.getData());
                        activeComplexList->push_back(c);
                    }

                }
                else if(ui->RationalList->isChecked())
                {
                    if(!RationalListVector.empty())
                    {
                        Rational tempRational;
                        tempRational.fromString(PushBack.getData());
                        activeRationalList->push_back(tempRational);
                    }
                }
            }
            ///Selected date will be pushed back
            else if(ui->DateList->isChecked())
            {
                Date d(static_cast<unsigned>
                       (ui->Calendar->selectedDate().month()),
                       static_cast<unsigned>
                       (ui->Calendar->selectedDate().day()),
                       static_cast<unsigned>
                       (ui->Calendar->selectedDate().year()));
                activeDateList->push_back(d);
            }
        }
        catch(nullptr_t)
        {
            QMessageBox::critical(this, "ERROR",
                                  "Cannot add values to uninitialized list");
        }
        catch(out_of_range)
        {
            QMessageBox::critical(this, "ERROR",
                                  "Cannot add values to uninitialized list");
        }
    }


}

/**************************************************************************
* slot on_PushFrontButton_clicked() : Class MainWindow
*--------------------------------------------------------------------------
* Activates: when PushFrontButton is clicked
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   none
*
* POST-CONDITIONS
* This will add a node to the front of the list
**************************************************************************/
void MainWindow::on_PushFrontButton_clicked()
{
    try
    {
        if(!ui->DateList->isChecked())
        {
            PushBackWindow PushFront(this, "Push_Front");
            PushFront.setModal(true);
            PushFront.exec();

            if(ui->IntList->isChecked())
            {
                activeIntList->push_front(atoi(PushFront.getData().c_str()));
            }
            else if(ui->DoubleList->isChecked())
            {
                activeDoubleList->push_front(atof(PushFront.getData().c_str()));
            }

            else if(ui->StringList->isChecked())
                activeStringList->push_front(PushFront.getData());

            else if(ui->ComplexList->isChecked())
            {
                Complex c;
                c.fromString(PushFront.getData());
                activeComplexList->push_front(c);

            }

            else if(ui->RationalList->isChecked())
            {
                Rational tempRational;
                tempRational.fromString(PushFront.getData());
                activeRationalList->push_front(tempRational);
            }
        }
        else if(ui->DateList->isChecked())
        {
            Date d(static_cast<unsigned>
                   (ui->Calendar->selectedDate().month()),
                   static_cast<unsigned>
                   (ui->Calendar->selectedDate().day()),
                   static_cast<unsigned>
                   (ui->Calendar->selectedDate().year()));
            activeDateList->push_front(d);
        }
    }
    catch(out_of_range)
    {
        QMessageBox::critical(this, "Error", "List does not exist");
    }
}


/**************************************************************************
* slot on_PopFrontButton_clicked() : Class MainWindow
*--------------------------------------------------------------------------
* Activates: when PopFrontButton is clicked
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   none
*
* POST-CONDITIONS
* This will delete the node at the front of the list
**************************************************************************/
void MainWindow::on_PopFrontButton_clicked()
{
    try
    {
        if(ui->IntList->isChecked())
        {
            if(activeIntList != nullptr)
                activeIntList->pop_front();
            else
                QMessageBox::critical(this, "ERROR", "List is empty");
        }
        else if(ui->DoubleList->isChecked())
        {
            if(activeDoubleList != nullptr)
                activeDoubleList->pop_front();
            else
                QMessageBox::critical(this, "ERROR", "List is empty");
        }
        else if(ui->StringList->isChecked())
        {
            if(activeStringList != nullptr)
                activeStringList->pop_front();
            else
                QMessageBox::critical(this, "ERROR", "List is empty");
        }
        else if(ui->ComplexList->isChecked())
        {
            if(activeComplexList != nullptr)
                activeComplexList->pop_front();
            else
                QMessageBox::critical(this, "ERROR", "List is empty");
        }
        else if(ui->DateList->isChecked())
        {
            if(activeDateList != nullptr)
                activeDateList->pop_front();
            else
                QMessageBox::critical(this, "ERROR", "List is empty");
        }
        else if(ui->RationalList->isChecked())
        {
            if(activeDateList != nullptr)
                activeRationalList->pop_front();
            else
                QMessageBox::critical(this, "ERROR", "List is empty");
        }
    }
    catch(out_of_range)
    {
        QMessageBox::critical(this, "Error", "List entered is not in our"
                                             " records");
    }
}

/**************************************************************************
* function AskForList(QString reason) : Class MainWindow
*--------------------------------------------------------------------------
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   reason (QString): Text that displays when the PushBackWindow is activated
*
* POST-CONDITIONS
* This will return the name of a list
**************************************************************************/
string MainWindow::AskForList(QString reason)
{
    PushBackWindow AddList(this, reason);
    AddList.setModal(true);
    AddList.exec();
    return AddList.getData();
}

/**************************************************************************
* function getIndexofVector(QString reason) : Class MainWindow
*--------------------------------------------------------------------------
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   reason (QString): Text that displays when the PushBackWindow is activated
*
* POST-CONDITIONS
* This will return an unsigned value
*   When called in the context of the program, this program will be called
*   in conjuction with an indexOf function
**************************************************************************/
unsigned MainWindow::getIndexofVector(QString reason)
{
    PushBackWindow index_get(this, reason);
    index_get.setModal(true);
    index_get.exec();

    return static_cast<unsigned>(atoi(index_get.getData().c_str()) - 1);
}

/**************************************************************************
* slot on_DisplayPartofList_clicked() : Class MainWindow
*--------------------------------------------------------------------------
* Activates: when DisplayPartofList is clicked
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   none
*
* POST-CONDITIONS
* This will display a part of the list from specified indices
**************************************************************************/
void MainWindow::on_DisplayPartofList_clicked()
{
    ///////////////////////////////////////////////////////////////////////////
    /// Due to the repetitive nature of this method, a brief summary of     ///
    /// what the program does will be given at the beginning instead of at  ///
    /// every condition                                                     ///
    ///////////////////////////////////////////////////////////////////////////
    string fromto;
    ostringstream output;
    unsigned from;
    unsigned to;
    try
    {
        PushBackWindow indices(this, "Enter the index to start and index\n"
                                     "to end, separated by a comma.\n"
                                     "Ex. 3,5");
        indices.setModal(true);
        indices.exec();
        fromto = indices.getData();
        ///Setting values to the input
        ///
        /// From will be set to the value before the comma
        /// To will be set to the value after the comma
        from = static_cast<unsigned>
                (atoi(fromto.substr(0,fromto.find(",")).c_str()));

        to = static_cast<unsigned>
                (atoi(fromto.substr(fromto.find(",") + 1).c_str()));




        ///Two iterators will be created: ifrom and ito
        ///
        /// ifrom will point to the from'th index, ito will point to the to'th
        /// index
        ///
        ///
        /// An unsigned variable mover will be created, the number of indices to
        /// display
        ///
        /// A while loop will then cause the iterators to update and output
        /// their values





        if(ui->IntList->isChecked())
        {
            LinkedList<int>::Iterator ifrom;
            LinkedList<int>::Iterator ito;

            ifrom = activeIntList->begin();
            ito = activeIntList->begin();

            for(unsigned i = 0; i < from - 1; i++)
            {
                ++ifrom;
            }
            for(unsigned i = 0; i < to - 1; i++)
                ++ito;
            unsigned mover = to - from;
            unsigned count = 0;
            while(count < mover)
            {
                output << *ifrom;
                output << " ";
                ++ifrom;
                count++;
            }
            output << *ifrom;
            ui->OutputDisplay->setText(QString::fromStdString(output.str()));
        }
        else if(ui->DoubleList->isChecked())
        {
            LinkedList<double>::Iterator ifrom;
            LinkedList<double>::Iterator ito;

            ifrom = activeDoubleList->begin();
            ito = activeDoubleList->begin();

            for(unsigned i = 0; i < from - 1; i++)
                ++ifrom;
            for(unsigned i = 0; i < to - 1; i++)
                ++ito;

            unsigned mover = to - from;
            unsigned count = 0;
            while(count < mover)
            {
                output << *ifrom;
                output << " ";
                ++ifrom;
                count++;
            }
            output << *ifrom;
            ui->OutputDisplay->setText(QString::fromStdString(output.str()));
        }
        else if(ui->StringList->isChecked())
        {
            LinkedList<string>::Iterator ifrom;
            LinkedList<string>::Iterator ito;

            ifrom = activeStringList->begin();
            ito = activeStringList->begin();

            for(unsigned i = 0; i < from - 1; i++)
                ++ifrom;
            for(unsigned i = 0; i < to - 1; i++)
                ++ito;

            unsigned mover = to - from;
            unsigned count = 0;
            while(count < mover)
            {
                output << *ifrom;
                output << " ";
                ++ifrom;
                count++;
            }
            output << *ifrom;
            ui->OutputDisplay->setText(QString::fromStdString(output.str()));
        }
        else if(ui->ComplexList->isChecked())
        {
            LinkedList<Complex>::Iterator ifrom;
            LinkedList<Complex>::Iterator ito;

            ifrom = activeComplexList->begin();
            ito = activeComplexList->begin();

            for(unsigned i = 0; i < from - 1; i++)
                ++ifrom;
            for(unsigned i = 0; i < to - 1; i++)
                ++ito;

            unsigned mover = to - from;
            unsigned count = 0;
            while(count < mover)
            {
                output << *ifrom;
                output << " ";
                ++ifrom;
                count++;
            }
            output << *ifrom;
            ui->OutputDisplay->setText(QString::fromStdString(output.str()));
        }
        else if(ui->DateList->isChecked())
        {
            LinkedList<Date>::Iterator ifrom;
            LinkedList<Date>::Iterator ito;

            ifrom = activeDateList->begin();
            ito = activeDateList->begin();

            for(unsigned i = 0; i < from - 1; i++)
                ++ifrom;
            for(unsigned i = 0; i < to - 1; i++)
                ++ito;

            unsigned mover = to - from;
            unsigned count = 0;
            while(count < mover)
            {
                output << *ifrom;
                output << " ";
                ++ifrom;
                count++;
            }
            output << *ifrom;
            ui->OutputDisplay->setText(QString::fromStdString(output.str()));
        }
        else if(ui->RationalList->isChecked())
        {
            LinkedList<Rational>::Iterator ifrom;
            LinkedList<Rational>::Iterator ito;

            ifrom = activeRationalList->begin();
            ito = activeRationalList->begin();

            for(unsigned i = 0; i < from - 1; i++)
                ++ifrom;
            for(unsigned i = 0; i < to - 1; i++)
                ++ito;

            unsigned mover = to - from;
            unsigned count = 0;
            while(count < mover)
            {
                output << *ifrom;
                output << " ";
                ++ifrom;
                count++;
            }
            output << *ifrom;
            ui->OutputDisplay->setText(QString::fromStdString(output.str()));
        }
    }
    catch (nullptr_t)
    {
        QMessageBox::critical(this, "ERROR", "The indices you "
                                             "entered are not in the list");
    }
}

/**************************************************************************
* slot on_ChangeListButton_clicked() : Class MainWindow
*--------------------------------------------------------------------------
* Activates: when ChangeListButton is clicked
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   none
*
* POST-CONDITIONS
* This will change the active list
**************************************************************************/
void MainWindow::on_ChangeListButton_clicked()
{
    try
    {
        if(ui->IntList->isChecked())
        {

            //cout << "IntList button is checked" << endl;
            string List_Name = AskForList("Change to which list?");
            //cout << "List_Name is: " << List_Name << endl;
            //cout << namesofIntLists.indexOf(List_Name) << endl;;
            if(namesofIntLists.indexOf(List_Name) != static_cast<unsigned>(-1))
            {
                activeIntList = nullptr;
                //cout << "if statement passed" << endl;
                activeIntList = IntListVector.at
                        (namesofIntLists.indexOf(List_Name));
                activeListName = List_Name;
                ui->ActiveListLabel->setText
                        (QString::fromStdString(activeListName));
            }
            //cout << "We got through this" << endl;

        }
        else if(ui->DoubleList->isChecked())
        {
            string List_Name = AskForList("Change to which list?");
            if(namesofDoubleLists.indexOf(List_Name) !=
                    static_cast<unsigned>(-1))
            {
                activeDoubleList = nullptr;
                activeDoubleList = DoubleListVector.at
                        (namesofDoubleLists.indexOf(List_Name));
                activeListName = List_Name;
                ui->ActiveListLabel->setText
                        (QString::fromStdString(activeListName));
            }

        }
        else if(ui->StringList->isChecked())
        {
            string List_Name = AskForList("Change to which list?");
            if(namesofStringLists.indexOf(List_Name) !=
                    static_cast<unsigned>(-1))
            {
                activeStringList = nullptr;
                activeStringList = StringListVector.at
                        (namesofStringLists.indexOf(List_Name));
                activeListName = List_Name;
                ui->ActiveListLabel->setText
                        (QString::fromStdString(activeListName));
            }

        }
        else if(ui->ComplexList->isChecked())
        {
            string List_Name = AskForList("Change to which list?");
            if(namesofComplexLists.indexOf(List_Name) !=
                    static_cast<unsigned>(-1))
            {
                activeComplexList = nullptr;
                activeComplexList = ComplexListVector.at
                        (namesofComplexLists.indexOf(List_Name));
                activeListName = List_Name;
                ui->ActiveListLabel->setText
                        (QString::fromStdString(activeListName));
            }

        }
        if(ui->DateList->isChecked())
        {
            string List_Name = AskForList("Change to which list?");
            if(namesofDateLists.indexOf(List_Name) != static_cast<unsigned>(-1))
            {
                activeDateList = nullptr;
                activeDateList = DateListVector.at
                        (namesofDateLists.indexOf(List_Name));
                activeListName = List_Name;
                ui->ActiveListLabel->setText
                        (QString::fromStdString(activeListName));
            }

        }
        else if(ui->RationalList->isChecked())
        {
            string List_Name = AskForList("Change to which list?");
            if(namesofRationalLists.indexOf(List_Name) !=
                    static_cast<unsigned>(-1))
            {
                activeRationalList = nullptr;
                activeRationalList = RationalListVector.at
                        (namesofRationalLists.indexOf(List_Name));
                activeListName = List_Name;
                ui->ActiveListLabel->setText
                        (QString::fromStdString(activeListName));
            }

        }
        QMessageBox::information(this, "", "List changed to " +
                                 QString::fromStdString(activeListName));

    }
    catch(nullptr_t)
    {
        QMessageBox::critical(this, "ERROR", "List does not exist");
    }

}

/**************************************************************************
* slot on_SortButton_clicked() : Class MainWindow
*--------------------------------------------------------------------------
* Activates: when SortButton is clicked
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   none
*
* POST-CONDITIONS
* This will sort a list using the select sort algorithm
**************************************************************************/
void MainWindow::on_SortButton_clicked()
{
    if(ui->IntList->isChecked())
    {
        if(activeIntList == nullptr)
            QMessageBox::critical(this, "ERROR",
                                  "Cannot sort uninitialied list");
        else
            activeIntList->select_sort();
    }
    else if(ui->DoubleList->isChecked())
    {
        if(activeDoubleList == nullptr)
            QMessageBox::critical(this, "ERROR",
                                  "Cannot sort uninitialied list");
        else
            activeDoubleList->select_sort();
    }
    else if(ui->StringList->isChecked())
    {
        if(activeStringList == nullptr)
            QMessageBox::critical(this, "ERROR",
                                  "Cannot sort uninitialied list");
        else
            activeStringList->select_sort();
    }
    else if(ui->ComplexList->isChecked())
    {
        if(activeComplexList == nullptr)
            QMessageBox::critical(this, "ERROR",
                                  "Cannot sort uninitialied list");
        else
            activeComplexList->select_sort();
    }
    else if(ui->DateList->isChecked())
    {
        if(activeDateList == nullptr)
            QMessageBox::critical(this, "ERROR",
                                  "Cannot sort uninitialied list");
        else
            activeDateList->select_sort();
    }
    else if(ui->RationalList->isChecked())
    {
        if(activeRationalList == nullptr)
            QMessageBox::critical(this, "ERROR",
                                  "Cannot sort uninitialied list");
        else
            activeRationalList->select_sort();
    }
    QMessageBox::information(this, "", "List sorted");
}

/**************************************************************************
* slot on_RemoveDuplicatesButton_clicked() : Class MainWindow
*--------------------------------------------------------------------------
* Activates: when RemoveDuplicatesButton is clicked
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   none
*
* POST-CONDITIONS
* This will remove the duplicates in a list
**************************************************************************/
void MainWindow::on_RemoveDuplicatesButton_clicked()
{
    if(ui->IntList->isChecked())
    {
        if(activeIntList == nullptr)
            QMessageBox::critical(this, "ERROR",
                                  "Cannot sort uninitialied list");
        else
            activeIntList->remove_duplicates();
    }
    else if(ui->DoubleList->isChecked())
    {
        if(activeDoubleList == nullptr)
            QMessageBox::critical(this, "ERROR",
                                  "Cannot sort uninitialied list");
        else
            activeDoubleList->remove_duplicates();
    }
    else if(ui->StringList->isChecked())
    {
        if(activeStringList == nullptr)
            QMessageBox::critical(this, "ERROR",
                                  "Cannot sort uninitialied list");
        else
            activeStringList->remove_duplicates();
    }
    else if(ui->ComplexList->isChecked())
    {
        if(activeComplexList == nullptr)
            QMessageBox::critical(this, "ERROR",
                                  "Cannot sort uninitialied list");
        else
            activeComplexList->remove_duplicates();
    }
    else if(ui->DateList->isChecked())
    {
        if(activeDateList == nullptr)
            QMessageBox::critical(this, "ERROR",
                                  "Cannot sort uninitialied list");
        else
            activeDateList->remove_duplicates();
    }
    else if(ui->RationalList->isChecked())
    {
        if(activeRationalList == nullptr)
            QMessageBox::critical(this, "ERROR",
                                  "Cannot act with uninitialied list");
        else
            activeRationalList->remove_duplicates();
    }
    QMessageBox::information(this, "", "Duplicates removed");
}

/**************************************************************************
* slot on_CopyListButton_clicked() : Class MainWindow
*--------------------------------------------------------------------------
* Activates: when CopyListButton is clicked
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   none
*
* POST-CONDITIONS
* This will copy a list
**************************************************************************/
void MainWindow::on_CopyListButton_clicked()
{
    ///////////////////////////////////////////////////////////////////////////
    /// Due to the repetitive nature of this method, a brief summary of     ///
    /// what the program does will be given at the beginning instead of at  ///
    /// every condition                                                     ///
    ///////////////////////////////////////////////////////////////////////////
    ///
    /// A new LinkedList pointer and an iterator will be created
    /// The iterator will point to the active list and extract the data from the
    /// active list and put it into the new list
    ///
    /// The new list will then be added to the list of vectors
    ///
    ///
    string List_Name = AskForList("Name of the new list");
    if(ui->IntList->isChecked())
    {


        LinkedList<int> *L = new LinkedList<int>;
        LinkedList<int>::Iterator I = activeIntList->begin();
        for(int i = 0; i < activeIntList->length(); i++)
        {
            L->push_back(*I);
            ++I;
        }
        IntListVector.push_back(L);
        namesofIntLists.push_back(List_Name);
        activeIntList = IntListVector.at(IntListVector.size() - 1);
        ui->ActiveListLabel->setText(QString::fromStdString(List_Name));

    }
    else if(ui->DoubleList->isChecked())
    {
        LinkedList<double> *L = new LinkedList<double>;
        LinkedList<double>::Iterator I = activeDoubleList->begin();
        for(int i = 0; i < activeDoubleList->length(); i++)
        {
            L->push_back(*I);
            ++I;
        }
        DoubleListVector.push_back(L);
        namesofDoubleLists.push_back(List_Name);
        activeDoubleList = DoubleListVector.at(DoubleListVector.size() - 1);
        ui->ActiveListLabel->setText(QString::fromStdString(List_Name));
    }
    else if(ui->StringList->isChecked())
    {
        LinkedList<string> *L = new LinkedList<string>;
        LinkedList<string>::Iterator I = activeStringList->begin();
        for(int i = 0; i < activeStringList->length(); i++)
        {
            L->push_back(*I);
            ++I;
        }
        StringListVector.push_back(L);
        namesofStringLists.push_back(List_Name);
        activeStringList = StringListVector.at(StringListVector.size() - 1);
        ui->ActiveListLabel->setText(QString::fromStdString(List_Name));

    }
    else if(ui->ComplexList->isChecked())
    {
        LinkedList<Complex> *L = new LinkedList<Complex>;
        LinkedList<Complex>::Iterator I = activeComplexList->begin();
        for(int i = 0; i < activeComplexList->length(); i++)
        {
            L->push_back(*I);
            ++I;
        }
        ComplexListVector.push_back(L);
        namesofComplexLists.push_back(List_Name);
        activeComplexList = ComplexListVector.at(ComplexListVector.size() - 1);
        ui->ActiveListLabel->setText(QString::fromStdString(List_Name));

    }
    else if(ui->DateList->isChecked())
    {
        LinkedList<Date> *L = new LinkedList<Date>;
        LinkedList<Date>::Iterator I = activeDateList->begin();
        for(int i = 0; i < activeDateList->length(); i++)
        {
            L->push_back(*I);
            ++I;
        }
        DateListVector.push_back(L);
        namesofDateLists.push_back(List_Name);
        activeDateList = DateListVector.at(DateListVector.size() - 1);
        ui->ActiveListLabel->setText(QString::fromStdString(List_Name));

    }
    else if(ui->RationalList->isChecked())
    {
        LinkedList<Rational> *L = new LinkedList<Rational>;
        LinkedList<Rational>::Iterator I = activeRationalList->begin();
        for(int i = 0; i < activeRationalList->length(); i++)
        {
            L->push_back(*I);
            ++I;
        }
        RationalListVector.push_back(L);
        namesofRationalLists.push_back(List_Name);
        activeRationalList = RationalListVector.at(RationalListVector.size()-1);
        ui->ActiveListLabel->setText(QString::fromStdString(List_Name));

    }
    QMessageBox::information(this, "", "List copied");

}

/**************************************************************************
* slot on_InsertSortedButton_clicked() : Class MainWindow
*--------------------------------------------------------------------------
* Activates: when InsertSortedButton is clicked
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   none
*
* POST-CONDITIONS
* This will assume the list is sorted and insert a node accordingly
**************************************************************************/
void MainWindow::on_InsertSortedButton_clicked()
{
    if(!ui->IntList->isChecked() && !ui->DoubleList->isChecked() &&
            !ui->StringList->isChecked() && !ui->ComplexList->isChecked() &&
            !ui->DateList->isChecked() && !ui->RationalList->isChecked())
    {
        QMessageBox::critical(this, "ERROR",
                              "Cannot add values to uninitialized list");
    }
    else
    {
        try
        {
            if(!(ui->DateList->isChecked()))
            {
                PushBackWindow PushBack(this, "PUSH_BACK");
                PushBack.setModal(true);
                PushBack.exec();
                if(ui->IntList->isChecked())
                {
                    if(!IntListVector.empty())
                        activeIntList->insert_sorted
                                (atoi(PushBack.getData().c_str()));
                }


                else if(ui->DoubleList->isChecked())
                {
                    if(!DoubleListVector.empty())
                        activeDoubleList->
                                insert_sorted(atof(PushBack.getData().c_str()));
                }

                else if(ui->StringList->isChecked())
                {
                    if(!StringListVector.empty())
                        activeStringList->insert_sorted(PushBack.getData());
                }

                else if(ui->ComplexList->isChecked())
                {
                    if(!ComplexListVector.empty())
                    {
                        Complex c;
                        c.fromString(PushBack.getData());
                        activeComplexList->insert_sorted(c);
                    }

                }
                else if(ui->RationalList->isChecked())
                {
                    if(!RationalListVector.empty())
                    {
                        Rational tempRational;
                        tempRational.fromString(PushBack.getData());
                        activeRationalList->insert_sorted(tempRational);
                    }
                }
            }
            else if(ui->DateList->isChecked())
            {
                Date d(static_cast<unsigned>
                       (ui->Calendar->selectedDate().month()),
                       static_cast<unsigned>
                       (ui->Calendar->selectedDate().day()),
                       static_cast<unsigned>
                       (ui->Calendar->selectedDate().year()));
                activeDateList->insert_sorted(d);
            }
        }
        catch(out_of_range)
        {
            QMessageBox::critical(this, "ERROR",
                                  "Cannot add values to uninitialized list");
        }
    }

}

/**************************************************************************
* slot on_InsertButton_clicked() : Class MainWindow
*--------------------------------------------------------------------------
* Activates: when InsertButton is clicked
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   none
*
* POST-CONDITIONS
* This will insert a node into a specified index
**************************************************************************/
void MainWindow::on_InsertButton_clicked()
{
    if(!(ui->DateList->isChecked()))
    {
        if(ui->IntList->isChecked())
        {
            ///Data will contain the data value
            /// Data will return the value to insert
            /// Data2 will return the index to insert the value in
            PushBackWindow Data(this, "Enter the data value");
            Data.setModal(true);
            Data.exec();
            int value = atoi(Data.getData().c_str());
            PushBackWindow Data2(this, "Enter the index");
            Data2.setModal(true);
            Data2.exec();
            unsigned index = static_cast<unsigned>(atoi
                                                   (Data2.getData().c_str()));
            activeIntList->insert(value, index);
        }
        else if(ui->DoubleList->isChecked())
        {
            ///Data will contain the data value
            /// Data will return the value to insert
            /// Data2 will return the index to insert the value in
            PushBackWindow Data(this, "Enter the data value");
            Data.setModal(true);
            Data.exec();
            double value = atof(Data.getData().c_str());
            PushBackWindow Data2(this, "Enter the index");
            Data2.setModal(true);
            Data2.exec();
            unsigned index = static_cast<unsigned>(atoi
                                                   (Data2.getData().c_str()));
            activeDoubleList->insert(value, index);
        }
        else if(ui->StringList->isChecked())
        {
            ///Data will contain the data value
            /// Data will return the value to insert
            /// Data2 will return the index to insert the value in
            PushBackWindow Data(this, "Enter the data value");
            Data.setModal(true);
            Data.exec();
            string value = Data.getData();
            PushBackWindow Data2(this, "Enter the index");
            Data2.setModal(true);
            Data2.exec();
            unsigned index = static_cast<unsigned>(atoi
                                                   (Data2.getData().c_str()));
            activeStringList->insert(value, index);
        }
        else if(ui->ComplexList->isChecked())
        {
            ///Data will contain the data value
            /// Data will return the value to insert
            /// Data2 will return the index to insert the value in
            PushBackWindow Data(this, "Enter the data value");
            Data.setModal(true);
            Data.exec();
            Complex value;
            value.fromString(Data.getData());
            PushBackWindow Data2(this, "Enter the index");
            Data2.setModal(true);
            Data2.exec();
            unsigned index = static_cast<unsigned>(atoi
                                                   (Data2.getData().c_str()));
            activeComplexList->insert(value, index);
        }
        else if(ui->RationalList->isChecked())
        {
            ///Data will contain the data value
            /// Data will return the value to insert
            /// Data2 will return the index to insert the value in
            PushBackWindow Data(this, "Enter the data value");
            Data.setModal(true);
            Data.exec();
            Rational value;
            value.fromString(Data.getData());
            PushBackWindow Data2(this, "Enter the index");
            Data2.setModal(true);
            Data2.exec();
            unsigned index = static_cast<unsigned>(atoi
                                                   (Data2.getData().c_str()));
            activeRationalList->insert(value, index);
        }
    }
    else if(ui->DateList->isChecked())
    {
        ///Data will contain the data value
        /// Data will return the value to insert
        /// Data2 will return the index to insert the value in
        PushBackWindow Data(this, "Enter the data value");
        Data.setModal(true);
        Data.exec();
        Date value(static_cast<unsigned>
               (ui->Calendar->selectedDate().month()),
               static_cast<unsigned>
               (ui->Calendar->selectedDate().day()),
               static_cast<unsigned>
               (ui->Calendar->selectedDate().year()));
        PushBackWindow Data2(this, "Enter the index");
        Data2.setModal(true);
        Data2.exec();
        unsigned index = static_cast<unsigned>(atoi(Data2.getData().c_str()));
        activeDateList->insert(value, index);
    }
    QMessageBox::information(this, "", "Value inserted");

}

/**************************************************************************
* slot on_DeleteListButton_clicked() : Class MainWindow
*--------------------------------------------------------------------------
* Activates: when DeleteListButton is clicked
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   none
*
* POST-CONDITIONS
* This will delete a list
**************************************************************************/
void MainWindow::on_DeleteListButton_clicked()
{
    string List_Name = AskForList("Enter the name of the list to delete");
    ///Checks if the list name is not null
    if(List_Name != "\0")
    {
        try
        {
            if(ui->IntList->isChecked())
            {
                ///Case if the list to delete is the most recent
                if(namesofIntLists.indexOf(List_Name) ==
                        namesofIntLists.size() - 1)
                {
                    LinkedList<int> *deleter = IntListVector.at
                            (namesofIntLists.size() - 1);
                    delete deleter;
                    ui->BoxofInts->removeItem(static_cast<int>
                                              (namesofIntLists.
                                               indexOf(List_Name)));
                    IntListVector.pop_back();
                    namesofIntLists.pop_back();
                }
                else
                {
                    cout << "Index to erase: " << namesofIntLists.
                            indexOf(List_Name);
                    cout << endl;
                    LinkedList<int> *deleter = IntListVector.at
                            (namesofIntLists.indexOf(List_Name));


                    ui->BoxofInts->removeItem(static_cast<int>
                                              (namesofIntLists.
                                               indexOf(List_Name)));
                    IntListVector.erase(namesofIntLists.indexOf(List_Name));
                    namesofIntLists.erase(namesofIntLists.indexOf(List_Name));
                    delete deleter;
                }

            }
            else if(ui->DoubleList->isChecked())
            {
                ///Case if the list to delete is the most recent
                if(namesofDoubleLists.indexOf(List_Name) ==
                        namesofDoubleLists.size() - 1)
                {
                    LinkedList<double> *deleter = DoubleListVector.at
                            (namesofDoubleLists.size() - 1);
                    delete deleter;
                    ui->BoxofDoubles->removeItem(static_cast<int>
                                              (namesofDoubleLists.
                                               indexOf(List_Name)));
                    DoubleListVector.pop_back();
                    namesofDoubleLists.pop_back();
                }
                else
                {
                    LinkedList<double> *deleter = DoubleListVector.at
                            (namesofDoubleLists.indexOf(List_Name));


                    ui->BoxofDoubles->removeItem(static_cast<int>
                                              (namesofDoubleLists.
                                               indexOf(List_Name)));
                    DoubleListVector.erase
                            (namesofDoubleLists.indexOf(List_Name));
                    namesofDoubleLists.erase
                            (namesofDoubleLists.indexOf(List_Name));
                    delete deleter;
                }
            }
            else if(ui->StringList->isChecked())
            {
                ///Case if the list to delete is the most recent
                if(namesofStringLists.indexOf(List_Name) ==
                        namesofStringLists.size() - 1)
                {
                    LinkedList<string> *deleter = StringListVector.at
                            (namesofStringLists.size() - 1);
                    delete deleter;
                    ui->BoxofStrings->removeItem(static_cast<int>
                                              (namesofStringLists.
                                               indexOf(List_Name)));
                    StringListVector.pop_back();
                    namesofStringLists.pop_back();
                }
                else
                {
                    LinkedList<string> *deleter = StringListVector.at
                            (namesofStringLists.indexOf(List_Name));


                    ui->BoxofStrings->removeItem(static_cast<int>
                                              (namesofStringLists.
                                               indexOf(List_Name)));
                    StringListVector.erase
                            (namesofStringLists.indexOf(List_Name));
                    namesofStringLists.erase
                            (namesofStringLists.indexOf(List_Name));
                    delete deleter;
                }
            }
            else if(ui->ComplexList->isChecked())
            {
                ///Case if the list to delete is the most recent
                if(namesofComplexLists.indexOf(List_Name) ==
                        namesofComplexLists.size() - 1)
                {
                    LinkedList<Complex> *deleter = ComplexListVector.at
                            (namesofComplexLists.size() - 1);
                    delete deleter;
                    ui->BoxofComplexes->removeItem(static_cast<int>
                                              (namesofComplexLists.
                                               indexOf(List_Name)));
                    ComplexListVector.pop_back();
                    namesofComplexLists.pop_back();
                }
                else
                {
                    LinkedList<Complex> *deleter = ComplexListVector.at
                            (namesofComplexLists.indexOf(List_Name));


                    ui->BoxofComplexes->removeItem(static_cast<int>
                                              (namesofComplexLists.
                                               indexOf(List_Name)));
                    ComplexListVector.erase
                            (namesofComplexLists.indexOf(List_Name));
                    namesofComplexLists.erase
                            (namesofComplexLists.indexOf(List_Name));
                    delete deleter;
                }
            }
            else if(ui->DateList->isChecked())
            {
                ///Case if the list to delete is the most recent
                if(namesofDateLists.indexOf(List_Name) ==
                        namesofDateLists.size() - 1)
                {
                    LinkedList<Date> *deleter = DateListVector.at
                            (namesofDateLists.size() - 1);
                    delete deleter;
                    ui->BoxofDates->removeItem(static_cast<int>
                                              (namesofDateLists.
                                               indexOf(List_Name)));
                    DateListVector.pop_back();
                    namesofDateLists.pop_back();
                }
                else
                {
                    LinkedList<Date> *deleter = DateListVector.at
                            (namesofDateLists.indexOf(List_Name));


                    ui->BoxofDates->removeItem(static_cast<int>
                                              (namesofDateLists.
                                               indexOf(List_Name)));
                    DateListVector.erase
                            (namesofDateLists.indexOf(List_Name));
                    namesofDateLists.erase
                            (namesofDateLists.indexOf(List_Name));
                    delete deleter;
                }
            }
            else if(ui->RationalList->isChecked())
            {
                ///Case if the list to delete is the most recent
                if(namesofRationalLists.indexOf(List_Name) ==
                        namesofRationalLists.size() - 1)
                {
                    LinkedList<Rational> *deleter = RationalListVector.at
                            (namesofRationalLists.size() - 1);
                    delete deleter;
                    ui->BoxofRationals->removeItem(static_cast<int>
                                              (namesofRationalLists.
                                               indexOf(List_Name)));
                    RationalListVector.pop_back();
                    namesofRationalLists.pop_back();
                }
                else
                {
                    LinkedList<Rational> *deleter = RationalListVector.at
                            (namesofRationalLists.indexOf(List_Name));


                    ui->BoxofRationals->removeItem(static_cast<int>
                                              (namesofRationalLists.
                                               indexOf(List_Name)));
                    RationalListVector.erase
                            (namesofRationalLists.indexOf(List_Name));
                    namesofRationalLists.erase
                            (namesofRationalLists.indexOf(List_Name));
                    delete deleter;
                }
            }
            QMessageBox::information(this, "", "List deleted");
        }
        catch(bad_alloc)
        {
            QMessageBox::critical(this, "ERROR", "Cannot delete active list.\n"
                                                 "Change lists or choose another "
                                                 "list");
        }

    }


}
