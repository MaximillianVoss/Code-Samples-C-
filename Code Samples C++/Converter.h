#include "NumberSystems.h"
#pragma once
class Converter
{
private:
	NumberSystems ns;
public:
	Converter();
	~Converter();
	/// <summary>
	/// 
	/// </summary>
	/// <param name="c"></param>
	/// <returns></returns>
	int Convert(char c);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="a"></param>
	/// <returns></returns>
	char Convert(int a);
	/// <summary>
	/// ������������ ��������� 
	/// ������ � ������� � ������ ����
	/// </summary>
	/// <param name="str">������</param>
	/// <returns></returns>
	vector<int> Convert(const char * str);
	/// <summary>
	/// ������������ ��������� ������ ��������� ���� 
	/// � ������ ����
	/// </summary>
	/// <param name="str">������ ��������(����)</param>
	/// <returns></returns>
	vector<int> Convert(vector<char> str);
	/// <summary>
	/// ������������ ����� �� ���������� 
	/// ������� ��������� � ��������� ������� ���������
	/// </summary>
	/// <param name="value">�����</param>
	/// <param name="base">��������� ��</param>
	/// <returns></returns>
	char* Convert(int value, int base);
	/// <summary>
	/// ������������ ����� �� ��������� ������� ��������� � ����������
	/// </summary>
	/// <param name="value">������, ���������� �����</param>
	/// <param name="base">�������� ���������</param>
	/// <returns></returns>
	int Convert(char *value, int base);
};

