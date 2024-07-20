#include "Algorithm.h"

template <typename InputType, typename OutputType>
Algorithm<InputType, OutputType>::Algorithm(std::string name) : name(name)
{
}

template <typename InputType, typename OutputType> std::string Algorithm<InputType, OutputType>::getName()
{
    return name;
}

template <typename InputType, typename OutputType> std::vector<double> Algorithm<InputType, OutputType>::getTimes()
{
    return times;
}

template <typename InputType, typename OutputType> void Algorithm<InputType, OutputType>::insertTime(double t)
{
    times.push_back(t);
}
