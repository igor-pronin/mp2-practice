#include <iostream>
#include "Calculating.h"
//void Calculating::input_string()
//{
//	cout << "Enter string" << endl;
//	cin >> s;
//}
//bool Calculating::priority(char a, char b)
//{
//	if (((a == '+' || a == '-') && (b == '*' || b == '/' || b == '+' || b == '-')) || ((a == '*' || a == '/') && (b == '*' || b == '/')))
//	return false;
//	 return true;
//}
//int Calculating::calculate(int a, int b, char c)
//{
//	if (c == '+')
//		return a + b;
//	if (c == '-')
//		return a - b;
//	if (c == '*')
//		return a * b;
//	if (c == '/')
//		return a / b;
//}
//void Calculating::create_postfix_form()
//{
//	TStack<char> operators;
//	TStack<char> operands;
//	for (int i = 0; i < s.length(); i++)
//	{
//		if ((s[i] == '+') || (s[i] == '-') || (s[i] == '*') || (s[i] == '/') || (s[i] == ')') || (s[i] == '('))
//		{
//			if (operators.IsEmpty()) operators.Push(s[i]);
//			else
//			{
//				if (s[i] == '(') operators.Push(s[i]);
//				else
//				{
//					if (s[i] == ')')
//					{
//						while (operators.Top() != '(')
//						{
//							operands.Push(operators.Top());
//							operators.Pop();
//						}
//						operators.Pop();
//					}
//					else
//					{
//						if (priority(s[i], operators.Top()) == true) {
//							operators.Push(s[i]);
//						}
//						else
//						{
//							while ((operators.top != 0) && (operators.Top() != '(') && (priority(s[i], operators.Top()) != true))
//							{
//
//								operands.Push(operators.Top());
//								operators.Pop();
//							}
//							if (priority(s[i], operators.Top()) != true)
//							{
//								operands.Push(operators.Top());
//								operators.Pop();
//							}
//							operators.Push(s[i]);
//						}
//					}
//				}
//			}
//		}
//		else
//		operands.Push(s[i]);
//	}
//	while (operators.top != -1)
//	{
//		operands.Push(operators.Top());
//		operators.Pop();
//	}
//	PostfixForm = operands;
//}
//void Calculating::output_postfix_form()
//{
//	for (int i = 0; i < PostfixForm.top + 1; i++)
//		cout << PostfixForm.elements[i];
//}
//void Calculating::postfix_form_volue()
//{
//	int a, b, j = 0, flag = 0;
//	int exchange[10];
//	for (int i = 0; i < 10; i++)
//		exchange[i] = 0;
//	TStack<int> finalvolue;
//	for (int i = 0; i < PostfixForm.top + 1; i++)
//	{
//		if ((PostfixForm.elements[i] == '+') || (PostfixForm.elements[i] == '-') || (PostfixForm.elements[i] == '*') || (PostfixForm.elements[i] == '/'))
//			exchange[i] = 0;
//		else
//		{
//			for (int k = 0; k < i; k++)
//				if (PostfixForm.elements[i] == PostfixForm.elements[k])
//				{
//					exchange[i] = exchange[k];
//					flag = 1;
//				}
//			if (flag == 0)
//			{
//				cout << endl;
//				cout << "Enter the meaning of " << PostfixForm.elements[i] << endl;
//				cin >> a;
//				exchange[i] = a;
//			}
//		}
//	}
//	for (int i = 0; i < PostfixForm.top + 1; i++)
//	{
//		if ((PostfixForm.elements[i] == '+') || (PostfixForm.elements[i] == '-') || (PostfixForm.elements[i] == '*') || (PostfixForm.elements[i] == '/'))
//		{
//			b = calculate(finalvolue.elements[i - 2 - j], finalvolue.elements[i - 1 - j], PostfixForm.elements[i]);
//			finalvolue.Pop();
//			finalvolue.Pop();
//			finalvolue.Push(b);
//			j = j + 2;
//		}
//		else
//			finalvolue.Push(exchange[i]);
//	}
//	cout << "postfixform volue:" << endl;
//	cout << finalvolue.elements[0];
//}
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
void Calculating::get_operands(const string & postfixform, double *&exchange)
{
	double a, flag = 0;
		for (int i = 0; i < postfixform.length(); i++)
		{
			if ((postfixform[i] == '+') || (postfixform[i] == '-') || (postfixform[i] == '*') || (postfixform[i] == '/'))
				exchange[i] = 0;
			else
			{
				for (int k = 0; k < i; k++)
					if (postfixform[i] == postfixform[k])
					{
						exchange[i] = exchange[k];
						flag = 1;
					}
				if (flag == 0)
				{
					//cout << endl;
					cout << "Enter the meaning of " << postfixform[i] << endl;
					cin >> a;
					exchange[i] = a;
				}
			}
			flag = 0;
		}
}
double Calculating::calculate(const string & postfixform, const double * exchange)
{
	double b;
	int j = 0;
	TStack<double> finalvolue;
	for (int i = 0; i < postfixform.length(); i++)
	{
		if ((postfixform[i] == '+') || (postfixform[i] == '-') || (postfixform[i] == '*') || (postfixform[i] == '/'))
		{
			b = calculator(finalvolue.elements[i - 2 - j], finalvolue.elements[i - 1 - j], postfixform[i]);
			finalvolue.Pop();
			finalvolue.Pop();
			finalvolue.Push(b);
			j = j + 2;
		}
		else
		{
			finalvolue.Push(exchange[i]);
		}
	}
	return finalvolue.elements[0];
}