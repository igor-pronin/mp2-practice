#include <iostream>
#include "Calculating.h"
bool Calculating::priority(char a, char b)
{
	if (((a == '+' || a == '-') && (b == '*' || b == '/' || b == '+' || b == '-')) || ((a == '*' || a == '/') && (b == '*' || b == '/')))
	return false;
	 return true;
}
double Calculating::calculator(double a, double b, char c)
{
	if (c == '+')
		return a + b;
	if (c == '-')
		return a - b;
	if (c == '*')
		return a * b;
	if (c == '/')
		return a / b;
}
string Calculating::create_postfix(const string s)
{
	TStack<char> operators;
	TStack<char> operands;
	for (int i = 0; i < s.length(); i++)
	{
		if ((s[i] == '+') || (s[i] == '-') || (s[i] == '*') || (s[i] == '/') || (s[i] == ')') || (s[i] == '('))
		{
			if (operators.IsEmpty()) operators.Push(s[i]);
			else
			{
				if (s[i] == '(') operators.Push(s[i]);
				else
				{
					if (s[i] == ')')
					{
						while (operators.Top() != '(')
						{
							operands.Push(operators.Top());
							operators.Pop();
						}
						operators.Pop();
					}
					else
					{
						if (priority(s[i], operators.Top()) == true) {
							operators.Push(s[i]);
						}
						else
						{
							while ((operators.top != 0) && (operators.Top() != '(') && (priority(s[i], operators.Top()) != true))
							{

								operands.Push(operators.Top());
								operators.Pop();
							}
							if (priority(s[i], operators.Top()) != true)
							{
								operands.Push(operators.Top());
								operators.Pop();
							}
							operators.Push(s[i]);
						}
					}
				}
			}
		}
		else
			operands.Push(s[i]);
	}
	while (operators.top != -1)
	{
		operands.Push(operators.Top());
		operators.Pop();
	}
	string postfixform(operands.elements);
	return postfixform;
}
void Calculating::get_operands(const string postfixform, double *&exchange, char *&operands, int & size)
{
	int j = 0;
	double a, flag = 0;
		for (int i = 0; i < postfixform.length(); i++)
		{
			if ((postfixform[i] != '+') && (postfixform[i] != '-') && (postfixform[i] != '*') && (postfixform[i] != '/'))
			{
				for (int k = 0; k < i; k++)
					if (postfixform[i] == postfixform[k])
					{
						flag = 1;
					}
				if (flag == 0)
				{
					operands[j] = postfixform[i];
					cout << "Enter the meaning of " << postfixform[i] << endl;
					cin >> a;
					exchange[j] = a;
					j++;
					size++;
				}
				flag = 0;
			}
		}
}
double Calculating::calculate(const string postfixform, const double *exchange, const char *operands, int size)
{
	double b;
	TStack<double> finalvolue;
	for (int i = 0; i < postfixform.length(); i++)
	{
		if ((postfixform[i] == '+') || (postfixform[i] == '-') || (postfixform[i] == '*') || (postfixform[i] == '/'))
		{
			b = calculator(finalvolue.elements[finalvolue.top - 1], finalvolue.elements[finalvolue.top], postfixform[i]);
			finalvolue.Pop();
			finalvolue.Pop();
			finalvolue.Push(b);
		}
		else
		{
			for (int k = 0; k < size; k++)
				if (postfixform[i] == operands[k])
				{
					finalvolue.Push(exchange[k]);
					break;
				}
		}
	}
	return finalvolue.elements[0];
}