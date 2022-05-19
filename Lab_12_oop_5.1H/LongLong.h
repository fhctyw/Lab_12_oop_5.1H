// LongLong.h
#pragma once
#include <string>
using namespace std;

string showbits(const void* ptr, int bytes);

class LongLong
{
	unsigned long low;
	long high;
public:
	LongLong(unsigned long low = 0, long high = 0);
	LongLong(const LongLong& ll);
	LongLong& operator=(const LongLong& ll);

	operator string() const;
	friend ostream& operator<<(ostream& out, const LongLong& c);
	friend istream& operator>>(istream& in, LongLong& c);
	
	long getHigh() const { return high; }
	void setHigh(long _high) { high = _high; }
	unsigned long getLow() const { return low; }
	void setLow(unsigned long _low) { low = _low; }
	
	LongLong operator++(int);
	LongLong operator--(int);
	LongLong& operator++();
	LongLong& operator--();

	LongLong& operator+();
	LongLong& operator-();
	friend LongLong operator+(const LongLong& l1, const LongLong& l2);
	friend LongLong operator-(const LongLong& l1, const LongLong& l2);
	friend LongLong operator*(const LongLong& l1, const LongLong& l2);
	friend LongLong operator/(const LongLong& l1, const LongLong& l2);

	friend LongLong operator<<(const LongLong &l1, int c);
	friend LongLong operator^(const LongLong& l1, const LongLong& l2);
	friend LongLong operator&(const LongLong& l1, const LongLong& l2);
	LongLong& operator~();

	bool friend operator<(const LongLong& l1, const LongLong& l2);
	bool friend operator>(const LongLong& l1, const LongLong& l2);
	bool friend operator==(const LongLong& l1, const LongLong& l2);
	bool friend operator!=(const LongLong& l1, const LongLong& l2);
};

