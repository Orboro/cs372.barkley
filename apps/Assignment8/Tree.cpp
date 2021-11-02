#include "Tree.h"

template<class V>
bool Tree<V>::isEmpty() const
{
	return (root == nullptr);
}

template<class V>
V Tree<V>::getRoot() const
{
	return root->value;
}

template<class V>
Tree<V> Tree<V>::left() const
{
	return Tree<V>(root->left);
}

template<class V>
Tree<V> Tree<V>::right() const
{
	return Tree<V>(root->right);
}

template<class V>
bool Tree<V>::member(V x) const
{
	if (root->value == x)
	{
		return true;
	}

	if (isLeaf())
	{
		return false;
	}

	if (left() != nullptr)
	{
		if (left()->member(x))
		{
			return true;
		}
	}

	if (right() != nullptr)
	{
		if (right()->member(x))
		{
			return true;
		}
	}

	return false;
}

template<class V>
bool Tree<V>::isLeaf() const
{
	return (left() == nullptr && right() == nullptr);
}