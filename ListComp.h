#pragma once

#include <list>
#include <map>

void clearList(auto& list)
{
    list.clear();
}

void sortList(auto& list)
{
    list.sort();
}

void addToList(auto& outputList, auto& inputList)
{
    for (auto n : inputList)
    {
        outputList.push_front(n);
    }
}

void addToListIfMatch(auto& outputList, auto& inputList, auto lambda)
{
    for (auto n : inputList)
    {
        if (lambda(n))
        {
            outputList.push_front(n);
        }
    }
}

void filterList(auto& list, auto lambda)
{
    std::remove_reference_t<decltype(list)> outputList;
    for (auto n : list)
    {
        if (lambda(n))
        {
            outputList.push_front(n);
        }
    }
    list = outputList;
}

void addToMapIfMatch(auto& outputMap, auto& inputMap, auto lambda)
{
    for (auto const& [constKey, constValue] : inputMap)
    {
        auto mutableKey = constKey;
        auto mutableValue = constValue;
        if (lambda(mutableKey, mutableValue))
        {
            outputMap.emplace(mutableKey, mutableValue);
        }
    }
}