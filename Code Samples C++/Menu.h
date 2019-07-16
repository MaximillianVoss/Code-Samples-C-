#include "stdafx.h"
#include "InfoIO.h"
#include "FileIO.h"
#include "BSGame.h"
#include "Enums.h"
#include "MenuItem.h"
#include "Cell.h"
#pragma once
/// <summary>
/// �������� ����� ����
/// </summary>
class Menu
{
private:
public:
	/// <summary>
	/// ��������� ������ ���� ��� ���
	/// </summary>
	bool closeMenu;
	/// <summary>
	/// ��������� ���� ��� ���
	/// true - ��
	/// false - ���
	/// </summary>
	bool closeGame;
	/// <summary>
	/// ���� ����
	/// </summary>
	BSGame *game;
	/// <summary>
	/// ������ ����
	/// </summary>
	vector<MenuItem> menuItems;
	/// <summary>
	/// ���� �����
	/// </summary>
	IO io = IO();
	/// <summary>
	/// �������� ���� �����
	/// </summary>
	FileIO fileIO = FileIO();
	/// <summary>
	/// ���������� ����
	/// </summary>
	/// <param name="items">�������� ����</param>
	/// <param name="clear">true-�������� �����</param>
	void ShowMenu(vector<MenuItem> items, bool clear);
	/// <summary>
	/// ���������� ���� �� ������ �����
	/// </summary>
	/// <param name="items"></param>
	void ShowMenu(vector<MenuItem> items);
	/// <summary>
	/// ��������� ����
	/// </summary>
	bool Start();
	/// <summary>
	/// ��������� ����
	/// </summary>
	/// <param name="showField">���������� �� ������� ����</param>
	/// <returns></returns>
	bool Start(bool showField);
	/// <summary>
	/// ������ �������� ��� ������� ������ ����
	/// </summary>
	/// <param name="action">��� ��������</param>
	/// <returns></returns>
	virtual bool Action(int action);
	/// <summary>
	/// �������� ����� ������ ���� �� ������������
	/// </summary>
	/// <returns>true - ���� ��������� ����</returns>
	bool GetAction();
	/// <summary>
	/// 
	/// </summary>
	Menu();
	/// <summary>
	/// ������� ����/������� ����
	/// </summary>
	/// <param name="game">������ �� ����</param>
	Menu(BSGame *_game);
	/// <summary>
	/// ����������
	/// </summary>
	~Menu();
	/// <summary>
	/// �������� ����
	/// </summary>
	/// <param name="player">����� ������</param>
	/// <param name="colorsMap">�������� �����</param>
	void PrintField(int player, map<CellTypes, ConsoleColor> colorsMap);
	/// <summary>
	/// �������� ����
	/// </summary>
	/// <param name="player">����� ������</param>
	void PrintField(int player);
	/// <summary>
	/// ������� �� ����� ����� �������� ������
	/// </summary>
	/// <param name="player">�����</param>
	void PrintPlayer(int player);
};

