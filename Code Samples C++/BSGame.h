#include "stdafx.h"
#include "BShip.h"
#include "Field.h"
#include "Enums.h"
#include "Pair.h"
#include "Serializator.h"
#include "Player.h"
#include  "ArrayHelper.h"
#pragma once
/// <summary>
/// ���� ����
/// </summary>
class BSGame {
public:
#pragma region ����
	/// <summary>
	/// ����� ������������ ������ ���� ������
	/// ������� ����������
	/// </summary>
	map<CellTypes, ConsoleColor> colorsMap;
	/// <summary>
	/// ����� ������������ ������ ���� ������
	/// ������� ������
	/// </summary>
	map<CellTypes, ConsoleColor>colorMapHidden;
#pragma endregion

#pragma region ������������
	/// <summary>
		/// 
		/// </summary>
	BSGame();
	/// <summary>
	/// ������� ���� � �����������
	/// </summary>
	/// <param name="_size">������ �����</param>
	BSGame(int _size);
	/// <summary>
	/// ������� ���� � �����������
	/// </summary>
	/// <param name="_ships">��������� ����� ��������</param>
	/// <param name="_size">������ �����</param>
	BSGame(int _ships, int _size);
	/// <summary>
	/// ����������
	/// </summary>
	~BSGame();
#pragma endregion 

#pragma region ������

#pragma region Start
	/// <summary>
	/// 
	/// </summary>
	void Start();
	/// <summary>
	///  ��������� ����
	/// </summary>
	/// <param name="_debugMode">����� �������, true - ��������</param>
	void Start(bool _debugMode);
	/// <summary>
	/// 
	/// </summary>
	void Finish();
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	bool IsStarted();
#pragma endregion

#pragma region Players
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	int GetPlayer();
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	int GetNextPLayer();
	/// <summary>
	/// ������� ������ �� �������
	/// </summary>
	/// <param name="i">����� ������</param>
	/// <returns></returns>
	Player* GetPlayer(int i);
#pragma endregion

#pragma region Gameplay
	/// <summary>
	/// 
	/// </summary>
	/// <param name="player"></param>
	/// <returns></returns>
	Field GetField(int player);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="player"></param>
	void SetShips(int player);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="cell"></param>
	/// <returns></returns>
	bool Shoot(Cell cell);
	/// <summary>
	/// ��������� ������� ������
	/// </summary>
	/// <returns></returns>
	bool CheckWin();
	/// <summary>
	/// ������� ����������
	/// </summary>
	/// <returns></returns>
	int GetWinner();
#pragma endregion

#pragma region Save/Load
	/// <summary>
	/// ���������� ����
	/// </summary>
	void Save();
	/// <summary>
	/// ��������� ����
	/// </summary>
	void Load();
#pragma endregion

#pragma region Settings
	/// <summary>
	/// ���������� ��������� ������ �������
	/// </summary>
	/// <returns>true - ���� � ������ �������</returns>
	bool isInDebugMode();
	/// <summary>
	/// ���������� ����� �������
	/// </summary>
	/// <param name="value">true- ����� �������,false - ��� �������</param>
	void SetDebugMode(bool value);
	/// <summary>
	/// �������� ���� � ����
	/// ���� ���������� PvAI
	/// </summary>
	/// <param name="_player">����� ������</param>
	void EnableBot(int _player);
	/// <summary>
	/// ������� ���� �� ����
	/// ���� ���������� PvP
	/// </summary>
	/// <param name="_player">����� ������</param>
	void DisableBot(int _player);
	/// <summary>
	/// ���������� ������� ��� ��� ���
	/// </summary>
	/// <param name="_player">����� ������</param>
	bool IsBotEnabled(int _player);
	/// <summary>
	/// ������������� ����� �������
	/// </summary>
	void SetDebugMode();
#pragma endregion

#pragma endregion

private:
#pragma region ����
	/// <summary>
	/// ���������� �������� �� ���������
	/// ������������� ������ ���� 
	/// ������ ���������� ���������
	/// </summary>
	int defaultShips = 10;
	/// <summary>
	/// ������ ���� �� ���������
	/// </summary>
	int defaultSize = 10;
	/// <summary>
	/// ������ ����� �������
	/// </summary>
	int size;
	/// <summary>
	/// ��������� �� ����� 
	/// ��������� ������ � ������ ������:
	/// 0 - ������
	/// 1- ������ 
	/// � �.�.
	/// </summary>
	int player;
	/// <summary>
	/// ������
	/// </summary>
	vector<Player> players;
	/// <summary>
	/// 
	/// </summary>
	vector<Field> fields;
	/// <summary>
	/// true -���� ���� ��������
	/// </summary>
	bool gameStarted;
	/// <summary>
	/// ����� ������� 
	/// � ��� ������������ ������� ����������
	/// </summary>
	bool debugMode;
	/// <summary>
	/// ��������� ����� ��������
	/// </summary>
	int startShips;
	/// <summary>
	/// �������� ����� �������� �����
	/// </summary>
	vector<string> fieldNames = {
		"size",
		"player",
		"shipsRemain",
		"fields",
		"gameStarted",
		"debugMode",
		"startShips"
	};
	/// <summary>
	/// ������� ��������
	/// </summary>
	vector<int>sizes = { 4,3,3,2,2,2,1,1,1,1 };
	/// <summary>
	/// ��� ����������
	/// </summary>
	string savegameFile = "savegame.txt";
#pragma endregion

#pragma region ������
	/// <summary>
	/// �������������� ����
	/// </summary>
	/// <param name="size">������ �����</param>
	void Init(int _size);
	/// <summary>
	/// �������������� ����
	/// </summary>
	/// <param name="_ships">��������� ����� ��������</param>
	/// <param name="_size">������ �����</param>
	void Init(int _ships, int _size);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="value"></param>
	/// <returns></returns>
	bool CheckCoord(int value);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="cell"></param>
	/// <returns></returns>
	bool Check(Cell cell);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="types"></param>
	/// <param name="type"></param>
	/// <returns></returns>
	bool InRange(vector<CellTypes> types, CellTypes type);
#pragma endregion

};