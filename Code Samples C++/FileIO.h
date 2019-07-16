#include "pch.h"
#include "StrHelper.h"
#pragma once
class FileIO
{
public:
	/// <summary>
	/// ���������� ������ � ����
	/// </summary>
	///<param name="fileName">��� �����</param>
	/// <param name="lines">������ ��� ������</param>
	void WriteLines(string fileName, vector<string> lines);
	/// <summary>
	/// ���������� ������ � ����
	/// ��������� � ������ ������ ������� �� ����� ������
	/// </summary>
	///<param name="fileName">��� �����</param>
	/// <param name="lines">������ ��� ������</param>
	void WriteLinesLn(string fileName, vector<string> lines);
	///<summary>��������� ���� ����� ������ �� �����</summary>
	///<param name="fileName">��� �����</param>
	vector<string> ReadLines(string fileName);
	/// <summary>
	/// ������ ������� �� �����
	/// ��� ������ �������:
	/// 0 1 2
	/// 3 4 5
	/// 7 8 9
	/// ����������� �����
	/// </summary>
	vector<vector<string>> ReadMatrix(string fileName);
	/// <summary>
	/// ��������� ��������� ������ � ����� �����
	/// </summary>
	void FileIO::Append(string filename, vector<string>lines);
	/// <summary>
	/// ������� ���� �� ������
	/// </summary>
	/// <param name="fileName">��� �����</param>
	/// <returns>�������� �����</returns>
	FILE* OpenRead(string fileName);
	/// <summary>
	/// ��������� ���������� ����� � ���� ������
	/// </summary>
	/// <param name="fileName">��� �����</param>
	/// <returns>������ � ���������� �����</returns>
	string ReadAllText(string fileName);
	/// <summary>
	/// ������� ���� �� ������
	/// </summary>
	/// <param name="fileName">��� �����</param>
	/// <returns>�������� �����</returns>
	FILE* OpenWrite(string fileName);
	/// <summary>
	/// ������� ����
	/// </summary>
	/// <param name="file"></param>
	void Close(FILE* file);
	/// <summary>
	/// ������� ����������� �� ������� �����
	/// � ��������� ��������� �� ������� �����
	/// </summary>
	/// <param name="inFile">������� ����</param>
	/// <param name="outFile">�������� ����</param>
	void RemoveComments(string inFile, string outFile);
	/// <summary>
	/// ������� ����������� �� ������� �����
	/// � ��������� ��������� �� ������� �����
	/// </summary>
	/// <param name="in">������� ����</param>
	/// <param name="out">�������� ����</param>
	void RemoveComments(FILE* in, FILE* out);
	FileIO();
	~FileIO();
};

