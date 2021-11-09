#include <vector>
#include <random>
#include <memory>
#include <chrono>
#include "Tree.h"

using namespace std;

struct homework
{
	size_t size;
	vector<int> arr;
	Tree<int> tree;
};

void buildRecursive(Tree<int>* tree, vector<int>* arr, int left, int right)
{
	if (left > right)
		return;

	int mid = (left + right) / 2;

	int val = arr->at(mid);

	// Binary search trees only have one copy of an element.
	if (!tree->member(val))
	{
		tree->insert(arr->at(mid));
	}

	if (left == right)
		return;

	buildRecursive(tree, arr, left, mid-1 );
	buildRecursive(tree, arr, mid+1, right);
}

void buildTree(homework* sh)
{
	Tree<int> *tree = &sh->tree;
	buildRecursive(tree, &sh->arr, 0, sh->size-1);

}

shared_ptr<homework> buildHomework(int size)
{
	shared_ptr<homework> result = make_shared<homework>();
	result->size = size;
	result->arr.reserve(size);

	random_device device;
	mt19937 mt(device());
	uniform_real_distribution<float> dist(0, 100);

	for (int i = 0; i < result->arr.capacity(); ++i)
	{
		int val = (int)dist(mt);
		result->arr.push_back(val);

		//Case 2: entering as we generate numbers.
		//result->tree.insert(val);
	}

	auto comp = [](int i, int j) {return(i < j); };

	std::sort(result->arr.begin(), result->arr.end(), comp);

	//Case 3: insert balanced
	buildTree(result.get());

	//Case 1: inserting already sorted
	/*for (int i : result->arr)
	{
		result->tree.insert(i);
	}*/

	return result;
}

void print_pre(homework* sh)
{
	sh->tree.PrintPreOrder();
}

void print_in(homework* sh)
{
	sh->tree.PrintInOrder();
}

void print_post(homework* sh)
{
	sh->tree.PrintPostOrder();
}

template<typename T>
bool binarySearch(T val, vector<T> arr, int low, int high, /*out*/ int* index)
{
	if (low > high)
		return false;

	if (low == high)
	{
		if (val == arr[low])
		{
			*index = low;
			return true;
		}

		return false;
	}

	int mid = (high + low) / 2;
	if (val == arr[mid])
	{
		*index = mid;
		return true;
	}

	if (val < arr[mid])
		return binarySearch(val, arr, low, mid - 1, index);

	return binarySearch(val, arr, mid + 1, high, index);
}

template<typename T>
bool find(T val, vector<T> arr, /*out*/ int* index)
{
	return binarySearch(val, arr, 0, arr.size() - 1, index);
}

int main()
{
	auto sh = buildHomework(32);

	printf("pre-order\n");
	print_pre(sh.get());

	printf("in-order\n");
	print_in(sh.get());

	printf("post-order\n");
	print_post(sh.get());

	int index;
	int toFind = 32;
	if (find(toFind, sh->arr, &index))
	{
		printf("found %d at index %d", toFind, index);
	}
	else
	{
		printf("Did not find %d\nArray:\n", toFind);

		for (int i : sh->arr)
		{
			printf("%d\n", i);
		}
	}
}