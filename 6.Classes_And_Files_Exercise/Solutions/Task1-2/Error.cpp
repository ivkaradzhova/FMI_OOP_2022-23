#include "Error.h"

Error::Error(int code, String message) : code(code), message(message)
{ }

String Error::get_message() const
{
	return this->message;
}

int Error::get_code() const
{
	return this->code;
}
