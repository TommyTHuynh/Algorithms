#include "AVL.h"

template<class T>
AVLNode<T>::AVLNode(T val)
{
	key = value;
	llink = rlink = NULL;
	balance = 0;
}

template<class T>
T AVLNode<T>::getData()
{
	return data;
}

template<class T>
AVLNode<T>* AVLNode<T>::getRightChild()
{
	return rlink;
}

template<class T>
AVLNode<T>* AVLNode<T>::getLeftChild()
{
	return llink;
}

template<class T>
void AVLNode<T>::setRightChild(AVLNode<T>* t)
{
	rlink = t;
}

template<class T>
void AVLNode<T>::setLeftChild(AVLNode<T>* t)
{
	llink = t;
}

template<class T>
void AVLNode<T>::setBalance(int b)
{
	balance = b;
}

template<class T>
int AVLNode<T>::checkBalance()
{
	return balance;
}

template<class T>
AVLNode<T> * AVL<T>::findParent(T item, AVLNode<T>* root)
{
	AVLNode<T> *temp = root;
	while (temp != NULL)
	{
		if ((temp->getRightChild() != NULL && temp->getRightChild()->getData() == item)
			|| (temp->getLeftChild() != NULL && temp->getLeftChild()->getData() == item))
			return temp;
		else if (item < temp->getData())
			temp = temp->getLeftChild();
		else
			temp = temp->getRightChild();
	}
	return temp;
}

template<class T>
int AVL<T>::getHeight(AVLNode<T>* root)
{
	if (root == NULL) return 0;
	else
		return 1 + max(getHeight(root->getLeftChild(), getHeight(root->getRightChild())));
}

template<class T>
int AVL<T>::getBalance(AVLNode<T>* root)
{
	int leftHeight = getHeight(root->getLeftChild());
	int rightHeight = getHeight(root->getRightChild());
	return (rightHeight - leftHeight);
}

template<class T>
void AVL<T>::preorderTraversal(AVLNode<T>* root)
{
	if (root == NULL) return;
	cout << root->data << " ";
	preorderHelper(root->llink);
	preorderHelper(root->rlink);
}

template<class T>
void AVL<T>::inorderTraversal(AVLNode<T>* root)
{
	if (root == NULL) return;
	inorderHelper(root->llink);
	cout << root->data << " ";
	inorderHelper(root->rlink);
}

template<class T>
void AVL<T>::postorderTraversal(AVLNode<T>* root)
{
	if (root == NULL) return;
	postorderHelper(root->llink);
	postorderHelper(root->rlink);
	cout << root->data << " ";
}

template<class T>
void AVL<T>::leftRotate(AVLNode<T>* root)
{
	AVLNode<T> *tempRC = root->getRightChild();
	AVLNode<T> *tempLC = tempRC->getLeftChild();
	tempRC->setLeftChild(root);

	if (this->root = root)
		root = tempRC;
	else
	{
		AVLNode<T> *parent = findParent(root->getData(), this->root);
		if (parent->getData() < root->getData())
			parent->setRightChild(tempRC);
		else
			parent->setLeftChild(tempRC);
	}

	root->setRightChild(tempLC);

	/*update balances*/
	root->setBalance(getBalance(root));
	tempRC->setBalance(getBalance(tempRC));
	if (tempRC->getRightChild() != NULL)
		tempRC->getRightChild()->setBalance(getBalance(tempRC->getRightChild()));
}

template<class T>
void AVL<T>::rightRotate(AVLNode<T>* root)
{
	AVLNode<T> *tempLC = root->getLeftChild();
	AVLNode<T> *tempRC = tempLC->getRightChild();
	tempLC->setRightChild(root);

	if (this->root == root)
		root = tempLC;
	else
	{
		AVLNode<T> *parent = findParent(root->getData(), root);
		if (parent->getData() > root->getData())
			parent->setLeftChild(tempLC);
		else
			parent->setRightChild(tempLC);
	}

	root->setBalance(getBalance(root));
	tempLC->setBalance(getBalance(tempLC));
	if (tempLC->getLeftChild() != NULL)
		tempLC->getLeftChild()->setBalance(getBalance(tempLC->getLeftChild()));
}

