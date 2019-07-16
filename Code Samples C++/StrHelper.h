#pragma once
/// <summary>
/// ����� ��� ������ �� ��������
/// </summary>
class StrHelper
{
private:
public:
#pragma region ������������
	StrHelper();
	~StrHelper();
#pragma endregion
#pragma region ������
	/// <summary>
	/// ���������� ������ � ������ � ���� ������
	/// </summary>
	/// <param name="lines">������</param>
	/// <returns></returns>
	string Join(vector<string> lines);
	/// <summary>
	/// ���������� ������ � ������ � ���� ������
	/// </summary>
	/// <param name="lines">������</param>
	/// <param name="spacer">�����������</param>
	/// <returns></returns>
	string Join(vector<string> lines, string spacer);
	/// <summary>
	/// �������� ��� ��������� 
	/// ��������� ��������� � ������
	/// </summary>
	/// <param name="s">�������� ������</param>
	/// <param name="search">������� ���������</param>
	/// <param name="replace">������ ��� ���������</param>
	void ReplaceAll(string & s, const string & search, const string & replace);
	/// <summary>
	/// �������� ��� ��������� 
	/// ��������� ��������� � ������
	/// </summary>
	/// <param name="str">�������� ������</param>
	/// <param name="what">��� ��������</param>
	/// <param name="replace">�� ��� ��������</param>
	/// <returns></returns>
	string Replace(string str, string what, string replace);
	/// <summary>
	/// ��������� ������ �� ������������
	/// </summary>
	/// <param name="str">������</param>
	/// <param name="delimiters">������ � �������������</param>
	/// /// <param name="notDelete">������ � ����������, ������� �� ����� �������</param>
	/// <returns>������ �����</returns>
	vector<string> Split(string str, string delimiters, string notDelete);
	/// <summary>
	/// ��������� ������ �� ������������
	/// </summary>
	/// <param name="str">������</param>
	/// <param name="delimiters">������ � �������������</param>
	/// /// <param name="notDelete">������ � ����������, ������� �� ����� �������</param>
	/// <returns></returns>
	//vector<string> Split(string str, const string delimiters, const string notDelete);
	/// <summary>
	/// ��������� ������ �� ������������
	/// </summary>
	/// <param name="str">������</param>
	/// <param name="delimiter">�����������</param>
	vector<string> Split(string str, char delimiter);
	/// <summary>
	/// ��������� �������� �� ������ ��������� �������
	/// </summary>
	/// <param name="str">������ ��� ��������</param>
	/// <param name="collection">������� � ����� ������</param>
	/// <returns></returns>
	bool Contains(string str, string collection);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="str"></param>
	/// <param name="strFind"></param>
	/// <returns></returns>
	bool ContainsStr(string str, string strFind) {
		return (str.find(strFind) != std::string::npos);
	}
	/// <summary>
	/// ��������, �������� �� ������ ������
	/// </summary>
	/// <param name="s">������</param>
	/// <returns>true - ���� �������� ������</returns>
	bool IsNumber(const std::string & s);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="values"></param>
	/// <returns></returns>
	vector<string> RemoveCopies(vector<string> values) {
		string valuesStr = "";
		for (int i = 0; i < values.size(); i++)
			if (!ContainsStr(valuesStr, values[i])) {
				valuesStr += values[i];
				valuesStr += " ";
			}
		values = Split(valuesStr, ' ');
		return values;
	}
	/// <summary>
	/// ������� ��������� ������� ������� � ������
	/// </summary>
	/// <param name="str">������</param>
	/// <param name="c">������ ��� ��������</param>
	/// <returns>������ � ���������� ���������</returns>
	string Remove(string str, char c);
#pragma endregion
};

