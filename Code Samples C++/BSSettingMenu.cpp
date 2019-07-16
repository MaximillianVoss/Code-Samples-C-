#include "stdafx.h"
#include "Enums.h"
#include "BSSettingMenu.h"


BSSettingMenu::BSSettingMenu(BSGame * _game)
{
	game = _game;
	menuItems = {
		{ ActionsSettings::debug,"����� �������" },
		{ ActionsSettings::fieldSize, "�������� ������ ����" },
		{ ActionsSettings::setAI, "�������� ����" },
		{ ActionsSettings::goBackToMain,"�����" }
	};
}

BSSettingMenu::BSSettingMenu()
{
}

BSSettingMenu::~BSSettingMenu()
{
}

bool BSSettingMenu::Action(int action)
{
	bool flag = false;
	int size = 0;
	switch (action)
	{
	case ActionsSettings::debug:
		io.Get(&flag);
		game->SetDebugMode(flag);
		return false;
	case ActionsSettings::fieldSize:
		io.Get(size, "������� ������ ����:");
		game = new BSGame(size);
		return false;
	case ActionsSettings::goBackToMain:
		return false;
	case ActionsSettings::setAI:
		io.Get(&flag);
		if (flag)
			game->EnableBot(Players::second);
		else
			game->DisableBot(Players::second);
		return false;
	default:
		return true;
	}
}
