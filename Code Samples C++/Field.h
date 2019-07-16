#include "Cell.h"
#include "ChessEnums.h"
#include "StrHelper.h"
#pragma once
/// <summary>
/// ����� �������� ����
/// </summary>
class Field
{
private:
	/// <summary>
	/// ��������� ���������� �� ������������
	/// </summary>
	/// <param name="coord">����������</param>
	/// <returns>true- ���� � �������� ����</returns>
	bool Check(int coord);
public:
	/// <summary>
	/// ���������� ������� �������� ��� ������ ����
	/// </summary>
	vector<vector<Cell>> a;
	/// <summary>
	/// ������� ������ ����
	/// </summary>
	size_t size;
	/// <summary>
	/// 
	/// </summary>
	Field();
	/// <summary>
	/// 
	/// </summary>
	/// <param name="_a"></param>
	Field(vector<vector<Cell>> _a);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="a"></param>
	Field(vector<vector<int>> _a);
	/// <summary>
	/// ������� ���� ���������� �������
	/// </summary>
	/// <param name="_size">������ ����</param>
	Field(size_t _size);
	/// <summary>
	/// ���������� ���� �� ������ ����:
	/// {0,0},{1,1},
	/// {1,1),{2,2}
	/// </summary>
	/// <param name="str">������ � �������</param>
	Field(string str);
	/// <summary>
	/// ����������
	/// </summary>
	~Field();
	/// <summary>
	/// ����������� �������� � ������� ������ � �������
	/// </summary>
	/// <param name="row">������</param>
	/// <param name="column">�������</param>
	/// <param name="value">��������</param>
	bool SetItem(size_t row, size_t column, int value);
	bool SetItem(size_t row, size_t column, CellTypes type, int value);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="row"></param>
	/// <param name="columns"></param>
	/// <returns></returns>
	Cell GetItem(size_t row, size_t columns);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="cell"></param>
	/// <param name="value"></param>
	bool SetItem(Cell cell, int value);
	bool SetItem(Cell cell, CellTypes type, int value);
	/// <summary>
	/// s
	/// </summary>
	/// <param name="cell"></param>
	/// <returns></returns>
	Cell GetItem(Cell cell);
	/// <summary>
	/// �������� ��������
	/// </summary>
	Field operator+(Field & a);
	/// <summary>
	/// ����������� � ������
	/// </summary>
	/// <returns></returns>
	string GetStr();
	/// <summary>
	/// ������� �������
	/// </summary>
	Field Shift(Directions direction);
	/// <summary>
	/// ��������� ������ �� �������������� ����
	/// </summary>
	/// <param name="cell"></param>
	/// <returns></returns>
	bool Check(Cell cell);
	Field(Field * field);
};

