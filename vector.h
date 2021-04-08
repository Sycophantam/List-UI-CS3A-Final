#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstdlib>

using namespace std;

template<class E>
class Vector
{
    private:
        unsigned sz;        //Size of the vector
        unsigned cap;       //Capacity of the vector
        E *data;          //Pointer to return data
    public:

        /*******************************
         ******** CONSTRUCTORS *********
         *******************************/

        Vector();
        Vector(unsigned size);   //Size of the vector
        Vector(unsigned size,    //Size of the vector
                  E& value);       //Vector contents

        Vector(const Vector& v);    //Vector to copy
        ~Vector();

        /***************
         ** ACCESSORS **
         ***************/

        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const E& at(unsigned index) const;    //Index to return
        E& at(unsigned index);                //Index to return
        const E& front() const;
        E& front();
        const E& back() const;
        E& back();
        unsigned indexOf(E& data);

        /**************
         ** MUTATORS **
         **************/
    private:
        void expand();
        void expand(unsigned amount);
    public:
        void assign(unsigned n,         //New size
                    E& value);         //Value in the new Vector
        void push_back(E& value);      //Value to add
        void pop_back();
        void insert(unsigned index,     //Index where the value is inserted
                    E& value);         //Value to insert
        void clear();
        void resize(unsigned size);     //New size
        void resize(unsigned size,      //New size
                    E& value);         //Value to fill
        void erase(unsigned index);     //Index to erase
        void reserve(unsigned n);       //New size
        Vector operator = (const Vector& right);    //vector to copy
};



/**********************************************************
 *
 * Method Vector<E>: Class Vector
 *_________________________________________________________
 * This method constructs the Vector class
 *_________________________________________________________
 * PRE-CONDITIONS
 *     none
 *
 * POST-CONDITIONS
 *     This function will construct an Vector class
 ***********************************************************/
template<class E>
Vector<E>::Vector()
{
    sz = 0;
    cap = 0;
    data = nullptr;
}
/**********************************************************
 *
 * Method Vector<E>(unsigned size): Class Vector
 *_________________________________________________________
 * This method constructs the Vector class
 *_________________________________________________________
 * PRE-CONDITIONS
 *     size: size of the vector
 *
 * POST-CONDITIONS
 *     This function will construct an Vector class
 ***********************************************************/
template<class E>
Vector<E>::Vector(unsigned size)
{
    sz = size;
    cap = size;
    data = new E[size];
    for(unsigned i = 0; i < size; i++)
    {
        *(data + i) = 0;
    }
}
/**********************************************************
 *
 * Method Vector<E>(unsigned size, int value): Class Vector
 *_________________________________________________________
 * This method constructs the Vector class
 *_________________________________________________________
 * PRE-CONDITIONS
 *     size: size of the Vector
 *     value: value to fill the Vector with
 *
 * POST-CONDITIONS
 *     This function will construct an Vector class
 ***********************************************************/
template<class E>
Vector<E>::Vector(unsigned size, E& value)
{
    sz = size;
    cap = size;
    data = new E[size];
    for(unsigned i = 0; i < size; i++)
    {
        *(data + i) = value;
    }
}
/**********************************************************
 *
 * Method Vector<E>: Class Vector
 *_________________________________________________________
 * This method deconstructs the Vector class
 *_________________________________________________________
 * PRE-CONDITIONS
 *     no pre conditions
 *
 * POST-CONDITIONS
 *     This function will deconstruct a Vector class
 ***********************************************************/
template<class E>
Vector<E>::~Vector()
{
    delete [] data;
}
/**********************************************************
 *
 * Method size: Class Vector
 *_________________________________________________________
 * This method returns the size of the Vector
 *_________________________________________________________
 * PRE-CONDITIONS
 *     none
 *
 * POST-CONDITIONS
 *     This function returns the size of the Vector
 ***********************************************************/
