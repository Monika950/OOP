#include <cstring>
#include <iostream>

using namespace std;

class String {
  char *data;
  size_t length;

public:
  String(const char *data) {
    this->data = strdup(data);
    this->length = strlen(data);
  }

  String(const String &other) {
    this->data = strdup(other.data);
    this->length = other.length;
  }

  String &operator=(const String &other) {
    if (this != &other) {
      delete[] this->data;

      this->data = strdup(other.data);
      this->length = other.length;
      delete[] other.data;
    }
    return *this;
  }

  ~String() { delete[] this->data; }

  const char *getCString() const { return this->data; }

  size_t strlength() const { return this->length; }
};

int main() {
  String myString("Test message");

  cout << "Expected: Test message, got: " << myString.getCString() << endl;

  String stringFromCopyConstructor(myString);
  cout << "Expected: Test message, got: "
       << stringFromCopyConstructor.getCString() << endl;

  String string("Test message 2");

  string = myString;
  cout << "Expected: Test message, got: " << string.getCString() << endl;
}