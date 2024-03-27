#include <iostream>
#include <vector>
using namespace std;

class Person
{
public:
    virtual void work() const // allows the function to be replaced with another implementation
    {
        cout << "The person is working" << endl;
    }
};

class Student : public Person
{
public:
    void work() const override
    { // work without it as well, but makes the code more readable
        cout << "The student is learning" << endl;
    }
};

class Teacher : public Person
{
public:
    void work() const override
    {
        // Person::work();
        cout << "The teacher is teaching" << endl;
    }
};

int main()
{
    Student s;
    Teacher t;
    s.work();
    t.work();
    vector<Person *> people;
    people.push_back(new Teacher());

    for (int i = 0; i < people.size(); i++)
    {
        people.push_back(new Student());
    }
    for (int i = 0; i < people.size(); i++)
    {
        people[i]->work();
    }
    return 0;
}