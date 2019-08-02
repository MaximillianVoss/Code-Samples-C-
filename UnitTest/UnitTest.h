#pragma once
#include "Generator.h"



/// <summary>
/// ���� ����
/// </summary>
template<typename T>
class UnitTest {
private:
	/// <summary>
	/// �������
	/// </summary>
	string prefixName = "���� ";
	/// <summary>
	/// �������� ������ � �������
	/// </summary>
	void Print(vector<T> items) {
		for (T item : items)
			cout << item << endl;
	}
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
	/// ���������� ���� ������ � ���� �� �������� �����������
	/// </summary>
	void ResetColor() {
		this->SetColor(ConsoleColor::white, ConsoleColor::black);
	}
public:
	string name;
	vector<T> expected;
	vector<T> actual;
	/// <summary>
	/// ����� � �������
	/// </summary>
	enum ConsoleColor {
		/// <summary>
		///  0
		/// </summary>
		black,
		/// <summary>
		///  1
		/// </summary>
		dark_blue,
		/// <summary>
		/// 2
		/// </summary>
		dark_green,
		/// <summary>
		/// 3 
		/// </summary>
		dark_cyan,
		/// <summary>
		/// 4
		/// </summary>
		dark_red,
		/// <summary>
		/// 5
		/// </summary>
		dark_magenta,
		/// <summary>
		/// 6
		/// </summary>
		dark_yellow,
		/// <summary>
		/// 7
		/// </summary>
		light_gray,
		/// <summary>
		/// 8
		/// </summary>
		dark_gray,
		/// <summary>
		/// 9
		/// </summary>
		light_blue,
		/// <summary>
		/// 10
		/// </summary>
		light_green,
		/// <summary>
		/// 11
		/// </summary>
		light_cyan,
		/// <summary>
		/// 12
		/// </summary>
		light_red,
		/// <summary>
		/// 13
		/// </summary>
		light_magenta,
		/// <summary>
		/// 14
		/// </summary>
		light_yellow,
		/// <summary>
		/// 15
		/// </summary>
		white
	};
	UnitTest() {
		this->name = this->prefixName + Constants::Strings::undefined;
		this->expected = 0;
	}
	UnitTest(string name, vector<T> expected) {
		this->name = this->prefixName + name;
		this->expected = expected;
	}
	virtual void Test() = 0;
	virtual bool Compare(T actual) { return false; };
	virtual bool Compare(vector<T> actual) { return false; };
	/// <summary>
	/// ��������� ��������� �������� � actual
	/// </summary>
	/// <param name="items">�������� ��� ����������</param>
	void Add(vector<T>items) {
		for (T item : items)
			this->actual.push_back(item);
	}
	/// <summary>
	/// ��������� �������� ����������(actual) ���������
	/// </summary>
	/// <param name="item">������� ��� ����������</param>
	void Add(T item) {
		this->actual.push_back(item);
	}
	/// <summary>
	/// ���������� ��������� � ����������
	/// </summary>
	/// <param name="actual">���������� ���������</param>
	/// <param name="expected">��������� ���������</param>
	/// <returns>true - ���� ���������</returns>
	bool Compare(vector<T> actual, vector<T> expected) {
		if (actual.size() != expected.size())
			return false;
		for (int i = 0; i < actual.size(); i++)
			if (actual[i] != expected[i])
				return false;
		return true;
	}
	/// <summary>
	/// ���������� ��������� � ����������
	/// ���������� ������� � actual ������ ��� ���������!
	/// </summary>
	/// <returns>true - ���� ���������</returns>
	bool Compare() {
		return this->Compare(this->actual, this->expected);
	}
	/// <summary>
	/// ������ �����
	/// </summary>
	void Start() {
		this->SetColor(ConsoleColor::black, ConsoleColor::white);
		cout << this->name << endl;
		this->ResetColor();
		try {
			Test();
			if (this->Compare()) {
				this->SetColor(ConsoleColor::white, ConsoleColor::light_green);
				cout << Constants::Strings::Messages::UnitTest::passed << endl;
				this->ResetColor();
			}
			else {
				this->SetColor(ConsoleColor::white, ConsoleColor::light_red);
				cout << Constants::Strings::Messages::UnitTest::failed << endl;
				this->ResetColor();
				cout << Constants::Strings::Messages::UnitTest::expected << endl;
				this->Print(this->expected);
				cout << Constants::Strings::Messages::UnitTest::actual << endl;
				this->Print(this->actual);
			}
		}
		catch (exception ex) {
			cout << ex.what() << endl;
		}

	}
};
/// <summary>
/// ���� ���� ������
/// </summary>
class UnitTests {
private:
	string title;
public:
	UnitTests(string title) {
		this->title = title;
		cout << this->title << endl;
	}
	virtual void Start() = 0;
};