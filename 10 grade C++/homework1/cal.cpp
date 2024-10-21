#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <exception>

using namespace std;

class Operation
{
protected:
    string name;
    string symbol;

public:
    Operation(const string &name, const string &symbol)
    {
        if (name.empty() || symbol.empty())
        {
            throw invalid_argument("Name and symbol cannot be empty");
        }
        this->name = name;
        this->symbol = symbol;
    }

    Operation(const Operation &other)
        : name(other.name), symbol(other.symbol)
    {
    }

    Operation &operator=(const Operation &other)
    {
        if (this != &other)
        {
            this->name = other.name;
            this->symbol = other.symbol;
        }
        return *this;
    }

    string getName() const { return name; }
    string getSymbol() const { return symbol; }
    void setName(string name)
    {
        if (name.empty())
        {
            throw invalid_argument("Name cannot be empty");
        }
        this->name = name;
    }
    void setSymbol(string symbol)
    {
        if (symbol.empty())
        {
            throw invalid_argument("Symbol cannot be empty");
            this->symbol = symbol;
        }
    }

    virtual double execute(const double n1, const double n2) = 0;
};

class AddOperation : public Operation
{
public:
    AddOperation()
        : Operation("add", "+")
    {
    }

    AddOperation(const AddOperation &other)
        : Operation(other)
    {
    }

    AddOperation &operator=(const AddOperation &other)
    {
        if (this != &other)
        {
            Operation::operator=(other);
        }
        return *this;
    }

    double execute(const double n1, const double n2) override
    {
        return n1 + n2;
    }
};

class SubtractOperation : public Operation
{
public:
    SubtractOperation()
        : Operation("sub", "–")
    {
    }

    SubtractOperation(const SubtractOperation &other)
        : Operation(other)
    {
    }

    SubtractOperation &operator=(const SubtractOperation &other)
    {
        if (this != &other)
        {
            Operation::operator=(other);
        }
        return *this;
    }

    double execute(const double n1, const double n2) override
    {
        return n1 - n2;
    }
};

class MultiplyOperation : public Operation
{
public:
    MultiplyOperation()
        : Operation("multiplication", "*")
    {
    }

    MultiplyOperation(const MultiplyOperation &other)
        : Operation(other)
    {
    }

    MultiplyOperation &operator=(const MultiplyOperation &other)
    {
        if (this != &other)
        {
            Operation::operator=(other);
        }
        return *this;
    }

    double execute(const double n1, const double n2) override
    {
        return n1 * n2;
    }
};

class DivideOperation : public Operation
{
public:
    DivideOperation()
        : Operation("division", "/")
    {
    }

    DivideOperation(const DivideOperation &other)
        : Operation(other)
    {
    }

    DivideOperation &operator=(const DivideOperation &other)
    {
        if (this != &other)
        {
            Operation::operator=(other);
        }
        return *this;
    }

    double execute(const double n1, const double n2) override
    {
        if (n2 != 0)
        {
            return n1 / n2;
        }
        else
        {
            throw invalid_argument("Division by zero!");
        }
    }
};

class PowerOperation : public Operation
{
public:
    PowerOperation()
        : Operation("power", "**")
    {
    }

    PowerOperation(const PowerOperation &other)
        : Operation(other)
    {
    }

    PowerOperation &operator=(const PowerOperation &other)
    {
        if (this != &other)
        {
            Operation::operator=(other);
        }
        return *this;
    }

    double execute(const double n1, const double n2) override
    {
        return pow(n1, n2);
    }
};

class RootOperation : public Operation
{
public:
    RootOperation()
        : Operation("root", "V")
    {
    }

    RootOperation(const RootOperation &other)
        : Operation(other)
    {
    }

    RootOperation &operator=(const RootOperation &other)
    {
        if (this != &other)
        {
            Operation::operator=(other);
        }
        return *this;
    }

    double execute(const double n1, const double n2) override
    {
        if ((n1 < 0 && (int)n2 % 2 == 0) || n2 <= 0)
            throw invalid_argument("Cannot calculate");

        if (n1 < 0)
            return -pow(-n1, 1 / n2);

        return pow(n1, 1 / n2);
    }
};

class Calculator
{
private:
    const char *name;
    size_t numberOfSupportedOperations;
    size_t capacityForOperations;
    Operation **operations;
    static int numberOfSuccessfulCalculations;

public:
    Calculator()
        : name(strdup("")), numberOfSupportedOperations(0), capacityForOperations(2)
    {
        this->operations = new Operation *[capacityForOperations];
    }

