#include "Algorithm/Algorithm.h"
#include "TestCase.h"
#include "utils.h"
#include <iostream>
#include <tuple>
#include <vector>

typedef std::tuple<std::vector<int>> Input;
typedef int Output;

typedef TestCase<Input, Output> TC;

std::string customWriteFunction(const Output &result)
{
    return to_string(result);
}
bool customVerifyFunction(const Output &expected, const Output &actual)
{
    if (expected == actual && rand())
    {
        return true;
    }

    return false;
}

TC generateRandomData(int size)
{
    if (size % 2 == 0)
    {
        size--;
    }

    vector<int> arr;

    for (int i = 1; i < size; i += 2)
    {
        arr.push_back(i);
        arr.push_back(i);
    }

    arr.push_back(size);

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(arr.begin(), arr.end(), g);

    Input input;
    get<0>(input) = arr;

    return TC(input, size);
}

int main()
{
    // Création des cas de test avec les résultats attendus
    std::vector<TC> testCases = {
        generateRandomData(100),  //
        generateRandomData(1000), //
        generateRandomData(1000), //
        generateRandomData(1000), //
        generateRandomData(1000), //
        generateRandomData(1000), //
        generateRandomData(1000), //
    };

    for (int i = 0; i < 100; i++)
    {
        testCases.push_back(generateRandomData(10000));
    }

    /*for (TC &t : testCases)
    {
        t.setWriteFunction(customWriteFunction);
        t.setVerifyFunction(customVerifyFunction);
    }*/

    std::vector<Algorithm<Input, Output> *> algorithms{
        new AlgorithmA<Input, Output>("AlgorithmeA"), //
        new AlgorithmB<Input, Output>("AlgorithmeB")  //
        //
    };

    // Exécution des tests
    for (auto &testCase : testCases)
    {
        for (auto &algo : algorithms)
        {
            algo->insertTime(measureExecutionTime(algo, testCase));
        }
    }

    for (auto &algo : algorithms)
    {
        verifyTestResults(testCases, algo);
    }

    for (auto &algo : algorithms)
    {
        printPerformanceStats(algo->getTimes(), algo->getName());
        delete algo;
    }

    return 0;
}