#include <iostream>
#include "MyVector.h"

// example function
double addOne(double& a) {
    return ++a;
}

//example function 2
bool hasHalf(double& a) {
    return (a - 0.5) == (int) a;
}

int main() {
    MyVector<double> arr;

    arr.addElement(5.5);
    arr.addElement(5.7);
    arr.addElement(4.2);
    arr.addElement(9.3);

    arr.apply(addOne);
    arr.apply(hasHalf);
    return 0;
}
