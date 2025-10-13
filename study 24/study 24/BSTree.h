#pragma once
#include<iostream>

using namespace std;

template <class K,class V>
struct BSTreeNode
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;
	V _value;
	BSTreeNode(const K& key,const V& value)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
		,_value(value)
	{

	}
};

template <class K,class V>
class BSTree
{
	typedef BSTreeNode<K,V> Node;
public:
	BSTree() = default;
	BSTree(const BSTree<K,V>& t)
	{
		_root = Copy(t._root);
	}
	~BSTree()
	{
		Destory();
	}
	BSTree<K>& operator=(BSTree<K> t)
	{
		swap(_root, t._root);
		return *this;
	}
	bool Insert(const K& key,const V& value)
	{
		if (_root == nullptr)
		{
			_root = new Node(key,value);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key,value);
		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}

	bool Find(const k& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return ture;
			}
		}
		return false;
	}
	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				if (cur->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					if (cur == parent->_left)
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_right;
					}
					delete cur;
				}
				else if(cur->_right == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					if (cur == parent->_left)
					{
						parent->_left = cur->_left;
					}
					else
					{
						parent->_right = cur->_left;
					}
					delete cur;
				}
				else
				{
					Node* pMinRight = cur;
					Node* minRight = cur->_right;
					while (minRight->_left)
					{
						pMinRight = minRight;
						minRight = minRight->_left;
					}
					swap(cur->_key, minRight->_key);
					
					if (pMinRight->_left == minRight)
					{
						pMinRight->_left = minRight->_right;
					}
					else
					{
						pMinRight->_right = minRight->_right;
					}

					delete minRight;
				}
			}
			return true;
		}
		return false;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	void Destory(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		Destory(root->_left);
		Destory(root->_right);
		delete root;
	}
	Node* Copy(Node* root)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		Node* copy = new Node(root->_key,root->_value);
		copy->_left = Copy(root->_left);
		copy->_right = Copy(root->_right);

		return copy;
	}
private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
	Node* _root = nullptr;
};