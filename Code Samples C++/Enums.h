#pragma once
#pragma region ������������
#pragma region Menu
/// <summary>
/// �������� � ������� ����
/// </summary>
enum ActionsMain {
	/// <summary>
	/// ����� ����
	/// </summary>
	newgame = 1,
	/// <summary>
	/// ���������
	/// </summary>
	load,
	/// <summary>
	/// ��������
	/// </summary>
	settings,
	/// <summary>
	/// �������� ����
	/// </summary>
	close
};
/// <summary>
/// �������� � ������� ����
/// </summary>
enum ActionsInGame {
	/// <summary>
	/// ����������
	/// </summary>
	shoot = 1,
	/// <summary>
	/// ��������� ����
	/// </summary>
	save,
	/// <summary>
	/// �����
	/// </summary>
	goBack
};
/// <summary>
/// �������� � ���� ��������
/// </summary>
enum ActionsSettings {
	/// <summary>
	/// ��������(���������)
	/// </summary>
	debug = 1,
	/// <summary>
	/// ������ ����(���������)
	/// </summary>
	fieldSize,
	setAI,
	goBackToMain
};
/// <summary>
/// 
/// </summary>
enum ActionsCommon {
	/// <summary>
	/// �����
	/// </summary>
	back
};
#pragma endregion

#pragma region Other
/// <summary>
/// ���� ������
/// </summary>
enum CellTypes {
	empty,
	hit,
	miss,
	ship,
	default,
	notFound
};
/// <summary>
/// ���� ��������
/// </summary>
enum ShipTypes {

};
/// <summary>
/// ���� �������
/// </summary>
enum Players {
	first,
	second
};
/// <summary>
/// ����� � �������
/// </summary>
enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};
/// <summary>
/// ������ ����� ���� ������� ���
/// </summary>
enum FieldsBS {
	/// <summary>
	/// ������ ����
	/// </summary>
	size,
	/// <summary>
	/// ����� ������� �����
	/// </summary>
	player,
	shipsRemain,
	fields,
	gameStarted,
	debugMode,
	maxShips
};
#pragma endregion
#pragma endregion