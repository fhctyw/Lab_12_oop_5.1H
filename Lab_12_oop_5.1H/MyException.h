#pragma once

class MyException
{
	const char* const msg;
public:
	MyException(const char* const msg) : msg(msg) {};
	const char* const What() const { return msg; }
};

