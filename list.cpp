#include "list.h"
#include <iostream>
using namespace std;

template <class T>
List<T>::List()
{
    size = 10;
    length = 0;
    array = new T[size];
}

template <class T>
List<T>::List(int size)
{
    this->size = size;
    length = 0;
    array = new T[size];
}


template <class T>
List<T>::~List()
{
    delete[] array;
}

template <class T>
void List<T>::IncreaseSize()
{
    T *newArray = new T[size * 2];
    for (int i = 0; i < length; i++)
    {
        newArray[i] = array[i];
    }
    T *temp = array;
    array = newArray;

    size *= 2;

    delete[] temp;
}

template <class T>
void List<T>::SwapValues(int firstIndex, int secondIndex)
{
    T temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

template <class T>
void List<T>::Display()
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

template <class T>
T List<T>::Get(int index) {
    return index < length ? array[index] : 0;
}

template <class T>
void List<T>::Insert(int index, T value)
{
    if (index < 0 || index > length) return;
    if (length == size)
    {
        IncreaseSize();
    }

    for (int i = length + 1; i >= index; i--)
    {
        if (i == index)
            array[i] = value;
        else
            SwapValues(i - 1, i);
    }

    length++;
}

template <class T>
T List<T>::Delete(int index)
{
    if (index < 0 || index >= length) return 0;
    T deletedElement = array[index];
    for (int i = index; i < length - 1; i++)
    {
        array[i] = array[i + 1];
    }
    length--;
    return deletedElement;
}

template <class T>
List<T> List<T>::Union(List<T> *listA)
{
    int i = 0, j = 0, k = 0;
    List<T> listB = List<T>(listA->length + this->length);

    while (i < this->length && j < listA->length)
    {
        if (this->array[i] < listA->array[j])
        {
            listB.array[k++] = this->array[i++];
        }
        else if (this->array[i] > listA->array[j])
        {
            listB.array[k++] = listA->array[j++];
        }
        else
        {
            listB.array[k++] = this->array[i++];
            j++;
        }
    }

    while (i < this->length)
    {
        listB.array[k++] = this->array[i++];
    }
    while (j < listA->length)
    {
        listB.array[k++] = listA->array[j++];
    }

    listB.length = k;
    return listB;
}

template <class T>
List<T> List<T>::Intersection(List<T> *listA)
{
    int i = 0, j = 0, k = 0;
    List<T> listB = List<T>(listA->length + this->length);

    while (i < this->length && j < listA->length)
    {
        if (this->array[i] < listA->array[j])
        {
            i++;
        }
        else if (this->array[i] > listA->array[j])
        {
            j++;
        }
        else
        {
            listB.array[k++] = this->array[i++];
            j++;
        }
    }

    listB.length = k;
    return listB;
}

template <class T>
List<T> List<T>::Difference(List<T> *listA)
{
    int i = 0, j = 0, k = 0;
    List<T> listB = List<T>(listA->length + this->length);

    while (i < this->length && j < listA->length)
    {
        if (this->array[i] < listA->array[j])
        {
            listB.array[k++] = this->array[i++];
        }
        else if (this->array[i] > listA->array[j])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }

    while (i < this->length)
    {
        listB.array[k++] = this->array[i++];
    }

    listB.length = k;
    return listB;
}

template class List<int>;