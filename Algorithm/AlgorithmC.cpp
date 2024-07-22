#include "Algorithm.h"

#include <algorithm>

using namespace std;

template <typename InputType, typename OutputType> class AlgorithmC : public Algorithm<InputType, OutputType>
{
  public:
    AlgorithmC(std::string name);
    OutputType run(const InputType &data) override;
};

template <typename InputType, typename OutputType>
AlgorithmC<InputType, OutputType>::AlgorithmC(string name) : Algorithm<InputType, OutputType>(name)
{
}

template <typename InputType, typename OutputType>
OutputType AlgorithmC<InputType, OutputType>::run(const InputType &data)
{
    vector<string> names = get<0>(data);
    vector<int> heights = get<1>(data);

    vector<pair<int, string>> peoples;

    for (int i = 0; i < names.size(); i++)
    {
        peoples.push_back({heights[i], names[i]});
    }

    sort(peoples.begin(), peoples.end(), greater<pair<int, string>>());

    for (int i = 0; i < peoples.size(); i++)
    {
        names[i] = peoples[i].second;
    }

    return names;
}