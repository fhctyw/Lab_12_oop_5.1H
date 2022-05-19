// PrivateCursor.h
#pragma once
#include "LongLong.h"
#include <iostream>
using namespace std;

class PrivateCursor : LongLong
{
	char size;
	bool view;
public:
	PrivateCursor(LongLong pos = LongLong(0, 0), char size = 1, bool  view = false);
	PrivateCursor(const PrivateCursor& c);
	PrivateCursor& operator=(const PrivateCursor& c);

	operator string() const;
	friend ostream& operator<<(ostream& out, const PrivateCursor& c);
	friend istream& operator>>(istream& in, PrivateCursor& c);

	bool setPosition(LongLong ll);
	LongLong getPosition() const { return *this; }
	char getSize() { return size; }
	bool setSize(char s);
	bool getView() { return view; }
	bool setView(bool v) { view = v; return true; }

	void move(long x, long y);
	void changeView();
	void SizeUp();
	void SizeDown();

	void Show();
	void Hide();
};

