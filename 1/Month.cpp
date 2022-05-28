#include <iostream>
#include <vector>
#include "Month.h"

using namespace std;

Month::Month()
{
    this->month = 1;
}

Month::Month(char first, char second, char third)
{
    string res = "";
    res += first;
    res += second;
    res += third;

    this->month = this->getNumber(res);
}

Month::Month(int monthInt)
{
    this->month = monthInt;

    if (monthInt < 1 || monthInt > 12)
        this->month = 1;
}

Month::~Month()
{
}

void Month::inputInt()
{
    int x;
    cin >> x;

    this->month = x;

    if (x < 1 || x > 12)
        this->month = 1;
}

void Month::inputStr()
{
    char f, s, t;
    cin >> f >> s >> t;
    string res = "";
    res += f;
    res += s;
    res += t;

    this->month = this->getNumber(res);
}

void Month::outputInt()
{
    cout << this->month;
}

void Month::outputStr()
{
    cout << this->getAbbr(this->month);
}

Month Month::nextMonth()
{
    int next = this->month + 1;
    if (next > 12)
        next = 1;

    return Month(next);
}

string Month::getAbbr(int n)
{
    vector<string> abbrs;
    abbrs.push_back("");
    abbrs.push_back("Jan");
    abbrs.push_back("Feb");
    abbrs.push_back("Mar");
    abbrs.push_back("Apr");
    abbrs.push_back("May");
    abbrs.push_back("Jun");
    abbrs.push_back("Jul");
    abbrs.push_back("Aug");
    abbrs.push_back("Sep");
    abbrs.push_back("Oct");
    abbrs.push_back("Nov");
    abbrs.push_back("Dec");

    if (n < 1 || n > 12)
        return abbrs[1];

    return abbrs[n];
}

int Month::getNumber(string s)
{
    vector<string> abbrs;
    abbrs.push_back("Jan");
    abbrs.push_back("Feb");
    abbrs.push_back("Mar");
    abbrs.push_back("Apr");
    abbrs.push_back("May");
    abbrs.push_back("Jun");
    abbrs.push_back("Jul");
    abbrs.push_back("Aug");
    abbrs.push_back("Sep");
    abbrs.push_back("Oct");
    abbrs.push_back("Nov");
    abbrs.push_back("Dec");

    for (int i = 0; i < abbrs.size(); i++)
        if (s == abbrs[i])
            return i + 1;

    return 1;
}
