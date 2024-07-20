#ifndef UTILS_H
#define UTILS_H

#include "TestCase.h"
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

void printPerformanceStats(const std::vector<double> &times, const std::string &algoName);
std::string formatDuration(double seconds);

template <typename AlgorithmType, typename InputType, typename OutputType>
double measureExecutionTime(AlgorithmType *&algo, TestCase<InputType, OutputType> &testCase)
{
    auto start = std::chrono::high_resolution_clock::now();
    OutputType result = algo->run(testCase.getData());
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;

    testCase.setActualResult(algo->getName(), result);
    return elapsed.count();
}

template <typename AlgorithmType, typename InputType, typename OutputType>
void verifyTestResults(const std::vector<TestCase<InputType, OutputType>> &testCases, AlgorithmType *&algo)
{
    std::vector<double> times = algo->getTimes();
    std::string algoName = algo->getName();
    std::cout << "\nVerification Report: " << algoName << '\n';

    for (const auto &testCase : testCases)
    {
        if (!testCase.verifyResult(algoName))
        {
            std::cout << "Test Case ID " << testCase.getTestCaseId() << ":\n"
                      << " - Expected: " << testCase.getExpectedResult()
                      << ", Obtained: " << testCase.getActualResult(algoName) << '\n';
        }
        else
        {
            std::cout << "Test Case ID " << testCase.getTestCaseId() << " - Passed, "
                      << "Execution time: " << formatDuration(times[testCase.getTestCaseId() - 1]) << '\n';
        }
    }
    std::cout << '\n';
}

#include "utils.cpp"

#endif // UTILS_H