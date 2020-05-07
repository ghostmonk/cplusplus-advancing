//
// Created by Nicholas Hillier on 2020-04-27.
//

#include "Resourcing.h"
#include "Resource.h"
#include <vector>
using std::vector;

void Resourcing::Run(bool exec) {
    if(!exec) return;
    Resource r("local");
    {
        vector<Resource> resources;
        resources.push_back(r);
        resources.emplace_back("first");
        resources.emplace_back("second");
    }
}
