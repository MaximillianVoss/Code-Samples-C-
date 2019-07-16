#pragma once
#include "Enums.h"
#include "Constants.h"
#include "pchUnit.h"
/// <summary>
/// ���������� ������� ������
/// </summary>
class Generator
{
private:
#pragma region ������
	/// <summary>
	/// ���������� ������ �������� �����
	/// </summary>
	/// <param name="length">�����</param>
	/// <param name="str">����� �������� ��� ����������</param>
	/// <returns></returns>
	string GetStr(int length, const char* str) {
		int len = strlen(str);
		string result = "";
		for (int i = 0; i < length; i++)
			result += str[this->GetInt(0, len - 1)];
		return result;
	}
#pragma endregion
public:
#pragma region ����
#pragma endregion
#pragma region ������������
	Generator() {};
	~Generator() {};
#pragma endregion
#pragma region ������
	/// <summary>
	/// ���������� ��������� ����� ����� � ��������� �����������
	/// </summary>
	/// <param name="min">������� (������������)</param>
	/// <param name="max">�������� (������������)</param>
	/// <returns></returns>
	int GetInt(int min, int max)
	{
		return  min + (rand() % static_cast<int>(max - min + 1));
	}
	/// <summary>
	/// ���������� ������ ��������� ����� �����
	/// </summary>
	/// <param name="min">������� (������������)</param>
	/// <param name="max">�������� (������������)</param>
	/// <param name="count">����������</param>
	/// <returns></returns>
	vector<int> GetIntArray(int min, int max, size_t count)
	{
		vector<int> items;
		for (int i = 0; i < count; i++)
			items.push_back(GetInt(min, max));
		return items;
	}
	/// <summary>
	/// ���������� ��������� ������������ ����� � ��������� �����������
	/// </summary>
	/// <param name="min">������� (������������)</param>
	/// <param name="max">�������� (������������)</param>
	/// <returns></returns>
	double GetDouble(double min, double max) {
		double value = (double)rand() / RAND_MAX;
		return min + value * (max - min);
	}
	/// <summary>
	/// ���������� ������ ��������� ������������ �����
	/// </summary>
	/// <param name="min">������� (������������)</param>
	/// <param name="max">�������� (������������)</param>
	/// <param name="count">����������</param>
	/// <returns></returns>
	vector<double> GetDoubleArray(double min, double max, size_t count) {
		vector<double> items;
		for (int i = 0; i < count; i++)
			items.push_back(GetDouble(min, max));
		return items;
	}
	/// <summary>
	/// ������� ��������� ������ ��������� ������
	/// </summary>
	/// <param name="length">�����</param>
	/// <param name="lang">����</param>
	/// <returns></returns>
	string GetStr(int length, Language lang = byDefault) {
		if (lang == ENG || lang == byDefault)
			return GetStr(length, Constants::Strings::Alphabets::eng);
		if (lang == RUS)
			return GetStr(length, Constants::Strings::Alphabets::rus);
		return "";
	}
	/// <summary>
	/// ������� ������ ��������� ����� ��������� �����
	/// </summary>
	/// <param name="minlength">����������� �����</param>
	/// <param name="maxlength">������������ �����</param>
	/// <param name="count">����������</param>
	/// <param name="lang">����</param>
	/// <returns></returns>
	vector<string> GetStrArray(size_t minlength, size_t maxlength, size_t count, Language lang = byDefault) {
		vector<string> items;
		for (int i = 0; i < count; i++)
			items.push_back(GetStr(GetInt(minlength, maxlength), lang));
		return items;
	}
#pragma endregion
};