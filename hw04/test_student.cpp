#include "catch.hpp"
#include "trie.h"

#if 1

static int iter = 1;

class Monkey {
};

template <typename IntType>
void complileTestConst(const std::string& testname)
{
    std::cout << ("Verify/const " + testname + "--ENTRY") << " iter=" << iter++;

    SECTION("Verify/" + testname, "")
    {
        std::cout << " :: IN SECTION" << std::endl;
        const Trie<IntType> trie;
        const Trie<IntType> d(trie);

        trie.empty();
        trie.search({});
        //trie.at({});
        trie.items();
        trie.root();
        return;
    }

    std::cout << std::endl;
}

template <typename IntType>
void complileTest(const std::string& testname)
{
    std::cout << ("Verify/" + testname + "--ENTRY") << " iter=" << iter++;

    SECTION("Verify/" + testname, "")
    {
        std::cout << " :: IN SECTION" << std::endl;
        Trie<IntType> trie;
        Trie<IntType> t = trie;
        Trie<IntType> d(trie);

        trie.root();
        trie.items();
        //trie.at({});
        trie.search({});
        trie.empty();
        trie.insert({}, {});
        //t.at({});
        t.items();
        t.mergeWith(d);
        t.clear();
        (void)t[{}];
        t.remove({});
        return;
    }

    std::cout << std::endl;
}

template <typename IntType>
void drawTestCompile(const std::string& testname)
{
    std::cout << ("Verify/" + testname + "--ENTRY") << " iter=" << iter++;

    SECTION("Verify/" + testname, "")
    {
        std::cout << " :: IN SECTION" << std::endl;
        Trie<IntType> trie;
        trie.draw(std::cout);
        const Trie<IntType> t;
        t.draw(std::cout);
        return;
    }

    std::cout << std::endl;
}

TEST_CASE("compile")
{
    complileTest<int>("int compile");
    complileTest<std::string>("string compile");
    complileTest<double>("double compile");
    complileTest<std::pair<int, double>>("std::pair<int, double> compile");
    complileTest<Monkey>("custom compile");
}

TEST_CASE("compile const")
{
    complileTestConst<int>("int compile");
    complileTestConst<std::string>("string compile");
    complileTestConst<double>("double compile");
    complileTestConst<std::pair<int, double>>("std::pair<int, double> compile");
    complileTestConst<Monkey>("custom compile");
}

TEST_CASE("draw")
{
    drawTestCompile<int>("int");
    drawTestCompile<std::string>("string");
    drawTestCompile<double>("double");
}

#endif

TEST_CASE("normal")
{
}
