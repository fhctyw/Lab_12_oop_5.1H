// PrivateCursor.cpp
#include "PrivateCursor.h"
#include <sstream>
#include <iostream>

using namespace std;

PrivateCursor::PrivateCursor(LongLong pos, char s, bool v)
{
    if (!(setPosition(pos) && setSize(s) && setView(v)))
        *this = PrivateCursor();
}

PrivateCursor::PrivateCursor(const PrivateCursor& c)
{
    *this = c;
}

PrivateCursor& PrivateCursor::operator=(const PrivateCursor& c)
{
    size = c.size;
    view = c.view;
    *this = LongLong::operator=(c);
    return *this;
}

istream& operator>>(istream& in, PrivateCursor& c)
{
    long x, y;
    int s;
    bool v;
    do
    {
        cout << "¬вед≥ть позиц≥ю x: "; in >> x;
        cout << "¬вед≥ть позиц≥ю y: "; in >> y;
        cout << "¬вед≥ть розм≥р: "; in >> s;
        cout << "¬ед≥ть вид курсору(1 - horizontal, 0 - vertical): "; in >> v;
    } while (!(c.setPosition(LongLong(x, y)) && c.setSize(s) && c.setView(v)));
    return in;
}

PrivateCursor::operator string() const
{
    stringstream ss;
    ss << '(' << getHigh() << ", " << getLow() << ") size: " << (int)size << (view ? " horizontal" : " vertical");
    return ss.str();
}

ostream& operator<<(ostream& out, const PrivateCursor& c)
{
    out << string(c);
    return out;
}

bool PrivateCursor::setPosition(LongLong ll)
{
    if (ll.getHigh() >= 0)
    {
        LongLong::operator=(ll);
        return true;
    }
    else
        return false;
}

bool PrivateCursor::setSize(char s)
{
    if (s > 0 && s < 16)
    {
        size = s;
        return true;
    }
    else
        return false;
}

void PrivateCursor::move(long x, long y)
{
    Hide();

    LongLong ll(y, x);
    LongLong::operator=(*this + ll);

    Show();
}

void PrivateCursor::changeView()
{
    view = !view;
}

void PrivateCursor::SizeUp()
{
    setSize(size + 1);
}

void PrivateCursor::SizeDown()
{
    setSize(size - 1);
}

void PrivateCursor::Show()
{
    cout << "PrivateCursor shows" << endl;
}

void PrivateCursor::Hide()
{
    cout << "PrivateCursor hides" << endl;
}
