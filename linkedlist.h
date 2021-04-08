#ifndef LINKEDLIST_H
#define LINKEDLIST_H



#include "listempty.h"

#include <iostream>
#include <string>
#include <sstream>
#include "complex.h"
#include "rational.h"
template<typename E>


struct Node{
    E data;
    Node *next;
    Node( E data ) : data(data), next(0) {}
};


using namespace std;

template<typename E>
class LinkedList;

template<typename E>
class LinkedList
{
public:
    class Iterator
    {
        private:
            Node<E> *current;   //pointer that points to a certain node

        public:

            /***************
             * Constructor *
             ***************/

            Iterator();
            Iterator(Node<E> *ptr);  //Pointer that points to a node

            /*************
             * Operators *
             *************/
            E& operator* ();
            Iterator operator++();
            bool operator==(const Iterator& right) const;    //Other list
            bool operator!=(const Iterator &right) const;   //Other list

    };
private:
    Node<E> *head;
    Node<E> *tail;
    E dataSum(Node<E> *current) const;            //Node that
                                                        //points to the
                                                        //correct Node
    int recursionLength(Node<E> *current) const;    //Node that
                                                        //points to the
                                                        //correct Node

public:
    LinkedList();
    LinkedList(const LinkedList& source);   //LinkedList to copy
    ~LinkedList();
    LinkedList & operator= ( const LinkedList& source );
    string display() const throw(ListEmpty);
    void push_front( const E& value );
    void push_back( const E& value );

    void pop_front() throw(ListEmpty);
    const E& front() const throw(ListEmpty);
    const E& back() const throw(ListEmpty);
    void clear();
    void select_sort();
    void insert(const E& value, unsigned index);
    void insert_sorted( const E& value );
    void remove_duplicates();
    Iterator begin();
    Iterator end();
    int length() const;
    E sum() const;
    bool isEmpty() const;

};

/**********************************************************
 *
 * Method Iterator: Class Iterator
 *_________________________________________________________
 * This method constructs the Iterator class
 *_________________________________________________________
 * PRE-CONDITIONS
 *     none
 *
 * POST-CONDITIONS
 *     This function will construct an Iterator class
 ***********************************************************/
template<class E>
LinkedList<E>::Iterator::Iterator()
{
    current = nullptr;
}

/**********************************************************
 *
 * Method Iterator: Class Iterator
 *_________________________________________________________
 * This method constructs the Iterator class
 *_________________________________________________________
 * PRE-CONDITIONS
 *     ptr: pointer that points to an IntNode
 *
 * POST-CONDITIONS
 *     This function will construct an Iterator class
 ***********************************************************/
template<typename E>
LinkedList<E>::Iterator::Iterator(Node<E> *ptr)
{
    current = ptr;
}

/**********************************************************
 *
 * Operator *: Class Iterator
 *_________________________________________________________
 * Overloaded dereference operator
 *_________________________________________________________
 * PRE-CONDITIONS
 *     The following need pre-defined values:
 *     none
 *
 * POST-CONDITIONS
 *     This function will return the data in the node
 ***********************************************************/
template<typename E>
E& LinkedList<E>::Iterator::operator*()
{
    return current->data;
}

/**********************************************************
 *
 * Operator ++: Class Iterator
 *_________________________________________________________
 * Overloaded decrement operator
 *_________________________________________________________
 * PRE-CONDITIONS
 *     The following need pre-defined values:
 *     none
 *
 * POST-CONDITIONS
 *     This function will update the Iterator to point
 *          to the next node in the
 ***********************************************************/
template<typename E>
typename LinkedList<E>::Iterator LinkedList<E>::Iterator::operator++()
{
    current = current->next;
    return *this;
}

/**********************************************************
 *
 * Operator ==: Class Iterator
 *_________________________________________________________
 * Overloaded equality operator
 *_________________________________________________________
 * PRE-CONDITIONS
 *     The following need pre-defined values:
 *     right: Iterator to compare to
 *
 * POST-CONDITIONS
 *     This function will check if two Iterators are equal
 ***********************************************************/
