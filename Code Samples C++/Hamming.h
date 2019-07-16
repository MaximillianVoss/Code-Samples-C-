#include "InfoIO.h"
#include "Converter.h"
#pragma once
class Hamming
{
private:
	Converter converter;
public:
	Hamming();
	~Hamming();
	/// <summary>
	/// 
	/// </summary>
	vector<int> Code(char c);
	/// <summary>
	/// 
	/// </summary>
	vector<int> Code(int a);
	/// <summary>
	/// https://teckphile.wordpress.com/2017/10/27/hamming-code-c-implementation-for-n-bits/
	/// �������� ���������� ���� ��������
	/// </summary>
	vector<int> Code(vector<int>bits);
	/// <summary>
	/// �������� ������
	/// </summary>
	/// <param name="str">������</param>
	/// <returns></returns>
	vector<int>Code(string str);
	/// <summary>
	/// �������� ������ �����
	/// </summary>
	/// <param name="strs">������ �����</param>
	/// <returns></returns>
	vector<int> Code(vector<string> strs);
	/// <summary>
	/// ���������� ����������
	/// </summary>
	void Decode();
};

