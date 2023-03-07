#include "Set.hpp"

int const DEFAULT_CAPACITY = 10;

Set::Set() {
    this->numElements = 0;
    this->capacity = DEFAULT_CAPACITY;

    this->elements = new int[this->capacity];
}

Set::Set(Set const& other) {
    this->numElements = other.numElements;
    this->capacity = other.capacity;

    this->elements = new int[this->capacity];

    for(int i = 0; i < this->numElements; i++) {
        this->elements[i] = other.elements[i];
    }
}


Set& Set::operator= (Set const& other) {
    if(this != &other) {
        this->numElements = other.numElements;
        this->capacity = other.capacity;

        if (!this->elements) {
            delete[] this->elements;
        }
        this->elements = new int[this->capacity];
        for(int i = 0; i < this->numElements; i++) {
            this->elements[i] = other.elements[i];
        }
    }
}

Set::~Set();

bool Set::addElement(int const element) {
    int i = 0;
    while(i < this->numElements && this->elements[i] != element) {
        i++;
    }
    if (i == this->numElements) {
        return false;
    }

    if (this->numElements >= this->capacity) {
        this->resize();
        this->elements[this->numElements++] = element;
    }
    return true;
}
bool deleteElement(int const element);
void setUnion(Set const& other);
void setIntersection(Set const& other);
void print();

void Set::resize() {
    this->capacity *= 2;
    int* copyElements = new int[this->capacity];
    for(int i = 0; i < this->numElements; i++) {
        copyElements[i] = this->elements[i];
    }

    delete[] this->elements;
    this->elements = copyElements;
}
