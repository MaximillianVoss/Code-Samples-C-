#pragma once
/// <summary>
/// ��� �������� � ������ ������� ���������
/// </summary>
class NumberSystems
{
private:
	/// <summary>
	/// ������������ ����� � ������
	/// </summary>
	/// <param name="value">����� ��� �����������</param>
	/// <returns></returns>
	char * ConvertIntToString(int value);
public:
	/// <summary>
	/// �������� ������ �� ����
	/// </summary>
	/// <param name="a">��� �������</param>
	/// <returns></returns>
	char GetChar(int a);
	/// <summary>
	/// �������� ��� �������
	/// </summary>
	/// <param name="c"></param>
	/// <returns></returns>
	int GetNum(char c);
	/// <summary>
	/// 
	/// </summary>
	NumberSystems();
	/// <summary>
	/// 
	/// </summary>
	~NumberSystems();
	/// <summary>
	/// ������������ ����� �� ���������� 
	/// ������� ��������� � ��������� ������� ���������
	/// </summary>
	/// <param name="a">�����</param>
	/// <param name="b">���������</param>
	/// <returns></returns>
	char * Convert(int a, int b);
	/// <summary>
	/// ������������ ����� �� ��������� ������� ��������� � 10��
	/// </summary>
	/// <param name="value">��������</param>
	/// <param name="base">�������� ���������</param>
	/// <returns></returns>
	int ConvertToDecimal(char * value, int base);
};

