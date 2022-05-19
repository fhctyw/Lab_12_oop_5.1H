#pragma once
#include <exception>
using namespace std;

class CursorException : public exception
{
public:
	CursorException(const char* const msg) : exception(msg) {};
};

