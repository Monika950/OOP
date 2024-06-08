#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

class EmployeePayments
{

private:
    double *salaries;
    unsigned size;
    unsigned capacity;
    string employeeName;

    void resize()
    {
        capacity *= 2;
        double *newSalaries = new double[capacity];
        copy(salaries, salaries + size, newSalaries);
        delete[] salaries;
        salaries = newSalaries;
    }

public:
    EmployeePayments() : size(1), capacity(1), employeeName("")
    {
        salaries = new double[1];
        salaries[0] = 910.00;
    }

    EmployeePayments(const double *salaries, int size, int capacity, const string &name) : size(size), capacity(capacity), employeeName(name)
    {
        if (size < 0 || capacity < size)
        {
            throw invalid_argument("Invalid size or capacity");
        }
        this->salaries = new double[capacity];
        for (int i = 0; i < size; i++)
        {
            if (salaries[i] < 910.00 || salaries[i] > 2500.00)
            {
                delete[] this->salaries;
                throw invalid_argument("Invalid salary amount");
            }
            this->salaries[i] = salaries[i];
        }
    }

    EmployeePayments(const EmployeePayments &other) : size(other.size), capacity(other.capacity), employeeName(other.employeeName)
    {
        salaries = new double[capacity];
        copy(other.salaries, other.salaries + size, salaries);
    }

    EmployeePayments &operator=(const EmployeePayments &other)
    {
        if (this != &other)
        {
            delete[] salaries;

            size = other.size;
            capacity = other.capacity;
            employeeName = other.employeeName;
            salaries = new double[capacity];
            copy(other.salaries, other.salaries + size, salaries);
        }
        return *this;
    }

    ~EmployeePayments()
    {
        delete[] salaries;
    }

    double *getSalaries() const
    {
        return salaries;
    }

    int getSize() const
    {
        return size;
    }

    int getCapacity() const
    {
        return capacity;
    }

    string getEmployeeName() const
    {
        return employeeName;
    }

void addSalary(double salary)
{
    if (salary < 910.00 || salary > 2100.00)
    {
        throw invalid_argument("Invalid salary amount");
    }
    if (size == capacity)
    {
        resize();
    }
    salaries[size] = salary;

    size++;
}
};

class Person
{
private:
    string name;
    int age;
    static unsigned personCount;

public:
    Person(const string &name, int age)
    {
        if (name.empty())
        {
            throw invalid_argument("Name cannot be empty");
        }
        if (age < 0 || age > 65)
        {
            throw invalid_argument("Age must be between 0 and 65");
        }
        this->name = name;
        this->age = age;
        personCount++;
    }

    Person(const Person &other) : name(other.name), age(other.age)
    {
        personCount++;
    }

    Person &operator=(const Person &other)
    {
        if (this != &other)
        {
            name = other.name;
            age = other.age;
        }
        return *this;
    }

    virtual ~Person()
    {
        personCount--;
    }

    string getName() const
    {
        return name;
    }

    int getAge() const
    {
        return age;
    }

    static unsigned getPersonCount()
    {
        return personCount;
    }
};

unsigned Person::personCount = 0;

class Employee : public Person
{
private:
    string position;
    int experience;
    EmployeePayments salaries;

public:
    Employee(const string &name, int age, const string &position, int experience, const EmployeePayments &salaries)
        : Person(name, age), position(position), experience(experience), salaries(salaries)
    {
        if (position.empty())
        {
            throw invalid_argument("Position cannot be empty");
        }
        if (experience < 1)
        {
            throw invalid_argument("Experience must be at least 1 year");
        }
    }

    Employee(const Employee &other)
        : Person(other), position(other.position), experience(other.experience), salaries(other.salaries) {}

    Employee &operator=(const Employee &other)
    {
        if (this != &other)
        {
            Person::operator=(other);
            position = other.position;
            experience = other.experience;
            salaries = other.salaries;
        }
        return *this;
    }

    ~Employee()
    {
        Person::~Person();
    }

    string getPosition() const
    {
        return position;
    }

    int getExperience() const
    {
        return experience;
    }

    EmployeePayments getSalariesE() const
    {
        return salaries;
    }

