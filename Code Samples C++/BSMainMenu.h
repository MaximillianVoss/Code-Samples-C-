#include "Menu.h"
#include "BSInGameMenu.h"
#include "BSSettingMenu.h"
#pragma once
/// <summary>
/// ���� ����
/// </summary>
class BSMainMenu : public Menu
{
public:

#pragma region ������������
	BSMainMenu(BSGame *_game);
	BSMainMenu();
	~BSMainMenu();
#pragma endregion

#pragma region ������

#pragma endregion
private:
#pragma region ����

#pragma endregion

#pragma region ������
	virtual bool Action(int action);

	void Init();
#pragma endregion
};