#include "Algorithm.h"

#include <algorithm>

using namespace std;

template <typename InputType, typename OutputType> class AlgorithmB : public Algorithm<InputType, OutputType>
{
  public:
    AlgorithmB(std::string name);
    OutputType run(const InputType &data) override;
};

template <typename InputType, typename OutputType>
AlgorithmB<InputType, OutputType>::AlgorithmB(string name) : Algorithm<InputType, OutputType>(name)
{
}

template <typename InputType, typename OutputType>
OutputType AlgorithmB<InputType, OutputType>::run(const InputType &data)
{
    vector<string> names = get<0>(data);
    vector<int> heights = get<1>(data);

    vector<int> indexs(names.size());

    for (int i = 0; i < names.size(); i++)
    {
        indexs[i] = i;
    }

    sort(indexs.begin(), indexs.end(), [&heights](int a, int b) { return heights[a] > heights[b]; });

    vector<string> ans;

    for (int n : indexs)
    {
        ans.push_back(names[n]);
    }

    return ans;
}