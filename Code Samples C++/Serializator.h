#include "FileIO.h"
#include "Pair.h"
#include "StrHelper.h"
#pragma once
class Serializator
{
private:
#pragma region ����
	/// <summary>
	/// �����������
	/// </summary>
	string delimiter = ":";
	/// <summary>
	/// ��� ������ � �������
	/// </summary>
	FileIO fileIO = FileIO();
	/// <summary>
	/// ��� ������ �� ��������
	/// </summary>
	StrHelper strHelper = StrHelper();
#pragma endregion

public:
#pragma region ������
	/// <summary>
	/// ����������� ���� �������
	/// </summary>
	/// <param name="fileName">���� ��� ����������</param>
	/// <param name="fieldsValues">���� � ��������</param>
	void Serialize(string fileName, vector<Pair> fieldsValues);
	/// <summary>
	/// ������������� ���� �������
	/// </summary>
	/// <param name="fileName">���� ��� ��������</param>
	/// <returns></returns>
	vector<Pair>Deserialize(string fileName);
#pragma endregion

#pragma region ������������/�����������
	/// <summary>
	/// �����������
	/// </summary>
	Serializator();
	/// <summary>
	/// ����������
	/// </summary>
	~Serializator();
#pragma endregion
};

