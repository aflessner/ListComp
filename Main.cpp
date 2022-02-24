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

void PrintList(auto l)
{
    std::cout << "l = { ";
    for (auto n : l)
    {
        std::cout << n << ", ";
    }
    std::cout << "};\n";
}

void PrintMap(auto l)
{
    std::cout << "l = { ";
    for (auto it = l.cbegin(); it != l.cend(); ++it)
    {
        auto key = (*it).first;
        auto value = (*it).second;
        std::cout << "(" << key << " | " << value << "), ";
    }
    std::cout << "};\n";
}

void DoSomething(auto a)
{
    std::cout << "DoSomething " << a << "\n";
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

    addToMapIfMatch(output_dict, input_dict, [](auto k, auto v) { bool b = !v.starts_with("kyle");  if (b) { DoSomething(k); } return b; });

    PrintMap(output_dict);
}