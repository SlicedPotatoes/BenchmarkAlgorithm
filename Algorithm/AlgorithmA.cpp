#include "Algorithm.h"

using namespace std;

template <typename InputType, typename OutputType> class AlgorithmA : public Algorithm<InputType, OutputType>
{
  public:
    AlgorithmA(std::string name);
    OutputType run(const InputType &data) override;
};

template <typename InputType, typename OutputType>
AlgorithmA<InputType, OutputType>::AlgorithmA(string name) : Algorithm<InputType, OutputType>(name)
{
}

template <typename InputType, typename OutputType>
OutputType AlgorithmA<InputType, OutputType>::run(const InputType &data)
{
    vector<string> names = get<0>(data);
    vector<int> heights = get<1>(data);

    vector<string> ans;

    for (int i = 0; i < names.size(); i++)
    {
        int currMax = 0;
        int currIndex = -1;

        for (int j = 0; j < names.size(); j++)
        {
            if (heights[j] > currMax)
            {
                currMax = heights[j];
                currIndex = j;
            }
        }

        ans.push_back(names[currIndex]);
        heights[currIndex] = -1;
    }

    return ans;
}