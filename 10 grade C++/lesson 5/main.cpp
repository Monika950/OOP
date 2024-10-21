/* модификатори (visability) - public или private; protected- семейна тайна
const след функцията -> не модифицира вътрешното състояние на обекта, не трябва да променя стойността и не може да връщаш референция или трябва да е константна*/

#include <iostream>
using namespace std;

class Base
{
    int a;

public:
    Base()
    {
        cout << "Base constructor" << endl;
    }

    Base(int a)
    {
        cout << "Base param constructor" << endl;
    }

    Base(const Base &other)
    {
    }

    ~Base()
    {
        cout << "Base destructor" << endl;
    }

    void print() const
    {
        cout << "base" << endl;
    }
};

class Child : public Base // private/protected
{
    string a = "t";

public:
    Child()
        : Base()
    {
        cout << "Child constuctor" << endl;
    }

    Child(int a)
        : Base(a)
    {
        cout << "Child param constuctor" << endl;
    }

    Child(const Child &other)
        : Base(other)
    {
    }

    ~Child()
    {
        cout << "Child destructor" << endl;
    }

    Child &operator=(const Child &other)
    {
        if (this != &other)
        {
            Base::operator=(other);
            cout << "Child copy assign operator" << endl;
        }
        return *this;
    }

    void print2() const
    {
        cout << "Hello from child" << endl;
    }

    const string &getA() const
    {
        return a;
    }
};

int main()
{
    Child child;
    cout << child.getA() << endl;

    return 0;
}