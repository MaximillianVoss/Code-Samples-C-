#include "Field.h"
#include "Enums.h"
#pragma once
/// <summary>
/// ������� �� ����
/// </summary>
class BShip
{
private:
	/// <summary>
	/// ������ �������
	/// </summary>
	int size;
	/// <summary>
	/// ��������� �� ������ ����
	/// </summary>
	Field *field;
	/// <summary>
	/// ��������� ����������� ������:
	/// 1.������ ������ �� ������ ���� 
	/// ������ ������, ����� ������
	/// </summary>
	/// <param name="cell">������ ��� �������</param>
	bool Check(Cell cell);
public:
	/// <summary>
	/// ������� �������
	/// </summary>
	BShip();
	/// <summary>
	/// ������� ������� � ���������� �����������
	/// </summary>
	/// <param name="_size">������ �������</param>
	/// <param name="_field">��������� �� ����</param>
	BShip(int _size, Field *_field);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="cell"></param>
	/// <returns></returns>
	bool SetShip(Cell cell);
	/// <summary>
	/// ������ ������� �� ������ ���������� ������
	/// </summary>
	bool SetFirstEmpty();
	~BShip();
};

