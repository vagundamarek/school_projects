#pragma once

#include <iostream>
#include <string>

class Person {
public:
    const std::string name;
    const std::string email;
    const std::string city;

    Person(const std::string& name, const std::string& email, const std::string& city)
        : name(name)
        , email(email)
        , city(city)
    {
    }

    void print() const
    {
        std::cout << name << " <" << email << ">";
        if (hasCity())
            std::cout << ", " << city;
        std::cout << std::endl;
    }

    bool equalTo(const Person& person) const
    {
        return equalId(person.email);
    }
    bool equalId(const std::string& email) const
    {
        return this->email == email;
    }
    bool hasCity() const
    {
        return !city.empty();
    }
};