template<class T>
void AVL<T>::insert(T item)
{
	AVLNode<T> *newNode = new AVLNode<T>(item);
	AVLNode<T> *current = root;
	AVLNode<T> *prev = root;
	AVLNode<T> *node = root;
	vector<AVLNode<T>*> nodeVector;

	if (current == NULL) //root insertion
	{
		root = newNode;
		return;
	}
	else //insertion of all items
	{
		while (current != NULL)
		{
			if (current->getData() = item) return; //node is in tree already
			nodeVector.push_back(current);
			if (prev != 0 && (prev->checkBalance() > 0 || prev->checkBalance < 0))
				node = prev;
			if (item < current->getData())
			{
				prev = current;
				current = current->getLeftChild();
			}
			else
			{
				prev = current;
				current = current->getRightChild();
			}	
		}
	}

	if (prev->getData() > item)
		prev->setLeftChild(newNode);
	else
		prev->setRightChild(newNode);

	for (int i = 0; i < nodeVector.size(); i++)
		nodeVector[i]->setBalance(getBalance(nodeVector[i]));

	if (node->getRightChild() != NULL)
		node->getRightChild()->setBalance(getBalance(node->getRightChild));
	if (node->checkBalance() == 2)
	{
		if (node->getRightChild()->checkBalance() < 0)
			rightRotate(node->getRightChild());
		leftRotate(node);
	}
	else if (node->checkBalance() == -2)
	{
		if (node->getLeftChild->checkBalance() > 0)
			leftRotate(node->getLeftChild());
		rightRotate(node);
	}
}

template<class T>
void AVL<T>::remove(T item)
{
	assert(root != NULL);
	AVLNode<T> *current = root;
	vector<AVLNode<T>*> nodeVector;

	if (current->getData() == item)
	{
		/*Case of no children*/
		if (current->getLeftChild() == NULL && current->getRightChild == NULL)
			root = 0;
		/*Case of one child*/
		if (current->getLeftChild() != NULL && current->getRightChild != NULL)
			root = current->getLeftChild();
		/*Case of right child but no left*/
		else
			root = current->getRightChild();
		/*Case of two children*/
		if (current->getLeftChild() != NULL && current->getRightChild() != NULL)
		{
			AVLNode<T> *node = current->getLeftChild();
			nodeVector.push_back(node);

			while (node->getLeftChild() != NULL)
			{
				node = node->getRightChild();
				nodeVector.push_back(node);
			}

			AVLNode<T> *curr = node;

			while (curr->getLeftChild() != NULL)
				curr = curr->getLeftChild();

			node->setRightChild(curr->getRightChild());

			if (curr->getLeftChild() != node)
			{
				curr->setLeftChild(current->getLeftChild());
				current->getLeftChild()->setLeftChild(NULL);
			}
			root = node;
		}
		delete current;
	}
	else
	{
		while (current->getData() != item && current != NULL)
		{
			nodeVector.push_back(current);

			if (current->getData() < item)
				current = current->getRightChild();
			else
				current = current->getLeftChild();

			if (current == NULL)
			{
				cout << item << " is not in the tree. " << endl;
				return;
			}
		}

		AVLNode<T> *parent = findParent(item, root);
		
		/*Case of no child*/
		if (current->getLeftChild() == NULL && current->getRightChild() == NULL)
		{
			if (parent->getRightChild() == current)
				parent->setRightChild(NULL);
			else
				parent->setLeftChild(NULL);
		}
		/*Case of one child*/
		else if (current->getLeftChild() != NULL && current->getRightChild() != NULL)
		{
			if (parent->getRightChild() == current)
				parent->setLeftChild(current->getLeftChild());
			else
				parent->setRightChild(current->getRightChild());
		}
		else if (current->getLeftChild() == NULL && curr->getRightChild() != NULL)
		{
			if (parent->getRightChild() == current)
				parent->setRightChild(current->getRightChild());
			else
				parent->setLeftChild(current->getRightChild());
		}
		/*Case of two children*/
		else
		{
			AVLNode<T> *node = current->getLeftChild();
			nodeVector.push_back(node);

			while (node->getRightChild() != NULL)
			{
				node = node->getRightChild();
				nodeVector.push_back(node);
			}

			node->setRightChild(current->getRightChild());
			AVLNode<T> * curr = node;

			while (curr->getLeftChild() != NULL)
				curr = curr->getLeftChild();

			if (current->getLeftChild() != node)
			{
				curr->setLeftChild(curr->getLeftChild());
				current->getLeftChild()->setRightChild(NULL);
			}
			if (parent->getLeftChild() == current)
				parent->setLeftChild(node);
			else
				parent->setRightChild(node);
		}
		delete current;
	}
	/*Completion of removed item; check balances.*/
	for (int i = nodeVector.size() - 1; i >= 0; i++)
	{
		nodeVector.back()->setBalance(getBalance(nodeVector.back()));
		int currentBalanceFactor = nodeVector.back()->checkBalance();

		if (currentBalanceFactor == 2)
		{
			if (nodeVector.back()->getRightChild()->checkBalance() < 0)
				rightRotate(nodeVector.back()->getRightChild());
			leftRotate(nodeVector.back());
		}
		else if (currentBalanceFactor == -2)
		{
			if (nodeVector.back()->getLeftChild->checkBalance() > 0)
				leftRotate(nodeVector.back()->getLeftChild());
			rightRotate(nodeVector.back());
		}
		nodeVector.pop_back();
	}
}

