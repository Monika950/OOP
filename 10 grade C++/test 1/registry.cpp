#include <iostream>
#include <cstring>
#include <exception>
using namespace std;

class Registry
{
public:
    char *registerName;
    string *records;
    size_t numberOfRecords;
    static int numberOfActiveRegistries;

    Registry()
        : registerName(strdup("")), records(new string[2]), numberOfRecords(2)
    {
        numberOfActiveRegistries++;
    }

    Registry(const char *registerName, string *records, size_t numberOfRecords)
    {
        if (numberOfRecords <= 0 || registerName == nullptr || records == nullptr)
            throw invalid_argument("Invalid arguments");
        this->registerName = strdup(registerName);
        this->numberOfRecords = numberOfRecords;
        this->records = new string[numberOfRecords];
        for (int i = 0; i < numberOfRecords; i++)
            this->records[i] = records[i];

        numberOfActiveRegistries++;
    }

    Registry(const Registry &other)
    {
        this->registerName = strdup(other.registerName);
        this->numberOfRecords = other.numberOfRecords;
        this->records = new string[this->numberOfRecords];
        for (int i = 0; i < this->numberOfRecords; i++)
            this->records[i] = other.records[i];

        numberOfActiveRegistries++;
    }

    Registry &operator=(const Registry &other)
    {
        if (this != &other)
        {
            delete[] this->registerName;
            this->registerName = strdup(other.registerName);
            this->numberOfRecords = other.numberOfRecords;
            delete[] this->records;
            this->records = new string[this->numberOfRecords];
            for (int i = 0; i < this->numberOfRecords; i++)
                this->records[i] = other.records[i];
        }
        return *this;
    }

    ~Registry()
    {
        delete[] records;
        delete[] registerName;
        numberOfActiveRegistries--;
    }

    static int getActiveRegistries()
    {
        return numberOfActiveRegistries;
    }

    void printRegistryInformation()
    {
        cout << registerName;
        for (int i = 0; i < numberOfRecords; i++)
            cout << " " << records[i];
        cout << endl;
    }
};

int Registry::numberOfActiveRegistries = 0;

class PhoneRegistry : public Registry
{
    string *phoneNumbers;
    size_t numberOfPhoneNumbers;

public:
    PhoneRegistry()
        : Registry(), phoneNumbers(new string[2]), numberOfPhoneNumbers(2)
    {
    }

    PhoneRegistry(const char *registerName, string *records, size_t numberOfRecords, string *phoneNumbers, size_t numberOfPhoneNumbers)
        : Registry(registerName, records, numberOfRecords)
    {
        if (numberOfPhoneNumbers <= 0 || phoneNumbers == nullptr)
            throw invalid_argument("Invalid arguments");
        this->numberOfPhoneNumbers = numberOfPhoneNumbers;
        this->phoneNumbers = new string[numberOfPhoneNumbers];
        for (int i = 0; i < numberOfPhoneNumbers; i++)
            this->phoneNumbers[i] = phoneNumbers[i];
    }

    PhoneRegistry &operator=(const PhoneRegistry &other)
    {
        if (this != &other)
        {
            Registry::operator=(other);
            this->numberOfPhoneNumbers = other.numberOfPhoneNumbers;
            delete[] this->phoneNumbers;
            this->phoneNumbers = new string[this->numberOfPhoneNumbers];
            for (int i = 0; i < this->numberOfPhoneNumbers; i++)
                this->phoneNumbers[i] = other.phoneNumbers[i];
        }
        return *this;
    }

    ~PhoneRegistry()
    {
        Registry::~Registry();
        delete[] phoneNumbers;
    }

    void printRegistryInformation()
    {
        cout << registerName;
        for (int i = 0; i < numberOfRecords; i++)
        {
            if (i < numberOfPhoneNumbers)
                cout << " " << records[i] << " " << phoneNumbers[i];
            else
                cout << " " << records[i] << " -";
        }
        cout << endl;
    }
};

int main()
{
    try
    {
        string records[] = {"Record1", "Record2", "Record3"};
        string phones[] = {"123", "456"};

        Registry *reg1 = new Registry("Registry1", records, 3);
        PhoneRegistry *phoneReg1 = new PhoneRegistry("PhoneRegistry1", records, 3, phones, 2);

        cout << "Active registries: " << Registry::getActiveRegistries() << endl;

        reg1->printRegistryInformation();
        phoneReg1->printRegistryInformation();

        delete reg1;
        delete phoneReg1;

        cout << "Active registries: " << Registry::getActiveRegistries() << endl;
    }
    catch (exception &e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}