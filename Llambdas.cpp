//
// Created by Nicholas Hillier on 2020-04-27.
//

#include "Llambdas.h"
#include "Resource.h"
#include <vector>
#include <iostream>
#include <string>
#include <memory>
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::make_unique;

void Llambdas::Run(bool exec) {
    if(!exec) return;

    auto isOdd = [](int candidate) { return candidate % 2 != 0; };
    bool is3Odd = isOdd(3);
    bool is4Odd = isOdd(4);

    vector nums{ 2, 3, 4, -1, 1, 0 };

    int odds = std::count_if(begin(nums), end(nums), isOdd);
    int evens = std::count_if(begin(nums), end(nums), [](int candidate){return candidate %2 == 0;});
    cout << "#Odds = " << odds << endl;
    cout << "#Evens = " << evens << endl;

    int x = 3;
    int y = 7;
    string message = "elements between ";
    message += std::to_string(x) + " and " + std::to_string(y) + " inclusive: ";
    for_each(begin(nums), end(nums),
            [&](int n) {
                if(n >= x && n <=y)
                    message += " " + std::to_string(n);
            });

    cout << message << endl;

    x = y = 0;
    std::for_each(begin(nums), end(nums),
            [&, x](int element) mutable {
                x += element;
                y += element;
            });


    cout << "x = " << x << " y = " << y << endl;

    {
        auto pResource = make_unique<Resource>(", ");

        for_each(begin(nums), end(nums),
                [=, &message, pr=std::move(pResource)](int n){
                    if(n >= x && n <=y)
                        message += pr->GetName() + std::to_string(n);
                });

        int i = 2;
    }

    cout << message << endl;
}
