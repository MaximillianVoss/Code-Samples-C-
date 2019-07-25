#pragma once
#include "pch.h"
#include "LLItem.h"
#include "Constants.h"
template <typename T>
class LL {
private:
#pragma region ����
	/// <summary>
	/// ������� ����� ������
	/// </summary>
	int length;
#pragma endregion
public:
#pragma region ����
	/// <summary>
	/// ������ ������
	/// </summary>
	LLItem<T>* head;
	/// <summary>
	/// ����� ������
	/// </summary>
	LLItem<T>* tail;
#pragma endregion
#pragma region ������������/�����������
	/// <summary>
	/// ������� ������ ������
	/// ������ ������ - ������ ���������
	/// ����� ������ - ������ ���������
	/// </summary>
	LL() {
		this->head = NULL;
		this->tail = NULL;
		this->length = 0;
	}
	/// <summary>
	/// ����������
	/// </summary>
	~LL() {
		try {
			LLItem<T>* current = this->head;
			while (current && this->length > 0)
			{
				LLItem<T>* toDel = current;
				current = current->next;
				if (toDel != nullptr) {
					delete(toDel);
					toDel = NULL;
					this->DecLength();
				}
				else
					break;
			}
		}
		catch (exception ex) {
			cout << ex.what();
		}
	}
#pragma endregion
#pragma region ������
#pragma region ����������/��������
	/// <summary>
	/// ��������� ������� � ����� ������
	/// </summary>
	void virtual Add(T data) { throw exception(Constants::Strings::Errors::notImplemented); };
	/// <summary>
	/// ��������� ������� �� ���������� �������
	/// </summary>
	void virtual Add(T data, size_t index) { throw exception(Constants::Strings::Errors::notImplemented); };
	/// <summary>
	/// ��������� ����� � ����� ������
	/// </summary>
	void virtual Add(LLItem<T>* item) { throw exception(Constants::Strings::Errors::notImplemented); }
	/// <summary>
	/// ������� ������� � ����� ������
	/// </summary>
	void virtual Delete() { throw exception(Constants::Strings::Errors::notImplemented); };
	/// <summary>
	/// ������� ������� �� ���������� �������
	/// </summary>
	void virtual Delete(size_t index) { throw exception(Constants::Strings::Errors::notImplemented); };
	/// <summary>
	/// ������� ������� � ��������� ���������
	/// </summary>
	void virtual Delete(LLItem<T>* item) { throw exception(Constants::Strings::Errors::notImplemented); };
	/// <summary>
	/// ������� ������
	/// </summary>
	void Clear() {
		while (this->head)
			this->Delete();
	}
#pragma endregion
#pragma region �����
	/// <summary>
	/// ����� ���������� �������� � ������ (���� data)
	/// </summary>
	/// <param name="item">��������� �� �������</param>
	/// <returns>NULL-���� �������� �� ����������</returns>
	LLItem<T>* Find(LLItem<T>* item) {
		LLItem<T>* current = this->head;
		while (current)
		{
			if (item == current)
				return current;
			current = current->next;
		}
		return NULL;
	}
	/// <summary>
	/// ����� ���������� �������� � ������ (���� data)
	/// </summary>
	/// <param name="data">������</param>
	/// <returns>NULL-���� �������� �� ����������</returns>
	LLItem<T>* Find(T data) {
		LLItem<T>* current = this->head;
		while (current)
		{
			if (data == current->data)
				return current;
			current = current->next;
		}
		return NULL;
	}
	/// <summary>
	/// ����� �������� �� �������
	/// </summary>
	/// <param name="index"></param>
	///<returns>NULL-���� �������� �� ����������</returns>
	LLItem<T>* Find(size_t index) {
		if (this->length < index)
			return NULL;
		size_t i = 0;
		LLItem<T>* current = this->head;
		while (current && i <= index)
		{
			if (i == index)
				return current;
			current = current->next;
			i++;
		}
		return NULL;
	}
	/// <summary>
	/// �������� ��������� ������� � ������
	/// </summary>
	/// <returns></returns>
	LLItem<T>* GetLast() {
		return this->Find(size_t(this->GetLength() - 1));
	}
#pragma endregion
#pragma region �����
	/// <summary>
	/// ����������� ����� ������
	/// </summary>
	void IncLength() {
		this->length++;
	}
	/// <summary>
	/// ��������� ����� ������
	/// </summary>
	void DecLength() {
		this->length--;
	}
	/// <summary>
	/// �������� ����� ������
	/// </summary>
	/// <returns></returns>
	int GetLength() {
		return this->length;
	}
#pragma endregion
#pragma region �����
	/// <summary>
	/// ����������� ������ � ������
	/// </summary>
	/// <param name="showDetails">���������� ������ ������� ��������</param>
	/// <returns></returns>
	string ToString(bool showDetails = false) {
		LLItem<T>* current = this->head;
		if (current) {
			stringstream ss;
			while (current)
			{
				ss << current->ToString(showDetails);
				if (current->next)
					ss << Constants::Strings::Separators::arrow;
				current = current->next;
			}
			return ss.str();
		}
		else
			return Constants::Strings::Errors::Lists::empty;
	}
	/// <summary>
	/// ������������ ������ �� ������ � ������
	/// </summary>
	/// <returns>vector � �������</returns>
	vector<T> ToList() {
		vector<T> items;
		LLItem<T>* current = this->head;
		while (current) {
			items.push_back(current->data);
			current = current->next;
		}
		return items;
	}
#pragma endregion
#pragma endregion
};
#pragma region ���������
template<typename T>
ostream& operator<<(ostream& os, LL<T>& list)
{
	os << list.ToString() << endl;
	return os;
}
#pragma endregion