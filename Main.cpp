#include <iostream>
#include <time.h>
#include "ListComp.h"

const unsigned int SizeOfList = 1000;

void PopulateRandomList(auto& l)
{
    for (unsigned int i = 0; i < SizeOfList; i++)
    {
        l.push_front(rand());
    }
}

void PopulateMap(auto& l)
{
    char c = 'a';
    for (unsigned int i = 1; i <= 26; i++)
    {
        l.emplace(i, c);
        c++;
    }
}

void PrintList(auto l)
{
    std::cout << "l = { ";
    for (auto n : l)
    {
        std::cout << n << ", ";
    }
    std::cout << "};\n";
}

void PrintMap(auto m)
{
    std::cout << "l = { ";
    for (auto const& [key, value] : m)
    {
        std::cout << "(" << key << " | " << value << "), ";
    }
    std::cout << "};\n";
}

bool DoSomething(auto a)
{
    std::cout << "DoSomething " << a << "\n";
    return true;
}

bool isOdd(const auto n)
{
    return n % 2 != 0;
}

bool modifyKey(auto& k)
{
    k *= 4;
    return true;
}


int main()
{
    srand((unsigned int)time(NULL));

    std::list<int> j, k, sum;

    PopulateRandomList(j);
    PopulateRandomList(k);

    addToListIfMatch(sum, j, [](auto n) { return n % 2 == 0; });

    addToListIfMatch(sum, k, [](auto n) { return n % 2 == 0; });

    //PrintList(sum);

    filterList(sum, [](auto n) { return 1000 < n && n < 10000; });

    //PrintList(sum);

    filterList(sum, [](auto n) { return n % 3 == 0; });

    //PrintList(sum);

    filterList(sum, [](auto n) { return n % 5 == 0; });

    PrintList(sum);

    sortList(sum);

    PrintList(sum);

    std::list<std::string> fruits = {"apple", "banana", "cherry", "kiwi", "mango"};

    PrintList(fruits);

    filterList(fruits, [](auto n) { return n.starts_with("a");  });

    PrintList(fruits);

    std::map<int, std::string> input_dict, output_dict;

    input_dict.emplace(5, "blah");
    input_dict.emplace(6, "kyle");

    PrintMap(input_dict);

    addToMapIfMatch(output_dict, input_dict, [](auto& k, auto& v) { return !v.starts_with("kyle") && DoSomething(k); });

    PrintMap(output_dict);

    std::map<int, char> input_dict2, output_dict2;

    PopulateMap(input_dict2);

    PrintMap(input_dict2);

    addToMapIfMatch(output_dict2, input_dict2, [](auto& k, auto& v) { bool bIsOdd = isOdd(k); if (bIsOdd) { modifyKey(k); } return bIsOdd; });

    PrintMap(output_dict2);

    return 0;
}