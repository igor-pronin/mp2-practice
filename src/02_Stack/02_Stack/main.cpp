#include "Stack.h"
#include "Calculating.h"
#include <iostream>
int main()
{
	///*try
	//{
	//	Calculating form;
	//	form.input_string();
	//	form.create_postfix_form();
	//	form.output_postfix_form();	
	//	form.postfix_form_volue();
	//}
	//catch (const char* str)
	//{
	//	cout << str << endl;
	//}
	//system("pause");*/
	string s;
	string postfixform;
	double *exchange = new double[10];
	for (int i = 0; i < 10; i++)
		exchange[i] = 0;
	double postfixformvolue = 0;
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
	try
	{
		Calculating::get_operands(postfixform, exchange); //можно ли передать как аргумента функции ссылку на массив exchange?
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	try
	{
		postfixformvolue = Calculating::calculate(postfixform, exchange);
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	cout << "postfixform volue:" << endl;
	cout << postfixformvolue;
	system("pause");
}