template<class E>
unsigned Vector<E>::size() const
{
    return sz;
}
/**********************************************************
 *
 * Method capacity: Class Vector
 *_________________________________________________________
 * This method returns the capacity of the Vector
 *_________________________________________________________
 * PRE-CONDITIONS
 *     none
 *
 * POST-CONDITIONS
 *     This function returns the capacity of the Vector
 ***********************************************************/
template<class E>
unsigned Vector<E>::capacity() const
{
    return cap;
}
/**********************************************************
 *
 * Method empty: Class Vector
 *_________________________________________________________
 * This method returns true or false if the vector is empty
 *_________________________________________________________
 * PRE-CONDITIONS
 *     none
 *
 * POST-CONDITIONS
 *     This function returns true if the vector is empty
 ***********************************************************/
template<class E>
bool Vector<E>::empty() const
{
    if(sz == 0)
    {
        return true;
    }
    return false;
}

/**********************************************************
 *
 * Method at: Class Vector
 *_________________________________________________________
 * This method returns the value at the specified index
 *_________________________________________________________
 * PRE-CONDITIONS
 *     none
 *
 * POST-CONDITIONS
 *     This function returns the value at the specified index
 ***********************************************************/
template<class E>
const E& Vector<E>::at(unsigned index) const
{
    return *(data + index);
}

/**********************************************************
 *
 * Method at: Class Vector
 *_________________________________________________________
 * This method returns the value at the specified index
 *_________________________________________________________
 * PRE-CONDITIONS
 *     none
 *
 * POST-CONDITIONS
 *     This function returns the value at the specified index
 ***********************************************************/
template<class E>
E& Vector<E>::at(unsigned index)
{
    return *(data + index);
}

/**********************************************************
 *
 * Method front: Class Vector
 *_________________________________________________________
 * This method returns the value at the front of the Vector
 *_________________________________________________________
 * PRE-CONDITIONS
 *     none
 *
 * POST-CONDITIONS
 *     This function returns the first value of the Vector
 ***********************************************************/
template<class E>
const E& Vector<E>::front() const
{
    return *(data);
}
/**********************************************************
 *
 * Method front: Class Vector
 *_________________________________________________________
 * This method returns the value at the front of the Vector
 *_________________________________________________________
 * PRE-CONDITIONS
 *     none
 *
 * POST-CONDITIONS
 *     This function returns the first value of the Vector
 ***********************************************************/
template<class E>
E& Vector<E>::front()
{
    return *(data);
}

/**********************************************************
 *
 * Method back: Class Vector
 *_________________________________________________________
 * This method returns the value at the back of the Vector
 *_________________________________________________________
 * PRE-CONDITIONS
 *     none
 *
 * POST-CONDITIONS
 *     This function returns the last value of the Vector
 ***********************************************************/
template<class E>
const E& Vector<E>::back() const
{
    return *(data + (sz-1));
}

/**********************************************************
 *
 * Method back: Class Vector
 *_________________________________________________________
 * This method returns the value at the back of the Vector
 *_________________________________________________________
 * PRE-CONDITIONS
 *     none
 *
 * POST-CONDITIONS
 *     This function returns the last value of the Vector
 ***********************************************************/
template<class E>
E& Vector<E>::back()
{
    return *(data + (sz-1));
}
/**********************************************************
 *
 * Method expand: Class Vector
 *_________________________________________________________
 * This method doubles the capacity of the Vector
 *_________________________________________________________
 * PRE-CONDITIONS
 *     none
 *
 * POST-CONDITIONS
 *     This function expands the capacity of the Vector
 ***********************************************************/
