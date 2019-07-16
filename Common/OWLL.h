#pragma once
#include "pch.h"
#include "ListItem.h"
template <typename T>
class OWLList {
private:
#pragma region ���������
	const string incorrectIndex = "������������ ������ - ������ ������� ���!";
	const string listIsEmpty = "������ ����";
	const string separator = "->";
#pragma endregion
#pragma region ����
#pragma endregion
#pragma region ������
	/// <summary>
	/// ��������� �������� �� �������
	/// </summary>
	/// <param name="index">������ �������� ������</param>
	/// <returns>NULL-���� �������� �� ����������</returns>
	ListItem<T>* Get(int index) {
		ListItem<T>* current = head;
		if (current) {
			int i = 0;
			while (current->next && i < index)
				current = current->next;
			if (i < index)
				current = NULL;
		}
		return current;
	}
	/// <summary>
	/// �������� ��������� ������� ������
	/// </summary>
	/// <returns>NULL-���� ������ ������ ��� ��������� �� �������</returns>
	ListItem<T>* GetLast() {
		if (this->head) {
			ListItem<T>* current = head;
			while (current->next)
				current = current->next;
			return current;
		}
		return this->head;
	}
#pragma endregion
public:
#pragma region ����
	/// <summary>
	/// ������ ������
	/// </summary>
	ListItem<T>* head;
#pragma endregion
#pragma region ������������/�����������
	/// <summary>
	/// ������� ������ ������
	/// ������ ������ - ������ ���������
	/// </summary>
	OWLList() {
		head = NULL;
	}
	/// <summary>
	/// ����������
	/// </summary>
	~OWLList() {
		ListItem<T>* current = head;
		while (current)
		{
			ListItem<T>* toDel = current;
			current = current->next;
			delete(toDel);
		}
	}
#pragma endregion
#pragma region ������
	/// <summary>
	/// ���������� � ������ ������
	/// </summary>
	/// <param name="data">������</param>
	void AddBegin(T data) {
		if (!head)
			this->head = new  ListItem<T>(data);
		else {
			ListItem<T>* newHead = new  ListItem<T>(data);
			newHead->next = head;
			this->head = newHead;
		}
	}
	/// <summary>
	/// ���������� � ����� ������
	/// </summary>
	/// <param name="data">������</param>
	void Add(T data) {
		if (!head)
			this->AddBegin(data);
		else
			this->GetLast()->next = new  ListItem<T>(data);
	}
	/// <summary>
	/// ���������� � ������ �� ���������� �������
	/// </summary>
	/// <param name="data">������</param>
	/// <param name="index">������</param>
	void Add(T data, int index) {
		ListItem<T>* prev = Get(index - 1);
		if (!prev)
			this->AddBegin(data);
		else {
			ListItem<T>* next = Get(index);
			if (!next)
				this->Add(data);
			else {
				prev->next = new ListItem<T>(data);
				prev->next->next = next;
			}
		}

	}
	/// <summary>
	/// �������� �������� � ������ ������
	/// </summary>
	void DeleteBegin() {
		if (head) {
			ListItem<T>* newHead = head->next;
			delete(this->head);
			this->head = newHead;
		}
	}
	/// <summary>
	/// �������� �������� � ����� ������
	/// </summary>
	void Delete() {
		ListItem<T>* last = this->GetLast();
		if (last) {
			ListItem<T>* toDel = last;
			free(toDel);
			toDel = NULL;
			last = NULL;
		}
	}
	/// <summary>
	/// �������� �������� �� �������
	/// </summary>
	/// <param name="index"></param>
	void Delete(int index) {
		ListItem<T>* prev = Get(index - 1);
		if (!prev)
			this->DeleteBegin();
		else {
			ListItem<T>* current = Get(index);
			if (current) {
				prev->next = current->next;
				delete(current);
				current = NULL;
			}
		}
	}
	/// <summary>
	/// �������� ����� ������
	/// </summary>
	/// <returns></returns>
	int GetLength() {
		int i = 0;
		ListItem<T>* current = head;
		while (current) {
			current = current->next;
			i++;
		}
		return i;
	}
	/// <summary>
	/// ����������� ������ � ������
	/// </summary>
	/// <param name="showDetails">���������� ����� ������� ��������</param>
	/// <returns></returns>
	string ToString(bool showDetails = false) {
		if (head) {
			string str = "";
			ListItem<T>* current = head;
			while (current)
			{
				str += current->ToString(showDetails) + this->separator;
				current = current->next;
			}
			return str;
		}
		else
			return this->listIsEmpty;
	}
#pragma endregion
};