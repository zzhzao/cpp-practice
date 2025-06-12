#pragma once
#include<iostream>
using namespace std;
template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data = T())
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _data(data)
		, _bf(0)
	{
	}

	AVLTreeNode<T>* _pLeft;
	AVLTreeNode<T>* _pRight;
	AVLTreeNode<T>* _pParent;
	T _data;
	int _bf;   // 节点的平衡因子
};


// AVL: 二叉搜索树 + 平衡因子的限制
template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		: _pRoot(nullptr)
	{
	}

	// 在AVL树中插入值为data的节点
	bool Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_data < data)
			{
				parent = cur;
				cur = cur->_pRight;
			}
			else if (cur->_data > data)
			{
				parent = cur;
				cur = cur->_pLeft;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(data);
		if (parent->_data < data)
		{
			parent->_pRight = cur;
		}
		else
		{
			parent->_pLeft = cur;
		}
		cur->_pParent = parent;
		while (parent)
		{
			if (parent->_pLeft = cur)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					//右旋
					RotateR(parent);
				}
				if (parent->_bf == -2 && cur->_bf == 1)
				{
					//右左
					RotateRL(parent);
				}
				if (parent->_bf == 2 && cur->_bf == -1)
				{
					//左右
					RotateLR(parent);
				}
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					//左旋
					RotateL(parent);
				}

				else
				{
					assert(false);
				}
				break;
			}
			return true;
		}
	}


private:

	// 右单旋
	void RotateR(Node* parent)
	{
		Node* subL = parent->_pLeft;
		Node* subLR = subL->_pRight;

		parent->_pLeft = subLR;
		if (subLR)
		{
			subLR->_pParent = parent;
		}
		Node* pparent = parent->_pParent;
		subL->_pRight = parent;
		parent->_pParent = subL;

		if (pparent == nullptr)
		{
			_root = subL;
			subL->_pParent = nullptr;
		}
		else
		{
			if (pparent->_pLeft == parent)
			{
				pparent->_pLeft = subL;
				subL->_pParent = pparent;
			}
			else if (pparent->_pRight == parent)
			{
				pparent->_pRight = subL;
				subL->_pParent = pparent;
			}
			parent->_bf = subL->_bf = 0;
		}
	}
	// 左单旋
	void RotateL(Node* parent)
	{
		Node* subR = parent->_pRight;
		Node* subRL = subR->_pLeft;
		parent->_pRight = subRL;
		if (subRL)
		{
			subRL->_pParent = parent;
		}
		Node* pparent = parent->_pParent;
		subR->_pLeft = parent;
		parent->_pParent = subR;
		if (pparent == nullptr)
		{
			_root = subR;
			subR->_pParent = nullptr;
		}
		else
		{
			if (pparent->_pLeft == parent)
			{
				pparent->_pLeft = subR;
			}
			else
			{
				pparent->_pRight = subR;
			}
			subR->_pParent = pparent;
		}
		parent->_bf = subR->_bf = 0;
	}
	// 右左双旋
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_pRight;
		Node* subRL = subR->_pLeft;
		int bf = subRL->_bf;
		RotateR(subR);
		RotateL(parent);
		if (bf == 0)
		{
			subR->_bf = 0;
			subRL->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == 1)
		{
			subR->_bf = 0;
			subRL->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1)
		{
			subR->_bf = 1;
			subRL->_bf = 0;
			parent->_bf = 0;
		}
		else

		{
			assert(false);
		}
	}
	// 左右双旋
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_pLeft;
		Node* subLR = subL->_pRight;
		int bf = subLR->_bf;
		RotateL(parent->_pLeft);
		RotateR(parent);
		if (bf == 0)
		{
			subL->_bf = 0;
			subLR->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == -1)
		{
			subL->_bf = 0;
			subLR->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 1)
		{
			subL->_bf = -1;
			subLR->_bf = 0;
			parent->_bf = 0;
		}
		else

		{
			assert(false);
		}
	}


private:
	Node* _root = nullptr;
};
