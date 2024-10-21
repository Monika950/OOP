/* класът е рецептата, а обектът самото ястие
разгледахме дефолт конструктури и с параметри
монолит - цялото приложение е на едно място
микросървисна архитектура - разбит монолит

constructor -  a special function of a class that is automatically called when an object is created.
destructor - a special function of a class that is automatically called when an object goes out of scope or is explicitly deleted

голямата 5рка:
default constructor
param constructor
copy constructor
move constructor
operator= (a special kind of operator used to assign the value of one object to another of the same type.)
*/

/*SHALLOW COPY - пести памет, но ако единият изчезне, и другият също (shared resourses)
  DEEP COPY - прави същото второ*/

#include <iostream>
#include <cstring>
using namespace std;

enum Weekday
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

/*const char* - ne moje da promenim elementite, const value
  char const* - ne moje da promenim pointera, const pointer
  const char const* - ne moje da promenqme nishto*/

const char *translateDay(Weekday day)
{
    char *result;
    switch (day)
    {
    case Weekday::MONDAY:
        result = strdup("monday"); // samo zadelq pametta
        break;
    case Weekday::TUESDAY:
        result = strdup("tuesday");
        break;
    case Weekday::WEDNESDAY:
        result = strdup("wednesday");
        break;
    case Weekday::THURSDAY:
        result = strdup("thursday");
        break;
    case Weekday::FRIDAY:
        result = strdup("friday");
        break;
    case Weekday::SATURDAY:
        result = strdup("saturday");
        break;
    case Weekday::SUNDAY:
        result = strdup("sunday");
        break;
    }

    return result;
}

// function overloading
Weekday translateDay(const char *day)
{
    return Weekday::MONDAY; // dr
}

class Event
{
    Weekday day;
    char *name;
    char *description;
    unsigned duration;

public:
    Event(const char *name, const char *description, unsigned duration, Weekday day)
    {
        cout << "Hello from Constructor with parameters" << endl;
        this->name = strdup(name);
        this->description = strdup(description);
        this->duration = duration;
        this->day = day;
    }

    Event(Event &other)
    {
        cout << "Hello from  Copy constructor" << endl;
        this->name = strdup(other.name);
        this->description = strdup(other.description);
        this->duration = other.duration;
        this->day = other.day; // ako ne iskame taka da gi dostupvame shte si napravim methodi
    }

    /*Event(Event &&other) //move construktor
    {
        cout <<"Hello from  Copy constructor"<<endl;
        this->name = strdup(other.name);
        this->description = strdup(other.description);
        this->duration = other.duration;
        this->day = other.day;

        delete[] other.name;
        delete[] other.description;
    }*/

    Event &operator=(const Event &other) // ako e read only e hubavo da slagame const
    {
        if (this != &other)
        {
            delete[] this->name;
            delete[] this->description;
            this->name = strdup(other.name);
            this->description = strdup(other.description);
            this->duration = other.duration;
            this->day = other.day;
        }
        return *this;
    }

    ~Event()
    {
        delete[] this->name;
        delete[] this->description;
    }
};

int main()
{
    Event e("Test", "Test test", 1, Weekday::MONDAY);
    Event e2 = e;
    // Event a=b; == Event a(b); трябва нов конструктор

    /* Event a(...);
       a = b;
    */

    Event e3 = e2;
    e3 = e;
    return 0;
}