template<typename E>
bool LinkedList<E>::Iterator::operator==
(const LinkedList<E>::Iterator &right) const
{
    if(current == &right)
        return true;
    return false;
}

/**********************************************************
 *
 * Operator !=: Class Iterator
 *_________________________________________________________
 * Overloaded inequality operator
 *_________________________________________________________
 * PRE-CONDITIONS
 *     The following need pre-defined values:
 *     right: Iterator to compare to
 *
 * POST-CONDITIONS
 *     This function will check if two Iterators are not equal
 ***********************************************************/
template<typename E>
bool LinkedList<E>::Iterator::operator!=(
        const LinkedList<E>::Iterator &right) const     //Iterator to compare to
{
    if(this == &right)
        return false;
    return true;
}

///!LinkedList comments start here!///



/**********************************************************
 *
 * Method LinkedList: Class LinkedList
 *_________________________________________________________
 * This method constructs the LinkedList class
 *_________________________________________________________
 * PRE-CONDITIONS
 *     none
 *
 * POST-CONDITIONS
 *     This function will construct an LinkedList class
 ***********************************************************/
template<class E>
LinkedList<E>::LinkedList()
{
    //Sets the value of the first Node<E> to 0
    head = nullptr;
    tail = nullptr;
}

/**********************************************************
 *
 * Method LinkedList: Class LinkedList
 *_________________________________________________________
 * Overloaded copy constructor
 *_________________________________________________________
 * PRE-CONDITIONS
 *     none
 *
 * POST-CONDITIONS
 *     This function will construct an LinkedList class
 ***********************************************************/
template<class E>
LinkedList<E>::LinkedList(const LinkedList<E> &source)
{
    for(Node<E> *i = source.head; i != source.tail; i = i->next)
    {
        this->push_back(i->data);
    }
    this->push_back(source.tail->data);
}

/**********************************************************
 *
 * Method LinkedList: Class LinkedList
 *_________________________________________________________
 * This method deconstructs the LinkedList class
 *_________________________________________________________
 * PRE-CONDITIONS
 *     none
 *
 * POST-CONDITIONS
 *     This function will deconstruct an LinkedList class
 ***********************************************************/
template<class E>
LinkedList<E>::~LinkedList<E>()
{
    Node<E> *start = head;
    while(start != tail)
    {
        Node<E> *stay = start;
        start = start->next;
        delete stay;
    }
    delete tail;
}

/**********************************************************
 *
 * Method display: Class LinkedList
 *_________________________________________________________
 * This method displays the contents of an LinkedList
 *_________________________________________________________
 * PRE-CONDITIONS
 *     none
 *
 * POST-CONDITIONS
 *     This function will go through the LinkedList and display
 *          all values in it
 ***********************************************************/
template<class E>
string LinkedList<E>::display() const throw(ListEmpty)
{
    Node<E> *i = head;
    ostringstream output;
    try
    {
        if(head == NULL)
            throw ListEmpty();
        while(i != NULL)
        {
            output << i->data << " ";
            i = i->next;
        }
        return output.str();
    }
    catch (ListEmpty)
    {
        throw;
    }
    cout << "Ended display" << endl;
}

/**********************************************************
 *
 * Method push_front: Class LinkedList
 *_________________________________________________________
 * This method adds a new value to the front of the LinkedList
 *_________________________________________________________
 * PRE-CONDITIONS
 *     The following need pre-defined values
 *         value: int value to add to the front of the list
 *
 * POST-CONDITIONS
 *     This function will add a value to the front of the LinkedList
 ***********************************************************/
template<class E>
void LinkedList<E>::push_front(const E& value)     //Value to add to the front of the list
{
    //cout << "Got to push_front" << endl;
    if(head == nullptr)
    {
        //cout << "head->next = 0" << endl;
        Node<E> *add = new Node<E>(value);
        head = add;
        tail = head;
    }
    else
    {
        Node<E> *start = new Node<E>(value);
        start->next = head;
        head = start;
    }
    //cout << head->data << endl;
}