template<class E>
void Vector<E>::expand()
{
    cap *= 2;
    //cout << "cap = " << cap << endl;
    E *tempPtr = new E[cap];
    for(unsigned i = 0; i < sz; i++)
    {
        *(tempPtr + i) = *(data + i);
    }

    delete[] data;
    data = tempPtr;

//    for(unsigned i = sz; i < cap; i++)
//    {
//        *(data + i) = E();
//    }
    tempPtr = NULL;
}
/**********************************************************
 *
 * Method expand: Class Vector
 *_________________________________________________________
 * This method expands the capacity of the Vector by a value
 *_________________________________________________________
 * PRE-CONDITIONS
 *     amount: the value by which to expand the Vector's capacity
 *
 * POST-CONDITIONS
 *     This function expands the capacity of the Vector
 ***********************************************************/
template<class E>
void Vector<E>::expand(unsigned amount)
{
    cap += amount;
    E *tempPtr = new E[cap];
    for(unsigned i = 0; i < sz; i++)
    {
        *(tempPtr + i) = *(data + i);
    }
    delete[] data;
    data = tempPtr;
//    for(unsigned i = sz; i < cap; i++)
//    {
//        *(data + i) = E(0);
//    }
    tempPtr = NULL;
}
/**********************************************************
 *
 * Method insert: Class Vector
 *_________________________________________________________
 * This method inserts the value specified into the index
 *              specified
 *_________________________________________________________
 * PRE-CONDITIONS
 *     index: the index of the Vector
 *     value: the value to insert
 *
 * POST-CONDITIONS
 *     This function inserts a value into the Vector
 ***********************************************************/
template<class E>
void Vector<E>::insert(unsigned index, E& value)
{
    if(index > sz)
        exit(1);

    if(sz == cap)
        expand();

    sz++;
    for(unsigned i = sz; i >= index; i--)
    {
        data[i + 1] = data[i];
    }
    data[index] = value;

}
/**********************************************************
 *
 * Method erase: Class Vector
 *_________________________________________________________
 * This method erases the value at the index specified
 *_________________________________________________________
 * PRE-CONDITIONS
 *     index: the index of the Vector
 *
 * POST-CONDITIONS
 *     This function erases a value from the Vector
 ***********************************************************/
template<class E>
void Vector<E>::erase(unsigned index)
{
    cout << "In erase function" << endl;
    cout << "Index: " << index << endl;

    if(index > sz)
        exit(1);

    for(unsigned i = index; i < sz; i++)
    {
        cout << "In for loop" << endl;
        *(data + i) = *(data + i + 1);
    }
    sz--;
    cout << "Erase function exited" << endl;
}
/**********************************************************
 *
 * Method push_back: Class Vector
 *_________________________________________________________
 * This method adds a value to the end of the Vector
 *_________________________________________________________
 * PRE-CONDITIONS
 *     value: the value to add
 *
 * POST-CONDITIONS
 *     This function adds a value to the Vector
 ***********************************************************/
template<class E>
void Vector<E>::push_back(E& value)
{
    if(sz == 0)
    {
        expand(1);
    }

    else if(sz == cap)
    {
        expand(sz);
    }
    sz++;
    data[sz - 1] = value;
}
/**********************************************************
 *
 * Method pop_back: Class Vector
 *_________________________________________________________
 * This method adds a value to the end of the Vector
 *_________________________________________________________
 * PRE-CONDITIONS
 *     value: the value to add
 *
 * POST-CONDITIONS
 *     This function adds a value to the Vector
 ***********************************************************/
template<class E>
void Vector<E>::pop_back()
{
    if(sz == 0)
        exit(1);
    sz--;
}
/**********************************************************
 *
 * Method clear: Class Vector
 *_________________________________________________________
 * This method reduces the value of the Vector to 0
 *_________________________________________________________
 * PRE-CONDITIONS
 *     none
 *
 * POST-CONDITIONS
 *     This function reduces the size to 0
 ***********************************************************/
template<class E>
void Vector<E>::clear()
{
    sz = 0;
}
/**********************************************************
 *
 * Method resize: Class Vector
 *_________________________________________________________
 * This method resizes the Vector
 *_________________________________________________________
 * PRE-CONDITIONS
 *     size: size to resize the Vector to
 *
 * POST-CONDITIONS
 *     This function resizes the Vector
 ***********************************************************/
