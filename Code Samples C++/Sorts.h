#pragma once
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstddef>
#include <iterator>
/// <summary>
/// �������� ����������� ����������
/// </summary>
class Sorts
{
private:
	/// <summary>
	/// ������� ��������� ��������� �������
	/// </summary>
	/// <param name="x1"></param>
	/// <param name="x2"></param>
	/// <returns></returns>
	int Compare(const void * a, const void * b);
public:
	Sorts();
	~Sorts();
	/// <summary>
	/// ���������� ���������: 
	/// </summary>
	/// <param name="a">������</param>
	/// <param name="length">������</param>
	void BubbleSort(int * a, size_t length);
	/// <summary>
	/// ������� ����������
	/// </summary>
	/// <param name="a">������</param>
	/// <param name="n">������</param>
	void QuickSort(int * a, size_t n);
	/// <summary>
	/// ���������� ���������
	/// </summary>
	/// <param name="a"></param>
	/// <param name="n"></param>
	void InsertionSort(int * a, size_t n);
	/// <summary>
	/// �������� ��������� ��� ���������� � ������
	/// � ������� ������� ���������
	/// </summary>
	void Test();
	template<typename T>
	/// <summary>
	/// ���������� ��������
	/// </summary>
	/// <param name="array">������</param>
	/// <param name="size">������</param>
	void MergerSort(T array[], size_t size);
};

