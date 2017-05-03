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
struct AVLNode
{
	AVLNode<T> *llink;
	AVLNode<T> *rlink;
	T key;
	int balance;
};

template <class T>
class AVL
{
private:
	AVLNode<T> *root;
	AVLNode<T> *findNode(T item, AVLNode<T> *root);
	AVLNode *findParent(T item, AVLNode<T> *root);
	int getHeight(AVLNode<T> *root);
	int getBalance(AVLNode<T> *root);
	void preorderHelper(AVLNode<T> *root);
	void inorderHelper(AVLNode<T> *root);
	void postorderHelper(AVLNode<T> *root);
	void leftRotate(AVLNode<T> *root);
	void rightRotate(AVLNode<T> *root);
public:
	AVL<T>();
	~AVL<T>();
	bool find(T item);
	void insert(T item);
	void remove(T item);
	void preorder();
	void inorder();
	void postorder();
	void treePrint();
};

