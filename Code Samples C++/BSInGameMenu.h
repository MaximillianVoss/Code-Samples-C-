#include "Menu.h"
#pragma once
class BSInGameMenu : public Menu
{
private:
	/// <summary>
	/// ���������� �������� ��� ���
	/// </summary>
	bool correctShoot;
	/// <summary>
	/// ��������� ���� ��� ���
	/// true - ��
	/// false - ���
	/// </summary>
	bool close;
public:
	BSInGameMenu(BSGame *_game);
	BSInGameMenu();
	~BSInGameMenu();
#pragma region ������
	virtual bool Action(int action);
	/// <summary>
	/// �������� ���������� � ������������
	/// </summary>
	/// <returns></returns>
	Cell GetCoords();
#pragma endregion
};

