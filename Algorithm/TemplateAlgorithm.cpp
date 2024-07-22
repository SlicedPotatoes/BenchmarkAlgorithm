#include "Algorithm.h"

using namespace std;

template <typename InputType, typename OutputType> class TemplateAlgorithm : public Algorithm<InputType, OutputType>
{
  public:
    TemplateAlgorithm(std::string name);
    OutputType run(const InputType &data) override;
};

template <typename InputType, typename OutputType>
TemplateAlgorithm<InputType, OutputType>::TemplateAlgorithm(string name) : Algorithm<InputType, OutputType>(name)
{
}

template <typename InputType, typename OutputType>
OutputType TemplateAlgorithm<InputType, OutputType>::run(const InputType &data)
{
}