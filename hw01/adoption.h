#pragma once

#include "animal.h"
#include "person.h"

class Adoption {
public:
    const Person adopter;
    const Animal animal;
    const unsigned amount;

    Adoption(const Person& adopter, const Animal& animal, unsigned amount)
        : adopter(adopter)
        , animal(animal)
        , amount(amount)
    {
    }

    void print() const
    {
        adopter.print();
        animal.print();
        std::cout << "Amount: " << amount << std::endl;
    }
    bool equalTo(const Adoption& adoption) const
    {
        return adopter.equalTo(adoption.adopter) && animal.equalTo(adoption.animal);
    }
};