/**********************************************************
 *
 * Method push_back: Class LinkedList
 *_________________________________________________________
 * This method adds a new value to the back of the LinkedList
 *_________________________________________________________
 * PRE-CONDITIONS
 *     The following need pre-defined values
 *         value: int value to add to the back of the list
 *
 * POST-CONDITIONS
 *     This function will add a value to the back of the LinkedList
 ***********************************************************/
template<class E>
void LinkedList<E>::push_back(const E& value)      //Value to add to the back of the list
{
    if(head == nullptr)
    {
        head = new Node<E>(value);
        tail = head;
    }
    else
    {
        Node<E> *add = new Node<E>(value);
        tail->next = add;
        tail = add;
    }
}

/**********************************************************
 *
 * Method pop_front: Class LinkedList
 *_________________________________________________________
 * This method deletes the value at the front of the LinkedList
 *_________________________________________________________
 * PRE-CONDITIONS
 *     The following need pre-defined values
 *         value: value to insert
 *
 * POST-CONDITIONS
 *     This function will delete the value at the front of the LinkedList
 ***********************************************************/
template<class E>
void LinkedList<E>::pop_front() throw (ListEmpty)
{
    try
    {
        if(head == NULL)
            throw ListEmpty();

        Node<E> *temp;
        temp = head;
        head = head->next;
        delete temp;
    }
    catch (ListEmpty)
    {
        throw;
    }

}

/**********************************************************
 *
 * Method select_sort: Class LinkedList
 *_________________________________________________________
 * This method sorts the values of the LinkedList in ascending order
 *_________________________________________________________
 * PRE-CONDITIONS
 *     The following need pre-defined values:
 *     none
 *
 * POST-CONDITIONS
 *     This function will sort the values of the list
 ***********************************************************/
template<class E>
void LinkedList<E>::select_sort()
{

    Node<E> *current;           //Current Node to check
    Node<E> *beforecurrent;     //Node that stores the Node before current
    beforecurrent = head;
    current = head;

    //cout << "Before while loop" << endl;
    int repValue = 0;//repValue checks if the loop has already gone once through
    while(current != NULL)
    {
        E min = current->data;       //Value that acts as an test value
        int temp = 0;               //Temporary index to store the location
                                        //of the lowest value
        int index;                  //Index of the lowest value

        //cout << "Comparing string data" << endl;



        //Finds the minimum value in the list
        for(Node<E> *i = current; i != 0; i = i->next)
        {
//            if(i->data < min)
//                cout << i->data << " is less than " << min << endl;
//            else if(i->data == min)
//                cout << i->data << " is equal to " << min << endl;
//            else
//                cout << i->data << " is greater than " << min << endl;
            if(i->data <= min)
            {
                min = i->data;
                index = temp;
            }
            temp++;
        }
        //cout << "min is: " << min << " at index " << index << endl;


        Node<E> *tempPtr;   //Value that points to the Node to switch
        Node<E> *tempPtr2;  //Always points to current
        Node<E> *linker;    //Points to the one before tempPtr

        tempPtr = current;
        tempPtr2 = current;
        linker = current;

        //Finds the index of the lowest value
        for(int i = 0; i < index; i++)
        {
            tempPtr = tempPtr->next;
            if(i != 0)
                linker = linker->next;
        }
        tempPtr2 = tempPtr->next;



        //cout << "Index of the lowest value has been found" << endl;


        //Case if the values to switch are not right next to each other
        if(current->next != tempPtr)
        {
            //Case if we need to switch the last value with another
            if(tempPtr2 == NULL)
            {

                if(repValue != 0)
                    beforecurrent->next = tempPtr;
                tempPtr->next = current->next;
                linker->next = current;
                current->next = NULL;
                tail = current;
                //cout << "After switching the last value" << endl;
            }

            //Normal node switch operation
            else
            {

                tempPtr->next = current->next;
                if(repValue != 0)
                    beforecurrent->next = tempPtr;
                linker->next = current;
                current->next = tempPtr2;
                //cout << "After normal switch operation" << endl;
            }
        }



        //Case if the nodes to switch are consecutive
        else
        {
            tempPtr->next = current;
            if(repValue != 0)
                beforecurrent->next = tempPtr;
            current->next = tempPtr2;

            //cout << "After switching consecutive nodes" << endl;
        }

        //If this is the first swap, head will point to the new swapped node
        if(repValue == 0)
        {
            head = tempPtr;
            current = tempPtr;
        }
        else
            current = tempPtr;

        current = current->next;
        if(repValue == 0)
            beforecurrent = head;
        if(repValue != 0)
            beforecurrent = beforecurrent->next;

        repValue++;
//        this->display();
//        cout << endl;


    }
    //cout << tail->data << endl;


}

