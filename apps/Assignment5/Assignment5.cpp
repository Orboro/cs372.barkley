#include <iostream>
#include <chrono>

using namespace std;


void towerOfHanoi(int n, char from_peg,
    char to_peg, char aux_peg)
{
    if (n == 1)
    {
        return;
    }
    towerOfHanoi(n - 1, from_peg, aux_peg, to_peg);
    towerOfHanoi(n - 1, aux_peg, to_peg, from_peg);
    
}

int main()
{
 
    auto start = std::chrono::steady_clock::now();
    int n = 50; 
    towerOfHanoi(n, 'A', 'C', 'B'); 
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration <double> elapsed_seconds = end - start;
    cout << elapsed_seconds.count() << "s\n";
    return 0;
}
