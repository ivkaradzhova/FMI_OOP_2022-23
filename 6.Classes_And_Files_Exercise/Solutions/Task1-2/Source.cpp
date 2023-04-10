#include <iostream>
#include "String.h"
#include "Error.h"

int main() {
    String str;
    std::cin >> str;
    std::cout << str << std::endl;
    std::cout << str + " asd" << std::endl;
    str += "test test";
    const char* saas = str.c_str();
    std::cout << saas << std::endl;


    Error err(0, "Success");
    String err_str = err.get_message();
    err_str += " changed";
    std::cout << err_str << std::endl;
    std::cout << err.get_message() << std::endl;

    return 0;
}