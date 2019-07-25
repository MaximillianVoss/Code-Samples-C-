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
		/// <summary>
		/// ������ ������
		/// </summary>
		static constexpr const char* strEmpty = "";
		/// <summary>
		/// ������������� ��������-��������
		/// </summary>
		static constexpr const char* undefined = "undefined";
		/// <summary>
		/// ��������
		/// </summary>
		class Alphabets {
		public:
			static constexpr const char* rus = "��������������������������������";
			static constexpr const char* eng = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		};
		/// <summary>
		/// ���������/����������
		/// </summary>
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
		/// <summary>
		/// ��������� �� �������/����������
		/// </summary>
		class Errors {
		public:
			static constexpr const char* notImplemented = "����������� ���������� ������";
			class IO {
			public:
				static constexpr const char* input = "������ �����, ��������� ����";
				static constexpr const char* format = "������ ��������������, ��������� ������ ������  ��������� ����";
			};
			class Lists {
			public:
				static constexpr const char* empty = "������ ����";
				static constexpr const char* incorrectIndex = "������������ ������";
				static constexpr const char* notFound = "������� �� ������";
			};
		};
		/// <summary>
		/// �����������
		/// </summary>
		class Separators {
		public:
			static constexpr const char* arrow = "->";
			static constexpr const char* column = ";";
			static constexpr const char* space = " ";
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