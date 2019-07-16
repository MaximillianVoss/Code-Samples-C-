#include "stdafx.h"
#pragma once

/// <summary>
/// ����������� �������
/// ������� ������� ���������� �������
/// � ���������� ����
/// </summary>
class Matrix
{
private:

public:
	/// <summary>
	/// ��� �������
	/// </summary>
	enum MatrixType {
		/// <summary>
		/// �� ������� �������� ����� 0
		/// � ��������� ������ 1
		/// </summary>
		zeroDiagonal,
		/// <summary>
		/// �� ������� �������� ����� 1
		/// � ��������� ������ 0
		/// </summary>
		oneDiagonal,
		/// <summary>
		/// ��������� 1
		/// </summary>
		one,
		/// <summary>
		/// ��������� 0
		/// </summary>
		zero,
		/// <summary>
		/// �������� ��������� �����:
		/// ������������� � �������������
		/// </summary>
		randomAll,
		/// <summary>
		/// �������� ������ ������������� �����
		/// </summary>
		randomPositive,
		/// <summary>
		/// ����������� ������� 
		/// ��� ���� ��������
		/// </summary>
		check
	};
	/// <summary>
	/// ������� �������, ����������� ���������� �������
	/// </summary>
	/// <param name="n">����� �����</param>
	/// <param name="m">����� ��������</param>
	Matrix(int n, int m, Matrix::MatrixType type);
	/// <summary>
	/// ����������� �� ���������
	/// </summary>
	Matrix();
	/// <summary>
	/// ����������
	/// </summary>
	~Matrix();
	/// <summary>
	/// ���������� �������
	/// </summary>
	vector<vector<int>> matrix;
	/// <summary>
	/// ������� �������, ����������� ���������� �������
	/// </summary>
	/// <param name="rowsCount">����� �����</param>
	/// <param name="columnCount">����� ��������</param>
	/// <returns></returns>
	void CreateMatrix(int rowsCount, int columnCount, Matrix::MatrixType type);
	/// <summary>
	/// ��������� ��� ������� �� �����������
	/// ������� ����� ���� ������ ������� �� �������
	/// </summary>
	/// <param name="m">������� ��� �������</param>
	/// <returns></returns>
	void Add(Matrix m);
	/// <summary>
	/// ������������ ������ � ������� � �������
	/// </summary>
	/// <param name="m">�������</param>
	void Rotate(Matrix& m);
};