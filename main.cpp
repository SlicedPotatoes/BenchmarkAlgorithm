#include "Algorithm/Algorithm.h"
#include "TestCase.h"
#include "utils.h"
#include <iostream>
#include <tuple>
#include <vector>

int main()
{
    // Création des cas de test avec les résultats attendus
    std::vector<TestCase<std::tuple<std::vector<int>>, int>> testCases = {
        TestCase<std::tuple<std::vector<int>>, int>::generateRandomData(100),   //
        TestCase<std::tuple<std::vector<int>>, int>::generateRandomData(1000),  //
        TestCase<std::tuple<std::vector<int>>, int>::generateRandomData(10000), //
        TestCase<std::tuple<std::vector<int>>, int>::generateRandomData(10000), //
        TestCase<std::tuple<std::vector<int>>, int>::generateRandomData(10000), //
        TestCase<std::tuple<std::vector<int>>, int>::generateRandomData(10000), //
        TestCase<std::tuple<std::vector<int>>, int>::generateRandomData(10000), //
        TestCase<std::tuple<std::vector<int>>, int>::generateRandomData(10000), //
        TestCase<std::tuple<std::vector<int>>, int>::generateRandomData(10000)  //
    };

    std::vector<Algorithm<std::tuple<std::vector<int>>, int> *> algorithms{
        new AlgorithmA<std::tuple<std::vector<int>>, int>("AlgorithmeA"), //
        new AlgorithmB<std::tuple<std::vector<int>>, int>("AlgorithmeB")  //
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
        printPerformanceStats(algo->getTimes(), algo->getName());
        verifyTestResults(testCases, algo);

        delete algo;
    }

    return 0;
}