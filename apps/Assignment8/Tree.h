#pragma once
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

	explicit Tree(Node* node) : root(node) {}
	Node* root;
public:
	Tree() {}
	Tree(Tree* lft, V value, Tree* rgt) :
		root(new Node(value, lft->root, rgt->root)) {}
	bool isEmpty() const;
	V getRoot() const;
	Tree left() const;
	Tree right() const;
	bool member(V x) const;
	bool isLeaf() const;
};