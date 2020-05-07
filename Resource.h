//
// Created by Nicholas Hillier on 2020-04-27.
//
#pragma once
#include <string>

class Resource {
private:
    std::string name;
public:
    explicit Resource(std::string n);
    Resource(const Resource& r);
    Resource& operator=(const Resource& r);
    ~Resource();
    bool operator>(const Resource& r) { return name > r.name; }
    bool operator<(const Resource& r) { return name < r.name; }
    bool operator==(const Resource& r) { return name == r.name; }
    [[nodiscard]] std::string GetName() const { return name; }
};
