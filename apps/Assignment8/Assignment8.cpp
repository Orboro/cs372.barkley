#include <vector>
#include "Tree.h"

template<typename T>
bool binarySearch(T val, std::vector<T> arr, int low, int high)
{
	if (low > high)
		return false;

	if (low == high)
		return val == arr[low];

	int mid = (high + low) / 2;
	if (val == arr[mid])
		return true;

	if (val < arr[mid])
		return binarySearch(val, arr, low, mid - 1);

	return binarySearch(val, arr, mid + 1, high);
}

template<typename T>
bool find(T val, std::vector<T> arr)
{
	return binarySearch(val, arr, 0, arr.size() - 1);
}

int main()
{
	Tree<int> tree(nullptr, 2, nullptr);
}