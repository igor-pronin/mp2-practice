#include "Stack.h"
#include "Calculating.h"
#include <iostream>
int main()
{
	string s;
	string postfixform;
	double postfixformvolue = 0;
	int size = 0;
	cout << "Enter string" << endl;
	cin >> s;
	try
	{
		postfixform = Calculating::create_postfix(s);
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	cout << "postfix_form:" << endl;
	cout << postfixform << endl;
	//double *exchange = new double[postfixform.length()];
	//char * operands = new char[postfixform.length()];
	double *exchange;
	char *operands;
	try
	{
		Calculating::get_operands(postfixform, exchange, operands, size);
	}
	catch (const char* str)
	{
		cout << str << endl;

	}
	try
	{
		postfixformvolue = Calculating::calculate(postfixform, exchange, operands, size);
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	cout << "postfixform volue:" << endl;
	cout << postfixformvolue;
	system("pause");
}