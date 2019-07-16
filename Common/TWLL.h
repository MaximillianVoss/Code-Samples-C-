#pragma once
#include "pch.h"
#include "ListItem.h"
template <typename T>
class TWLList {
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
	ListItem* Get(int index) {
		ListItem* current = head;
		if (current) {
			int i = 0;
			while (current->next && i < index)
				current = current->next;
			if (i < index)
				current = NULL;
		}
		return current;
	}
#pragma endregion
public:
#pragma region ����
	/// <summary>
	/// ������ ������
	/// </summary>
	ListItem* head;
#pragma endregion
#pragma region ������������/�����������
	/// <summary>
	/// ������� ������ ������
	/// ������ ������ - ������ ���������
	/// </summary>
	TWLList() {
		head = NULL;
	}
	/// <summary>
	/// ����������
	/// </summary>
	~TWLList() {
		ListItem* current = head;
		while (current)
		{
			ListItem* toDel = current;
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
		if (!this->head)
			this->head = new  ListItem<T>(data);
		else {
			ListItem* newHead = new  ListItem<T>(data);
			newHead->next = this->head;
			this->head->prev = newHead;
			this->head = newHead;
		}
	}
	/// <summary>
	/// ���������� � ����� ������
	/// </summary>
	/// <param name="data">������</param>
	void Add(T data) {
		if (!head)
			this->head = new  ListItem<T>(data);
		else {
			ListItem* current = head;
			while (current->next)
				current = current->next;
			current->next = new  ListItem<T>(data);
			current->next->prev = current;
		}

	}
	/// <summary>
	/// ���������� � ������ �� ���������� �������
	/// </summary>
	/// <param name="data">������</param>
	/// <param name="index">������</param>
	void Add(T data, int index) {
		if (!head)
			this->head = new  ListItem<T>(data);
		else {
			ListItem* current = head;
			int i = 0;
			while (current->next && i < index) {
				current = current->next;
				i++;
			}
			if (i < index)
				throw exception(this->incorrectIndex);
			ListItem* next = NULL;
			if (current)
				next = current->next;
			current->next = new  ListItem<T>(data);
			current->next->prev = current;
			current->next->next = next;
			if (next)
				next->prev = current->next;
		}
	}
	/// <summary>
	/// �������� �������� � ������ ������
	/// </summary>
	void DeleteBegin() {
		if (head) {
			ListItem* newHead = head->next;
			delete(this->head);
			this->head = newHead;
			this->head->prev = NULL;
		}
	}
	/// <summary>
	/// �������� �������� � ����� ������
	/// </summary>
	void Delete() {
		if (head) {
			ListItem* current = head;
			while (current->next)
				current = current->next;
			ListItem* toDel = current;
			free(toDel);
			current = NULL;
		}
	}
	/// <summary>
	/// �������� �������� �� �������
	/// </summary>
	/// <param name="index"></param>
	void Delete(int index) {
		if (head) {
			ListItem* prev = Get(index - 1);
			ListItem* current = Get(index);
			if (!prev || !current)
				throw exception(this->incorrectIndex);
			prev->next = current->next;
			delete(current);
		}
	}
	/// <summary>
	/// �������� ����� ������
	/// </summary>
	/// <returns></returns>
	int GetLength() {
		int i = 0;
		if (head) {
			ListItem* current = head;
			while (current->next) {
				current = current->next;
				i++;
			}
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
			ListItem* current = head;
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