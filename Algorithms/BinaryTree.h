#pragma once
#include <iostream>

using std::cout;

template <class T>
struct TreeNode
{
protected:
	T data;
	TreeNode<T> *llink;
	TreeNode<T> *rlink;
public:
	friend void preorder(TreeNode<T> *root); /*<root><left><right>*/
	friend void inorder(TreeNode<T> *root); /*<left><root><right>*/
	friend void postorder(TreeNode<T> *root); /*<left><right><root>*/
	friend TreeNode *GetNewNode(T data); 
	friend TreeNode* insert(TreeNode<T> *root,T item);
	friend bool search(TreeNode<T> *root, T item);  
};