/**********************************************************
 *
 * Method insert: Class LinkedList
 *_________________________________________________________
 * This method inserts a node into the LinkedList
 *_________________________________________________________
 * PRE-CONDITIONS
 *     The following need pre-defined values:
 *     value: E value to insert
 *     index: unsigned value. Index to insert the data
 *
 * POST-CONDITIONS
 *     This function will insert a new value into any part of
 *     the list
 ***********************************************************/
template<class E>
void LinkedList<E>::insert(const E& value, unsigned index)
{
    cout << "Inside insert function" << endl;
    //These cases execute if the user tries to insert a value at the beginning
        //or end of the list
    if(index == 1)
    {
        cout << "index = 1" << endl;
        push_front(value);
    }
    else if(index >= length())
        push_back(value);




    else
    {
        unsigned location;
        cout << "index was not greater than length" << endl;

        Node<E> *n = new Node<E> (value);   //Node that contains new data

        Node<E> *previous = head;       //Node that points to the node before
                                            //the insert location
        Node<E> *post = head;          //Node that points to the node after
                                            //the insert location
        for(unsigned i = 0; i < index - 2; i++)
        {
            previous = previous->next;
            post = post->next;
            location++;
        }
        cout << "Location is " << location << endl;

        post = post->next;
        if(post == tail)
        {
            cout << "post = tail" << endl;
            previous->next = n;
            n->next = tail;
        }
        else
        {
            cout << "post != tail" << endl;
            post = previous->next;
            previous->next = n;
            n->next = post;
        }
    }


}
/**********************************************************
 *
 * Method insert_sorted: Class LinkedList
 *_________________________________________________________
 * This method inserts a value into the correct location of the list
 *_________________________________________________________
 * PRE-CONDITIONS
 *     The following need pre-defined values:
 *         value: value to insert
 *
 * POST-CONDITIONS
 *     This function will insert an Node containing value into the
 *         correct location of the LinkedList
 ***********************************************************/
template<class E>
void LinkedList<E>::insert_sorted(const E& value) //Value to insert
{
    Node<E> *add = new Node<E>(value);
    Node<E> *current = head;
    if(value < head->data)
    {
        push_front(value);
//        add->next = head;
//        head = add;
    }
    else
    {
        for(Node<E> *i = current; i->next->data < value; i = i->next)
        {
            current = current->next;
        }
        add->next = current->next;
        current->next = add;
    }

}

/**********************************************************
 *
 * Method remove_duplicates: Class LinkedList
 *_________________________________________________________
 * This method removes all duplicates from the list
 *_________________________________________________________
 * PRE-CONDITIONS
 *     The following need pre-defined values:
 *     none
 *
 * POST-CONDITIONS
 *     This function will remove all Nodes containing duplicate ints
 ***********************************************************/
template<class E>
void LinkedList<E>::remove_duplicates()
{

    Node<E> *start = head;
    Node<E> *Parser = head;
    Node<E> *deleter;

    while(start != NULL && start->next != NULL)
    {
        Parser = start;
        while(Parser->next != NULL)
        {
            if(start->data == Parser->next->data)
            {
                deleter = Parser->next;
                if(deleter == tail)
                    tail = Parser;
                Parser->next = Parser->next->next;
                delete deleter;
            }
            else
                Parser = Parser->next;
        }
        start = start->next;
    }
}


