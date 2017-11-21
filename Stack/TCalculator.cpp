#include "TCalculator.h"
void TCalculator::setinfix(const string& s) 
{
	infix = s;
}

string TCalculator::getinfix() const 
{
	return infix;
}

string TCalculator::getpostfix() const 
{
	return postfix;
}
int TCalculator::priority(char ch)
{
	switch (ch)
	{
		case '+': return 1; break; 
		case '-': return 1; break; 
		case '*': return 2; break; 
		case '/': return 2; break; 
		case '^': return 3; break; 
		case '(': return 0; break; 
		case ')': return 0; break; 
		default: return -1; break;
	}
}
void TCalculator::topostfix()
{
	postfix = " ";
	StC.clear();
	string temp = "(" + infix + ")";
	for ( int i = 0; i < temp.size(); i++)
	{
		if (( temp[i] >= '0')&&(temp[i]<='9')||(temp[i] == '.'))
			postfix += temp[i];
		else if (temp[i] == '(')
			StC.Push('(');
		else if ( temp[i] == ')')
		{
			while ( StC.Top() != '(')
				postfix += StC.Pop();
			StC.Pop();
		}
		else if ( temp[i] == '+' || temp[i] == '-' || temp[i] == '*' || temp[i] == '/' || temp[i] == '^')
		{
			postfix += ' ';
			if ( priority(StC.Top()) < priority(temp[i]))
				StC.Push(temp[i]);
			else
			{
				while (priority(StC.Top()) >= priority(temp[i]))
					postfix += StC.Pop();
				StC.Push(temp[i]);
			}
		}
	}
}
double TCalculator::Calc()
{
	StD.clear();
	double first, second, res; 
	for ( int i = 0; i < postfix.size(); i++)
	{
		if ( postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
		{
			second = StD.Pop();
			first = StD.Pop();
			switch ( postfix[i]) 
			{
			case '+': res = first + second; break;
			case '-': res = first - second; break; 
			case '*': res = first * second; break;
			case '/': res = first / second; break; 
			default: break;
			}
			StD.Push(res);
		}
			if (( postfix[i] >= '0')&&(postfix[i]<='9')||(postfix[i] == '.'))
			{
				char* temp;
				res = strtod( &postfix[i], &temp);
				StD.Push(res);
				int j = temp - &postfix[i];
				i += j-1;
			}
	}
	return StD.Pop();
}

