#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>

using std::cout;
using std::endl;
using std::max;
using std::vector;

template <class T>
class AVLNode
{
private:
	AVLNode<T> *llink;
	AVLNode<T> *rlink;
	T data;
	int balance;
public:
	AVLNode<T>(T val);
	T getData();
	AVLNode<T> *getRightChild();
	AVLNode<T> *getLeftChild();
	void setRightChild(AVLNode<T>* t);
	void setLeftChild(AVLNode<T>* t);
	void setBalance(int b);
	int checkBalance();
};

template <class T>
class AVL
{
private:
	AVLNode<T> *root;
	AVLNode *findParent(T item, AVLNode<T> *root);
	int getHeight(AVLNode<T> *root);
	int getBalance(AVLNode<T> *root);
	void preorderTraversal(AVLNode<T> *root);
	void inorderTraversal(AVLNode<T> *root);
	void postorderTraversal(AVLNode<T> *root);
	void leftRotate(AVLNode<T> *root);
	void rightRotate(AVLNode<T> *root);
public:
	AVL<T>();
	~AVL<T>();
	void insert(T item);
	void remove(T item);
	void preorder();
	void inorder();
	void postorder();
	void treePrint();
	void destroyTree(AVL<T> * root);
};


