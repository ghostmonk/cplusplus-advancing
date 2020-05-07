//
// Created by Nicholas Hillier on 2020-04-28.
//

#include "CollectionExercise.h"
#include "Resource.h"
#include <chrono>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;

#include <string>
using std::string;

#include <vector>
#include <list>
using std::vector;
using std::list;

#include <iostream>
using std::endl;
using std::cout;

#include <algorithm>
#include <random>

template <typename Func>
long long TimeFunc(Func f)
{
    auto begin = steady_clock::now();
    f();
    auto end = steady_clock::now();

    return duration_cast<milliseconds>(end - begin).count();
}

template <typename T>
void exercise(int size, string commonname) {
    T v;
    typename T:: value_type res1("starting entry");
    v.push_back(res1);
    for (int i = 0; i < size; i++)
    {
        int r = (int)rand();
        string s;
        int ss = r % 100;
        s.reserve(ss);
        std::generate_n(std::back_inserter(s), ss, [ss]() {return (char)('!' + ss / 2); });
        typename T:: value_type res(s);
        bool inserted = false;
        for (auto it = begin(v); it != end(v); it++)
        {
            if (*it > res)
            {
                v.insert(it, res);
                inserted = true;
                break;
            }
        }
        if (!inserted)
            v.push_back(res);
    }

    auto it = max_element(begin(v), end(v));
    typename T:: value_type maxV = *it;
    it = min_element(begin(v), end(v));
    typename T:: value_type minV = *it;

    bool sorted = is_sorted(begin(v), end(v));
}

void CollectionExercise::Run(bool exec) {
    if(!exec) return;
    const int size = 1000;
    auto vectorMilliseconds = TimeFunc([&](){ exercise<vector<string>>(size, "vector"); });
    auto listMilliseconds = TimeFunc([&](){ exercise<list<string>>(size, "list"); });
    cout << vectorMilliseconds << endl;
    cout << listMilliseconds << endl;
}
