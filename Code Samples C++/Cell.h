/// <summary>
/// ����� ��������� � ������ CellTypes
/// </summary>
#include "Enums.h"
#include "StrHelper.h"
#pragma once
class Cell
{
private:
public:
#pragma region ����
	/// <summary>
	/// ������
	/// </summary>
	int row;
	/// <summary>
	/// �������
	/// </summary>
	int column;
	/// <summary>
	/// ���
	/// </summary>
	CellTypes type;
	/// <summary>
	/// �������� � ������
	/// </summary>
	int value;
#pragma endregion
#pragma region ������������/�����������
	Cell();
	/// <summary>
	/// ������� ������ �� ������ ���� { ��� ; �������� }
	/// </summary>
	/// <param name="str">������</param>
	Cell(string str);
	Cell(int _row, int _col);
	Cell(int _row, int _col, CellTypes _type);
	Cell(int _row, int _col, CellTypes _type, int _value);
	~Cell();
#pragma endregion
#pragma region ������
	/// <summary>
	/// ������� ������ � �������
	/// </summary>
	void Print();
	/// <summary>
	/// ����������� � ������: { ��� ; �������� }
	/// </summary>
	string GetStr();
	/// <summary>
	/// �������� ��������� 
	/// � ������ ����������
	/// </summary>
	/// <param name="cell">������ ��� ��������</param>
	/// <returns></returns>
	bool SameCoods(Cell cell);
	/// <summary>
	/// ��������� ����������
	/// � �������
	/// </summary>
	/// <param name="_row"></param>
	/// <param name="_col"></param>
	void Add(int _row, int _col);
	/// <summary>
	/// ���������� ����� �� 0 �� 63
	/// � ����������� �� ����� �������
	/// </summary>
	/// <returns></returns>
	int GetNum() {
		return row * 8 + column;
	}
	/// <summary>
	/// ��������� ���������� 
	/// ������ �� ������������
	/// </summary>
	/// <param name="row">������</param>
	/// <param name="column">�������</param>
	/// <param name="size">������ ����</param>
	/// <returns></returns>
	bool Check(int row, int column, int size);
	/// <summary>
	/// ��������� ���������� 
	/// ������ �� ������������
	/// </summary>
	/// <param name="size">������ ����</param>
	/// <returns>true ���� ���������� ������ � �������� ����</returns>
	bool Check(int size);
#pragma endregion
};

