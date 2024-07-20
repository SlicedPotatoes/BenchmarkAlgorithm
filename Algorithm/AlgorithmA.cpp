#include "Algorithm.h"

using namespace std;

template <typename InputType, typename OutputType>
AlgorithmA<InputType, OutputType>::AlgorithmA(string name) : Algorithm<InputType, OutputType>(name)
{
}

template <typename InputType, typename OutputType>
OutputType AlgorithmA<InputType, OutputType>::run(const InputType &data)
{
    vector<int> arr = get<0>(data);

    int ans = 0;

    for (int n : arr)
    {
        ans ^= n;
    }

    return ans;
}