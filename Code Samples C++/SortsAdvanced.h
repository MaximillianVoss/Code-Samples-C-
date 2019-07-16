#include "stdafx.h"
#include "Matrix.h"
#pragma once
class SortsAdvanced
{
private:
#pragma region ��������� ��� �����������	
	/// <summary>
	///��������� ��� �������� 
	///����������� ���������� ����������
	/// </summary>
	struct Result {
		/// <summary>
		/// �������� ���������� 
		/// </summary>
		string name;
		/// <summary>
		/// ���������� ���������
		/// </summary>
		int cmpsValue;
		/// <summary>
		/// ���������� ������������
		/// </summary>
		int swapsValue;
		/// <summary>
		/// ������� ��������� � ���������� �����������
		/// </summary>
		/// <param name="_name">���</param>
		/// <param name="cmps">���������� ���������</param>
		/// <param name="swaps">���������� ������������</param>
		Result(string _name, int cmps, int swaps)
		{
			name = _name;
			cmpsValue = cmps;
			swapsValue = swaps;
		}
	};
#pragma endregion
	/// <summary>
	/// ���������� ��� ��������
	/// </summary>
	/// <param name="a">������ �������</param>
	/// <param name="b">������ �������</param>
	/// <param name="cmpsCounter">������� ���������</param>
	/// <returns>true ���� ������ ������ �������</returns>
	bool cmp(int a, int b, int & cmpsCounter);

public:
	SortsAdvanced();
	~SortsAdvanced();
	/// <summary>
	/// ���������� ���������
	/// ���������� ���������� �� ����������� ��������
	/// </summary>
	/// <param name="a">������</param>
	/// <param name="cmpsCounter">������� ���������</param>
	/// <param name="swapsCounter">������� ������������</param>
	void BubbleSort_Abs(vector<int>& a, int & cmpsCounter, int & swapsCounter);
	/// <summary>
	/// ���������� �������
	/// ���������� ���������� �� ����������� ��������
	/// </summary>
	/// <param name="a">������</param>
	/// <param name="cmpsCounter">������� ���������</param>
	/// <param name="swapsCounter">������� ������������</param>
	void SelectSort_Abs(vector<int>& a, int & cmpsCounter, int & swapsCounter);
	/// <summary>
	/// ���������� ���������
	/// ���������� ���������� �� ����������� ��������
	/// </summary>
	/// <param name="a">������</param>
	/// <param name="cmpsCounter">������� ���������</param>
	/// <param name="swapsCounter">������� ������������</param>
	void Insertsort_Abs(vector<int>& a, int & cmpsCounter, int & swapsCounter);
	/// <summary>
	/// ���������� �����
	/// ���������� ���������� �� ����������� ��������
	/// </summary>
	/// <param name="a">������</param>
	/// <param name="cmpsCounter">������� ���������</param>
	/// <param name="swapsCounter">������� ������������</param>
	void ShellSort_Abs(vector<int>& a, int & cmpsCounter, int & swapsCounter);
	/// <summary>
	/// ������� ����������
	/// ���������� ���������� �� ����������� ��������
	/// </summary>
	/// <param name="a">������</param>
	/// <param name="cmpsCounter">������� ���������</param>
	/// <param name="swapsCounter">������� ������������</param>
	void QSort_Abs(int * a, int size, int & cmpsCounter, int & swapsCounter);
	/// <summary>
	/// �������� ��������� 
	/// ��� ����������� ������
	/// </summary>
	void Test();
	/// <summary>
	/// �������� ������� �� 
	/// ����������� ��� ����������
	/// </summary>
	/// <param name="results">���������� ����������</param>
	/// <param name="message">�������</param>
	void PrintTable(vector<Result> results, string message);
	/// <summary>
	/// ������ ���������� 
	/// ��������� � ������������
	/// </summary>
	/// <param name="cmps">���������� ���������</param>
	/// <param name="swaps">���������� ������������</param>
	void PrintStatistics(int cmps, int swaps);
};

