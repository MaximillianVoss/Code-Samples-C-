#include "stdafx.h"
#pragma once
class PairStr
{
private:
public:

#pragma region ����
	/// <summary>
	/// ����
	/// </summary>
	string key;
	/// <summary>
	/// ��������
	/// </summary>
	string value;
#pragma endregion

#pragma region ������������/�����������
	PairStr();
	/// <summary>
	/// ������� ���� � ��������� ������ � ���������
	/// </summary>
	/// <param name="_key">����</param>
	/// <param name="_value">��������</param>
	PairStr(string _key, string _value);
	~PairStr();
#pragma endregion

#pragma region ������
	/// <summary>
	/// ����������� � ������
	/// </summary>
	/// <returns></returns>
	string GetStr();
#pragma endregion

};