#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/**
 * Your task is to add a counter of how many Objects of type String are currently in the memory, and how many have been created.
 */

class String
{
    char *data;
    size_t length;

public:
    static int stringsCurrently;
    static int totalStrings;

    String(const char *data)
    {
        this->length = strlen(data);
        this->data = strdup(data);
        stringsCurrently++;
        totalStrings++;
    }

    String(const String &other)
    {
        this->length = other.length;
        this->data = strdup(other.data);
        totalStrings++;
    }

    String &operator=(const String &other)
    {
        if (this != &other)
        {
            free(this->data);
            this->length = other.length;
            this->data = strdup(other.data);
            totalStrings++;
        }
        return *this;
    }

    ~String()
    {
        stringsCurrently--;
        free(this->data);
    }

    const char *getCString() const
    {
        return this->data;
    }

    size_t strlength() const
    {
        return this->length;
    }

    static int getCurrentStringCount()
    {
        return stringsCurrently;
    }

    static int getTotalStringCount()
    {
        return totalStrings;
    }
};

int String::stringsCurrently = 0;
int String::totalStrings = 0;

int main()
{
    String *s = new String("Test message");

    vector<String *> arr;
    for (int i = 0; i < 3; i++)
    {
        arr.push_back(new String("Test message"));
    }

    cout << "Expected: 4, got: " << String::getCurrentStringCount() << endl;
    delete s;
    cout << "Expected: 3, got: " << String::getCurrentStringCount() << endl;
    cout << "Expected: 4, got: " << String::getTotalStringCount() << endl;

    return 0;
}