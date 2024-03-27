#include <iostream>
#include <exception>
#include <cstring>

using namespace std;

/**
 * Your task is to create a class MyException that inherits from std::exception and overrides the what() method.
 * You have the signature of the what method below.
 *
 * I want you to create:
 *  - Default constructor that will have a default message: MyCustomError: No message!
 *  - Constructor with a message
 *  - Destructor
 *  - Copy constructor
 *  - Copy assignment operator
 *  - what() method that will print the message in the following format: MyCustomError: <message>
 */

class MyException : public std::exception
{
private:
    char *errorMessage;

public:
    const char *what() const noexcept override
    {
        return errorMessage;
    }

    MyException()
        : errorMessage(strdup("MyCustomError: No message!"))
    {
    }

    MyException(const char *message)
        : errorMessage(strdup("MyCustomError: "))
    {
        this->errorMessage = strcat(this->errorMessage, message);
    }

    MyException(MyException const &other)
    {
        this->errorMessage = strdup(other.errorMessage);
    }

    MyException &operator=(const MyException &other)
    {
        if (this != &other)
        {
            delete[] this->errorMessage;
            this->errorMessage = strdup(other.errorMessage);
        }
        return *this;
    }

    ~MyException()
    {
        delete[] errorMessage;
    }
};

int main()
{
    MyException e1;
    cout << "Expected: MyCustomError: No message!\n"
         << "Got: " << e1.what() << endl;

    MyException e2("This is a message");
    cout << "Expected: MyCustomError: This is a message\n"
         << "Got: " << e2.what() << endl;
    return 0;
}