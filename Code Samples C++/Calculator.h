#pragma once
#include "Stack.h"
#include "StrHelper.h"
#include "PolandStr.h"
#include <vector>
#include <string>
/// <summary>
/// ��������� �����������
/// </summary>
class Calculator
{
private:
	/// <summary>
	/// ���� ������������
	/// </summary>
	bool overflow;
	/// <summary>
	/// �������������� �������
	/// ��������:"+-*/^()"
	/// </summary>
	string commands = "";
	/// <summary>
	/// ��� ������ �� ��������
	/// </summary>
	StrHelper strWizard = StrHelper();
	/// <summary>
	/// ��� ����������� �������� ������
	/// </summary>
	PolandStr polandStr = PolandStr(commands);
	/// <summary>
	/// ��������� ��������� ��������
	/// </summary>
	/// <param name="sa">������ �������</param>
	/// <param name="sb">������ �������</param>
	/// <param name="op">���� ��������</param>
	/// <returns>��������� �������� � ��������� ����, ���� ������ ������ 0</returns>
	string MakeOpeartion(string sa, string sb, string op);
	/// <summary>
	/// ��������� ������������� ��������
	/// </summary>
	/// <param name="sa">������� 1</param>
	/// <param name="sb">������� 2</param>
	/// <param name="op">���� ��������</param>
	/// <returns></returns>
	string MakeOpeartionInt(string sa, string sb, string op);
public:
	/// <summary>
	/// �������������� �����������
	/// </summary>
	/// <param name="_commands">�������������� �������, ��������:"+-*/^()"</param>
	Calculator(string _commands);
	/// <summary>
	/// ����������
	/// </summary>
	~Calculator();
	/// <summary>
	/// ���������  ��������� 
	/// </summary>
	/// <param name="str">���������, ���������� � �������� �������� ������</param>
	/// <param name="result">���������� ��� �������� ����������</param>
	/// <returns>true - ���� ���������� ������ �������(��� ������������)</returns>
	bool Calculator::Calc(string str, double *result);
};

