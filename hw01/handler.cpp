#include "handler.h"
#include <sstream>

void getHelp()
{
    std::cout << "Availible actions:" << std::endl;
    std::cout << "0 - exit" << std::endl;
    std::cout << "1 - add person" << std::endl;
    std::cout << "2 - add animal" << std::endl;
    std::cout << "3 - add adoption" << std::endl;
    std::cout << "4 - print people" << std::endl;
    std::cout << "5 - print animals" << std::endl;
    std::cout << "6 - print adoptions" << std::endl;
    std::cout << "7 - print adopters of given animal" << std::endl
              << std::endl;
}
/*
If the argument is required, and nothing is entered, returns true
returns false otherwise
*/
bool load(const std::string& argument, std::string& out, bool required = false)
{
    std::cout << argument << ":" << std::endl;
    std::getline(std::cin, out);
    if (out.empty() && required) {
        std::cerr << "Error - no argument has been entered" << std::endl;
        return true;
    }
    return false;
}

void Handler::addPerson(std::string& line_0, std::string& line_1, std::string& line_2)
{

    if (load("Name", line_0, true))
        return;
    if (load("Email", line_1, true))
        return;
    load("City", line_2);
    Person toInsert(line_0, line_1, line_2);
    if (!zoo.addPerson(toInsert)) {
        std::cerr << "Error - this person already exists" << std::endl;
        return;
    }
    std::cout << "OK" << std::endl;
}

void Handler::addAnimal(std::string& line_0, std::string& line_1)
{
    if (load("Name", line_0, true))
        return;
    if (load("Description", line_1, false))
        return;
    Animal toInsert(line_0, line_1);
    if (!zoo.addAnimal(toInsert)) {
        std::cerr << "Error - this animal already exists" << std::endl;
        return;
    }
    std::cout << "OK" << std::endl;
}

void Handler::addAdoption(std::string& line_0, std::string& line_1, std::string& line_2)
{
    if (load("Email", line_0, true))
        return;
    if (!zoo.hasPerson(line_0)) {
        std::cerr << "Error - no person of such ID exists" << std::endl;
        return;
    }
    if (load("Name", line_1, true))
        return;
    if (!zoo.hasAnimal(line_1)) {
        std::cerr << "Error - no animal of such ID exists" << std::endl;
        return;
    }
    if (load("Amount", line_2, true))
        return;
    Adoption toInsert(zoo.findPerson(line_0), zoo.findAnimal(line_1),
        std::stoi(line_2));
    if (!zoo.adopt(toInsert)) {
        std::cerr << "Error - this adoption already exists" << std::endl;
        return;
    }
    std::cout << "OK" << std::endl;
}

void Handler::printPeople() const
{
    std::vector<Person> const& toPrint(zoo.getPeople());
    for (auto&& x : toPrint)
        x.print();

    std::cout << "OK" << std::endl;
}

void Handler::printAnimals() const
{
    std::vector<Animal> const& toPrint(zoo.getAnimals());
    for (auto&& x : toPrint)
        x.print();

    std::cout << "OK" << std::endl;
}

void Handler::printAdoptions() const
{
    std::vector<Adoption> const& toPrint(zoo.getAdoptions());
    for (auto&& x : toPrint)
        x.print();

    std::cout << "OK" << std::endl;
}

void Handler::printAdoptersOfAnimal(std::string& line_0) const
{
    if (load("Name", line_0, true))
        return;
    if (!zoo.hasAnimal(line_0)) {
        std::cerr << "Error - this animal doesn't exist" << std::endl;
        return;
    }
    Animal const& a(zoo.findAnimal(line_0));
    a.print();
    std::vector<Adoption> toPrint = (zoo.getAdoptions());
    for (auto&& x : toPrint) {
        if (x.animal.equalTo(a))
            x.adopter.print();
    }

    std::cout << "OK" << std::endl;
}

void Handler::handle()
{
    int command = 8;
    std::string line_0;
    std::string line_1;
    std::string line_2;
    while (command != 0) {
        getHelp();
        std::getline(std::cin, line_0);
        command = std::stoi(line_0);
        switch (command) {
        case 0:
            break;
        case 1: {
            addPerson(line_0, line_1, line_2);
            break;
        }
        case 2: {
            addAnimal(line_0, line_1);
            break;
        }
        case 3: {
            addAdoption(line_0, line_1, line_2);
            break;
        }
        case 4: {
            printPeople();
            break;
        }
        case 5: {
            printAnimals();
            break;
        }
        case 6: {
            printAdoptions();
            break;
        }
        case 7: {
            printAdoptersOfAnimal(line_0);
            break;
        }
        }
    }
}
