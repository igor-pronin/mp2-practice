#pragma once
#include "TArrayStack.h"
#include "TListStack.h"
#include <string>
using namespace std;
class Calculating
{
private:
	TStack<char>* operators;
	TStack<char>* operands;
	TStack<double>* finalvolue;
	string s;
private:
	 bool priority(char, char);
	 double calculator(double, double, char);
public:
	string create_postfix();
	void get_operands(const string, double *&, char *&, int &);
	double calculate(const string, double *, char *, int);
public:
	Calculating(int, string);
};
