#pragma once
class BinarySearch
{
public:
	BinarySearch();
	~BinarySearch();
	/// <summary>
	/// ���� ��������� ����� 
	/// � �������
	/// </summary>
	/// <param name="a">������</param>
	/// <param name="value">������� ��������</param>
	/// <param name="start">������ �������</param>
	/// <param name="end">����� �������</param>
	/// <returns></returns>
	bool Search(int *a, int value, int start, int end);
};

