#pragma once

#include <iostream>
#include <string>

class Animal {
public:
    const std::string name;
    const std::string description;

    Animal(const std::string& name, const std::string& description)
        : name(name)
        , description(description)
    {
    }

    void print() const
    {
        std::cout << name;
        if (hasDescription())
            std::cout << std::endl
                      << description;
        std::cout << std::endl;
    }
    bool equalTo(const Animal& animal) const
    {
        return equalId(animal.name);
    }

    bool equalId(const std::string& name) const
    {
        return this->name == name;
    }
    bool hasDescription() const
    {
        return !description.empty();
    }
};
