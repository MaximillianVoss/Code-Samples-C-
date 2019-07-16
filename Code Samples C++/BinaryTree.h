#include "TreeNode.h"
#pragma once
/// <summary>
/// ��������� �������� ������
/// </summary>
class BinaryTree
{
public:
	/// <summary>
	/// ������� ������ 
	/// �� ���������� �������
	/// ������ ������� ������������� �� �����������
	/// </summary>
	/// <param name="data">������</param>
	/// <param name="start">��������� ������</param>
	/// <param name="end">�������� ������</param>
	BinaryTree(int *data, int from, int n);
	BinaryTree();
	~BinaryTree();
	/// <summary>
	/// �������� ������ ������
	/// </summary>
	/// <returns>��������� �� ������ ������</returns>
	TreeNode* GetRoot();
private:
	TreeNode *root;
	/// <summary>
	/// ������� ������ 
	/// �� ���������� �������
	/// ������ ������� ������������� �� �����������
	/// </summary>
	/// <param name="data">������</param>
	/// <param name="start">��������� ������</param>
	/// <param name="end">�������� ������</param>
	/// <returns>��������� �� ������ ������</returns>
	TreeNode * MakeTree(int *data, int start, int end);
};

