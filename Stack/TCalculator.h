#include <iostream>
#include <string>
#include "TStack.h"
#pragma once 
using namespace std;
class TCalculator
{
private:
	string infix;
	string postfix;
	TStack <char> StC;
    TStack <double> StD;
public:
	TCalculator(string _infix = " "): StC(), StD(), infix(_infix), postfix(" ") {}
	TCalculator(const TCalculator& st): StC(st.StC), StD(st.StD), infix(st.infix), postfix(st.postfix) {}
	void setinfix(const string& str);
	string getinfix() const;
	string getpostfix() const;
	int priority(char ch);
	void topostfix();
	double Calc();
};