    Calculator(const char *name, size_t n, Operation **ops)
        : capacityForOperations(n),
          numberOfSupportedOperations(n)
    {
        if (name == nullptr || *name == '\0')
        {
            throw invalid_argument("Name cannot be empty or null");
        }
        this->name = strdup(name);
        if (capacityForOperations <= 0)
        {
            throw invalid_argument("capacityForOperations cannot be 0");
        }
        this->operations = new Operation *[capacityForOperations];
        for (size_t i = 0; i < numberOfSupportedOperations; i++)
            this->operations[i] = ops[i];
    }

    Calculator(const Calculator &other)
        : name(strdup(other.name)), capacityForOperations(other.capacityForOperations), numberOfSupportedOperations(other.numberOfSupportedOperations)
    {
        this->operations = new Operation *[capacityForOperations];
        for (size_t i = 0; i < capacityForOperations; i++)
            this->operations[i] = other.operations[i];
    }

    Calculator &operator=(const Calculator &other)
    {
        if (this != &other)
        {
            delete[] name;
            for (size_t i = 0; i < numberOfSupportedOperations; ++i)
            {
                delete operations[i];
            }
            delete[] operations;

            this->name = strdup(other.name);
            this->numberOfSupportedOperations = other.numberOfSupportedOperations;
            this->capacityForOperations = other.capacityForOperations;

            this->operations = new Operation *[capacityForOperations];
            for (size_t i = 0; i < this->numberOfSupportedOperations; ++i)
            {
                operations[i] = other.operations[i];
            }
        }
        return *this;
    }

    ~Calculator()
    {
        delete[] name;
        for (size_t i = 0; i < numberOfSupportedOperations; i++)
        {
            delete operations[i];
        }
        delete[] operations;
    }

    void listSupportedOperations()
    {
        if (numberOfSupportedOperations == 0)
        {
            cout << "No supported operations";
        }
        else
        {
            for (size_t i = 0; i < numberOfSupportedOperations; i++)
            {
                cout << operations[i]->getSymbol() << " - " << operations[i]->getName() << endl;
            }
        }
    }

    void listInputFormat() const
    {
        cout << "Input format: <number> <operation> <number> = " << endl;
    }

