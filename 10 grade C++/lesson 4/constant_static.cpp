/* статичната променлива е обвързана с класа, а не с обекта
само статични методи могат да променят статични променливи извън класа
константните полета се инициализират с конструктор*/
#include <string>
#include <iostream>

using namespace std;

class Class
{
    const string name;
    int grade;
    string teacherName;

public:
    static int numberOfClasses;
    Class()
        : name("A"), grade(10) // ako go slojim tuk, a ne v tqlo e po burzo zashtoto spestqva edna operaciq
    {
    }
    Class(const string &name)
        : name(name), teacherName("Test") // извиква конструктор
    {
        this->teacherName = "Test";
        cout << this->grade << endl;
    }

    string getName() const
    {
        return this->name;
    }

    const string &getTeacherName(string name) const
    {
        // this->teacherName = name;
        return this->teacherName;
    }

    // void setName(const string &name)...
};

int Class::numberOfClasses = 0;

int main()
{
    cout << Class::numberOfClasses << endl;
    Class a("A");
    // a.getTeacherName("test2");
    cout << a.getTeacherName("Test2") << endl;
    return 0;
}