/**********************************************************
 *
 * Method begin: Class LinkedList
 *_________________________________________________________
 * This method returns an iterator that points to the beginning of the list
 *_________________________________________________________
 * PRE-CONDITIONS
 *     The following need pre-defined values:
 *     none
 *
 * POST-CONDITIONS
 *     This function will return an iterator that points to the
 *      beginning of the list
 ***********************************************************/
template<class E>
typename LinkedList<E>::Iterator LinkedList<E>::begin()
{
    Iterator a(head);
    return a;
}

/**********************************************************
 *
 * Method end: Class LinkedList
 *_________________________________________________________
 * This method returns an iterator that points to the end of the list
 *_________________________________________________________
 * PRE-CONDITIONS
 *     The following need pre-defined values:
 *     none
 *
 * POST-CONDITIONS
 *     This function returns an iterator that points to the end of the list
 ***********************************************************/
template<class E>
typename LinkedList<E>::Iterator LinkedList<E>::end()
{
    Iterator a(tail->next);
    return a;
}

/**********************************************************
 *
 * Method front: Class LinkedList
 *_________________________________________________________
 * This method returns the data at the first Node<E>
 *_________________________________________________________
 * PRE-CONDITIONS
 *     The following need pre-defined values:
 *     none
 *
 * POST-CONDITIONS
 *     This function will return the first int in the list
 ***********************************************************/
template<class E>
const E& LinkedList<E>::front() const throw(ListEmpty)
{
    try
    {
        if(head == NULL)
            throw ListEmpty();
        return head->data;
    }
    catch (ListEmpty)
    {
        throw;
    }
}

/**********************************************************
 *
 * Method back: Class LinkedList
 *_________________________________________________________
 * This method returns the data at the end Node<E>
 *_________________________________________________________
 * PRE-CONDITIONS
 *     The following need pre-defined values:
 *     none
 *
 * POST-CONDITIONS
 *     This function will return the last int in the list
 ***********************************************************/
template<class E>
const E& LinkedList<E>::back() const throw(ListEmpty)
{
    try
    {
        if(head == NULL)
            throw ListEmpty();
        return tail->data;
    }
    catch (ListEmpty)
    {
        throw;
    }

}

/**********************************************************
 *
 * Method sum: Class LinkedList
 *_________________________________________________________
 * This method returns the sum of all the data in the list
 *_________________________________________________________
 * PRE-CONDITIONS
 *     The following need pre-defined values:
 *     none
 *
 * POST-CONDITIONS
 *     This function will return sum of the data in the list
 ***********************************************************/
template<class E>
E LinkedList<E>::sum() const
{
    return dataSum(head);
}

/**********************************************************
 *
 * Method sum: Class LinkedList
 *_________________________________________________________
 * This method returns the sum of all the data in the list
 *_________________________________________________________
 * PRE-CONDITIONS
 *     The following need pre-defined values:
 *     none
 *
 * POST-CONDITIONS
 *     This function will return sum of the data in the list
 ***********************************************************/
template<class E>
E LinkedList<E>::dataSum(Node<E> *current) const
{
    if(current == NULL)
        return 0;
    else
        return current->data + dataSum(current->next);
}
/**********************************************************
 *
 * Method length: Class LinkedList
 *_________________________________________________________
 * This method recursively determines the length of the LinkedList
 *_________________________________________________________
 * PRE-CONDITIONS
 *     The following need pre-defined values:
 *     none
 *
 * POST-CONDITIONS
 *     This function will return the length of the list
 ***********************************************************/
template<class E>
int LinkedList<E>::length() const
{
    return recursionLength(head);
}

