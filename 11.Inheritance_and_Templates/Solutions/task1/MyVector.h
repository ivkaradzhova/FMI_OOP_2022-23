//
// Created by Iva Karadzhova on 8.05.23.
//

#ifndef _MYVECTOR_H
#define _MYVECTOR_H
#include <iostream>
const int INITIAL_CAPACITY = 2;

template <typename T>
class MyVector {
    T* arr;
    int size;
    int capacity;
    void resize();

public:
    MyVector();
    MyVector(const MyVector<T>& other);
    ~MyVector();

    void addElement(T element);

    template <typename R>
    void apply(R (*func)(T&));

    T operator[](unsigned int index);
};

template <typename T>
MyVector<T>::MyVector() {
    this->capacity = INITIAL_CAPACITY;
    this->size = 0;
    this->arr = new T[this->capacity];
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T> &other) {
    this->size = other.size;
    this->capacity = other.capacity;

    this->arr = new T [other.capacity];
    for(int i = 0; i < this->size; i++) {
        this->arr[i] = other.arr[i];
    }
}

template <typename T>
MyVector<T>::~MyVector() {
    delete [] this->arr;
}

template <typename T>
void MyVector<T>::resize() {
    this->capacity *= 2;
    T* copyArr = new T [this->capacity];
    for(int i = 0; i < this->size; i++) {
        copyArr[i] = this->arr[i];
    }

    delete[] this->arr;
    this->arr = copyArr;
}

template <typename T>
void MyVector<T>::addElement(T element) {
    if (size >= capacity) {
        resize();
    }

    this->arr[this->size++] = element;
}

template <typename T>
template <typename R>
void MyVector<T>::apply(R (*func)(T&)) {
    for (int i = 0; i < this->size; i++) {
        std::cout << func(this->arr[i]) << std::endl;
    }
}

template <typename T>
T MyVector<T>::operator[](int index) {
    if (index > this->size) {
        throw std::runtime_error("Index out of bounds");
    }

    return this->arr[index];
}

#endif
