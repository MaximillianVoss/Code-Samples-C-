#include "stdafx.h"
#include "Field.h"
#pragma once
class ChessFigure
{
protected:
	/// <summary>
	/// �������� ������
	/// </summary>
	int GetRow();
	/// <summary>
	/// �������� �������
	/// </summary>
	int GetColumn();
	/// <summary>
	/// ������ ������
	/// </summary>
	/// <param name="_row">������</param>
	void SetRow(int _row);
	/// <summary>
	/// ������ �������
	/// </summary>
	/// <param name="_col">�������</param>
	void SetColumn(int _col);
	/// <summary>
	/// ������������� ������� ������
	/// </summary>
	/// <param name="_row">������</param>
	/// <param name="_col">�������</param>
	void Init(int _row, int _col);
	/// <summary>
	/// ��� ��� ������ ����������� �� �����
	/// </summary>
	string name;
private:
	/// <summary>
	/// ������
	/// </summary>
	int row;
	/// <summary>
	/// �������
	/// </summary>
	int column;
	/// <summary>
	/// ������ � ������� ����� �� ���������
	/// </summary>
	int rowMatrix = 3;
	/// <summary>
	/// ������� � ������� ����� �� ���������
	/// </summary>
	int colMatrix = 3;
public:
	/// <summary>
	/// ��������� ���� ��� ������
	/// </summary>
	Field moves;
	/// <summary>
	/// ����� �� ��������� ������
	/// </summary>
	/// <param name="cell">������</param>
	virtual bool Attack(Cell cell);
	/// <summary>
	/// �������� ��������� ���� �� ������
	/// </summary>
	/// <returns></returns>
	Field GetPossibleMoves(Cell cell) {
		Field res = Field(moves);
		while (cell.row > rowMatrix) {
			res = res.Shift(Directions::down);
			cell.row--;
		}
		while (cell.row < rowMatrix) {
			res = res.Shift(Directions::up);
			cell.row++;
		}
		while (cell.column > colMatrix) {
			res = res.Shift(Directions::right);
			cell.column--;
		}
		while (cell.column < colMatrix) {
			res = res.Shift(Directions::left);
			cell.column++;
		}
		return res;
	}
	/// <summary>
	/// �������� ������������
	/// </summary>
	/// <param name="f">������ ������ ��� ��������</param>
	/// <returns></returns>
	ChessFigure operator+(ChessFigure f) {
		ChessFigure res = ChessFigure(*this);
		res.moves = res.moves + f.moves;
		return res;
	}
	/// <summary>
	/// ����������� �� ���������
	/// </summary>
	ChessFigure();
	/// <summary>
	/// ������� ������ � ���������� ������������
	/// </summary>
	ChessFigure(string _name, Cell cell, Field _moves);
	/// <summary>
	/// ������ ����� ������
	/// </summary>
	/// <param name="figure">�������</param>
	ChessFigure(ChessFigure *figure);
	/// <summary>
	/// ����������
	/// </summary>
	~ChessFigure();

};