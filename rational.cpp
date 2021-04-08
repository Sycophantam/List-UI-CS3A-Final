#include "rational.h"
#include <iostream>
#include <cstdlib>

using namespace std;

/***********************************************************
* CONSTRUCTOR Rational(int)
*_________________________________________________________
* User defines the numerator. Denominator set to 1
***********************************************************/
Rational::Rational(int topNum)
{
    denom = 1;
    numer = topNum;
}
/***********************************************************
* CONSTRUCTOR Rational(int, int)
*_________________________________________________________
* User defines the numerator and the denominator
***********************************************************/
Rational::Rational(int topNum,  //INPUT: numerator
                   int botNum)  //INPUT: denominator
{
    denom = botNum;
    numer = topNum;
}
/***********************************************************
* CONSTRUCTOR Rational
*_________________________________________________________
* Default constructor sets the numerator to zero and the
* denominator to 1
***********************************************************/
Rational::Rational()
{
    denom = 1;
    numer = 0;
}
/***********************************************************
*
* Method display: Class Rational
*_________________________________________________________
*  This function receives nothing
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* none
*
* POST-CONDITIONS
*     This function displays a rational number
***********************************************************/
void Rational::display() const
{
    cout << numer <<"/" << denom << endl;
}
/***********************************************************
* Method add: Class Rational
*_________________________________________________________
*  This function receives a rational number
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* r: rational number
*
* POST-CONDITIONS
*     This function returns the rational numbers added together
***********************************************************/
const Rational
Rational::add(const Rational& r) const   //Rational number to add
{
    int a;
    int b;
    a = r.numer * denom;
    b = r.denom * numer;
    Rational g(a + b, denom * r.denom);
    return g;
}
/***********************************************************
* Method subtract: Class Rational
*_________________________________________________________
*  This function receives a rational number
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* r: rational number
*
* POST-CONDITIONS
*     This function returns the subtracted rational numbers
***********************************************************/
const Rational
Rational::subtract(const Rational& r) const //Rational number to subtract
{
    int a;
    int b;
    a = r.numer * denom;
    b = r.denom * numer;
    Rational g(b - a, denom * r.denom);
    return g;
}
/***********************************************************
* Method multiply: Class Rational
*_________________________________________________________
*  This function receives a rational number
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* r: rational number
*
* POST-CONDITIONS
*     This function returns the rational numbers multiplied together
***********************************************************/
const Rational
Rational::multiply(const Rational& r) const //Rational number to multiply
{
    Rational g(r.numer * numer, r.denom * denom);
    return  g;
}
/***********************************************************
* Method divide: Class Rational
*_________________________________________________________
*  This function receives a rational number
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* r: rational number
*
* POST-CONDITIONS
*     This function returns the divided rational numbers
***********************************************************/
const Rational
Rational::divide(const Rational& r) const   //Rational number to divide
{
    Rational g(numer * r.denom, r.numer * denom);
    return  g;
}

bool Rational::operator==(const Rational &r) const
{
    if((r.denom * numer == denom * r.numer))
    {
        return true;
    }
    return false;
}
bool Rational::operator<(const Rational &r) const
{
    if(this->numer * r.denom < r.numer * this->denom)
        return true;
    return false;
}
bool Rational::operator<=(const Rational &r) const
{

    if(*this == r)
        return true;
    else if(*this < r)
        return true;
    return false;
}
ostream& operator << (ostream &out, const Rational &r)
{
    out << r.numer << '/' << r.denom;
    return out;
}

/***********************************************************
* Method fromString: Class Rational
*_________________________________________________________
*  This function receives a string
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* r: string
*
* POST-CONDITIONS
*     This function returns a new rational from a string
***********************************************************/
const Rational& Rational::fromString(const string r)
{
    string snumer;
    string sdenom;
    if(r.find('/') == string::npos)
    {
        this->numer = atoi(r.c_str());
        this->denom = 1;
    }
    else
    {
        snumer = r.substr(0,r.find('/'));
        sdenom = r.substr(r.find('/') + 1);
        this->numer = atoi(snumer.c_str());
        this->denom = atoi(sdenom.c_str());
    }

    return *this;
}
