#include "cs372vector.h"
using namespace std;
template <typename Thing>
class Bag {
private:
	// More on this shortly
	Vector<Thing> bagVector;
public:
	void insert(Thing aThing) {
		bagVector.push_back(aThing);
	}
	Thing pop() {
		return bagVector.pop();
	}
	int size() {
		return bagVector.size();
	}
	int count(Thing aThing) {
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

