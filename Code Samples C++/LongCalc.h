#include "stdafx.h"
#include "LongVal.h"
#pragma once
/// <summary>
/// �������� ��������� ���������
/// �������� � �������� �������
/// </summary>
class LongCalc
{
public:
	LongCalc();
	~LongCalc();
	/// <summary>
	/// ������� ��� ������������ ���� ������� �����. 
	/// ���� ����������� ����� ������ ������
	/// �� ����� ������� ��������� � �������� ������� ���������. 
	/// ���������� �����
	/// ����������������� �����.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	LongVal Sum(LongVal a, LongVal b);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	LongVal Sum(string a, string b);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	LongVal Sub(LongVal a, LongVal b);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	LongVal Sub(string a, string b);
	/// <summary>
	/// �������� ��� ����� ������� ��������
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	LongVal Div(LongVal a, LongVal b);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	LongVal Div(string a, string b);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	LongVal Mul(LongVal a, LongVal b);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	LongVal Mul(string a, string b);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	LongVal Mod(LongVal a, LongVal b);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	LongVal Mod(string a, string b);
};

