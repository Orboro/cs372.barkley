#pragma once

#include <string>

template<class V>
class Tree
{
private:
	struct Node {
		Node(V v, Node* l, Node* r) : value(v), left(l), right(r) {}

		V value;
		Node* left;
		Node* right;
	};

	Node* root;
public:
	Tree() {}
	explicit Tree(Node* node) : root(node) {}

	bool isEmpty() const;
	V getRootValue() const;
	Tree left() const;
	Tree right() const;
	bool member(V x) const;
	bool isLeaf() const;

	void insert(V x);

	void PrintPreOrder(std::string pad = "");
	void PrintInOrder(std::string pad = "");
	void PrintPostOrder(std::string pad = "");
};

template<class V>
bool Tree<V>::isEmpty() const
{
	return (root == nullptr);
}

template<class V>
V Tree<V>::getRootValue() const
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
	if (root == nullptr)
	{
		return false;
	}

	if (root->value == x)
	{
		return true;
	}

	if (isLeaf())
	{
		return false;
	}

	if ( !left().isEmpty() )
	{
		if (left().member(x))
		{
			return true;
		}
	}

	if ( !right().isEmpty() )
	{
		if (right().member(x))
		{
			return true;
		}
	}

	return false;
}

template<class V>
bool Tree<V>::isLeaf() const
{
	return ( left().isEmpty() && right().isEmpty() );
}

template<class V>
void Tree<V>::insert(V x)
{
	if (isEmpty())
	{
		root = new Node(x, nullptr, nullptr);
		return;
	}

	if (x < root->value)
	{
		if (root->left)
		{
			Tree<V> leftTree(root->left);
			leftTree.insert(x);
		}
		else
		{
			root->left = new Node(x, nullptr, nullptr);
		}
	}
	else
	{
		if (root->right)
		{
			Tree<V> leftTree(root->right);
			leftTree.insert(x);
		}
		else
		{
			root->right = new Node(x, nullptr, nullptr);
		}
	}

	return;
}

template<class V>
void Tree<V>::PrintPreOrder(std::string pad)
{
	printf("%s%d\n", pad.c_str(), getRootValue());

	auto left = this->left();
	auto right = this->right();

	if (!left.isEmpty())
	{
		left.PrintPreOrder(pad + "  ");
	}

	if (!right.isEmpty())
	{
		right.PrintPreOrder(pad + "  ");
	}
}

template<class V>
void Tree<V>::PrintInOrder(std::string pad)
{

	auto left = this->left();
	auto right = this->right();

	if (!left.isEmpty())
	{
		left.PrintInOrder(pad + "  ");
	}

	printf("%s%d\n", pad.c_str(), getRootValue());

	if (!right.isEmpty())
	{
		right.PrintInOrder(pad + "  ");
	}
}

template<class V>
void Tree<V>::PrintPostOrder(std::string pad)
{

	auto left = this->left();
	auto right = this->right();

	if (!left.isEmpty())
	{
		left.PrintPostOrder(pad + "  ");
	}

	if (!right.isEmpty())
	{
		right.PrintPostOrder(pad + "  ");
	}

	printf("%s%d\n", pad.c_str(), getRootValue());
}