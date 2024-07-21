#include "TestCase.h"
#include <algorithm>
#include <ctime>
#include <random>

template <typename InputType, typename OutputType> int TestCase<InputType, OutputType>::idCounter = 0;

template <typename InputType, typename OutputType>
TestCase<InputType, OutputType>::TestCase(const InputType &input, OutputType expectedResult)
    : data(input), expectedResult(expectedResult), testCaseId(++idCounter)
{
    verifyFunc = defaultVerifyFunc;
    writeFunc = defaultWriteFunc;
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
        return verifyFunc(expectedResult, it->second);
    }

    return false;
}

template <typename InputType, typename OutputType> int TestCase<InputType, OutputType>::getTestCaseId() const
{
    return testCaseId;
}

template <typename InputType, typename OutputType>
void TestCase<InputType, OutputType>::setVerifyFunction(VerifyFunction vf)
{
    verifyFunc = vf;
}
template <typename InputType, typename OutputType>
void TestCase<InputType, OutputType>::setWriteFunction(WriteFunction wf)
{
    writeFunc = wf;
}