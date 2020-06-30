#include "zoo.h"
#include <cassert>
#include <memory>
bool Zoo::addPerson(const Person& person)
{
    if (hasPerson(person.email))
        return false;

    people.push_back(person);
    return true;
}

bool Zoo::addAnimal(const Animal& animal)
{
    if (hasAnimal(animal.name))
        return false;

    animals.push_back(animal);
    return true;
}

bool Zoo::hasPerson(const std::string& email) const
{
    for (auto&& x : people) {
        if (x.equalId(email))
            return true;
    }
    return false;
}

bool Zoo::hasAnimal(const std::string& name) const
{
    for (auto&& x : animals) {
        if (x.equalId(name))
            return true;
    }

    return false;
}

const Person& Zoo::findPerson(const std::string& email) const
{
    for (auto&& x : people) {
        if (x.equalId(email))
            return x;
    }
    assert(false);
}
const Animal& Zoo::findAnimal(const std::string& name) const
{
    for (auto&& x : animals) {
        if (x.equalId(name))
            return x;
    }
    assert(false);
}
bool Zoo::adopt(const Adoption& adoption)
{
    for (auto&& x : adoptions) {
        if (x.equalTo(adoption))
            return false;
    }
    adoptions.push_back(adoption);
    return true;
}
const std::vector<Animal>& Zoo::getAnimals() const { return animals; }
const std::vector<Person>& Zoo::getPeople() const { return people; }
const std::vector<Adoption>& Zoo::getAdoptions() const { return adoptions; }
std::vector<Person> Zoo::getAdoptersForPlaque(const Animal& animal) const
{
    std::vector<Person> plaque;

    for (auto&& x : adoptions) {
        if (x.animal.equalTo(animal)) {
            plaque.push_back(x.adopter);
        }
    }

    return plaque;
}
