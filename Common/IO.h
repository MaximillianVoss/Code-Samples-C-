#pragma once
#include "Constants.h"
#include "pch.h"
#pragma once
/// <summary>
/// ����/����� ���������� � ������� � �����
/// </summary>
class IO
{
private:
#pragma region ����
#pragma endregion
#pragma region ������
#pragma region ����
	/// <summary>
	/// ��������� �������� ���������� ���� �� �������
	/// </summary>
	///<param name="value">��������</param>
	///<param name="message">���������</param>
	template<typename T>
	bool Get(T& value, string message = "") {
		this->Print(message, true);
		cin >> value;
		if (!cin.good()) {
			cin.clear();
			cin.ignore();
			return false;
		}
		return true;
	}
	bool Get(string& value, string message = "") {
		this->Print(message, true);
		cin.clear();
		cin.ignore();
		char buffer[Constants::Ints::strMaxLength];
		cin.getline(buffer, sizeof(buffer));
		value = buffer;
		if (!cin.good()) {
			cin.clear();
			cin.ignore();
			return false;
		}
		return true;
	}
#pragma endregion 
#pragma region �����
	char PutGetNext(char c, FILE* input, FILE* output) {
		fputc(c, output);
		return fgetc(input);
	}
#pragma endregion
#pragma endregion
public:
#pragma region ����
	string txtExtension = ".txt";
	string endInstruction = ":";
#pragma endregion
#pragma region �����������/����������
	/// <summary>
	/// 
	/// </summary>
	IO() {

	}
	/// <summary>
	/// 
	/// </summary>
	~IO() {

	}
#pragma endregion
#pragma region ������
#pragma region ����
#pragma region �������
	template<typename T>
	/// <summary>
	/// ��������� �������� ���������� ���� �� �������
	/// </summary>
	///<param name="message">���������</param>
	T Get(string message = "") {
		T value;
		if (this->Get<T>(value, message))
			return value;
		else {
			this->Print(Constants::Strings::Errors::IO::input);
			return Get<T>(message);
		}
	}
	string GetLine(string message = "") {
		string value;
		if (this->Get(value, message))
			return value;
		else {
			this->Print(Constants::Strings::Errors::IO::input);
			return this->GetLine(message);
		}
	}
#pragma endregion
#pragma region ����
	FILE* OpenRead(string fileName) {
		FILE* file = NULL;
		fopen_s(&file, fileName.c_str(), "r");
		return file;
	}
	FILE* OpenWrite(string fileName) {
		FILE* file = NULL;
		fopen_s(&file, fileName.c_str(), "w");
		return file;
	}
	void  Close(FILE* file) {
		if (file != NULL)
			fclose(file);
	}
	vector<string> ReadLines(string fileName)
	{
		fstream stream(&fileName[0]);
		string line;
		vector<string> result;
		while (getline(stream, line))
			result.push_back(line);
		stream.close();
		return result;
	}
	string ReadString(string fileName) {
		string res = "";
		vector<string> lines = ReadLines(fileName);
		for (int i = 0; i < lines.size(); i++)
			res += lines[i];
		return res;
	}
#pragma endregion
#pragma endregion
#pragma region �����
#pragma region �������
	/// <summary>
	/// ������������ ���� � �������
	/// </summary>
	/// <param name="text">���� ������</param>
	/// <param name="background">���� ����</param>
	void SetColor(int text, int background)
	{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
	}
	/// <summary>
	/// ������������� ���������� ���� ��� 
	/// ���� � ������
	/// </summary>
	/// <param name="color">���� � ������ � ������� ����</param>
	void SetColor(int color) {
		SetColor(color, color);
	}
	/// <summary>
	/// �������� ����������� � ������� 
	/// </summary>
	/// <param name="separator">������ �����������</param>
	/// <param name="length">����� ������������</param>
	void PrintSeparator(char separator = '_', int length = Constants::Ints::strMaxLength) {
		for (int i = 0; i < length; i++)
			cout << separator;
		cout << endl;
	}
	/// <summary>
	/// ������� ��������� ������ � �������
	/// </summary>
	/// <param name="message">��������� ��� ������</param>
	void Print(string message, bool newLine = false)
	{
		this->Print(message.c_str(), newLine);
	}
	/// <summary>
	/// ������� ��������� ������ � �������
	/// </summary>
	/// <param name="message">��������� ��� ������</param>
	void Print(const char* message, bool newLine = false)
	{
		if (strlen(message) > 0) {
			if (newLine)
				cout << endl;
			printf("%s", message);
		}
	}
	/// <summary>
	/// ������� �������� ������ ���� � �������
	/// </summary>
	/// <param name="value">��������</param>
	/// <param name="newLine">true - �������� ������� �� ����� ������</param>
	void Print(int value, bool newLine = false) {
		if (newLine)
			cout << endl;
		cout << value;
	}
	/// <summary>
	/// ������� �������� ������������� ���� � �������
	/// </summary>
	/// <param name="value">��������</param>
	/// <param name="newLine">true - �������� ������� �� ����� ������</param>
	void Print(float value, bool newLine = false) {
		if (newLine)
			cout << endl;
		cout << value;
	}
	/// <summary>
	/// ������� �������� ������������� ���� � �������
	/// </summary>
	/// <param name="value">��������</param>
	/// <param name="newLine">true - �������� ������� �� ����� ������</param>
	void Print(double value, bool newLine = false) {
		if (newLine)
			cout << endl;
		cout << value;
	}
	template <typename T>
	/// <summary>
	/// ������� ������ �� ���� 
	/// � ������(4 ������� �� �������)
	/// </summary>
	/// <param name="a">������</param>
	/// <param name="size">������</param>	
	void Print(T* a, int size, string message = "", bool newLine = false, bool numerate = false, string separator = "")
	{
		this->Print(message, true);
		for (size_t i = 0; i < size; i++) {
			if (numerate) {
				this->Print(to_string(i + 1) + '.', newLine);
				this->Print(a[i], !newLine);
			}
			else {
				this->Print(a[i], newLine);
			}
			if (i < size - 1)
				this->Print(separator);
		}
		cout << endl;
	}
	template <typename T>
	/// <summary>
	/// ������� ������� � �������
	/// </summary>
	/// <param name="a">�������</param>
	/// <param name="row">������</param>
	/// <param name="cols">�������</param>
	void Print(T** a, size_t rows, size_t cols, string message = "", string separator = "") {
		this->Print(message, true);
		throw exception(Constants::Strings::Errors::notImplemented);
		//for (size_t i = 0; i < rows; i++)
		//	this->Print(a[i], cols, "", true, separator);
	}
	template <typename T>
	/// <summary>
	/// ������� ������ �� ����� � ������
	/// </summary>
	/// <param name="a">������ ��� ������</param>
	/// <param name="message">���������</param>
	void Print(vector<T> a, string message = "", bool newLine = false, bool numerate = false, string separator = "")
	{
		this->Print(&a[0], a.size(), message, newLine, numerate, separator);
	}
	template <typename T>
	/// <summary>
	/// ������� ������� �� ����� � ���������� ����
	/// </summary>
	/// <param name="matrix">������� ��� ������</param>
	void Print(vector<vector<T>> matrix, string message = "", string separator = "")
	{
		this->Print(message, true);
		throw exception(Constants::Strings::Errors::notImplemented);
		//if (matrix.size() > 0)
		//	this->Print(&matrix[0], (size_t)matrix.size(),(size_t) matrix[0].size(), message, separator);
		//this->Print(message, true);
		//cout << endl;
		//for (size_t i = 0; i < matrix.size(); i++) {
		//	this->Print(matrix[i], "", false, false, separator);
		//}
	}
#pragma endregion
#pragma region �����
	/// <summary>
	/// ������� ���� � ��������� ������
	/// </summary>
	/// <param name="fileName">��� �����</param>
	void AddFile(string fileName) {
		this->WriteLines(fileName, {});
	}
	/// <summary>
	/// ������� ����
	/// </summary>
	/// <param name="fileName">��� �����</param>
	bool RemoveFile(string fileName) {
		if (remove(fileName.c_str()) != 0)
			return false;
		return true;
	}
	/// <summary>
	/// 
	/// </summary>
	/// <param name="fileName"></param>
	void ClearLines(string fileName) {
		this->AddFile(fileName);
	}
	/// <summary>
	/// ��������� ���������� ���� ��� ���
	/// </summary>
	/// <param name="fileName">��� �����</param>
	/// <returns></returns>
	bool IsExists(string fileName) {
		ifstream f(fileName.c_str());
		return f.good();
	}
	/// <summary>
	/// ���������� ������ � ����
	/// </summary>
	///<param name="fileName">��� �����</param>
	/// <param name="lines">������ ��� ������</param>
	/// <param name="addNewline">true-�������� ������� ������</param>
	void WriteLines(string fileName, vector<string>lines, bool addNewline = false) {
		ofstream stream(&fileName[0]);
		for (string line : lines) {
			if (addNewline)
				line += '\n';
			stream.write(line.c_str(), line.size());
		}
		stream.close();
	}
	/// <summary>
	/// ��������� ��������� ������ � ����� �����
	/// </summary>
	void Append(string filename, vector<string>lines, bool addNewline = false) {
		vector<string>currentLines = ReadLines(filename);
		currentLines.insert(currentLines.end(), lines.begin(), lines.end());
		WriteLines(filename, currentLines, addNewline);
	}
	/// <summary>
	/// ������� ����������� �� ������� ����� � ��������� ��������� �� ������ �����
	/// </summary>
	/// <param name="inFile">������� ����</param>
	/// <param name="outFile">�������� ����</param>
	void RemoveComments(string inFile, string outFile) {
		FILE* input = OpenRead(inFile);
		FILE* output = OpenWrite(outFile);
		if (!input)
		{
			printf("\n�� ������� ������� ���� %s ��� ������", inFile.c_str());
			fclose(output);
		}
		char cur = fgetc(input);

		if (output)
		{
			if (cur != EOF)
			{
				while (cur != EOF)
				{
					if ((cur != '/') && (cur != '\"') && (cur != '\''))
						cur = PutGetNext(cur, input, output);
					else
					{
						if ((cur != '\"') && (cur != '\''))
						{
							cur = fgetc(input);
							if (cur == '/' || cur == '*')
							{
								if (cur == EOF)
									break;
								if (cur == '/')
								{
									cur = fgetc(input);
									while (cur != '\n')
									{
										if (cur == EOF)
											break;
										if (cur == '\\')
										{
											cur = fgetc(input);
											cur = fgetc(input);
										}
										else
											cur = fgetc(input);
									}
								}
								else
								{
									cur = fgetc(input);
									while (cur)
									{
										if (cur == EOF)
											break;
										if (cur == '*')
										{
											cur = fgetc(input);
											if (cur == '/')
											{
												cur = fgetc(input);
												break;
											}
										}
										else
											cur = fgetc(input);
									}
								}
							}
							else
								fputc('/', output);
						}
						else
						{
							if (cur == '\"')
							{
								cur = PutGetNext(cur, input, output);
								while (cur != '\"')
								{
									if (cur == EOF)
										break;
									if (cur == '\\')
									{
										cur = PutGetNext(cur, input, output);
										cur = PutGetNext(cur, input, output);
										if (cur == '\"')
											break;
									}
									else
									{
										if (cur != '\n')
											cur = PutGetNext(cur, input, output);
										else
											break;
									}
								}
								cur = PutGetNext(cur, input, output);
							}
							else
							{
								cur = PutGetNext(cur, input, output);
								while (cur != '\'')
								{
									if (cur == EOF || cur == '\'')
										break;
									if (cur == '\\')
										cur = PutGetNext(cur, input, output);
									if (cur != '\n')
										cur = PutGetNext(cur, input, output);
									else
										break;
								}
								cur = PutGetNext(cur, input, output);
							}
						}
					}
				}
			}
		}
		else
			printf("\n�� ������� ������� ���� %s ��� ������", outFile.c_str());
		printf("\n����������� �� ����� %s �������, �������� ����: %s.\n", inFile.c_str(), outFile.c_str());
		Close(input);
		Close(output);
	}
#pragma endregion
#pragma endregion
#pragma region ������
	/// <summary>
	/// ������������� ������� ����/����� � �������
	/// </summary>
	void SetRusIO() {
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);
	}
	/// <summary>
	/// ������ ��������� �� �����, 
	/// ���� �� ����� ������ ����� �������
	/// </summary>
	void Pause() {
		system("pause");
	}
	/// <summary>
	/// ������� �������
	/// </summary>
	void Clear()
	{
		system("cls");
	}
	/// <summary>
	/// 
	/// </summary>
	/// <param name="milliSeconds"></param>
	void Wait(int milliSeconds) {
		Sleep(milliSeconds);
	}
#pragma endregion
#pragma endregion


};