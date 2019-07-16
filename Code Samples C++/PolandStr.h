#include "Stack.h"
#include "StrHelper.h"
#include <vector>
#include <string>
#pragma once
/// <summary>
/// ���������� �������� �������� ������ ���������
/// </summary>
class PolandStr
{
private:
	/// <summary>
	/// �������������� �������
	/// </summary>
	string commands = "";
	StrHelper strWizard = StrHelper();
public:
	/// <summary>
	/// �������������� ���������
	/// </summary>
	/// <param name="_commands">�������������� �������, �������� "+-*/^()"</param>
	PolandStr(string _commands);
	/// <summary>
	/// ����������
	/// </summary>
	~PolandStr();
	/// <summary>
	/// �������� ��������� �������
	/// </summary>
	/// <param name="command">�������</param>
	/// <returns>��������� �������</returns>
	int GetPriority(string command);
	/// <summary>
	/// ��������� ������ � ��������� �����
	/// </summary>
	/// <param name="lexems">������ ������</param>
	/// <param name="idx">������</param>
	/// <param name="value">������</param>
	/// <returns></returns>
	vector<string> Insert(vector<string> lexems, int idx, string value);
	/// <summary>
	/// ������� �������
	/// -5 -> (-5)
	/// 5-6 -> 5+(-6)
	/// </summary>
	/// <param name="lexems"></param>
	/// <returns></returns>
	vector<string> LexemReplace(vector<string> lexems);
	/// <summary>
	/// ���������� �������� ������ ��� ���������
	/// https://goo.gl/eaph5V
	/// </summary>
	/// <param name="str">������ � ����������</param>
	/// <returns>�������� �������� ������ ���������</returns>
	vector<string> GetPolandStr(string str);
};

