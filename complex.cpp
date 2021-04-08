/**************************************************************************
* Author:           Brian Downie & Zachary Anderson
* Lab #8:           Complex Class
* Class:            CS 003A
* Section:          MW:1:00pm-2:25pm; TR:1:00pm-3:05pm
* Due Date:         3/20/19
**************************************************************************/

#include "complex.h"
#include <string>
#include <cstdlib>
#include <cmath>

//const Complex i(0,1);

/**************************************************************************
* Method Complex : Class Complex
*--------------------------------------------------------------------------
* This Method will set a default.
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   none
*
* POST-CONDITIONS
* This will set the values accordly
**************************************************************************/

Complex::Complex()
{
    real = 0;
    imaginary = 0;
}

/**************************************************************************
* Method Complex : Class Complex
*--------------------------------------------------------------------------
* This Method will set a default with 1 parameter.
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   real_part : one of the input
*
* POST-CONDITIONS
* This will set the values accordly
**************************************************************************/
Complex::Complex(double real_part)      //IN - one of the first input
{
    real = real_part;
    imaginary = 0;
}

/**************************************************************************
* Method Complex : Class Complex
*--------------------------------------------------------------------------
* This Method will set a default with two parameter.
* return - none
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   real_part       : one of the input
*   imaginary_part  : second input
* POST-CONDITIONS
* This will set the values accordly
**************************************************************************/
Complex::Complex(double real_part,          //IN - one of the input
                 double imaginary_part)     //IN - second input
{
    real = real_part;
    imaginary = imaginary_part;
}

/**************************************************************************
* Method Complex operator + : Class Complex
*--------------------------------------------------------------------------
* This Method will add two complex numbers
* return - c2 (const Complex)
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   c   : first input
*
* POST-CONDITIONS
* This will return the added two complex
**************************************************************************/
const Complex Complex::operator+(const Complex& c) const    //IN - first input
{
    //PROCESSING : addition
    Complex c2(real + c.real, imaginary + c.imaginary);
    return c2;
}

/**************************************************************************
* Method Complex operator - : Class Complex
*--------------------------------------------------------------------------
* This Method will subtract two complex numbers
* return - c2 (const Complex)
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   c   : first input
*
* POST-CONDITIONS
* This will return subtracted two complex
**************************************************************************/
const Complex Complex::operator-(const Complex& c) const    //IN - first input
{
    //PROCESSING : subtraction
    Complex c2(real - c.real, imaginary - c.imaginary);
    return c2;
}

/**************************************************************************
* Method Complex operator * : Class Complex
*--------------------------------------------------------------------------
* This Method will multiply two complex numbers
* return - c2 (const Complex)
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   c   : first input
*
* POST-CONDITIONS
* This will return the two complex multiplied
**************************************************************************/
const Complex Complex::operator*(const Complex& c) const    //IN - first input
{
    //PROCESSING : multiplication
    Complex c2((real * c.real) - (imaginary * c.imaginary),
                (imaginary * c.real) + (real *c.imaginary));
    return c2;
}

/**************************************************************************
* Method Complex operator == : Class Complex
*--------------------------------------------------------------------------
* This Method will compare two complex numbers
* return - c2 (const Complex)
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   c   : first input
*
* POST-CONDITIONS
* This will return the boolean result
**************************************************************************/
bool Complex::operator==(const Complex &c) const        //IN - first input
{
    //PROCESSING : comparing numbers
    if(real == c.real && imaginary == c.imaginary)
        return true;
    return false;
}

/**************************************************************************
* Method Complex operator << : Class Complex
*--------------------------------------------------------------------------
* This Method will output two complex numbers
* return - c2 (const Complex)
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   c       : first input
*   osoject : output stream
*
* POST-CONDITIONS
* This will return the two complex output stream
**************************************************************************/
ostream& operator <<(ostream& osobject,     //OUT - output stream
                     const Complex& c)      //IN - first input
{
    //PROCESSING : preparing output stream
    if(c.imaginary >= 0)
        osobject << c.real << "+" << c.imaginary << 'i';
    else
        osobject << c.real << "-" << -1 * c.imaginary << 'i';
    return osobject;
}

