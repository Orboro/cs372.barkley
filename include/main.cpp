//
//  main.cpp
//  TreeTest
//
//  Created by Adam Lewis on 10/3/16.
//  Copyright © 2016 Adam Lewis. All rights reserved.
//

#include <iostream>
#include "Tree.h"


auto f2 = [](int thing)->void {std::cout << thing;};

int main(int argc, const char * argv[]) {

    std::cout << "Tree test program\n";
    Tree<int> aTree({45,74,28,32,45,44, 100});

    std::cout << "Preorder:\n";
    aTree.preorder(f2);
    std::cout << "\n Inorder:\n";
    aTree.inorder(f2);
    std::cout << "\n Postorder\n";
    aTree.postorder(f2);
    std::cout << std::endl;

    return 0;
}
