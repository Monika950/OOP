// virtual - ще бъде overrite-nata, ако няма тяло е напълно виртуална
// абстрактен клас - има само един напълно виртуален метод
// vector<Base*> - много е важно да се ползва pointer, за да са еднакъв размер и да не се shrink-va 
// виртуална таблица - 
#include<iostream>
#include<string>
#include<exception>
#include<vector>

using namespace std;

class Base
{
    int b;
    char* tmp; 
protected:
    int a;
    virtual bool validateA(int a) const=0;

public:
    virtual void printHello() const
    {
        cout<< "Hello from Base"<< endl;
    }
    int getA() const { return a; }
    virtual void setA(int a)
    {
        validateA(a);
        this->a=a;
    }
    virtual ~Base() // когато имаме абстрактен клас е много важно да се пише virtual
    {
        delete[] tmp;
    }

};

class Child : public Base
{
protected:
    bool validateA(int a) const override
    {
        if(a>0)
        {
            throw invalid_argument("getA() - a is positive");
        }
        return true;
    }

public:
    void printHello() const override
    {
        cout << "Hello from child " << endl;
    }
};

class Child2 : public Base 
{
    char* tmp1;
protected: 
    bool validateA(int a) const override
    {
        if(a<0)
        {
            throw invalid_argument("getA() - a is negative");
        }
        return true;
    }
public:
    Child2(): Base() //тук няма проблеми да го извикваме
    {

    }
    void printHello() const override
    {
        cout<< "Hello from Child2"<< endl;
    }
    ~Child2()
    {
        delete[] tmp1;
    }

};

int main()
{
    //vector<Base> arr;
    Child c;

    c.setA(-1);
    cout<<c.getA()<<endl;

    Child2 c2;
    c2.setA(5);
    cout<<c2.getA()<<endl;

    vector<Base*> arr;

    arr.push_back(&c);
    arr.push_back(&c2);
    for(int i=0; i < arr.size(); i++)
    {
        arr[i]->printHello();
    }

}