#include "date.h"

using namespace std;

/***********************************************************
* CONSTRUCTOR Date()
*_________________________________________________________
* Date is set to 1/1/2000
***********************************************************/
Date::Date()
{
    month = 1;
    monthName = "January";
    day = 1;
    year = 2000;
}
/***********************************************************
* CONSTRUCTOR Date(unsigned, unsigned, unsigned)
*_________________________________________________________
* User defines the month, day, and year
***********************************************************/
Date::Date(unsigned m,  //INPUT: month of the date
           unsigned d,  //INPUT: day of the date
           unsigned y)  //INPUT: year of the date
{
    bool flashInvalid;
    flashInvalid = false;

    ///If the month specified is greater than twelve, it defaults to 12
    if(m > 12)
    {
        m = 12;
        flashInvalid = true;

    }
    ///If the month sepecified is less than 1, the month defaults to January
    if(m < 1)
    {
        m = 1;
        flashInvalid = true;
    }
    ///If the day specified is greater than the maximum amount of days in the
    ///month, the day defaults to the number of days in the month
    if(d > daysPerMonth(m,y))
    {
        d = daysPerMonth(m,y);
        flashInvalid = true;
    }
    ///If the day specified is less than 1, the day defaults to one
    else if(d < 1)
    {
        d = 1;
        flashInvalid = true;
    }
    month = m;
    monthName = name(month);
    day = d;
    year = y;
    if(flashInvalid)
        cout << "Invalid date values: Date corrected to " << month << "/"
             << day << "/" << year << "." << endl;
}
/***********************************************************
* CONSTRUCTOR Date(const string, unsigned, unsigned)
*_________________________________________________________
* User defines the month name, day, and year
***********************************************************/
Date::Date(const string& mn,    //Month name
     unsigned d,                //Day
     unsigned y)                //Year
{
    string temp;
    temp = mn;
    bool flashInvalid;
    bool invalidMonth;
    invalidMonth = false;
    flashInvalid = false;

    ///If the month specified is greater than twelve, it defaults to 12
    if(number(mn) > 12)
    {
        temp = "January";
        flashInvalid = true;

    }
    ///If the month sepecified is less than 1, the month defaults to January
    if(number(mn) < 1)
    {
        temp = "January";
        d = 1;
        y = 2000;
        invalidMonth = true;
    }
    ///If the day specified is greater than the maximum amount of days in the
    ///month, the day defaults to the number of days in the month
    if(d > daysPerMonth(number(mn),y))
    {
        d = daysPerMonth(number(mn),y);
        flashInvalid = true;
    }
    ///If the day specified is less than 1, the day defaults to one
    else if(d < 1)
    {
        d = 1;
        flashInvalid = true;
    }
    monthName = temp;
    month = number(monthName);
    day = d;
    year = y;
    ///If the user gives an invalid month name, the date defaults to 1/1/2000
    if(invalidMonth)
    {
        cout << "Invalid month name: the Date was set to 1/1/2000.\n";
    }
    else if(flashInvalid)
    {
        cout << "Invalid date values: Date corrected to " << number(monthName)
             << "/" << day << "/" << year <<"." << endl;
    }


}
/***********************************************************
*
* Method daysPerMonth: Class Date
*_________________________________________________________
*  This function receives two unsigned integers
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* m: month of the date
* y: year of the date
*
* POST-CONDITIONS
*     This function returns the number of days in the month
***********************************************************/
unsigned Date::daysPerMonth(unsigned m,         //Month of the date
                            unsigned y) const   //Year of the date
{
    if(m == 1 || m == 3 || m == 5 || m == 7
            || m == 8 || m == 10 || m == 12)
        return 31;
    else if(m == 4 || m == 6 || m == 9 || m == 11)
        return 30;
    else if (m == 2)
    {
        if(isLeap(y))
            return 29;
        return 28;
    }
    return 0;
}
/***********************************************************
*
* Method isLeap: Class Date
*_________________________________________________________
*  This function receives an unsigned integer
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* y: year of the date
*
* POST-CONDITIONS
*     This function returns true if the year is a leap year
***********************************************************/
bool Date::isLeap(unsigned y) const     //Year of the date
{
    bool leap = false;
    if (y % 100 == 0)
    {
        if(y % 400 == 0)
            leap = true;
        else
            leap = false;
    }
    else if(y % 4 == 0)
        leap = true;
    return leap;
}
/***********************************************************
*
* Method printNumeric: Class Date
*_________________________________________________________
*  This function receives nothing
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* none
*
* POST-CONDITIONS
*     This function displays the year in numeric form
***********************************************************/
void Date::printNumeric() const
{
    cout << month << "/" << day << "/" << year;
}
/***********************************************************
*
* Method printAlpha: Class Date
*_________________________________________________________
*  This function receives nothing
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* none
*
* POST-CONDITIONS
*     This function displays the year using the month name
***********************************************************/
void Date::printAlpha() const
{
    cout << monthName << " " << day << ", " << year;
}
/***********************************************************
*
* Method name: Class Date
*_________________________________________________________
*  This function receives an unsigned integer
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* m: month of the date
*
* POST-CONDITIONS
*     This function returns the name of the month
***********************************************************/
string Date::name(unsigned m) const     //Month of the date
{
    switch (m)
    {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    }
    return "January";
}
/***********************************************************
*
* Method number: Class Date
*_________________________________________________________
*  This function receives a string
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* mn: name of the month of the date
*
* POST-CONDITIONS
*     This function returns which number the month is
***********************************************************/
unsigned Date::number(const string& mn) const   //Month name
{
    if(mn == "January" || mn == "Jan" || mn == "january" || mn == "jan")
        return 1;
    else if(mn == "February" || mn == "Feb" || mn == "february" || mn == "feb")
        return 2;
    else if(mn == "March" || mn == "Mar" || mn == "march" || mn == "mar")
        return 3;
    else if(mn == "April" || mn == "Apr" || mn == "april" || mn == "apr")
        return 4;
    else if(mn == "May" || mn == "may")
        return 5;
    else if(mn == "June" || mn == "Jun" || mn == "june" || mn == "jun")
        return 6;
    else if(mn == "July" || mn == "Jul" || mn == "july" || mn == "jul")
        return 7;
    else if(mn == "August" || mn == "Aug" || mn == "august" || mn == "aug")
        return 8;
    else if(mn == "September" || mn == "Sep" || mn == "september"
            || mn == "sep")
        return 9;
    else if(mn == "October" || mn == "Oct" || mn == "october" || mn == "oct")
        return 10;
    else if(mn == "November" || mn == "Nov" || mn == "november" || mn == "nov")
        return 11;
    else if(mn == "December" || mn == "Dec" || mn == "december" || mn == "dec")
        return 12;
}

/***********************************************************
*
* Operator << : Class Date
*_________________________________________________________
*  This function receives an ostream and a Date
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* d: Date to print
* out: ostream object
*
* POST-CONDITIONS
*     This function prints a date using <<
***********************************************************/
ostream& operator << (ostream& out, const Date& d)
{
    out << d.month;
    out << "/";
    out << d.day;
    out << "/";
    out << d.year;
    return out;
}
bool Date::operator==(const Date &d)const
{
    if(day == d.day && month == d.month && year == d.year)
        return true;
    return false;
}
bool Date::operator<(const Date &d) const
{
    if(year > d.year)
        return false;
    else if(year < d.year)
        return true;
    else if(month > d.month)
        return false;
    else if(month < d.month)
        return true;
    else if(day > d.day)
        return false;
    else if(day < d.day)
        return true;
    return false;
}
bool Date::operator<=(const Date &d) const
{
    if(*this == d)
        return true;
    else if(*this < d)
        return true;
    return false;
}
