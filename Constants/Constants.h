#pragma once
/// <summary>
/// ���������
/// </summary>
class Constants {
public:
	/// <summary>
	/// ��������� ���������
	/// </summary>
	class Strings {
	public:
		static constexpr const char* undefined = "undefined";
		class Alphabets {
		public:
			static constexpr const char* rus = "��������������������������������";
			static constexpr const char* eng = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		};
		class Messages {
		public:
			class Inputs {
			public:
				static constexpr const char* inputValue = "������� ��������";

			};
			class UnitTest {
			public:
				static constexpr const char* passed = "���� �������!";
				static constexpr const char* failed = "���� ��������!";
				static constexpr const char* expected = "���������";
				static constexpr const char* actual = "��������";
			};
		};
		class Errors {
		public:
			static constexpr const char* notImplemented = "����������� ���������� ������";
			class IO {
			public:
				static constexpr const char* input = "������ �����, ��������� ����";
				static constexpr const char* format = "������ ��������������, ��������� ������ ������  ��������� ����";
			};
		};
	};
	/// <summary>
	/// ������������� ���������
	/// </summary>
	class Ints {
	public:
		static const size_t strMaxLength = 255;
	};
	/// <summary>
	/// ������� ���������
	/// </summary>
	class Doubles {
	public:
	};
};