/**************************************************************************
* Method Complex operator << : Class Complex
*--------------------------------------------------------------------------
* This Method will input two complex numbers
* return - c2 (const Complex)
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   c       : first input
*   osoject : input stream
*
* POST-CONDITIONS
* This will return the two complex input stream
**************************************************************************/
istream& operator >>(istream& isobject,         //IN - input stream
                     Complex& c)                //IN - first input
{
    //VARIABLES
    string expression;
    string expression2;

    isobject >> expression;
    //cout << expression << endl;
    //PROCESSING : checking if the input includes a + or - sign
    if(expression == "i")
        c.imaginary = 1;
    else if (expression == "-i")
        c.imaginary = -1;

    else if(expression.find('i') == string::npos)
    {
        c.real = atof(expression.c_str());
        c.imaginary = 0;
    }
    else if(expression.find('+') != string::npos)
    {
        c.real = atof(expression.substr(0, expression.find('+')).c_str());
        c.imaginary = atof(expression.substr(expression.find('+')).c_str());
    }

    else if(expression.find('-') == 0)
    {
        if(expression.find_last_of('-') == 0)
        {
            c.imaginary = atof(expression.c_str());
        }
        else
        {
            c.real = atof(expression.substr
                          (0, expression.find_last_of('-')).c_str());
            c.imaginary = atof(expression.substr
                               (expression.find_last_of('-')).c_str());
        }
    }
    else if(expression.find('-') != 0 && expression.find('-') != string::npos)
    {
        c.real = atof(expression.substr(0, expression.find('-')).c_str());
        c.imaginary = atof(expression.substr(expression.find('-')).c_str());
    }
    else
    {
        c.imaginary = atof(expression.c_str());
    }

    return isobject;
}

double Complex::DistanceFromZero() const
{
    return sqrt(pow(this->real,2) + pow(this->imaginary,2));
}

/**************************************************************************
* Method Complex operator < : Class Complex
*--------------------------------------------------------------------------
* This Method will compare two complex numbers
* return - bool
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   c   : first input
*
* POST-CONDITIONS
* This will return the boolean result
**************************************************************************/
bool Complex::operator<(const Complex &c) const
{
    if(this->DistanceFromZero() < c.DistanceFromZero())
        return true;
    else
        return false;
}

/**************************************************************************
* Method Complex operator <= : Class Complex
*--------------------------------------------------------------------------
* This Method will compare two complex numbers
* return - bool
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need previously defined values:
*   c   : first input
*
* POST-CONDITIONS
* This will return the boolean result
**************************************************************************/
bool Complex::operator<=(const Complex &c) const
{
    if(this->DistanceFromZero() < c.DistanceFromZero())
        return true;
    else if (abs(this->DistanceFromZero() - c.DistanceFromZero()) < .0001)
    {
        return true;
    }
    return false;
}

const Complex& Complex::fromString(const string c)
{
    if(c == "i")
        this->imaginary = 1;
    else if (c == "-i")
        this->imaginary = -1;

    else if(c.find('i') == string::npos)
    {
        this->real = atof(c.c_str());
        this->imaginary = 0;
    }
    else if(c.find('+') != string::npos)
    {
        this->real = atof(c.substr(0, c.find('+')).c_str());
        this->imaginary = atof(c.substr(c.find('+')).c_str());
    }

    else if(c.find('-') == 0)
    {
        if(c.find_last_of('-') == 0)
        {
            this->imaginary = atof(c.c_str());
        }
        else
        {
            this->real = atof(c.substr
                          (0, c.find_last_of('-')).c_str());
            this->imaginary = atof(c.substr
                               (c.find_last_of('-')).c_str());
        }
    }
    else if(c.find('-') != 0 && c.find('-') != string::npos)
    {
        this->real = atof(c.substr(0, c.find('-')).c_str());
        this->imaginary = atof(c.substr(c.find('-')).c_str());
    }
    else
    {
        this->imaginary = atof(c.c_str());
    }
    return *this;
}