/**********************************************************
 *
 * Method recursionLength: Class LinkedList
 *_________________________________________________________
 * This method recursively determines the length of the list
 *_________________________________________________________
 * PRE-CONDITIONS
 *     The following need pre-defined values:
 *     current: pointer to an Node<E>
 *
 * POST-CONDITIONS
 *     This function will return the length of the list
 ***********************************************************/
template<class E>
int LinkedList<E>::recursionLength(Node<E> *current) const    //Pointer to an Node<E>
{
    if(current != NULL)
        return 1 + recursionLength(current->next);
    else
        return 0;
}

/**********************************************************
 *
 * Operator =: Class LinkedList
 *_________________________________________________________
 * Overloaded assignment operator
 *_________________________________________________________
 * PRE-CONDITIONS
 *     The following need pre-defined values:
 *     list: LinkedList to copy
 *
 * POST-CONDITIONS
 *     This function will copy one LinkedList to another
 ***********************************************************/
template<class E>
LinkedList<E>& LinkedList<E>::operator=(const LinkedList<E> &list)    //LinkedList to copy
{
    ///If the list is uninitialized, basically call the copy constructor
    if(head == nullptr)
    {
        for(Node<E> *i = list.head; i != list.tail; i = i->next)
        {
            this->push_back(i->data);
        }
        this->push_back(list.tail->data);
        return *this;
    }
    else
    {

        ///If this is already defined, we delete all data in this
        Node<E> *i = this->head;
        while(i != NULL)
        {
            Node<E> *deleted = i;
            i = i->next;
            delete deleted;
        }


        ///Setting this->head to 0 so push_back will work
        this->head = nullptr;

        for(Node<E> *i = list.head; i != list.tail; i = i->next)
        {
            this->push_back(i->data);
        }
        this->push_back(list.tail->data);
        return *this;
    }


}
/**********************************************************
 *
 * Method isEmpty: Class LinkedList
 *_________________________________________________________
 * This method determines if the list is empty
 *_________________________________________________________
 * PRE-CONDITIONS
 *     The following need pre-defined values:
 *     none
 *
 * POST-CONDITIONS
 *     This function will return true if the list is empty;
 *     false otherwise
 ***********************************************************/
template<class E>
bool LinkedList<E>::isEmpty() const
{
    if(head == NULL)
        return true;
    return false;
}

/**********************************************************
 *
 * Method clear: Class LinkedList
 *_________________________________________________________
 * This method destroys the list
 *_________________________________________________________
 * PRE-CONDITIONS
 *     The following need pre-defined values:
 *     none
 *
 * POST-CONDITIONS
 *     This function will delete all nodes in the list
 ***********************************************************/
template<class E>
void LinkedList<E>::clear()
{
    while(head != NULL)
    {
        this->pop_front();
        this->display();
        cout << endl;
    }

}

#endif // LINKEDLIST_H

///This is for the nested Iterator class

/****************************
CONSTRUCTORS
****************************/

/****************************************************************
* Iterator();
* Constructor; default constructor that initializes an empty pointer
*
* Parameters: none
* Returns: nothing
***************************************************************/

/****************************************************************
* Iterator(Node *ptr);
* Constructor; takes in a pointer
*
* Parameters: none
* Returns: nothing
***************************************************************/

/****************************************************************
* bool operator==(const Iterator& right) const;
* Operator; overloaded equality operator
*
* Parameters: none
* Returns: true if the iterators are equal
***************************************************************/

/****************************************************************
* bool operator!=(const Iterator& right) const;
* Operator; overloaded inequality operator
*
* Parameters: none
* Returns: true if the iterators are not equal
***************************************************************/

/****************************************************************
* Iterator operator*() const;
* Operator; overloaded dereference operator
*
* Parameters: none
* Returns: the data in the current node
***************************************************************/

/****************************************************************
* Iterator operator++() const;
* Operator; overloaded postfix operator operator
*
* Parameters: none
* Returns: the data in the current node
***************************************************************/



///This is for the LinkedList class
/****************************
CONSTRUCTORS
****************************/

