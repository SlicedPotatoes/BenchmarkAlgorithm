#ifndef TESTCASE_H
#define TESTCASE_H

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

template <typename InputType, typename OutputType> class TestCase
{
  public:
    using VerifyFunction = std::function<bool(const OutputType &, const OutputType &)>;
    using WriteFunction = std::function<std::string(const OutputType &)>;

    TestCase(const InputType &input, OutputType expectedResult);

    const InputType &getData() const;
    OutputType getExpectedResult() const;
    void setActualResult(const std::string &algoName, OutputType result);
    OutputType getActualResult(const std::string &algoName) const;
    bool verifyResult(const std::string &algoName) const;
    int getTestCaseId() const;

    WriteFunction writeFunc;

    void setWriteFunction(WriteFunction wf);
    void setVerifyFunction(VerifyFunction vf);

  private:
    InputType data;
    OutputType expectedResult;
    std::unordered_map<std::string, OutputType> actualResults;
    static int idCounter;
    int testCaseId;

    VerifyFunction verifyFunc;
};

#include "TestCase.cpp"

#endif // TESTCASE_H