#include <iostream>
#include <stack>
#include <vector>
#include <chrono>

using namespace std;
class Tower {
public:
    Tower(stack<int> discs) {
        _discs = discs;
    }
    Tower(int disc0) {
        _discs.push(0);
    }
    int getTopDisc() {
        return _discs.top();
    }
    bool placeDisc(int disc) {
        if (canPlaceDisc(disc)) {
            _discs.push(disc);
            return true;
        }
        return false;
    }
    void removeTopDisc() {
        _discs.pop();
    }
private:
    stack<int> _discs;
    bool canPlaceDisc(int disc) {
        if (_discs.top() > disc || _discs.top() == 0) {
            return true;
        }
        return false;
    }
};
int main() {
    stack<int> discs;
    vector<Tower> towers;
    const int towerNumber = 3;
    int discNumber = 30;
    auto start = std::chrono::steady_clock::now();

    discs.push(0);
    for (int i = discNumber; i > 0; i--) {
        discs.push(i);
    }
    towers.push_back(Tower(discs));
    for (int i = 0; i < towerNumber - 1; i++) {
        towers.push_back(Tower(0));
    }
    int smallestDisc;
    int smallestDiscPosition;
    for (int i = 0; i < (1U << discNumber) - 1; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < towerNumber; j++) {
                if (towers[j].getTopDisc() == 1) { 
                    towers[j].removeTopDisc();
                    if (j == towerNumber - 1) {
                        towers[0].placeDisc(1);
                    }
                    else {
                        towers[j + 1].placeDisc(1);
                    }

                    break;
                }
            }
        }
        else { //Move smallest disc, which is not disc 1 to valid place
            smallestDisc = discNumber + 1;
            smallestDiscPosition = 0;
            for (int j = 0; j < towerNumber; j++) {
                if (towers[j].getTopDisc() < smallestDisc && towers[j].getTopDisc() != 1 && towers[j].getTopDisc() != 0) {
                    smallestDisc = towers[j].getTopDisc();
                    smallestDiscPosition = j;
                }
            }
            for (int j = 0; j < towerNumber; j++) {
                if ((towers[j].getTopDisc() > smallestDisc || towers[j].getTopDisc() == 0) && towers[j].getTopDisc() != 1) {
                    towers[smallestDiscPosition].removeTopDisc();
                    towers[j].placeDisc(smallestDisc);
                    break;
                }
            }
        }
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration <double> elapsed_seconds = end - start;
    cout << elapsed_seconds.count() << "s\n";
    return 0;
}