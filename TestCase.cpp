#include "TestCase.h"
#include <algorithm>
#include <ctime>
#include <random>

template <typename InputType, typename OutputType> int TestCase<InputType, OutputType>::idCounter = 0;

template <typename InputType, typename OutputType>
TestCase<InputType, OutputType> TestCase<InputType, OutputType>::generateRandomData(int size)
{
    std::random_device rd;
    std::mt19937 rng(rd());

    InputType input;
    std::vector<int> randomNumber(size);

    for (int i = 0; i < size; i++)
    {
        randomNumber[i] = i + 1;
    }

    for (int i = 1; i < size; i += 2)
    {
        std::uniform_int_distribution<size_t> dist(0, randomNumber.size() - 1);

        int index = dist(rng);

        std::get<0>(input).push_back(randomNumber[index]);
        std::get<0>(input).push_back(randomNumber[index]);

        randomNumber.erase(randomNumber.begin() + index);
    }

    std::get<0>(input).push_back(randomNumber[0]);

    std::shuffle(std::get<0>(input).begin(), std::get<0>(input).end(), rng);

    return TestCase<InputType, OutputType>(input, randomNumber[0]);
}

template <typename InputType, typename OutputType>
TestCase<InputType, OutputType>::TestCase(const InputType &input, OutputType expectedResult)
    : data(input), expectedResult(expectedResult), testCaseId(++idCounter)
{
}

template <typename InputType, typename OutputType> const InputType &TestCase<InputType, OutputType>::getData() const
{
    return data;
}

template <typename InputType, typename OutputType> OutputType TestCase<InputType, OutputType>::getExpectedResult() const
{
    return expectedResult;
}

template <typename InputType, typename OutputType>
void TestCase<InputType, OutputType>::setActualResult(const std::string &algoName, OutputType result)
{
    actualResults[algoName] = result;
}

template <typename InputType, typename OutputType>
OutputType TestCase<InputType, OutputType>::getActualResult(const std::string &algoName) const
{
    auto it = actualResults.find(algoName);

    if (it != actualResults.end())
    {
        return it->second;
    }

    return OutputType();
}

template <typename InputType, typename OutputType>
bool TestCase<InputType, OutputType>::verifyResult(const std::string &algoName) const
{
    auto it = actualResults.find(algoName);

    if (it != actualResults.end())
    {
        return expectedResult == it->second;
    }

    return false;
}

template <typename InputType, typename OutputType> int TestCase<InputType, OutputType>::getTestCaseId() const
{
    return testCaseId;
}