    double calculateAverageSalary() const
    {
        double total = 0;
        for (int i = 0; i <= salaries.getSize(); i++)
        {
            total += salaries.getSalaries()[i];
        }
        return  salaries.getSize() > 0 ? total /  salaries.getSize() : 0.0;
    }
    friend ostream &operator<<(ostream &os, const Employee &emp)
    {
        os << "e " << emp.getName() << " " << emp.getAge() << " " << emp.getPosition() << " " << emp.getExperience()
           << " Average Salary: " << emp.calculateAverageSalary();
        return os;
    }
};

class Manager : public Person
{
private:
    string department;

    void validateDepartment(const string &department)
    {
        const vector<string> validDepartments = {"delivery", "marketing", "sales", "human resources"};

        bool found = false;
        for (int i = 0; i < validDepartments.size(); i++)
        {
            if (validDepartments[i] == department)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            throw invalid_argument("Invalid department: " + department);
        }
    }

public:
    Manager(const string &name, int age, const string &department)
        : Person(name, age), department(department)
    {
        if (department.empty())
        {
            throw invalid_argument("Department cannot be empty");
        }
        validateDepartment(department);
    }

    Manager(const Manager &other) : Person(other), department(other.department) {}

    Manager &operator=(const Manager &other)
    {
        if (this != &other)
        {
            Person::operator=(other);
            department = other.department;
        }
        return *this;
    }

    ~Manager()
    {
        Person::~Person();
    }

    string getDepartment() const
    {
        return department;
    }

    void payEmployeeByName(const string &employeeName, vector<Employee> &employees, double salary)
    {
        bool found = false;
        for (auto &employee : employees)
        {
            if (employee.getName() == employeeName)
            {
                employee.getSalariesE().addSalary(salary);
                found = true;
                break;
            }
        }
        if (!found)
        {
            throw invalid_argument("Employee with name " + employeeName + " not found.");
        }
    }

    friend ostream &operator<<(ostream &os, const Manager &mgr)
    {
        os << "m " << mgr.getName() << " " << mgr.getAge() << " " << mgr.getDepartment();
        return os;
    }
};

class FileManager
{
private:
    const string inputFileName;
    const string outputFileName;

public:
    FileManager(const string &inputFileName, const string &outputFileName)
        : inputFileName(inputFileName), outputFileName(outputFileName) {}

    void readData(vector<Employee> &employees, vector<Manager> &managers)
    {
        ifstream inputFile(inputFileName);
        if (!inputFile.is_open())
        {
            throw runtime_error("Cannot open input file.");
        }

        string type;
        while (inputFile >> type)
        {
            if (type == "e")
            {
                string firstName, lastName, name, position;
                int age, experience;
                inputFile >> firstName >> lastName >> age >> position >> experience;
                name = firstName + " " + lastName;

                EmployeePayments salaries;
                Employee emp(name, age, position, experience, salaries);
                employees.push_back(emp);
            }
            else if (type == "m")
            {
                string firstName, lastName, name, department, empName1, empName2, empName;
                int age;
                double salary;
                inputFile >> firstName >> lastName >> age >> department >> empName1 >> empName2 >> salary;
                name = firstName + " " + lastName;
                empName = empName1 + " " + empName2;

                Manager mgr(name, age, department);
                try
                {
                    mgr.payEmployeeByName(empName, employees, salary);
                }
                catch (const invalid_argument &e)
                {
                    cerr << "Error: " << e.what() << endl;
                }
                managers.push_back(mgr);
            }
        }

        inputFile.close();
    }

    void writeData(const vector<Employee> &employees, const vector<Manager> &managers)
    {
        ofstream outputFile(outputFileName);
        if (!outputFile.is_open())
        {
            throw runtime_error("Cannot open output file.");
        }

        for (const auto &emp : employees)
        {
            outputFile << emp << endl;
        }

        for (const auto &mgr : managers)
        {
            outputFile << mgr << endl;
        }

        outputFile.close();
    }
};

int main()
{
    try
    {
        vector<Employee> employees;
        vector<Manager> managers;

        FileManager fileManager("input.txt", "output.txt");

        fileManager.readData(employees, managers);
        fileManager.writeData(employees, managers);

        cout << "Data processing complete." << endl;
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
