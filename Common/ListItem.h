#pragma once
#include "pch.h"
template <typename T>
/// <summary>
/// ������� �������� ������
/// </summary>
class ListItem {
public:
	/// <summary>
	/// ������
	/// </summary>
	T data;
	/// <summary>
	/// ��������� �������
	/// </summary>
	ListItem* next;
	/// <summary>
	/// ���������� �������
	/// </summary>
	ListItem* prev;
	/// <summary>
	/// ������� ������� ������ � ���������� �������
	/// </summary>
	/// <param name="data">������(����� ���)</param>
	ListItem(T data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
	/// <summary>
	/// ������� ������� ������, 
	/// ��� ������ ���������� ����������� �� ���������
	/// </summary>
	ListItem() :ListItem(T()) {

	}
	/// <summary>
	/// ����������
	/// </summary>
	~ListItem() {
		this->next = NULL;
		this->prev = NULL;
	}
	/// <summary>
	/// ����������� ������� � ������
	/// </summary>
	/// <param name="showDetails">true - ���������� ��� ����������:������ + ������</param>
	/// <returns></returns>
	string ToString(bool showDetails) {
		string str = "";
		if (showDetails) {
			if (this->next)
				str += this->next->ToString(false);
			if (this->prev)
				str += this->prev->ToString(false);
		}
		return str + this->ToString();
	}
	/// <summary>
	/// ����������� ������� � ������
	/// </summary>
	/// <returns></returns>
	string ToString() {
		return to_string(this->data);
	}
};