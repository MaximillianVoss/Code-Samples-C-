
#pragma once
#include "pch.h"
#include "LogItem.h"
///<summary>
/// �������� ���������
///</summary>
class Log
{
private:

#pragma region ����
	/// <summary>
	/// ����� ��������� ����
	/// </summary>
	size_t logLimit;
	/// <summary>
	/// ������
	/// </summary>
	vector<LogItem> items;
	/// <summary>
	/// ������� Id ��������
	/// </summary>
	int currentItemId;
	/// <summary>
	/// ����������� ��������� ����
	/// </summary>
	string logSpacer = "__________________";
#pragma endregion

#pragma region ������

#pragma endregion

public:

#pragma region ����

#pragma endregion

#pragma region ������
	void Add(string message) {
		this->items.push_back(LogItem(this->currentItemId++, message));
	}
	void Add(vector<string> lines) {
		this->items.push_back(LogItem(this->currentItemId++, lines));
	}
	void Add(LogItem item) {
		if (this->GetCount() > this->logLimit)
			this->Clear();
		this->items.push_back(item);
	}
	int GetCount() {
		return this->items.size();
	}
	void Clear() {
		this->items.clear();
	}
	string ToString() {
		stringstream ss;
		for (LogItem item : this->items)
		{
			ss << this->logSpacer << endl;
			ss << item << endl;
			ss << this->logSpacer << endl;
		}
		return ss.str();
	}
#pragma endregion

#pragma region ������������/�����������
	Log(int limit = 1000) {
		this->logLimit = limit;
		this->currentItemId = 1;
	};
	~Log() {};
#pragma endregion

#pragma region ���������

#pragma endregion

#pragma region ����������� �������

#pragma endregion



};
#pragma region ���������
ostream& operator<<(ostream& os, Log log)
{
	os << log.ToString();
	return os;
}
#pragma endregion