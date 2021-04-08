#ifndef DATE_H
#define DATE_H

#endif // DATE_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;
/*****************************************************************
* Date Class
*   This class creates a set of numbers that act as a date
*****************************************************************/
class Date
{
    private:
        unsigned day;       //INPUT: day of the date
        unsigned month;     //INPUT: month of the date
        string monthName;   //INPUT: name of the month
        unsigned year;      //INPUT: year of the date

    public:
        /********************************
        *          CONSTRUCTOR          *
        ********************************/

        /*****************************************************************
        * Date()
        *   Constructor: initializes class attributes
        *   Parameters: none
        *   Return: none
        ***************************************************************/
        Date();

        /*****************************************************************
        * Date()
        *   Constructor; initializes class attributes
        *   Parameters: m(unsigned) -> INPUT: month
        *               d(unsigned) -> INPUT: day
        *               y(unsigned) -> INPUT: year
        *   Return: none
        ***************************************************************/
        Date(unsigned m,    //Month
             unsigned d,    //Day
             unsigned y);   //Year

        /*****************************************************************
        * Date()
        *   Constructor; initializes class attributes
        *   Parameters: mn(const string) -> INPUT: month name
        *               d(unsigned) -> INPUT: day
        *               y(unsigned) -> INPUT: year
        *   Return: none
        ***************************************************************/
        Date(const string& mn,  //Month name
             unsigned d,        //Day
             unsigned y);       //Year


        /*****************
        *    ACCESSORS   *
        *****************/

        /*****************************************************************
        * void printNumeric() const
        *
        *     Accessor; this method will print the date in numeric form
        *     Parameters: none
        *     Return: none
        ***************************************************************/
        void printNumeric() const;

        /*****************************************************************
        * void printNumeric() const
        *
        *     Accessor; this method will print the date in alphabetical form
        *     Parameters: none
        *     Return: none
        ***************************************************************/
        void printAlpha() const;
        /*****************
        *    MUTATORS    *
        *****************/

        /*****************************************************************
        * Date addDays( int ) const
        *
        *     Mutator; this method will add and subtract days from a date then
        *           print the date
        *     Parameters: days(int) -> INPUT: days to add
        *     Return: Date
        ***************************************************************/
        Date addDays(int days) const;       //Days to add


        /*****************************************************************
        * ostream operator << ( ostream &out,
        *                       const Date& d )
        *
        *     Mutator; this method will output a date using the << operator
        *     Parameters: d (Date) -> INPUT: Date to print
        *                 out (ostream) -> INPUT: ostream object
        *     Return: Date
        ***************************************************************/
        friend ostream& operator << (ostream &out,      //Output object
                                     const Date &d);    //Date to output

        /*****************************************************************
        * bool operator < ( const Date& d )
        *
        *     Accessor; this method compare if one date is less than the other
        *     Parameters: d (Date) -> INPUT: Date to compare
        *     Return: bool
        ***************************************************************/
        bool operator < (const Date& d) const;    //Date to compare

        /*****************************************************************
        * bool operator <= ( const Date& d )
        *
        *     Accessor; this method compare if one date is less than the other
        *                   or if they are equal
        *     Parameters: d (Date) -> INPUT: Date to compare
        *     Return: bool
        ***************************************************************/
        bool operator <= (const Date& d) const;    //Date to compare

        /*****************************************************************
        * bool operator == ( const Date& d )
        *
        *     Accessor; this method compare if two dates are equal
        *     Parameters: d (Date) -> INPUT: Date to compare
        *     Return: bool
        ***************************************************************/
        bool operator == (const Date& d) const;    //Date to compare

    private:

        /*****************************************************************
        * bool isLeap(unsigned) const
        *
        *     Accessor; this method will check if the date is a leap year
        *     Parameters: y(unsigned) -> INPUT: year
        *     Return: bool
        ***************************************************************/
        bool isLeap(unsigned y) const;    //Year

        /*****************************************************************
        * unsigned daysPerMonth(unsigned, unsigned) const
        *
        *     Accessor; this method will return the number of days in a month
        *     Parameters: m(unsigned) -> INPUT: month
        *                 y(unsigned) -> INPUT: year
        *     Return: unsigned
        ***************************************************************/
        unsigned daysPerMonth(unsigned m,           //Month
                              unsigned y) const;    //Year

        /*****************************************************************
        * string name(unsigned) const
        *
        *     Accessor; this method will return the name of the month
        *     Parameters: m(unsigned) -> INPUT: month
        *     Return: string
        ***************************************************************/
        string name(unsigned) const;    //Month

        /*****************************************************************
        * unsigned number(const string& mn) const
        *
        *     Accessor; this method will return the number of the month
        *     Parameters: mn(const string) -> INPUT: month name
        *     Return: unsigned
        ***************************************************************/
        unsigned number(const string& mn) const;    //Month name




};

