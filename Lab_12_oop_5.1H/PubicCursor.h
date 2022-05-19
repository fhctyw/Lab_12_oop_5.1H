// PubicCursor.h
#pragma once
#include "LongLong.h"
#include "MyException.h"
#include "CursorException.h"
#include <iostream>
using namespace std;

class PubicCursor : public LongLong
{
	char size;
	bool view;
public:
	PubicCursor(LongLong pos = LongLong(0,0), char size = 1, bool  view = false) throw(MyException);
	PubicCursor(const PubicCursor& c);
	PubicCursor& operator=(const PubicCursor& c);
	
	operator string() const;
	friend ostream& operator<<(ostream& out, const PubicCursor& c);
	friend istream& operator>>(istream& in, PubicCursor& c) throw(CursorException);

	bool setPosition(LongLong ll);
	char getSize() { return size; }
	bool setSize(char s);
	bool getView() { return view; }
	bool setView(bool v) { view = v; return true; }

	void move(long x, long y);
	void changeView();
	void SizeUp() throw(exception);
	void SizeDown();

	void Show();
	void Hide();
};

