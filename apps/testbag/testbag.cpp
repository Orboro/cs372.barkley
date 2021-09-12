//
// File:   testbag.cpp
// Author: Jonathan Barkley
//

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct node
{
	node(T dat) : data(dat), next(nullptr) {}

	T data;
	node* next;
};

template <typename N>
class Bag {
private:
	N* head;
	// More on this shortly
public:
	Bag() : head(nullptr) {}
	void insert(N* aThing) {
		if (head == nullptr) {
			head = aThing;
		}
		else {

			if (head == aThing)
			{
				return;
			}

			N* current = head;
			while (current->next != nullptr)
			{
				if (current == aThing)
				{
					return;
				}
				current = current->next;
			}

			if (current == aThing)
			{
				return;
			}

			current->next = aThing;
		}
	}
	N* pop() {

		if (head == nullptr)
		{
			return nullptr;
		}

		N* back = nullptr;
		N* current = head;
		while (current->next != nullptr)
		{
			back = current;
			current = current->next;
		}

		if (back != nullptr)
		{
			back->next = nullptr;
		}
		else
		{
			head = nullptr;
		}

		return current;
	}
	int size() {
		int result = 0;

		N* current = head;

		while (current != nullptr)
		{
			result += 1;
			current = current->next;
		}

		return result;
	}

	int count(N* aThing)
	{
		int result = 0;

		N* current = head;

		while (current != nullptr)
		{
			if (current->data == aThing->data) {
				result += 1;
			}

			current = current->next;
		}

		return result;
	}
};


template <typename Thing>
class BagWithReceipt {
private:
	// More on this shortly
	std::vector<Thing*> bagVector;
	std::vector<int>		receipts;
	int receiptCount;
public:
	BagWithReceipt() : receiptCount(0) {
	}

	int insert(Thing* aThing) {
		bagVector.push_back(aThing);
		receipts.push_back(receiptCount++);
		return receipts[receipts.size() - 1];
	}

	Thing* remove(int receipt) {
		for (int i = 0;
			i < receipts.size();
			++i)
		{
			if (receipts[i] == receipt)
			{
				Thing* thing = bagVector[i];
				bagVector.erase(bagVector.begin() + i);
				receipts.erase(receipts.begin() + i);
				return thing;
			}
		}

		return nullptr;
	}
	int size() {
		return bagVector.size();
	}
	int count(Thing* aThing) {
		int totalFound = 0;
		int bagvecsize = bagVector.size();
		for (int i = 0; i < bagvecsize; i++) {
			if (bagVector[i] == aThing) {
				totalFound++;
			}
		}
		return totalFound;
	}

};

int main()
{
	node<int>* n0 = new node<int>(0);
	node<int>* n1 = new node<int>(1);
	node<int>* n2 = new node<int>(2);
	node<int>* n3 = new node<int>(345);
	node<int>* n4 = new node<int>(1234987);
	node<int>* n5 = new node<int>(198);
	node<int>* n6 = new node<int>(0);
	node<int>* n7 = new node<int>(0);
	node<int>* n9 = new node<int>(0);
	node<int>* n8 = new node<int>(0);

	Bag<node<int>> bag;

	cout << "Size: " << bag.size() << endl;
	node<int>* popped = bag.pop();


	bag.insert(n0);
	bag.insert(n1);
	cout << "Size: " << bag.size() << endl;

	bag.insert(n2);
	cout << "Size: " << bag.size() << endl;
	bag.insert(n1);
	cout << "Size: " << bag.size() << endl;
	bag.insert(n5);
	bag.insert(n4);
	bag.insert(n8);
	bag.insert(n8);
	bag.insert(n2);
	bag.insert(n9);

	cout << "Size: " << bag.size() << endl;

	popped = bag.pop();
	cout << "Popped " << popped->data << endl;

	cout << "Count of 0: " << bag.count(n8) << endl;


	BagWithReceipt<char> bwr;

	std::vector<int> receipts;

	receipts.push_back(bwr.insert(new char('a')));
	receipts.push_back(bwr.insert(new char('6')));
	receipts.push_back(bwr.insert(new char('s')));
	receipts.push_back(bwr.insert(new char('e')));
	receipts.push_back(bwr.insert(new char('a')));
	receipts.push_back(bwr.insert(new char('d')));
	receipts.push_back(bwr.insert(new char('l')));
	receipts.push_back(bwr.insert(new char('0')));
	receipts.push_back(bwr.insert(new char('q')));
	receipts.push_back(bwr.insert(new char('z')));
	receipts.push_back(bwr.insert(new char('2')));
	receipts.push_back(bwr.insert(new char('y')));
	receipts.push_back(bwr.insert(new char('8')));
	receipts.push_back(bwr.insert(new char('p')));
	receipts.push_back(bwr.insert(new char('e')));

	cout << "Got back" << *(bwr.remove(receipts[10])) << endl;
	receipts.erase(receipts.begin() + 10);
	cout << "Got back" << *(bwr.remove(receipts[13])) << endl;
	receipts.erase(receipts.begin() + 13);
	cout << "Got back" << *(bwr.remove(receipts[10])) << endl;
	receipts.erase(receipts.begin() + 10);
	cout << "Got back" << *(bwr.remove(receipts[7])) << endl;
	receipts.erase(receipts.begin() + 7);
	cout << "Got back" << *(bwr.remove(receipts[10])) << endl;
	receipts.erase(receipts.begin() + 10);
	cout << "Got back" << *(bwr.remove(receipts[6])) << endl;
	receipts.erase(receipts.begin() + 6);
	cout << "Got back" << *(bwr.remove(receipts[8])) << endl;
	receipts.erase(receipts.begin() + 8);
	cout << "Got back" << *(bwr.remove(receipts[1])) << endl;
	receipts.erase(receipts.begin() + 1);
	cout << "Got back" << *(bwr.remove(receipts[1])) << endl;
	receipts.erase(receipts.begin() + 1);
	cout << "Got back" << *(bwr.remove(receipts[3])) << endl;
	receipts.erase(receipts.begin() + 3);
	cout << "Got back" << *(bwr.remove(receipts[3])) << endl;
	receipts.erase(receipts.begin() + 3);
	cout << "Got back" << *(bwr.remove(receipts[2])) << endl;
	receipts.erase(receipts.begin() + 2);
	cout << "Got back" << *(bwr.remove(receipts[1])) << endl;
	receipts.erase(receipts.begin() + 1);
	cout << "Got back" << *(bwr.remove(receipts[0])) << endl;
	receipts.erase(receipts.begin() + 1);



	delete n0;
	delete n1;
	delete n2;
	delete n3;
	delete n4;
	delete n5;
	delete n6;
	delete n7;
	delete n8;
	delete n9;
