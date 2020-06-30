#include "trie.h"


#if 0
//debug function
    void print(const ItemList& container) const
    {
        std::cout << "CONTAINER STATE:" << std::endl;
        for (auto& x : container) {
            std::cout << "Key: ";
            for (auto y : x.first)
                std::cout << y;
            std::cout << " Value: " << x.second << std::endl;
        }
        std::cout << "--------------------------" << std::endl;
    }
#endif


int main()

{
    Trie<int> t;
    t.insert({}, 1);
    t.insert({0}, 2);
    t.insert({1}, 3);
    t.insert({0,1}, 4);
    t.insert({1,0}, 5);
    t.insert({1,1}, 6);
    t.insert({0,0}, 7);
    t.insert({0,1,0}, 46);
    t.insert({0,0,0},85);
    t.insert({0,1,1}, 61);
    t.insert({0,1,0}, 180);
    t.insert({1,0,0},98);
    t.insert({1,1,1},89);
    t.insert({1,0,1},78);
    t.insert({1,1,0},87);
/*
    t.insert({1,0,1,0}, 11);
    t.insert({0,1,0,1}, 41);
    t.insert({1,0,1,0,1}, 31);
    t.insert({0,1,1,0,0}, 15);
    t.insert({1,1,0,1,0}, 18);
    t.insert({0,1,1,1,1}, 21);
    t.insert({1,1,1,1,1}, 66);
*/
    auto container = t.items();

    std::cout << "CONTAINER STATE:" << std::endl;
    for (auto& x : container) {
        std::cout << "Key: ";
        for (auto y : x.first)
            std::cout << y;
        std::cout << " Value: " << x.second << std::endl;
    }
    std::cout << "--------------------------" << std::endl;

    t.draw(std::cout);
    return 0;
}
