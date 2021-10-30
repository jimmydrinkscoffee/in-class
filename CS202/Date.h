#ifndef DATE
#define DATE

#include <iostream>
#include <ctime>
using namespace std;

const int normalYear[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
const int leapYear[13] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};

class Date
{
private:
    int day, month, year;

public:
    Date();
    Date(int y, int m = 1, int d = 1);
    Date(long offsetFromOrigin);
    Date(const Date &d);

    friend istream &operator>>(istream &in, Date &d);
    friend ostream &operator<<(ostream &out, const Date &d);

    Date tomorrow();
    Date yesterday();

    Date operator+(int i) const;
    Date operator-(int i) const;

    void operator+=(int i);
    void operator-=(int i);

    Date &operator++();
    Date operator++(int);
    Date &operator--();
    Date operator--(int);

    bool operator==(const Date &d) const;
    bool operator!=(const Date &d) const;
    bool operator>(const Date &d) const;
    bool operator<(const Date &d) const;
    bool operator>=(const Date &d) const;
    bool operator<=(const Date &d) const;

    explicit operator int() const;
    explicit operator long() const;

    bool isLeapYear() const;
};

#pragma region Define Methods
#pragma region Constructors
Date::Date()
{
    time_t cppTime = time(0);
    tm *currentTime = localtime(&cppTime);

    year = currentTime->tm_year + 1900;
    month = currentTime->tm_mon + 1;
    day = currentTime->tm_mday;
}

Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

Date::Date(long offsetFromOrigin)
{
    year = (offsetFromOrigin + 365) * 400 / 146097;
    int dayInYear = offsetFromOrigin - long(Date(year, 1, 1));

    if (isLeapYear())
    {
        for (int i = 0; i < 12; ++i)
            if (dayInYear > leapYear[i] && dayInYear < leapYear[i + 1])
            {
                month = i + 1;
                break;
            }
    }
    else
        for (int i = 0; i < 12; ++i)
            if (dayInYear > normalYear[i] && dayInYear < normalYear[i + 1])
            {
                month = i + 1;
                break;
            }

    day = dayInYear + 1 - (isLeapYear() ? leapYear[month - 1] : normalYear[month - 1]);
}

Date::Date(const Date &d)
{
    year = d.year;
    month = d.month;
    day = d.day;
}
#pragma endregion Constructors

#pragma region IO Operators
istream &operator>>(istream &in, Date &d)
{
    in >> d.year >> d.month >> d.day;
    return in;
}

ostream &operator<<(ostream &out, const Date &d)
{
    cout << d.year << "/" << d.month << "/" << d.day;
    return out;
}
#pragma endregion IO Operators

#pragma region Calculate Operators
Date Date::operator+(int i) const
{
    return Date(long(long(*this) + i));
}

Date Date::operator-(int i) const
{
    return Date(long(long(*this) - i));
}

void Date::operator+=(int i)
{
    *this = *this + i;
}

void Date::operator-=(int i)
{
    *this = *this - i;
}

Date &Date::operator++()
{
    *this += 1;
    return *this;
}

Date Date::operator++(int)
{
    Date temp(*this);
    ++*this;
    return temp;
}

Date &Date::operator--()
{
    *this -= 1;
    return *this;
}

Date Date::operator--(int)
{
    Date temp(*this);
    --*this;
    return temp;
}
#pragma endregion Calculate Operators

#pragma region Compare Operators
bool Date::operator==(const Date &d) const
{
    return day == d.day && month == d.month && year == d.year;
}

bool Date::operator!=(const Date &d) const
{
    return !(*this == d);
}

bool Date::operator>(const Date &d) const
{
    return year > d.year || month > d.month || day > d.day;
}

bool Date::operator<(const Date &d) const
{
    return !(*this > d) && (*this != d);
}

bool Date::operator>=(const Date &d) const
{
    return !(*this < d);
}

bool Date::operator<=(const Date &d) const
{
    return !(*this > d);
}
#pragma endregion Compare Operators

#pragma region Convert Operators
Date::operator int() const
{
    return day - 1 + (isLeapYear() ? leapYear[month - 1] : normalYear[month - 1]);
}

Date::operator long() const
{
    int leapYearCount = year / 4 - year / 100 + year / 400;
    return int(*this) + (year - 1) * 365 + leapYearCount;
}
#pragma endregion Convert Operators

Date Date::tomorrow()
{
    return *this + 1;
}

Date Date::yesterday()
{
    return *this - 1;
}

bool Date::isLeapYear() const
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
#pragma endregion Define Methods
#endif