#include "stdafx.h"
#include <Windows.h>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <string>
#pragma warning(disable : 4996)
using namespace std;

#pragma region ��������� ��� �����
struct StackAdv
{
private:
	int size;
	int maxSize;
	char *data;
public:
	StackAdv()
	{
		maxSize = 10;
		size = 0;
		data = new char[maxSize];
	}
	///<summary>���������� �������� � ����</summary>
	///<param name="c">������� ��� ����������</param>
	int push(char c)
	{
		if (size < maxSize)
		{
			data[size] = c;
			size++;
			return 1;
		}
		return 0;
	}
	///<summary>���������� �������� �� �����</summary>
	char pop()
	{
		if (size > 0)
		{
			char temp = data[size - 1];
			size--;
			return temp;
		}
		else
			return '-';


	}
	///<summary>�������� ����� �� �������������</summary>
	int full()
	{
		if (size == maxSize)
			return 1;
		else
			return 0;
	}
	///<summary>�������� ����� �� ������</summary>
	int empty()
	{
		if (size > 0)
			return 0;
		else
			return 1;
	}
	///<summary>���������� �������� �� �������� �����</summary>
	char top()
	{
		if (size > 0)
			return data[size - 1];
		else
			return '-';
	}
};
#pragma endregion

#pragma region ������� ���������� ������
//��������� ��� ������
struct Command
{
	int value;
	string command;
	Command(int _value, string _command)
	{
		value = _value;
		command = _command;
	}
};
///<summary>����������� ��������� ������� � �����</summary>
///<param name="commands">������ ������</param>
///<param name="command">������� � ��������� ����</param>
int GetCommand(vector<Command> commands, char* command)
{
	for each (Command item in commands)
	{
		if (strcmp(item.command.c_str(), command) == 0)
			return item.value;
	}
	return 0;
}
///<summary>����� ���������� ��������� � �������</summary>
///<param name="message">��������� ��� ������</param>
void Message(string message)
{
	printf("%s\n", message.c_str());
}
///<summary>����� ������� � �������</summary>
///<param name="message">������ ��� ������</param>
void Message(char message)
{
	printf("%c\n", message);
}
///<summary>���� ��� ������ �� ������</summary>
void Menu()
{
	vector<Command> commands = { Command(1,"push"), Command(2,"pop"), Command(3,"top"), Command(4,"empty"), Command(5,"full"), Command(6,"help") };
	StackAdv queue;
	char command[20];
	char value = ' ';
	scanf("%s", &command);
	while (strcmp(command, "exit") != 0)
	{
		switch (GetCommand(commands, command))
		{
		case 1:
			scanf("%s", &value);
			if (queue.push(value) == 1)
				Message("��������� � ����");
			else
				Message("���� ����������");
			break;
		case 2:

			value = queue.pop();
			if (value != '-')
			{
				Message("��������� �� �����:");
				Message(value);
			}
			else
				Message("���� ����");
			break;
		case 3:
			value = queue.top();
			if (value != '-')
			{
				Message("��������� �� �����:");
				Message(value);
			}
			else
				Message("���� ����");
			break;
		case 4:
			if (queue.empty() == 1)
				Message("���� ����");
			else
				Message("���� �� ����");
			break;
		case 5:
			if (queue.full() == 1)
				Message("���� ����������");
			else
				Message("���� �� ����������");
			break;
		case 6:
			Message("������ ��������� ������:\n");
			for each(Command item in commands)
			{
				if (item.command != "help")
				{
					if (item.command == "push")
						printf("%s <������ ��� ���������>\n", item.command.c_str());
					else
						printf("%s\n", item.command.c_str());
				}

			}
			Message("\n");
			break;
		default:
			Message("����������� �������");
			break;
		}
		scanf("%s", command);
	}
}
#pragma endregion

#pragma region ����� �����(������������ ��� �������������)
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	Menu();
//	system("pause");
//	return 0;
//}
#pragma endregion