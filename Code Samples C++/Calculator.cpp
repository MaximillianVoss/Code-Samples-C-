#include "stdafx.h"
#include "Calculator.h"
#include "PolandStr.h"

Calculator::Calculator(string _commands)
{
	overflow = false;
	commands = _commands;
}

Calculator::~Calculator()
{
}
/// <summary>
/// �������� �� ������������
/// </summary>
/// <param name="a">������� 1</param>
/// <param name="b">������� 2</param>
/// <param name="operation">���� ��������(1 ������)</param>
/// <returns>true - ���� ���� ������������</returns>
bool CheckOveflow(int a, int b, char operation) {
	switch (operation)
	{
	case '+':
		if (((b > 0) && (a > (INT_MAX - b))) ||
			((b < 0) && (a < (INT_MIN - b))))
			return true;
		break;
	case'-':
		if ((b > 0 && a < INT_MIN + b) ||
			(b < 0 && a > INT_MAX + b))
			return true;
		break;
	case'*':
		if (a > 0) {
			if (b > 0) {
				if (a > (INT_MAX / b))
					return true;
			}
			else {
				if (b < (INT_MIN / a))
					return true;
			}
		}
		else {
			if (b > 0) {
				if (a < (INT_MIN / b))
					return true;
			}
			else {
				if ((a != 0) && (b < (INT_MAX / a)))
					return true;
			}
		}
		break;
	case'/':
		if ((b == 0) || ((a == LONG_MIN) && (b == -1)))
			return true;
		break;
	default:
		return false;
	}
	return false;
}
/// <summary>
/// ��������� ��������� ��������
/// </summary>
/// <param name="sa">������ �������</param>
/// <param name="sb">������ �������</param>
/// <param name="op">���� ��������</param>
/// <returns>��������� �������� � ��������� ����, ���� ������ ������ 0</returns>
string Calculator::MakeOpeartion(string sa, string sb, string op) {
	double result = 0;
	double a = stod(sa.c_str());
	double b = stod(sb.c_str());
	if (op == "+")
		result = a + b;
	if (op == "-")
		result = a - b;
	if (op == "*")
		result = a * b;
	if (op == "/")
		result = a / b;
	if (op == "^")
		result = pow(a, b);
	overflow = CheckOveflow(a, b, op.c_str()[0]);
	overflow = abs(result) > pow(2, 31);
	return std::to_string(result);
}
/// <summary>
/// ��������� ��������� ��������
/// </summary>
/// <param name="sa">������ �������</param>
/// <param name="sb">������ �������</param>
/// <param name="op">���� ��������</param>
/// <returns>��������� �������� � ��������� ����, ���� ������ ������ 0</returns>
string Calculator::MakeOpeartionInt(string sa, string sb, string op) {
	double result = 0;
	double a = stod(sa.c_str());
	double b = stod(sb.c_str());
	if (op == "+")
		result = a + b;
	if (op == "-")
		result = a - b;
	if (op == "*")
		result = a * b;
	if (op == "/")
		result = a / b;
	if (op == "^")
		result = pow(a, b);
	overflow = CheckOveflow(a, b, op.c_str()[0]);
	overflow = abs(result) > pow(2, 31);
	return std::to_string((int)result);
}
/// <summary>
/// ���������  ��������� 
/// </summary>
/// <param name="str">���������, ���������� � �������� �������� ������</param>
/// <param name="result">���������� ��� �������� ����������</param>
/// <returns>true - ���� ���������� ������ �������(��� ������������)</returns>
bool Calculator::Calc(string str, double *result) {
	Stack stack;
	vector<string> lexems = polandStr.GetPolandStr(str);
	string commands = "+-*/^() ";
	for each (string lexem in lexems)
	{
		if (commands.find(lexem) == string::npos)
			stack.Push(lexem);
		else
			stack.Push(MakeOpeartionInt(stack.Pop(), stack.Pop(), lexem));
	}
	double res = stod(stack.Pop().c_str());
	if (res == -0)
		res = abs(res);

	*result = (int)res;
	return !overflow;
}
