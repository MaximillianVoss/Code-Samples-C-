#pragma once
#include "pch.h"
/// <summary>
/// ������ ���������
/// </summary>
class Client
{
private:
public:
	/// <summary>
	/// ��
	/// </summary>
	string id;
	/// <summary>
	/// ������ � ����:��/���
	/// </summary>
	bool isOnline;
	/// <summary>
	/// 
	/// </summary>
	Client() {}
	/// <summary>
	/// ������� ������� � ��������� ID
	/// </summary>
	/// <param name="id">��</param>
	Client(string id) {
		this->id = id;
	}
	/// <summary>
	/// 
	/// </summary>
	~Client() {}
};

