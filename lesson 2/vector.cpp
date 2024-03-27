/* class - blueprint (инструкция), по която ние създаваме обекти, дефинираме процес, който да ги създава по определен начин
разлика м/у класовете и структурите в размера и приложението
в класа всичко по начало е private, а в структурата public
енкапсулация - затваряне на данни, които не искаме на експоузваме, даваме им определен изход и вход
разликата между метод и функция - method е в класа
променлива - член, променлива, поле на даден клас
генерираният конструктор слага default стойности (NULL,0)
scope - област на видимост
референция не може да бъде NULL
*/

#include <iostream>
using namespace std;

const size_t DEFAULT_VECTOR_CAP = 5;

class Vector
{
    int *data;
    size_t size;
    size_t capacity;

    void _resize()
    {
        this->capacity *= 2;
        int *newData = new int[this->capacity];

        for (size_t i = 0; i < this->size; i++)
        {
            newData[i] = this->data[i];
        }
        delete[] this->data;
        this->data = newData;
    }

public:
    Vector()
    {
        this->capacity = DEFAULT_VECTOR_CAP;
        this->data = new int[this->capacity];
        this->size = 0;
    }

    Vector(size_t capacity)
    {
        this->capacity = capacity;
        this->data = new int[this->capacity];
        this->size = 0;
    }

    Vector(int *data, size_t size, size_t capacity)
    {
        this->capacity = capacity;
        this->size = size;
        // this->data = data;  не може
        this->data = new int[this->capacity];
        for (size_t i = 0; i < size; i++)
        {
            this->data[i] = data[i];
        }
    }

    ~Vector()
    {
        delete[] this->data;
    }

    int at(int index)
    {
        return this->data[index];
    }

    Vector &push_back(int value)
    {
        if (this->size == this->capacity)
        {
            this->_resize();
        }
        this->data[this->size++] = value;
        return *this;
    }
};

int main()
{
    int *data = new int[5];
    for (int i = 0; i < 5; i++)
        data[i] = i;
    Vector v1(data, 5, 5);
    delete[] data;
    cout << v1.at(4) << endl;

    Vector v2;
    v2.push_back(1).push_back(2).push_back(3);
    cout << v2.at(2) << endl;

    return 0;
}
