#pragma once
#include "pch.h"
template <typename T>
/// <summary>
/// ������� �������� ������
/// </summary>
class LLItem {
public:
#pragma region ����
	/// <summary>
	/// ������
	/// </summary>
	T data;
	/// <summary>
	/// ��������� �������
	/// </summary>
	LLItem* next;
	/// <summary>
	/// ���������� �������
	/// </summary>
	LLItem* prev;
#pragma endregion
#pragma region ������������/�����������
	/// <summary>
	/// ������� ������� ������ � ���������� ������� � ��������
	/// </summary>
	/// <param name="data">������</param>
	/// <param name="next">��������� �������</param>
	/// <param name="prev">���������� �������</param>
	LLItem(T data, LLItem * next = NULL, LLItem * prev = NULL) {
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
	/// <summary>
	/// �������� ��������� �������
	/// </summary>
	/// <param name="item">������� ��� �����������</param>
	LLItem(LLItem<T>* item) {
		this->data = item->data;
		this->next = item->next;
		this->prev = item->prev;
	}
	/// <summary>
	/// ������� ������� ������, 
	/// ��� ������ ���������� ����������� �� ���������
	/// </summary>
	LLItem() :LLItem(T()) {

	}
	/// <summary>
	/// ����������
	/// </summary>
	~LLItem() {
		this->next = NULL;
		this->prev = NULL;
	}
#pragma endregion
#pragma region ������	
	/// <summary>
	/// ��������� ��� ��������
	/// </summary>
	/// <param name="item">��������� �� �������(����������� ������)</param>
	void Add(LLItem* item) {
		this->next = item;
		if (item)
			item->prev = this;
	}
	/// <summary>
	/// ����������� ������� � ������
	/// </summary>
	/// <param name="showDetails">true - ���������� ��� ����������:������ + ������</param>
	/// <returns></returns>
	string ToString(bool showDetails = false) {
		stringstream ss;
		if (showDetails) {
			if (this->next)
				ss << this->next->ToString(false);
			if (this->prev)
				ss << this->prev->ToString(false);
		}
		ss << this->data;
		return ss.str();
	}
#pragma endregion
#pragma region ���������
	//friend ostream& operator<< <>(ostream& os, LLItem<T>& item)
	//{
	//	//os << item.data;
	//	return os;
	//}
	bool operator== (LLItem<T>& item) {
		return this->data == item.data;
	}
	/*LLItem<T>& operator+= (LLItem<T>& item) {
		this->next = item;
		item.prev = this;
		return *this;
	}*/
	//LLItem<T>* operator+=(LLItem<T>* item) {
	//	this->next = item;
	//	item->prev = this;
	//	return this;
	//}
#pragma endregion
};