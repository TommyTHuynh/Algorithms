#pragma once
#include <iostream>

using std::cout;

template <class T>
class TreeNode
{
protected:
	T data;
	TreeNode<T> *llink;
	TreeNode<T> *rlink;
public:
	friend TreeNode *GetNewNode(T data);
	friend void preorder(TreeNode<T> *root);
	friend void inorder(TreeNode<T> *root);
	friend void postorder(TreeNode<T> *root);
	friend TreeNode* insert(TreeNode<T> *root,T item);
};

