#include "pch.h"
#pragma once
/// <summary>
/// ����� ��� ������ �� ��������
/// </summary>
class StrHelper
{
private:
	/// <summary>
	/// ���� ��������� ��������� ��������� � ���������
	/// </summary>
	/// <param name="items">��������� �����</param>
	/// <param name="str">���������</param>
	/// <returns></returns>
	bool Find(vector<string> items, string str) {
		for (string item : items)
			if (str == item)
				return true;
		return false;
	}
public:
#pragma region ������������/�����������
	/// <summary>
	/// �����������
	/// </summary>
	StrHelper() {}
	/// <summary>
	/// ����������
	/// </summary>
	~StrHelper() {}
#pragma endregion
#pragma region ������
	/// <summary>
	/// ���������� ������ � ������ � ���� ������
	/// </summary>
	/// <param name="lines">������</param>
	/// <param name="spacer">�����������</param>
	/// <returns></returns>
	string Join(vector<string> lines, string spacer = "") {
		stringstream ss;
		for (int i = 0; i < lines.size(); i++)
		{
			ss << lines[i];
			if (i < lines.size() - 1)
				ss << spacer;
		}
		return ss.str();
	}
	/// <summary>
	/// �������� ��� ��������� 
	/// ��������� ��������� � ������
	/// </summary>
	/// <param name="str">�������� ������</param>
	/// <param name="what">��� ��������</param>
	/// <param name="replace">�� ��� ��������</param>
	/// <returns></returns>
	string Replace(string str, string what, string replace) {
		while (str.find(what) != -1)
			str = str.replace(str.find(what), what.size(), replace);
		return str;
	}
	/// <summary>
	/// ������� ��������� ������� ������� � ������
	/// </summary>
	/// <param name="str">������</param>
	/// <param name="subStr">��������� ��� ��������</param>
	/// <returns>������ � ���������� ���������</returns>
	string Remove(string str, string subStr) {
		size_t pos = string::npos;
		while ((pos = str.find(subStr)) != std::string::npos)
			str.erase(pos, subStr.length());
		return str;
	}
	/// <summary>
	/// ��������� �������� �� ������ ��������� ��������� �����
	/// </summary>
	/// <param name="str">������ ��� ��������</param>
	/// <param name="collection">��������� �����</param>
	/// <returns>true - ���� �������� ��� �������</returns>
	bool Contains(string str, vector<string> collection) {
		for (int i = 0; i < collection.size(); i++)
			if (!this->Contains(str, collection[i]))
				return false;
		return true;
	}
	/// <summary>
	/// ��������� �������� �� ������ ��������� ���������
	/// </summary>
	/// <param name="str">������ ��� ��������</param>
	/// <param name="strFind">���������</param>
	/// <returns>true - ���� ��������</returns>
	bool Contains(string str, string subStr) {
		return (str.find(subStr) != std::string::npos);
	}
	/// <summary>
	/// ��������, �������� �� ������ ������
	/// </summary>
	/// <param name="s">������</param>
	/// <returns>true - ���� �������� ������</returns>
	bool IsNumber(string str) {
		/*if (str.empty() || ((!isdigit(str[0])) && (str[0] != '-') && (str[0] != '+')))
			return false;
		char* p;
		strtol(str.c_str(), &p, 10);
		return (*p == 0);*/
		return this->GetNumbers(str).size() == 1;
	}
	/// <summary>
	/// ������� ��� ����� � ��������� ������
	/// </summary>
	/// <param name="str">������ � ������� � ������� ����������</param>
	/// <returns>������ �����</returns>
	vector<string> GetNumbers(string str) {
		vector<string>result;
		regex rx(R"((?:^|\s)([+-]?[[:digit:]]+(?:\.[[:digit:]]+)?)(?=$|\s))");
		smatch m;
		while (regex_search(str, m, rx)) {
			result.push_back(m[1]);
			str = m.suffix().str();
		}
		return result;
	}
	/// <summary>
	/// ��������� ������ �� ������������
	/// </summary>
	/// <param name="str">������</param>
	/// <param name="delimiters">������ � �������������</param>
	/// /// <param name="notDelete">������ � ����������, ������� �� ����� �������</param>
	/// <returns>������ �����</returns>
	vector<string> Split(string str, string delimiters, string notDelete = "") {
		string buffer = "";
		vector<string> res;
		for (int i = 0; i < str.size(); i++)
		{
			char c = str[i];
			if (delimiters.find(c) == string::npos)
				buffer += c;
			else if (buffer.length() > 0) {
				res.push_back(buffer);
				buffer = "";
			}
			if (notDelete.find(c) != string::npos) {
				string temp;
				temp += c;
				res.push_back(temp);
			}
		}
		if (buffer.length() > 0) {
			res.push_back(buffer);
			buffer = "";
		}
		return res;
	}
	/// <summary>
/// 
/// </summary>
/// <param name="values"></param>
/// <returns></returns>
	vector<string> RemoveCopies(vector<string> values) {
		vector<string>result;
		for (string item : values)
			if (!this->Find(result, item))
				result.push_back(item);
		return result;
	}
#pragma endregion
};