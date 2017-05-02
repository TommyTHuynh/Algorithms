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
void inorder(TreeNode<T>* root) /*<left><right><root>*/
{
	if (root == NULL) return;
	inorder(root->llink);
	inorder(root->rlink);
	cout << root->data << " ";
}


template <class T>
void postorder(TreeNode<T>* root) /*<left><root><right>*/
{
	if (root == NULL) return;
	postorder(root->llink);
	cout << root->data << " ";
	postorder(root->rlink);
}
