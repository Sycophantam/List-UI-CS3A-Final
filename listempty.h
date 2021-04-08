#ifndef LISTEMPTY_H
#define LISTEMPTY_H

#include <string>

using namespace std;
class ListEmpty
{
public:
    ListEmpty()
    {
        message = "Error: List is empty";
    }
    ListEmpty(string new_message)
    {
        message = new_message;
    }
    string what() const
    {
        return message;
    }
private:
    string message;
};

#endif // LISTEMPTY_H
