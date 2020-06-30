#pragma once

#include "zoo.h"

class Handler {
public:
    void handle();

private:
    Zoo zoo;

    void addPerson(std::string& line_0, std::string& line_1, std::string& line_2);
    void addAnimal(std::string& line_0, std::string& line_1);
    void addAdoption(std::string& line_0, std::string& line_1, std::string& line_2);
    void printPeople() const;
    void printAnimals() const;
    void printAdoptions() const;
    void printAdoptersOfAnimal(std::string& line_0) const;
};
