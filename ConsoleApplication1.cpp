#include <iostream>
using namespace std;

#define SIZE 20
#define LIMITSIZE 10

/// <summary>
/// Given: 
/// 1. Allocate a large array of integers in the heap, 
/// storing a pointer to that data. 
/// 2. Initialize a second pointer
/// to the same location in memory.
/// When: 
/// 3. An Array delete of the first pointer
/// Then:
/// 4. Print the first ten integers
/// pointed to by the second pointer
/// </summary>
void caseOne()
{
    int* ptr1 = new int[SIZE]; // 1
    int* ptr2 = ptr1; // 2

    delete[] ptr1; // 3

    for (int i = 0; i < LIMITSIZE; i++) // 4
    {
        cout << *(ptr2 + i) << endl;
    }
}

/// <summary>
/// Given: 
/// 1. Allocate a large array of integers in the heap, 
/// storing a pointer to that data. 
/// 2. Initialize a second pointer
/// to the same location in memory.
/// When: 
/// 3. A regular delete of the first pointer
/// Then:
/// 4. Print the address of the second pointer 
/// 5. Print the first ten integers
/// </summary>
void caseTwo()
{
    int* ptr1 = new int[SIZE]; // 1
    int* ptr2 = ptr1; // 2

    delete ptr1; // 3

    cout << "PTR2 Address: " << ptr2 << endl; // 4

    for (int i = 0; i < LIMITSIZE; i++) // 5
    {
        cout << *(ptr2 + i) << endl;
    }
}

/// <summary>
/// Given: 
/// 1. A function that defines a pointer 
/// to a C++ string object
/// When:
/// 2. Uses New to create a new string on the stack
/// 3. Return of the function uses de-reference operator(*)
/// to return string allocated on the heap.
/// Then:
/// 4. Calling function defines a string object, 
/// set to whatever is returned from the helper 
/// function 
/// 5. Prints the string
/// </summary>
string StringBuilder() // 1. Helper Function
{
    string* str = new string("hi, I'm allocated on the heap"); // 2. ordinary heap allocation

    return *str; // 3.
}

void caseThree()
{
    string str = StringBuilder(); // 4
    cout << str << endl; // 5
}

int main()
{
    cout << "Case 1" << endl;
    caseOne();
    cout << endl << "Case 2" << endl;
    caseTwo();
    cout << endl << "Case 3" << endl;
    caseThree();
}