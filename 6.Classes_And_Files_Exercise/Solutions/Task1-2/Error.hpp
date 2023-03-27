#ifndef  ERROR_H
#define  ERROR_H
#include "String.hpp"

class Error
{
private:
	int code;
	String message;

public:
	Error(int code, String message);
	String get_message() const;
	int get_code() const;
};

#endif // ! ERROR_H
