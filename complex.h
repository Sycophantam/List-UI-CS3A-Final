/**************************************************************************
* Author:           Brian Downie & Zachary Anderson
* Lab #8:           Complex Class
* Class:            CS 003A
* Section:          MW:1:00pm-2:25pm; TR:1:00pm-3:05pm
* Due Date:         3/20/19
**************************************************************************/

#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

using namespace std;

class Complex
{
    private:
        double real;                //IN&OUT - real number
        double imaginary;           //IN&OUT - imaginary number
        ///Comment this below
        double DistanceFromZero() const;
    public:

    /********************************
     *  CONSTRUCTOR & DESTRUCTOR    *
     ********************************/
        Complex();                          //CONSTRUCTOR
        Complex(double real_part);          //CONSTRUCTOR
        Complex(double real_part,
                double imaginary_part);     //CONSTRUCTOR

    /*****************
     **  MUTATORS   **
     ****************/

        const Complex operator +(const Complex& c) const;
        bool operator ==(const Complex& c) const;
        const Complex operator -(const Complex& c) const;
        const Complex operator *(const Complex& c) const;
        ///Comment < and <=
        bool operator <(const Complex& c) const;
        bool operator <=(const Complex& c) const;
        friend istream& operator >>(istream& isobject,
                                    Complex& c);
        friend ostream& operator <<(ostream& osobject,
                                    const Complex& c);

        const Complex& fromString(const string c);



};

/*************************************************************************
*  Complex Class
*   This represents a calculation of a complex calculation.
*   It manages 2 attributes, real & imaginary.
 *************************************************************************/

    /********************************
     *  CONSTRUCTOR & DESTRUCTOR    *
     ********************************/

/*************************************************************************
*  Complex();
*   Constructor; Initialize class attributes
*   Parameters: none
*   Return: none
 *************************************************************************/

/*************************************************************************
*  Complex(double real_part);
*   Constructor; Initialize class attributes with one parameter
*   Parameters: real_part (double)
*   Return: none
 *************************************************************************/

/*************************************************************************
*  Complex(double real_part, double imaginary_part);
*   Constructor; Initialize class attributes with two parameter
*   Parameters: real_part, imaginary_part (double)
*   Return: none
 *************************************************************************/

    /*****************
     **  ACCESSORS  **
     ****************/

/*******************************************************************
* double DistanceFromZero() const;
*   Accessor operator; This will return the number's distance from 0
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: double
*******************************************************************/

    /*****************
     **  MUTATORS   **
     ****************/

/*******************************************************************
* const Complex operator +(const Complex& c) const;
*   Mutator operator; This will add the complex number
*------------------------------------------------------------------
*   Parameter: c (const Complex) // IN - numbers to add
*------------------------------------------------------------------
*   Return: c2 (Complex)
*******************************************************************/

/*******************************************************************
* const Complex operator -(const Complex& c) const;
*   Mutator operator; This will subtract the complex number
*------------------------------------------------------------------
*   Parameter: c (const Complex) // IN - numbers to subtract
*------------------------------------------------------------------
*   Return: c2 (Complex)
*******************************************************************/

/*******************************************************************
* const Complex operator *(const Complex& c) const;
*   Mutator operator; This will multiply the complex number
*------------------------------------------------------------------
*   Parameter: c (const Complex) // IN - numbers to multiply
*------------------------------------------------------------------
*   Return: c2 (Complex)
*******************************************************************/

/*******************************************************************
* bool operator ==(const Complex& c) const;
*   Mutator operator; This will compare the complex number
*------------------------------------------------------------------
*   Parameter: c (const Complex) // IN - numbers to compare
*------------------------------------------------------------------
*   Return: (bool)
*******************************************************************/

/*******************************************************************
* bool operator < (const Complex& c) const;
*   Mutator operator; This will compare the complex number
*------------------------------------------------------------------
*   Parameter: c (const Complex) // IN - numbers to compare
*------------------------------------------------------------------
*   Return: (bool)
*******************************************************************/

/*******************************************************************
* bool operator <=(const Complex& c) const;
*   Mutator operator; This will compare the complex number
*------------------------------------------------------------------
*   Parameter: c (const Complex) // IN - numbers to compare
*------------------------------------------------------------------
*   Return: (bool)
*******************************************************************/

/*******************************************************************
* friend istream& operator >>(istream& isobject, Complex& c);
*   Mutator operator; This will compare the complex number
*------------------------------------------------------------------
*   Parameter: c (const Complex)  // IN - numbers to compare
*              isobject (istream) // IN - input stream
*------------------------------------------------------------------
*   Return: isobect (istream)
*******************************************************************/

/*******************************************************************
* friend istream& operator <<(ostream& isobject, Complex& c);
*   Mutator operator; This will compare the complex number
*------------------------------------------------------------------
*   Parameter: c (const Complex)  // IN - numbers to compare
*              isobject (ostream) // IN - output stream
*------------------------------------------------------------------
*   Return: isobect (ostream)
*******************************************************************/

#endif // COMPLEX_H
