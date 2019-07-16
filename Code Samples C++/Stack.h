#pragma once
#include<string>
#include<vector>
using namespace std;
/// <summary>
/// ����������� ����
/// �� ������������ ���������
/// </summary>
class Stack
{
private:
	/// <summary>
	/// ���������� �����
	/// </summary>
	vector<string> items;
public:
	Stack();
	~Stack();
	/// <summary>
	/// ���������� �� �����
	/// </summary>
	/// <returns>������� �� �������� �����</returns>
	string Pop();
	/// <summary>
	/// ���������� ������� 
	/// �� ����� ��� ����������
	/// </summary>
	/// <returns>������� �� �������� �����</returns>
	string Peek();
	/// <summary>
	/// ���������� � ����
	/// </summary>
	/// <param name="str">������� ��� ����������</param>
	void Push(string  str);
	/// <summary>
	/// �������� ���� �� �������
	/// </summary>
	/// <returns>true - ���� ���� ����</returns>
	bool isEmpty();
};