/****************************************************************
* LinkedList();
* Constructor; default constructor that initializes an empty list
*
* Parameters: none
* Returns: nothing but a list is now declared
***************************************************************/

/****************************************************************
* LinkedList(const LinkedList& source);
* Constructor; overloaded copy constructor
*
* Parameters: none
* Returns: nothing but a list is now declared
***************************************************************/

/****************************************************************
* ~LinkedList();
* Destructor; default destructor that deallocates all the dynamically
* allocated memory for the list
*
* Parameters: none
* Returns: nothing but the memory allocated for the list is removed
***************************************************************/

/****************************
ACCESSORS
****************************/

/****************************************************************
* void display() const;
* Accessor; accessor function that will display all the current
* data values in the list
*
* Parameters: none
* Returns: nothing but all values from the the list will be displayed
***************************************************************/

/****************************************************************
* Iterator begin();
* Accessor; function that will return the first value in the list
*
* Parameters: none
* Returns: an IntNode pointing to head
***************************************************************/

/****************************************************************
* Iterator end();
* Accessor; function that will return one more than the last value in the list
*
* Parameters: none
* Returns: an IntNode pointing to null
***************************************************************/

/****************************************************************
* Iterator front();
* Accessor; function that will return the first value in the list
*
* Parameters: none
* Returns: the first value in the list
***************************************************************/

/****************************************************************
* Iterator back();
* Accessor; function that will return the last value in the list
*
* Parameters: none
* Returns: the last value in the list
***************************************************************/

/****************************************************************
* int length() const;
* Accessor; function that will recursively return the size of the list
*
* Parameters: none
* Returns: the number of elements in the list
***************************************************************/

/****************************************************************
* int sum() const;
* Accessor; function that will return the sum of the elements in the list
*
* Parameters: none
* Returns: the sum of elements in the list
***************************************************************/

/****************************************************************
* void reverseDisplay() const;
* Accessor; function that calls recursionLength()
*
* Parameters: none
* Returns: nothing
***************************************************************/

/****************************************************************
* int recursionLength(Node *current) const;
* Accessor; function that will return the number of nodes in the list
*
* Parameters: none
* Returns: nothing
***************************************************************/

/****************************************************************
* void showReverse(Node *current) const;
* Accessor; function that will display the list in reverse order
*
* Parameters: none
* Returns: nothing
***************************************************************/

/****************************
MUTATORS
****************************/

/****************************************************************
* void push_front(int value);
* Mutator; Mutator function that will adjust the list by adding a
* new node to the front of the list
*
* Parameters: int value - the value that will be stored
* Returns: nothing but a new value is stored at the front of the list
***************************************************************/

/****************************************************************
* void push_back();
* Mutator; Mutator function that will adjust the list by adding a
* node to the back of the list
*
* Parameters: none
* Returns: nothing
***************************************************************/

/****************************************************************
* void pop_front();
* Mutator; Mutator function that will adjust the list by removing the
* node from the front of the list
*
* Parameters: none
* Returns: nothing but a the front-most node is removed
***************************************************************/

/****************************************************************
* void select_sort();
* Mutator; Mutator function that will sort the list from lowest
* to highest
*
* Parameters: none
* Returns: nothing
***************************************************************/

/****************************************************************
* void insert(E& value, unsigned index);
* Mutator; Mutator function that will insert a node with data value
* into the index index
*
* Parameters:
*           value: Value to insert
*           index: index to insert the new node into
* Returns: nothing
***************************************************************/

/****************************************************************
* void insert_sorted();
* Mutator; Mutator function that will insert a value in a place
* so that the list will still be sorted
*
* Parameters: none
* Returns: nothing
***************************************************************/

/****************************************************************
* void remove_duplicates();
* Mutator; Mutator function that will remove all duplicates from the list
*
* Parameters: none
* Returns: nothing
***************************************************************/

/****************************************************************
* LinkedList& operator=(const LinkedList& source);
* Operator; overloaded assignment operator
*
* Parameters: none
* Returns: a LinkedList
***************************************************************/
