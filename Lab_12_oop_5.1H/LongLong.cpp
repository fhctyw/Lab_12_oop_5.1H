// LongLong.cpp
#include "LongLong.h"
#include <iostream>
#include <sstream>
using namespace std;

string showbits(const void* ptr, int bytes) {
	stringstream ss;
	unsigned char* arr = (unsigned char*)ptr;

	for (int i = bytes-1; i >= 0; i--)
	{
		for (int j = 7; j >= 0; j--)
			arr[i] & (1 << j) ? ss << "1" : ss << "0";
		ss << " ";
	}
	return ss.str();
}

ostream& operator<<(ostream& out, const LongLong& c)
{
	out << string(c) << endl;
	return out;
}

istream& operator>>(istream& in, LongLong& c)
{
	cout << "¬вед≥ть молодшу частину: "; cin >> c.low;
	cout << "¬вед≥ть старшу частину: "; cin >> c.high;
	return in;
}

LongLong::LongLong(unsigned long low, long high)
{
	setLow(low);
	setHigh(high);
}

LongLong::LongLong(const LongLong& ll)
{
	*this = ll;
}

LongLong& LongLong::operator=(const LongLong& ll)
{
	high = ll.high;
	low = ll.low;
	return *this;
}


LongLong::operator string() const
{
	stringstream ss;
	ss << "high: " << high << " low: " << low << endl
		<< "high: " << showbits(&high, sizeof(high)) << " low: " << showbits(&low, sizeof(low));

	return ss.str();
}

LongLong LongLong::operator++(int)
{
	LongLong l(*this);
	low = low + 1;
	return l;
}

LongLong LongLong::operator--(int)
{
	LongLong l(*this);
	low = low - 1;
	return l;
}

LongLong& LongLong::operator++()
{
	low = low + 1;
	return *this;
}

LongLong& LongLong::operator--()
{
	low = low - 1;
	return *this;
}

LongLong& LongLong::operator+()
{
	return *this;
}

LongLong& LongLong::operator-()
{
	return ++(~*this);
}

LongLong operator+(const LongLong& l1, const LongLong& l2)
{
	LongLong x = l1, y = l2;

	while (y != 0)
	{
		LongLong carry = x & y;
		x = x ^ y;
		y = carry << 1;
	}
	return x;
}


LongLong operator-(const LongLong& l1, const LongLong& l2)
{
	LongLong x = l1, y = l2;
	return x + -y;
}

LongLong operator*(const LongLong& l1, const LongLong& l2)
{
	LongLong x = l1, y = l2;
	LongLong c;
	int i = 0;
	while (i < y)
	{
		c = c + x;
		i++;
	}
	return c;
}

LongLong operator/(const LongLong& l1, const LongLong& l2)
{
	LongLong _l1 = l1, _l2 = l2;
	LongLong res;
	while (_l1 > _l2 || _l1 == _l2)
	{
		_l1 = _l1 - _l2;
		res++;
	}
	return res;
}

LongLong operator<<(const LongLong& l, int c)
{
	LongLong _l = l;
	for (size_t i = 0; i < c; i++)
	{
		bool b = bool((1 << 31) & _l.low);
		_l.low <<= 1;
		_l.high <<= 1;
		if (b) _l.high |= (1 << 0);
	}
	return _l;
}

LongLong& LongLong::operator~()
{
	high = ~high;
	low = ~low;
	return *this;
}

LongLong operator^(const LongLong& l1, const LongLong& l2)
{
	return LongLong(l1.low ^ l2.low, l1.high ^ l2.high);
}

LongLong operator&(const LongLong& l1, const LongLong& l2)
{
	return LongLong(l1.low & l2.low, l1.high & l2.high);
}


bool operator<(const LongLong& l1, const LongLong& l2)
{
	return l1.high < l2.high || l1.high == l2.high && l1.low < l2.low;
}

bool operator>(const LongLong& l1, const LongLong& l2)
{
	return l1.high > l2.high || l1.high == l2.high && l1.low > l2.low;
}

bool operator==(const LongLong& l1, const LongLong& l2)
{
	return l1.low == l2.low && l1.high == l2.high;
}

bool operator!=(const LongLong& l1, const LongLong& l2)
{
	return !(l1 == l2);
}
