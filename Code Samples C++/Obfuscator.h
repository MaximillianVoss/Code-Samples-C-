#include "stdafx.h"
#pragma once
class Obfuscator
{
private:
#pragma region ���������
	const string input = "input";
	const string output = "output";
	const string keywords = "keywords";
	const string dummy = "dummy";
#pragma endregion
#pragma region ����
	string configFileName = "config.txt";
	string inputFileName = "";
	string outputFileName = "";
	string dummyFileName = "";
	string keyWordsFileName = "";
#pragma endregion
#pragma region ������
	/// <summary>
	/// �������� �������� ���������
	/// </summary>
	/// <param name="a">������ �� ��������</param>
	/// <returns>������ � ��������� ����������</returns>
	vector<string> RemoveTabs(vector<string> a);
	/// <summary>
	/// �������������� ����������
	/// </summary>
	/// <param name="a">������ �����</param>
	/// <returns></returns>
	vector<string> RenameVariables(vector<string> a);
	/// <summary>
	/// ��������� ���������� ������� � ����������
	/// </summary>
	/// <param name="a">������ �����</param>
	/// <returns></returns>
	vector<string> AddDummyVariables(vector<string> a);
	/// <summary>
	/// ����������� ���
	/// </summary>
	/// <returns>��������� ������ �����</returns>
	vector<string> Obfuscate(vector<string> a);
#pragma endregion
public:
#pragma region ����

#pragma endregion
#pragma region �����������/���������� 
	/// <summary>
	/// ������� ���������
	/// </summary>
	/// <param name="_configFileName">���� �� ����� ������������</param>
	Obfuscator(string _configFileName);
	~Obfuscator();
#pragma endregion
#pragma region ������

	/// <summary>
	/// ����������� ��������� ���� � �����
	/// </summary>
	/// <param name="inFileName">��� �������� �����</param>
	/// <param name="outFileName">��� ��������� �����</param>
	void Obfuscate();
#pragma endregion
};

