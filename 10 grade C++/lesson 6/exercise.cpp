#include <iostream>
#include <string>
#include <cstring>

using namespace std;

enum Sex
{
    MALE,
    FEMALE,
    OTHER,
    UNDEFINED
};

class Person
{
    char *name;
    const string birthday;
    Sex sex;
    static unsigned numberOfPeopleCreated;

protected:
    unsigned int age;
    unsigned int weight;
    unsigned int height;

public:
    Person()
        : name(strdup("")), age(0), weight(0), height(0), birthday(""), sex(Sex::UNDEFINED)
    {
        numberOfPeopleCreated++;
    }

    Person(const string &birthday, unsigned int weight, unsigned int height, Sex s)
        : name(strdup("")), age(0), weight(weight), height(height), birthday(birthday), sex(s)
    {
        numberOfPeopleCreated++;
    }

    Person(const Person &other)
        : birthday(other.birthday)
    {
        this->name = strdup(other.name);
        this->age = other.age;
        this->weight = other.weight;
        this->height = other.height;
        numberOfPeopleCreated++;
    }

    Person &operator=(const Person &other)
    {
        if (this->birthday != other.birthday)
        {
            throw runtime_error("Differance in birthday field");
        }

        if (this != &other)
        {
            delete[] this->name;
            this->name = strdup(other.name);
            this->age = other.age;
            this->weight = other.weight;
            this->height = other.height;
        }

        return *this;
    }

    ~Person()
    {
        delete[] name;
    }

    const char *getName() const
    {
        return this->name;
    }

    void setName(const char *name)
    {
        if (name == nullptr)
        {
            throw invalid_argument("Nullptr passed as argument!");
        }
        delete[] this->name;
        this->name = strdup(name);
    }

    unsigned int getAge() const
    {
        return age;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    unsigned getWeight() const
    {
        return weight;
    }

    void setWeight(unsigned weight)
    {
        this->weight = weight;
    }

    unsigned getHeight() const
    {
        return height;
    }

    void setHeight(unsigned height)
    {
        this->height = height;
    }

    string getBirthday() const
    {
        return birthday;
    }

    Sex getSex() const
    {
        return sex;
    }

    void setSex(Sex sex)
    {
        this->sex = sex;
    }

    static int getNumberOfPeopleCreated()
    {
        return numberOfPeopleCreated;
    }

    virtual void doSport() const
    {
        cout << "I am not doing anything..." << endl;
    }

    virtual void growUpWithOneYear()
    {
        this->age++;
        this->weight += 5;
        this->height += 2;
    }
};

unsigned Person::numberOfPeopleCreated = 0;

class BasketballPlayer : public Person
{
    string teamName;

public:
    BasketballPlayer()
        : Person(),
          teamName("")
    {
    }

    BasketballPlayer(const char *name, const string &birthday, unsigned age, unsigned weight, unsigned height, Sex s, string teamName)
        : Person(birthday, weight, height, s)
    {
        this->setName(name);
        this->age = age;
        this->teamName = teamName;
    }

    BasketballPlayer(BasketballPlayer &other)
        : Person(other)
    {
        this->teamName = other.teamName;
    }

    ~BasketballPlayer()
    {
        Person::~Person();
    }

    BasketballPlayer &operator=(const BasketballPlayer &other)
    {
        Person::operator=(other);
        this->teamName = other.teamName;
        return *this;
    }

    string getTeamName() const
    {
        return teamName;
    }

    void doSport() const override
    {
        cout << "I am playing a basketball game!" << endl;
    }

    virtual void growUpWithOneYear() override
    {
        this->age++;
        this->weight += 10;
        this->height += 7;
    }
};

class FootballPlayer : public Person
{
    string teamName;

public:
    FootballPlayer()
        : Person(),
          teamName("")
    {
    }

    FootballPlayer(const char *name, const string &birthday, unsigned age, unsigned weight, unsigned height, Sex s, string teamName)
        : Person(birthday, weight, height, s)
    {
        this->setName(name);
        this->age = age;
        this->teamName = teamName;
    }

    FootballPlayer(FootballPlayer &other)
        : Person(other)
    {
        this->teamName = other.teamName;
    }

    ~FootballPlayer()
    {
        Person::~Person();
    }

    FootballPlayer &operator=(const FootballPlayer &other)
    {
        Person::operator=(other);
        this->teamName = other.teamName;
        return *this;
    }

    string getTeamName() const
    {
        return teamName;
    }

    void doSport() const override
    {
        cout << "I am playing a football game!" << endl;
    }

    virtual void growUpWithOneYear() override
    {
        this->age++;
        this->weight += 6;
        this->height += 6;
    }
};

int main()
{
    const string b = "asd";

    Person p(b, 1, 2, Sex::MALE);

    return 0;
}