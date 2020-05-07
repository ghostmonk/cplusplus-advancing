//
// Created by Nicholas Hillier on 2020-04-27.
//

#include "Vectors.h"
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

void Vectors::Run(bool exec) {
    if(!exec) return;
    vector numbers{0,1,2};
    numbers.push_back(-2);
    numbers[0] = 3;
    for( int i : numbers) {
        cout << i << endl;
    }
}
