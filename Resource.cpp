//
// Created by Nicholas Hillier on 2020-04-27.
//

#include "Resource.h"
#include <string>
#include <iostream>
#include <utility>
using std::string;
using std::cout;
using std::endl;
using std::move;

Resource::Resource(string n) : name(move(n)) {
    cout << "Constructing " << GetName() << endl;
}

Resource::Resource(const Resource &r) : name(r.name) {
    cout << "Copy Constructing " << GetName() << endl;
}

Resource::~Resource() {
    cout << "Deconstructing " << GetName() << endl;
}

Resource & Resource::operator=(const Resource &r) {
    name = r.GetName();
    cout << "Copy assigning " << name << endl;
    return *this;
}
