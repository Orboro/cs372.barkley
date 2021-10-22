#include <iostream>
#include <chrono>
#include <random>

using namespace std;

int anyEqual(int n, int* A)
{
    int i, j, k, m;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                for (m = 0; m < n; m++)
                {
                    if ((*(A + i * n + j) == *(A + k * n + m)) && !(i == k && j == m))
                        return 1;
                }
            }
        }
    }
    return 0;
}

void fill_array_sequential(int n, int* A)
{
    for (int i = 0; i < n; ++i)
    {
        A[i] = i;
    }
}

void fill_array_random(int n, int* A)
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, n * 2000);
    for (int i = 0; i < n; ++i)
    {
        A[i] = dist(rd);
    }
}

void test_array(int n)
{
    int* arr = new int[n * n];

    fill_array_random(n * n, arr);

    auto start = std::chrono::steady_clock::now();
    int test_result = anyEqual(n, arr);

    if (test_result == 0)
    {
        std::cout << "No duplicates." << std::endl;
    }
    else
    {
        std::cout << "Found a duplicate." << std::endl;
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration <double> elapsed_seconds = end - start;
    cout << elapsed_seconds.count() << "s\n";

    delete[] arr;
}

int main()
{
    test_array(10);
    test_array(20);
    test_array(30);
    test_array(40);
    test_array(50);
    test_array(100);
    test_array(500);
    test_array(1000);

    return 0;
}