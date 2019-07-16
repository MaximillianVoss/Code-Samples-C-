#include "stdafx.h"
#include "Pair.h"
#pragma once
class MapArray
{
private:

#pragma region ����
	/// <summary>
	/// ������ ��������� ���� ( ���� , �������� )
	/// </summary>
	vector<Pair> values;
#pragma endregion

public:

#pragma region ������
	/// <summary>
	/// ��������� �������
	/// </summary>
	/// <param name="key">����</param>
	/// <param name="value">��������</param>
	/// <returns></returns>
	bool Add(string key, string value);
	/// <summary>
	/// ��������� �������
	/// </summary>
	/// <param name="pair">���� ���� ( ���� , �������� )</param>
	/// <returns></returns>
	bool Add(Pair pair);
	/// <summary>
	/// ������� �������� �� �����
	/// </summary>
	/// <param name="key"></param>
	/// <returns></returns>
	bool Remove(string key);
	/// <summary>
	/// ���� �������� �� �����
	/// </summary>
	/// <param name="key"></param>
	/// <returns></returns>
	bool Find(string key);
	/// <summary>
	/// �������� ������
	/// </summary>
	/// <returns></returns>
	size_t GetSize();
	/// <summary>
	/// ������ �������� �������� �� �������
	/// </summary>
	/// <param name="index"></param>
	/// <param name="item"></param>
	void SetItem(size_t index, Pair item);
	/// <summary>
	/// �������� ������� �� �����
	/// </summary>
	/// <param name="key"></param>
	/// <returns></returns>
	Pair* GetItem(string key);
	/// <summary>
	/// ������� ������� �� �������
	/// </summary>
	/// <param name="index"></param>
	/// <returns></returns>
	Pair* GetItem(size_t index);
	/// <summary>
	/// ����������� � ������
	/// </summary>
	/// <returns></returns>
	string GetStr();
#pragma endregion

#pragma region ������������/�����������
	/// <summary>
	/// �����������
	/// </summary>
	MapArray();
	/// <summary>
	/// ����������
	/// </summary>
	~MapArray();
#pragma endregion

};