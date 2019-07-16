#pragma once
class ArrayHelper
{
public:
	ArrayHelper();
	~ArrayHelper();

	template<typename T>
	/// <summary>
	/// ��������� ��� �������� � �������
	/// </summary>
	/// <param name="a">������</param>
	/// <param name="count">����� ���������</param>
	/// <returns></returns>
	T Sum(const T * a, int count);

	template <typename T>
	/// <summary>
	/// ��������� ��� �������� � �������
	/// </summary>
	/// <param name="a">������</param>
	/// <returns></returns>
	T Sum(vector<T> a);

	template<typename T>
	/// <summary>
	/// ������� ������� 
	/// �������������� ���������
	/// </summary>
	/// <param name="a">������</param>
	/// <param name="count">����� ���������</param>
	/// <returns></returns>
	float Avg(const T * a, int count);

	template <typename T>
	/// <summary>
	/// ������� ������� 
	/// �������������� ���������
	/// </summary>
	/// <param name="a">������</param>
	/// <returns></returns>
	float Avg(vector<T>a);

	template<typename T>
	/// <summary>
	/// 
	/// </summary>
	/// <param name="a"></param>
	/// <param name="count"></param>
	/// <returns></returns>
	T GetMax(const T * a, int count);

	template<typename T>
	/// <summary>
	/// 
	/// </summary>
	/// <param name="a"></param>
	/// <returns></returns>
	T GetMax(vector<T> a);

	template<typename T>
	/// <summary>
	/// ������� ������� � �������
	/// </summary>
	/// <param name="a">������</param>
	/// <param name="count">����� ���������</param>
	/// <returns></returns>
	T GetMin(const T * a, int count);

	template<typename T>
	/// <summary>
	/// ������� ������� � �������
	/// </summary>
	/// <param name="a">������</param>
	/// <returns></returns>
	T GetMin(vector<T> a);
};