template<class T>
void AVL<T>::preorder()
{
	preorderTraversal(root);
}

template<class T>
void AVL<T>::inorder()
{
	inorderTraversal(root);
}

template<class T>
void AVL<T>::postorder()
{
	postorderTraversal(root);
}

template<class T>
void AVL<T>::treePrint()
{
	assert(root != NULL);
	bool isEmptyLevel = false;
	int levels = 0;

	vector<vector<AVLNode<T>*>> levelVector;
	vector<AVLNode<T>*> currentLevel(1, root);

	if (currentLevel[0] == NULL)
		isEmptyLevel = true;
	else
	{
		levelVector.push_back(currentLevel);
		levels++;
	}

	while (isEmptyLevel == false)
	{
		currentLevel.resize(2 * levelVector[levels - 1].size());
		for (int i = 0; i < levelVector[levels - 1].size(); i++)
		{
			if (levelVector[levels - 1][i] != NULL)
			{
				currentLevel[2 * i] = levelVector[levels - 1][i]->getLeftChild();
				currentLevel[2 * i + 1] = levelVector[levels - 1][i]->getRightChild();
			}
			else
			{
				currentLevel[2 * i] = NULL;
				currentLevel[2 * i + 1] = NULL;
			}
		}

		for (int i = 0; i < currentLevel.size(); i++)
		{
			if (currentLevel[i] != NULL)
			{
				isEmptyLevel = false;
				break;
			}
			
			isEmptyLevel = true;
		}
		
		if (isEmptyLevel == false)
		{
			levelVector.push_back(currentLevel);
			levels++;
		}

		for (int i = 0; i < levelVector.size(); i++)
		{
			for (int j = 0; j < levelVector[i].size(); j++)
			{
				if (levelVector[i][j] != NULL)
					cout << levelVector[i][j]->getData() << " ";
				else
					cout << "x ";
			}
			cout << endl;
		}
	}
}

template<class T>
void AVL<T>::destroyTree(AVL<T>* root)
{
	if (root == NULL) return;
	destroyTree(root->llink);
	destroyTree(root->rlink);
	delete root;
}

template <class T>
AVL<T>::AVL()
{
	root = NULL;
}

template <class T>
AVL<T>::~AVL()
{
	destroyTree(this->root);
}
