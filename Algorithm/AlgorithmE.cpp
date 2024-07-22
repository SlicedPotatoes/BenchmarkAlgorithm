#include "Algorithm.h"

#include <map>

using namespace std;

template <typename InputType, typename OutputType> class AlgorithmE : public Algorithm<InputType, OutputType>
{
  public:
    AlgorithmE(std::string name);
    OutputType run(const InputType &data) override;
};

template <typename InputType, typename OutputType>
AlgorithmE<InputType, OutputType>::AlgorithmE(string name) : Algorithm<InputType, OutputType>(name)
{
}

template <typename InputType, typename OutputType>
OutputType AlgorithmE<InputType, OutputType>::run(const InputType &data)
{
    vector<string> names = get<0>(data);
    vector<int> heights = get<1>(data);

    map<int, string> mp;

    for (int i = 0; i < names.size(); i++)
    {
        mp[heights[i]] = names[i];
    }

    int i = 0;
    for (auto it = mp.rbegin(); it != mp.rend(); it++)
    {
        names[i++] = it->second;
    }

    return names;
}