template<class E>
void Vector<E>::resize(unsigned size)
{
    if(size >= cap)
    {
        if(size >= cap * 2)
            expand(size - cap);
        else
            expand();

        for(unsigned i = sz; i < size; i++)
        {
            *(data + i) = 0;
        }


    }
    else
    {
        sz = size;
    }



    sz = size;




}
/**********************************************************
 *
 * Method resize: Class Vector
 *_________________________________________________________
 * This method resizes the Vector
 *_________________________________________________________
 * PRE-CONDITIONS
 *     size: size to resize the Vector to
 *     value: value that is inputted into the new spaces
 *
 * POST-CONDITIONS
 *     This function resizes the Vector
 ***********************************************************/
template<class E>
void Vector<E>::resize(unsigned size, E& value)
{
    if(size > cap)
    {
        if(size > cap * 2)
            expand(size - cap);
        else
            expand();
        cout << "sz = " << sz << endl;
        cout << "cap = " << cap << endl;

        for(unsigned i = sz; i < size; i++)
        {
            data[i] = value;
        }

        sz = size;
    }
    else
    {
        for(unsigned i = sz; i < size; i++)
        {
            data[i] = value;
        }
        sz = size;
    }
    //cout << "Value is: " << value << endl;




}
/**********************************************************
 *
 * Method assign: Class Vector
 *_________________________________________________________
 * This method changes the Vector
 *_________________________________________________________
 * PRE-CONDITIONS
 *     n: size to resize the Vector to
 *     value: value that is inputted into the new spaces
 *
 * POST-CONDITIONS
 *     This function resizes the Vector
 ***********************************************************/
template<class E>
void Vector<E>::assign(unsigned int n, E& value)
{
    //clear();
    if(n > sz)
    {
        unsigned tempcap1 = cap;
        unsigned tempcap2;
        unsigned tempcap3;
        expand();
        tempcap2 = cap;
        cap = tempcap1;
        expand(n - cap);
        tempcap3 = cap;
        cap = tempcap1;

        if(tempcap3 > tempcap2)
            expand(n - cap);
        else
            expand();


        for(unsigned i = sz; i < n; i++)
        {
            *(data + i) = value;
        }

        sz = n;
    }
    else
    {
        sz = n;
        for(unsigned i = 0; i < sz; i++)
        {
            *(data + i) = value;
        }
    }

}
/**********************************************************
 *
 * Method reserve: Class Vector
 *_________________________________________________________
 * This method changes the capacity of Vector
 *_________________________________________________________
 * PRE-CONDITIONS
 *     n: size to change the capacity to
 *
 * POST-CONDITIONS
 *     This function changes the capacity of the Vector
 ***********************************************************/
template<class E>
void Vector<E>::reserve(unsigned int n)
{
    if(n > cap)
    {
        if(n > cap * 2)
            expand(n - cap);
        else
            expand();
    }

}

/**********************************************************
 *
 * Method indexOf: Class Vector
 *_________________________________________________________
 * This method returns the data at an index
 *_________________________________________________________
 * PRE-CONDITIONS
 *     data: data to check the index of
 *
 * POST-CONDITIONS
 *     This function returns the index of data
 ***********************************************************/
template<class E>
unsigned Vector<E>::indexOf(E& data)
{
    for(unsigned i = 0; i < this->size(); i++)
    {
        if(this->at(i) == data)
            return i;
    }
    return static_cast<unsigned>(-1);
}

/****************************************************************
 * Vector Class
 *   This class represents a Vector object.
 ***************************************************************/

/******************************
 ******** CONSTRUCTOR *********
 ******************************/

/****************************************************************
 * Vector();
 *   Constructor; Initialize class attributes
 *   Parameters: none
 *   Return: none
 ***************************************************************/

