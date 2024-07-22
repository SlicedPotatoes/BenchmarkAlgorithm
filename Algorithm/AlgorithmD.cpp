#include "Algorithm.h"

#include <unordered_map>

using namespace std;

template <typename InputType, typename OutputType> class AlgorithmD : public Algorithm<InputType, OutputType>
{
  public:
    AlgorithmD(std::string name);
    OutputType run(const InputType &data) override;
};

template <typename InputType, typename OutputType>
AlgorithmD<InputType, OutputType>::AlgorithmD(string name) : Algorithm<InputType, OutputType>(name)
{
}

template <typename InputType, typename OutputType>
OutputType AlgorithmD<InputType, OutputType>::run(const InputType &data)
{
    vector<string> names = get<0>(data);
    vector<int> heights = get<1>(data);

    unordered_map<int, string> mp;

    for (int i = 0; i < names.size(); i++)
    {
        mp[heights[i]] = names[i];
    }

    sort(heights.begin(), heights.end(), greater<int>());

    for (int i = 0; i < names.size(); i++)
    {
        names[i] = mp[heights[i]];
    }

    return names;
}