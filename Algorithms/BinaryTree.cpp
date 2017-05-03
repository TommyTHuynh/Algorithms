#include "BinaryTree.h"

template <class T>
void preorder(TreeNode<T>* root) /*<root><left><right>*/
{
	if (root == NULL) return;
	cout << root->data << " ";
	preorder(root->llink);
	preorder(root->rlink);
}

template <class T>
void inorder(TreeNode<T>* root) /*<left><root><right>*/
{
	if (root == NULL) return;
	inorder(root->llink);
	cout << root->data << " ";
	inorder(root->rlink);
}

template <class T>
void postorder(TreeNode<T>* root) /*<left><right><root>*/
{
	if (root == NULL) return;
	postorder(root->llink);
	postorder(root->rlink);
	cout << root->data << " ";
}

template <class T>
TreeNode<T> *GetNewNode(T data)
{
	TreeNode<T> node = new TreeNode();
	node->data = data;
	node->llink = NULL;
	node->rlink = NULL;
	return node;
}

template <class T>
TreeNode<T>* insert(TreeNode<T> *root, T item) 
{
	if (root == NULL)
		root = GetNewNode(item);
	else if (item < root->data)
		root->llink = insert(root, item);
	else if (item > root->data)
		root->rlink = insert(root, item);
	return root;
}

template <class T>
bool search(TreeNode<T> *root, T item)
{
	if (root == NULL) return false;
	else if (root->data == item) return true;
	else if (item < root->data) return search(root->llink, item);
	else return search(root->rlink, item);
}
