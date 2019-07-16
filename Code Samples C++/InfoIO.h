#include "stdafx.h"
//#include "Field.h"
//#include "Enums.h"
#pragma once
/// <summary>
/// �������� ������ � ������� 
/// ��� ������ ��������, ������ � ����������
/// </summary>
class IO
{
private:

public:
#pragma region �����������/����������
	IO();
	~IO();
#pragma endregion

#pragma region ������������

#pragma endregion

#pragma region ������

#pragma region ����
	/// <summary>
	/// ��������� ������� �� ������ ����� ������
	/// </summary>
	/// <param name="s">������</param>
	/// <returns>true -���� ����� �����</returns>
	bool isInt(string s);
	/// <summary>
	/// ��������� ������� �� ������ ����� ������ 
	/// </summary>
	/// <param name="s">������</param>
	/// <returns>true -���� ����� �����</returns>
	bool isInt(char* s);
	/// <summary>
	/// �������� ����� ����� �� �������
	/// </summary>
	/// <param name="value">���������� ��� ��������</param>
	/// <param name="message">��������� �� �����</param>
	/// <returns>false ���� ����� �� �����</returns>
	bool Get(int& value, string message);
	/// <summary>
	/// �������� ������� ����� �� �������
	/// </summary>
	/// <param name="value">���������� ��� ��������</param>
	/// <param name="message">��������� �� �����</param>
	/// <returns>false ���� ����� �� �����</returns>
	bool Get(double& value, string message);
	/// <summary>
	/// �������� ������������� ������ �� �������
	/// </summary>
	/// <param name="a">������</param>
	/// <param name="n">������</param>
	void Get(int* a, int n);
	/// <summary>
	/// �������� ������ ������� ����� �� �������
	/// </summary>
	/// <param name="a">������</param>
	/// <param name="n">������</param>
	void Get(double* a, int n);
	/// <summary>
	/// �������� ������ �� ������������
	/// </summary>
	/// <param name="str">������ �� ������</param>
	/// <param name="message">���������</param>
	void Get(string* str, string message);
	/// <summary>
	/// �������� ������ �� ������������
	/// </summary>
	/// <param name="str">������ �� ������</param>
	void Get(string* str);
	/// <summary>
	/// �������� ������ �������� �� ������������
	/// </summary>
	/// <param name="b">������� ��������</param>
	void Get(bool* b);
	/// <summary>
	/// �������� ����� ����� � ������������
	/// </summary>
	/// <returns></returns>
	int GetInt();
	/// <summary>
	/// �������� ����� ����� � ������������
	/// </summary>
	/// <param name="message">���������</param>
	/// <returns></returns>
	int GetInt(string message);
	/// <summary>
	/// �������� ������������ ����� � ������������
	/// </summary>
	/// <returns></returns>
	double GetDouble();
	/// <summary>
	/// �������� ������������ ����� � ������������
	/// </summary>
	/// <param name="message">���������</param>
	/// <returns></returns>
	double GetDouble(string message);
	/// <summary>
	/// �������� ������ � ������������
	/// </summary>
	/// <returns></returns>
	string GetStr();
	/// <summary>
	/// �������� ������ � ������������
	/// </summary>
	/// <param name="message">���������</param>
	/// <returns></returns>
	string GetStr(string message);
#pragma endregion

#pragma region �����
	/// <summary>
	/// ������������ ���� � �������
	/// </summary>
	/// <param name="text">���� ������</param>
	/// <param name="background">���� ����</param>
	void SetColor(int text, int background);
	/// <summary>
	/// ������������� ���������� ���� ��� 
	/// ���� � ������
	/// </summary>
	/// <param name="commonColor">����</param>
	void SetColor(int color);
	/// <summary>
	/// ������� ��������� ������ � �������
	/// </summary>
	/// <param name="message">��������� ��� ������</param>
	void Print(string message);
	/// <summary>
	/// ������� ��������� ������ � �������
	/// </summary>
	/// <param name="message">��������� ��� ������</param>
	void Print(const char* message);
	template <typename T>
	/// <summary>
	/// ������� ������ �� ���� 
	/// � ������(4 ������� �� �������)
	/// </summary>
	/// <param name="a">������</param>
	/// <param name="size">������</param>	
	void Print(T* a, int size)
	{
		for (size_t i = 0; i < size; i++)
			Print(a[i]);
		cout << endl;
	}
	template <typename T>
	/// <summary>
	/// 
	/// </summary>
	/// <param name="a"></param>
	/// <param name="row"></param>
	/// <param name="cols"></param>
	void Print(T * *a, int rows, int cols) {
		for (size_t i = 0; i < rows; i++)
			Print(a[i], cols);
	}
	template <typename T>
	/// <summary>
	/// ������� ������ �� ����� � ������
	/// </summary>
	/// <param name="a">������ ��� ������</param>
	void Print(vector<T> a)
	{
		Print(&a[0], a.size());
	}
	template <typename T>
	/// <summary>
	/// ������� ������ �� ����� � ������
	/// </summary>
	/// <param name="a">������ ��� ������</param>
	/// <param name="message">���������</param>
	void Print(vector<T> a, string message)
	{
		this->Print(message);
		this->Print(&a[0], a.size());
	}
	template <typename T>
	/// <summary>
	/// ������� ������ �� ����� � ������
	/// ������ ������ � ��������� ����� ������
	/// </summary>
	/// <param name="a">������ ��� ������</param>
	/// <param name="numerate">true- ���������� ������</param>
	void PrintLn(T * a, int size, bool numerate)
	{
		for (int i = 0; i < size; i++)
			if (numerate)
				PrintLn(a[i], i + 1);
			else
				PrintLn(a[i]);
		cout << endl;
	}
	template <typename T>
	/// <summary>
	/// ������� ������ �� ����� � ������
	/// ������ ������ � ��������� ����� ������
	/// </summary>
	/// <param name="a">������ ��� ������</param>
	/// <param name="numerate">true- ���������� ������</param>
	void PrintLn(vector<T> a, bool numerate)
	{
		PrintArrayLn(&a[0], a.size(), numerate);
	}
	template<typename T>
	/// <summary>
	/// ������� �������� 
	/// ������ ���� � �������
	/// ����� ������� �� ����� ������
	/// </summary>
	/// <param name="value">��������</param>
	void PrintLn(T value) {
		cout << value << endl;
	}
	template<typename T>
	/// <summary>
	/// ������� �������� 
	/// ������ ���� � �������
	/// ����� ������� �� ����� ������
	/// </summary>
	/// <param name="i">����� ��������</param>
	/// <param name="value">��������</param>
	void PrintLn(T value, int i) {
		cout << i << '.' << value << endl;
	}
	template<typename T>
	/// <summary>
	/// ������� �������� 
	/// ������ ���� � �������
	/// </summary>
	/// <param name="value">��������</param>
	void Print(T value) {
		//cout << value;
	}
	/// <summary>
	/// ������� ������� �� ����� � ���������� ����
	/// </summary>
	/// <param name="matrix">������� ��� ������</param>
	void Print(vector<vector<int>> matrix);
	/// <summary>
	/// ������� ������� � �������� 
	/// </summary>
	/// <param name="matrix">�������</param>
	/// <param name="message">�������</param>
	void Print(vector<vector<int>> matrix, string message);
	/// <summary>
	/// ������� ��������� ���� 
	/// �  ���� ��������
	/// </summary>
	/// <param name="field">������� ����</param>
	/// <param name="colorsMap">����� ������</param>
	//void Print(Field field, map<CellTypes, ConsoleColors> colorsMap);
	/// <summary>
	/// �������� ����������� � ������� ����: "________"
	/// </summary>
	/// <param name="count">����� ������������</param>
	void PrintSeparator(int count);
#pragma endregion

#pragma endregion

#pragma region ������
	/// <summary>
	/// ������������� ������� ����/����� � �������
	/// </summary>
	void SetRusIO();
	/// <summary>
	/// ������ ��������� �� �����, 
	/// ���� �� ����� ������ ����� �������
	/// </summary>
	void Pause();
	/// <summary>
	/// ������� �������
	/// </summary>
	void Clear();
	/// <summary>
	/// 
	/// </summary>
	/// <param name="milliSeconds"></param>
	void Wait(int milliSeconds);
#pragma endregion

};