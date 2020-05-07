//
// Created by Nicholas Hillier on 2020-04-28.
//
#include <iostream>
#include "Sizes.h"

void Sizes::Run(bool exec) {
    if(!exec) return;
    std::cout << sizeof(long long int) << std::endl;
    std::cout << sizeof(long) << std::endl;
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(long long) << std::endl;
    std::cout << sizeof(long int) << std::endl;
    std::cout << sizeof(char) << std::endl;
}
