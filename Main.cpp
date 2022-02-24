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
}