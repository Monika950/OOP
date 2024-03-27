/*масив - структура от данни, които са подредени в паметта
  индекс - коефициент на отстояване с големината на типа от данни от началната позиция
  при увеличаване на капацитета се заделя нова памет и масивът се копира в нея, а старата се освобождава
  kebap case - pop-back
  camel case - popBack
  pascal case - PopBack
  snake case - pop_back
  .cc или .cpp
  <iostream> */

#include <iostream>
using namespace std;

typedef struct vector_t
{
    int *data;
    size_t size;
    size_t capacity;
};

vector_t *init();

void destroy(vector_t *v);

void push_back(vector_t *v, int value);

void resize(vector_t *v, size_t cap);

int pop_back(vector_t *v);

int at(vector_t *v, int index);

int main()
{
    vector_t *v = init();
    push_back(v, 0);
    push_back(v, 1);
    push_back(v, 2);
    push_back(v, 3);

    cout << pop_back(v) << endl;
    cout << at(v, 1) << endl;

    return 0;
}

vector_t *init()
{
    vector_t *vector = new vector_t();
    vector->capacity = 2;
    vector->size = 0;
    vector->data = new int[vector->capacity];

    return vector;
}

void destroy(vector_t *v)
{
    delete[] v->data;
    delete v;
}

void push_back(vector_t *v, int value)
{
    if (v->size == v->capacity)
        resize(v, v->capacity * 2);
    v->data[v->size++] = value;
}

void resize(vector_t *v, size_t cap)
{
    v->capacity = cap;

    int *newArr = new int[v->capacity];

    for (unsigned int i = 0; i < v->size; i++)
    {
        newArr[i] = v->data[i]; // *(v->data+i)
    }

    delete[] v->data;
    v->data = newArr;
}

int pop_back(vector_t *v)
{
    if (v->size == 0)
    {
        return NULL;
    }

    v->size--;
    int value = v->data[v->size];

    if (v->size <= v->capacity / 2)
        resize(v, v->capacity / 2);

    return value;
}

int at(vector_t *v, int index)
{
    if (index >= v->size)
    {
        return NULL;
    }
    if (index < 0)
    {
        if (-1 * index > v->size)
        {
            return NULL;
        }
        return v->data[v->size + index];
    }
    return v->data[index];
}