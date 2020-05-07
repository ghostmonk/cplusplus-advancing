//
// Created by Nicholas Hillier on 2020-04-27.
//

#include "StdAlgos.h"
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <string>
using std::vector;
using std::cout;
using std::endl;
using std::string;

void StdAlgos::Run(bool exec) {
    if(!exec) return;
    vector<int> v;
    int i = 0;
    std::generate_n(std::back_inserter(v), 5, [&]() { return i++; });
    for(auto item: v) cout << item << " ";
    cout << endl;

    int total = std::accumulate(begin(v), end(v), 0);
    cout << total << endl;

    int threes = std::count(begin(v), end(v), 3);
    cout << threes << endl;

    auto remover = std::remove_if(begin(v), end(v), [](int elem){ return elem == 3;});
    v.erase(remover, end(v));
    for(auto item: v) cout << item << " ";
    cout << endl;

    v.push_back(5);
    v.push_back(-2);
    v.push_back(89);
    v.push_back(3);
    v.push_back(13);
    v.push_back(21);
    for(auto item: v) cout << item << " ";
    cout << endl;

    sort(begin(v), end(v));
    for(auto item: v) cout << item << " ";
    cout << endl;

    bool allPositive = std::all_of(begin(v), end(v), [](int elem) {return elem >= 0; });
    cout << allPositive << endl;

    string s{ "Hello I am a sentence!" };
    auto letter = find(begin(s), end(s), 'a');
    cout << &letter << endl;

    auto caps = std::count_if(begin(s), end(s), [](char c){return (c != ' ') && (toupper(c) == c);});
    cout << &caps << endl;
}
