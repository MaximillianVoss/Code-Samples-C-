#pragma once
#include "pch.h"
/// <summary>
/// ������ ���������
/// </summary>
class Client
{
private:
	/// <summary>
	/// ��������� ����� ��� ��������� �����
	/// </summary>
	string phrase;
	/// <summary>
	/// ��������� ����
	/// </summary>
	string key;
public:
	/// <summary>
	/// ������ � ����:��/���
	/// </summary>
	bool isOnline;
	/// <summary>
	/// ������� ������� � ��������� ID
	/// </summary>
	/// <param name="id">��</param>
	Client(string key = "", string phrase = "") {
		this->isOnline = false;
		this->key = key;
		this->phrase = phrase;
	}
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	string GetKey() {
		return this->key;
	}
	/// <summary>
	/// 
	/// </summary>
	/// <param name="key"></param>
	void SetKey(string key) {
		this->key = key;
	}
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	string GetPhrase() {
		return this->phrase;
	}
	/// <summary>
	/// 
	/// </summary>
	~Client() {}
};

#pragma region ���������
bool operator==(Client& c1, Client& c2) {
	return c1.GetKey() == c2.GetKey();
}
#pragma endregion

