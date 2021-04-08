#ifndef RATIONAL_H
#define RATIONAL_H


#include <iostream>
#include <string>

using namespace std;
/*****************************************************************
* Rational Class
*   This class causes two numbers to act as one rational number
*****************************************************************/
class Rational
{
   private:
      int numer;    //INPUT: numerator
      int denom;    //INPUT: denominator
   public:
      /********************************
      *          CONSTRUCTOR          *
      ********************************/

      /*****************************************************************
      * Rational()
      *   Constructor; initializes class attributes
      *   Parameters: none
      *   Return: none
      ***************************************************************/
      Rational();           //Default constructor

      /*****************************************************************
      * Rational()
      *   Constructor; initializes class attributes
      *   Parameters: numer (int) -> INPUT: numerator of the rational number
      *   Return: none
      ***************************************************************/
      Rational(int);        //Constructor setting the denominator to 1

      /*****************************************************************
      * Rational()
      *   Constructor; initializes class attributes
      *   Parameters: numer (int) -> INPUT: numerator of the rational number
      *               denom (int) -> INPUT: numerator of the rational number
      *   Return: none
      ***************************************************************/
      Rational(int, int);   //Constructor with user inputting numerator and
                                //denominator

      /*****************
      *    MUTATORS   *
      *****************/

      /*****************************************************************
      * const Rational add(const Rational&) const
      *
      *     Mutator; this method will add two rationals
      *     Parameters: r (Rational) -> INPUT: the second rational
      *     Return: the added rationals
      ***************************************************************/
      const Rational
      add(const Rational &) const;      //INPUT: rational number to add

      /*****************************************************************
      * const Rational subtract(const Rational&) const
      *
      *     Mutator; this method will subtract two rationals
      *     Parameters: r (Rational) -> INPUT: the second rational
      *     Return: the subtracted rationals
      ***************************************************************/
      const Rational
      subtract(const Rational &) const; //INPUT: rational number to subtract

      /*****************************************************************
      * const Rational multiply(const Rational&) const
      *
      *     Mutator; this method will multiply two rationals
      *     Parameters: r (Rational) -> INPUT: the second rational
      *     Return: the multiplied rationals
      ***************************************************************/
      const Rational
      multiply(const Rational &) const; //INPUT: rational number to multiply

      /*****************************************************************
      * const Rational divide(const Rational&) const
      *
      *     Mutator; this method will divide two rationals
      *     Parameters: r (Rational) -> INPUT: the second rational
      *     Return: the divided rationals
      ***************************************************************/
      const Rational
      divide(const Rational &) const;   //INPUT: rational number to divide

      /*****************************************************************
      * const Rational fromString(const string)
      *
      *     Mutator; this method will convert a string to a rational
      *     Parameters: r (string) -> INPUT: the string to convert
      *     Return: a rational number from the string
      ***************************************************************/
      const Rational& fromString(const string r);   //String to convert




      /*****************
      *    ACCESSORS   *
      *****************/

      /*****************************************************************
      * void display() const
      *
      *     Accessor; this method will display the function
      *     Parameters: none
      *     Return: none
      ***************************************************************/
      void display() const;

      /*****************************************************************
      * friend ostream& operator << (ostream &out, const Rational &r)
      *
      *     Accessor; this method will output a rational
      *     Parameters: out (ostream) -> INPUT: ostream object
      *                 r (Rational)  -> INPUT: the rational to output
      *     Return: an ostream object
      ***************************************************************/
      friend ostream& operator << (ostream &out,        //Ostream object
                                   const Rational &r);  //Rational object
                                                            //to output

      /*****************************************************************
      * bool operator == (const Rational &r)
      *
      *     Accessor; this method will check if two rationals are equal
      *     Parameters: r (Rational) -> INPUT: the rational to compare
      *     Return: a bool
      ***************************************************************/
      bool operator == (const Rational &r) const;     //Rational to compare to

      /*****************************************************************
      * bool operator <= (const Rational &r)
      *
      *     Accessor; this method will check if two rationals are equal or
      *                 less than each other
      *     Parameters: r (Rational) -> INPUT: the rational to compare
      *     Return: a bool
      ***************************************************************/
      bool operator <= (const Rational &r) const;     //Rational to compare to

      /*****************************************************************
      * bool operator < (const Rational &r)
      *
      *     Accessor; this method will check if two rationals are
      *                 less than each other
      *     Parameters: r (Rational) -> INPUT: the rational to compare
      *     Return: a bool
      ***************************************************************/
      bool operator < (const Rational &r) const;     //Rational to compare to




};

#endif // RATIONAL_H
