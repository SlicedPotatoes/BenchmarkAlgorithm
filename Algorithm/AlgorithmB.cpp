#include "Algorithm.h"

#include <unordered_set>

using namespace std;

template <typename InputType, typename OutputType>
AlgorithmB<InputType, OutputType>::AlgorithmB(string name) : Algorithm<InputType, OutputType>(name)
{
}

template <typename InputType, typename OutputType>
OutputType AlgorithmB<InputType, OutputType>::run(const InputType &data)
{
    vector<int> arr = get<0>(data);
    unordered_set<int> set;

    for (int n : arr)
    {
        if (set.find(n) != set.end())
        {
            set.erase(n);
        }
        else
        {
            set.insert(n);
        }
    }

    return *set.begin();
}