#pragma once
/// <summary>
/// �������� ������� ������
/// </summary>
class TreeNode
{
public:
	/// <summary>
	/// �������� ������ (����) 
	/// </summary>
	int  key;
	/// <summary>
	/// ��������� �� �������   
	/// </summary>
	struct TreeNode *left, *right;
	TreeNode();
	/// <summary>
	/// ����������� � �����������
	/// </summary>
	/// <param name="_key">���� �������</param>
	/// <param name="left">����� �������</param>
	/// <param name="right">������ �������</param>
	TreeNode(int _key, TreeNode *_left, TreeNode *_right);
	~TreeNode();
};

