#pragma once
#include "Stack.h"
#include <string>
using namespace std;
class Calculating 
{
	//TStack<char> PostfixForm;
	//string s;
//public:
	//void input_string();
	//void output_postfix_form();
	//void create_postfix_form();
	//int calculate(int, int, char);
	//void postfix_form_volue();
private:
	static bool priority(char, char);
	static double calculator(double, double, char);
public:
	static string create_postfix(const string);
	static void get_operands(const string &, double *&);
	static double calculate(const string &, const double *);
	//static void get_operands(string postfix, char *&operands, float *&values, int &count);
	//static float calculate(string postfix, char *operands, float *values, int count);
};