/****************************************************************
 * Vector(unsigned, E);
 *   Constructor; Initialize class attributes
 *   Parameters: an unsigned and a template
 *   Return: none
 ***************************************************************/

/****************************************************************
 * Vector(unsigned);
 *   Constructor; Initialize class attributes
 *   Parameters: an unsigned E
 *   Return: none
 ***************************************************************/

/****************************************************************
 * ~Vector;
 *   Destructor; deletes the class
 *   Parameters: none
 *   Return: none
 ***************************************************************/


/***************
 ** ACCESSORS **
 ***************/

/*******************************************************************
 * unsigned size() const;
 *
 *   Accessor; This method returns the size of the vector
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: Size of the vector
 *******************************************************************/

/*******************************************************************
 * unsigned capacity() const;
 *
 *   Accessor; This method returns the capacity of the vector
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: Capacity of the vector
 *******************************************************************/

/*******************************************************************
 * bool empty() const;
 *
 *   Accessor; This method returns true if the vector is empty
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: true if vector is empty
 *******************************************************************/

/*******************************************************************
 * const E& at(unsigned) const;
 *
 *   Accessor; This method returns the value at the index of the vector
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: Value at the index specified
 *******************************************************************/

/*******************************************************************
 * E& at(unsigned);
 *
 *   Accessor; This method returns the value at the index of the vector
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: Value at the index specified
 *******************************************************************/

/*******************************************************************
 * const E& front() const;
 *
 *   Accessor; This method returns the value at the front of the Vector
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: First value of the Vector
 *******************************************************************/

/*******************************************************************
 * E& front();
 *
 *   Accessor; This method returns the value at the front of the Vector
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: First value of the Vector
 *******************************************************************/

/*******************************************************************
 * const E& back() const;
 *
 *   Accessor; This method returns the value at the back of the Vector
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: Last value of the Vector
 *******************************************************************/

/*******************************************************************
 * E& back();
 *
 *   Accessor; This method returns the value at the back of the Vector
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: Last value of the Vector
 *******************************************************************/

/**************
 ** MUTATORS **
 **************/

/*******************************************************************
 * void expand();
 *
 *   Mutator; This method doubles the capacity of the Vector
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void expand(unsigned);
 *
 *   Mutator; This method increases the capacity of the Vector by
 *              the amount specified
 *------------------------------------------------------------------
 *   Parameter: unsigned
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void insert(unsigned index, E& value);
 *
 *   Mutator; This method inserts the value specified Eo the index
 *              specified
 *------------------------------------------------------------------
 *   Parameter: unsigned, E
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void erase(unsigned index);
 *
 *   Mutator; This method erases the value at the specified index
 *------------------------------------------------------------------
 *   Parameter: unsigned
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void push_back(E& value);
 *
 *   Mutator; This method adds one value to the Vector
 *------------------------------------------------------------------
 *   Parameter: E
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void pop_back();
 *
 *   Mutator; This method subtracts one value from the Vector
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void clear();
 *
 *   Mutator; This method reduces the size of the Vector to 0
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void resize(unsigned size);
 *
 *   Mutator; This method changes the size of the Vector to size size
 *              and fills all new spaces with 0
 *------------------------------------------------------------------
 *   Parameter: unsigned
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void resize(unsigned size, E& value);
 *
 *   Mutator; This method changes the size of the Vector to size size
 *              and fills all new spaces with value
 *------------------------------------------------------------------
 *   Parameter: unsigned and E
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void assign(unsigned n, E& value);
 *
 *   Mutator; This method assigns new content to the Vector
 *------------------------------------------------------------------
 *   Parameter: unsigned and E
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void reserve(unsigned n);
 *
 *   Mutator; This method assigns new content to the Vector
 *------------------------------------------------------------------
 *   Parameter: unsigned
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

#endif // VECTOR_H
