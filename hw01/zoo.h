#pragma once

#include "adoption.h"
#include <vector>

class Zoo {
public:
    bool addPerson(const Person& person);
    bool addAnimal(const Animal& animal);
    bool hasPerson(const std::string& email) const;
    bool hasAnimal(const std::string& name) const;
    const Person& findPerson(const std::string& email) const;
    const Animal& findAnimal(const std::string& name) const;
    bool adopt(const Adoption& adoption);
    const std::vector<Animal>& getAnimals() const;
    const std::vector<Person>& getPeople() const;
    const std::vector<Adoption>& getAdoptions() const;
    std::vector<Person> getAdoptersForPlaque(const Animal& animal) const;

private:
    std::vector<Animal> animals;
    std::vector<Person> people;
    std::vector<Adoption> adoptions;
};
