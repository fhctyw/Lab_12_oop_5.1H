#include <iostream>
#include "PubicCursor.h"
#include "PrivateCursor.h"
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try
	{
		PubicCursor cur({0, 0}, -3);
	}
	catch (MyException* e)
	{
		cout << "MyException* " << e->What() << endl;
	}

	try
	{
		PubicCursor cur;
		cin >> cur;
	}
	catch (CursorException& e)
	{
		cout << "CursorException& " << e.what() << endl;
	}

	try
	{
		PubicCursor cur({0, 0}, 15, 0);
		cur.SizeUp();
	}
	catch (exception e)
	{
		cout << "exception " << e.what() << endl;
	}

	return 0;
}