#include "Algorithm/Algorithm.h"
#include "TestCase.h"
#include "utils.h"
#include <iostream>
#include <tuple>
#include <vector>

#include <map>
#include <set>

typedef std::tuple<std::vector<string>, std::vector<int>> Input;
typedef std::vector<std::string> Output;

typedef TestCase<Input, Output> TC;

std::string writeFunction(const Output &result)
{
    std::string s = "{";

    for (std::string name : result)
    {
        s += name + ", ";
    }

    if (s.size() > 1)
    {
        s.pop_back();
        s.pop_back();
    }

    s += '}';

    return s;
}
bool verifyFunction(const Output &expected, const Output &actual)
{
    if (expected == actual)
    {
        return true;
    }

    return false;
}

TC generateRandomData(int size)
{
    Input input;

    std::random_device rd;
    std::mt19937 gen(rd());

    // Générer heights
    std::uniform_int_distribution<> dist(1, 100000);
    std::set<int> uniqueInts;
    while (uniqueInts.size() < size)
    {
        uniqueInts.insert(dist(gen));
    }
    std::vector<int> heights(uniqueInts.begin(), uniqueInts.end());
    get<1>(input) = heights;

    // Générer names
    const std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::vector<std::string> names;
    dist = uniform_int_distribution<>(0, chars.size() - 1);
    for (int i = 0; i < size; i++)
    {
        std::string str;
        for (int j = rand() % 20; j >= 0; j--)
        {
            str += chars[dist(gen)];
        }
        names.push_back(str);
    }
    get<0>(input) = names;

    // Récupérer le résultat
    std::vector<std::string> result(size);
    std::map<int, std::string> mp;

    for (int i = 0; i < names.size(); i++)
    {
        mp[heights[i]] = names[i];
    }

    int i = 0;
    for (auto it = mp.rbegin(); it != mp.rend(); it++)
    {
        result[i++] = it->second;
    }

    // Renvoyer le TestCase
    return TC(input, result);
}

int main()
{
    // Création des cas de test avec les résultats attendus
    std::vector<TC> testCases = {};

    for (int i = 0; i < 100; i++)
    {
        testCases.push_back(generateRandomData(100));
    }
    for (int i = 0; i < 100; i++)
    {
        testCases.push_back(generateRandomData(1000));
    }
    for (int i = 0; i < 100; i++)
    {
        testCases.push_back(generateRandomData(10000));
    }

    for (TC &t : testCases)
    {
        t.setWriteFunction(writeFunction);
        t.setVerifyFunction(verifyFunction);
    }

    std::vector<Algorithm<Input, Output> *> algorithms{
        new AlgorithmA<Input, Output>("Naive"),            //
        new AlgorithmB<Input, Output>("Sort Index Array"), //
        new AlgorithmC<Input, Output>("Sort Pair Array"),  //
        new AlgorithmD<Input, Output>("HashMap"),          //
        new AlgorithmE<Input, Output>("Map"),              //
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