#include "Player.h"
#pragma once
/// <summary>
/// ��� �������� ���
/// </summary>
class BSBot : public Player
{
private:
public:
	/// <summary>
	/// 
	/// </summary>
	BSBot();
	/// <summary>
	/// 
	/// </summary>
	/// <param name="_field"></param>
	BSBot(Field * _field);
	/// <summary>
	/// ������� ���� � ���������� �����������
	/// </summary>
	/// <param name="_startShips">��������� ����� ��������</param>
	/// <param name="_field">������ ����</param>
	BSBot(int _ships, Field * _field);
	/// <summary>
	///  �������� ������ � ������������ ��� ��������
	/// </summary>
	Cell BSBot::GetCoords();
	/// <summary>
	/// 
	/// </summary>
	~BSBot();
};