#include "stdafx.h"
#include "Field.h"
#include "InfoIO.h"
#pragma once
/// <summary>
/// �����
/// </summary>
class Player
{
protected:
	/// <summary>
	/// ���� ����������
	/// </summary>
	Field * field;
	/// <summary>
	/// ��� �����/������ ����������
	/// </summary>
	IO io = IO();
	/// <summary>
	/// �������� �� ��:
	/// true - ���� ��
	/// </summary>
	bool isAI;
public:
	/// <summary>
	/// ����� ���������� ��������
	/// </summary>
	int ships;
	/// <summary>
	/// ����������� �� ���������
	/// </summary>
	Player();
	/// <summary>
	/// ������� ������ � ����������
	/// </summary>
	/// <param name="_ships">��������� ����� ��������</param>
	/// <param name="_field">���� ����������</param>
	Player(int _ships, Field * _field);
	/// <summary>
	/// ����������
	/// </summary>
	~Player();
	/// <summary>
	///  �������� ������ � ������������ ��� ��������
	/// </summary>
	Cell GetCoords();
	/// <summary>
	/// ���������� �������� isAI
	/// </summary>
	/// <returns>true - ���� ��</returns>
	bool GetIsAI();
	/// <summary>
	/// ������ ������ ��� ���������� ��
	/// </summary>
	void EnableAI();
	/// <summary>
	/// ���������� ������ ��� ���������� ��������
	/// </summary>
	void DisableAI();
};