    Calculator &addOperation(const Operation *op)
    {
        if (op == nullptr)
        {
            throw invalid_argument("Operation cannot be null");
        }
        if (numberOfSupportedOperations == capacityForOperations)
        {
            capacityForOperations *= 2;

            Operation **tmp = new Operation *[capacityForOperations];
            for (size_t i = 0; i < numberOfSupportedOperations; ++i)
            {
                tmp[i] = operations[i];
            }
            delete[] operations;
            operations = tmp;

            if (typeid(*op) == typeid(AddOperation))
            {
                operations[numberOfSupportedOperations++] = new AddOperation(*dynamic_cast<const AddOperation *>(op));
            }
            else if (typeid(*op) == typeid(SubtractOperation))
            {
                operations[numberOfSupportedOperations++] = new SubtractOperation(*dynamic_cast<const SubtractOperation *>(op));
            }
            else if (typeid(*op) == typeid(MultiplyOperation))
            {
                operations[numberOfSupportedOperations++] = new MultiplyOperation(*dynamic_cast<const MultiplyOperation *>(op));
            }
            else if (typeid(*op) == typeid(DivideOperation))
            {
                operations[numberOfSupportedOperations++] = new DivideOperation(*dynamic_cast<const DivideOperation *>(op));
            }
            else if (typeid(*op) == typeid(PowerOperation))
            {
                operations[numberOfSupportedOperations++] = new PowerOperation(*dynamic_cast<const PowerOperation *>(op));
            }
            else if (typeid(*op) == typeid(RootOperation))
            {
                operations[numberOfSupportedOperations++] = new RootOperation(*dynamic_cast<const RootOperation *>(op));
            }
            else
            {
                throw invalid_argument("Unsupported operation");
            }
        }
        else
        {
            if (typeid(*op) == typeid(AddOperation))
            {
                operations[numberOfSupportedOperations++] = new AddOperation(*dynamic_cast<const AddOperation *>(op));
            }
            else if (typeid(*op) == typeid(SubtractOperation))
            {
                operations[numberOfSupportedOperations++] = new SubtractOperation(*dynamic_cast<const SubtractOperation *>(op));
            }
            else if (typeid(*op) == typeid(MultiplyOperation))
            {
                operations[numberOfSupportedOperations++] = new MultiplyOperation(*dynamic_cast<const MultiplyOperation *>(op));
            }
            else if (typeid(*op) == typeid(DivideOperation))
            {
                operations[numberOfSupportedOperations++] = new DivideOperation(*dynamic_cast<const DivideOperation *>(op));
            }
            else if (typeid(*op) == typeid(PowerOperation))
            {
                operations[numberOfSupportedOperations++] = new PowerOperation(*dynamic_cast<const PowerOperation *>(op));
            }
            else if (typeid(*op) == typeid(RootOperation))
            {
                operations[numberOfSupportedOperations++] = new RootOperation(*dynamic_cast<const RootOperation *>(op));
            }
            else
            {
                throw invalid_argument("Unsupported operation");
            }
        }
        return *this;
    }
    void startCalculation()
    {
        double n1, n2, result = 0;
        char op;
        try
        {
            cin >> n1 >> op;
            while (op != '=')
            {
                cin >> n2;
                bool found = false;
                for (size_t i = 0; i < numberOfSupportedOperations; ++i)
                {
                    if (operations[i]->getSymbol()[0] == op)
                    {
                        try
                        {
                            numberOfSuccessfulCalculations++;
                            result = operations[i]->execute(n1, n2);
                        }
                        catch (const std::exception &e)
                        {
                            cout << "Error: " << e.what() << endl;
                            numberOfSuccessfulCalculations--;
                        }
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    throw invalid_argument("Invalid operation");
                }
                n1 = result;
                cin >> op;
            }
            cout << "Result: " << result << endl;
    }
        catch (const exception &e)
        {
            cout << "Exception occurred: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            startCalculation();
        }
    }
    static int getNumberOfSuccessfulCalculations()
    {
        return numberOfSuccessfulCalculations;
    }

    void setName(const char *name)
    {
        if (name == nullptr || *name == '\0')
        {
            throw invalid_argument("Name cannot be empty");
        }
        delete[] this->name;
        this->name = strdup(name);
    }
};

int Calculator::numberOfSuccessfulCalculations = 0;

int main()
{
    Calculator calculator;

    cout << "Enter calculator's name: ";
    char name[100];
    cin.getline(name, 100);
    calculator.setName(name);

    size_t numberOfOperations;
    bool validInput = false;
    do {
        cout << "Enter number of operations: ";
        if (cin >> numberOfOperations && numberOfOperations > 0) {
            validInput = true;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cout << "Invalid input. Please enter a valid number greater than zero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    } while (!validInput);

    cout << "Enter operations: <symbol> - <name> " << endl;
    for (size_t i = 0; i < numberOfOperations; i++)
    {
        string name;
        string symbol;

        string line;
        getline(cin, line);

        stringstream ss(line);
        getline(ss, symbol, '-');
        getline(ss, name, '\n');

        symbol.erase(symbol.find_last_not_of(" \t") + 1);

        try
        {
            Operation *op = nullptr;
            if (symbol == "+")
                op = new AddOperation();
            else if (symbol == "–")
                op = new SubtractOperation();
            else if (symbol == "*")
                op = new MultiplyOperation();
            else if (symbol == "/")
                op = new DivideOperation();
            else if (symbol == "**")
                op = new PowerOperation();
            else if (symbol == "V")
                op = new RootOperation();
            else
            {
                cout << "Unsupported operation. Please try again." << endl;
                i--;
                continue;
            }
            op->setName(name);
            calculator.addOperation(op);
        }
        catch (exception &e)
        {
            cout << "Error: " << e.what() << endl;
            i--;
            continue;
        }
    }

    int choice;
    do
    {
        cout << "Menu: " << endl;
        cout << "1. List supported operations" << endl;
        cout << "2. List input format" << endl;
        cout << "3. Start calculation" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose option: ";
        cin >> choice;
        cin.clear();

        switch (choice)
        {
        case 1:
            cout << "Supported operations:" << endl;
            calculator.listSupportedOperations();
            break;
        case 2:
            calculator.listInputFormat();
            break;
        case 3:
            calculator.startCalculation();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}