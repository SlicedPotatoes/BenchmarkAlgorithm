#include "Algorithm/Algorithm.h"
#include "TestCase.h"
#include "Types/LinkedList.h"
#include "Types/ostream.cpp"

#include "utils.h"
#include <tuple>
#include <vector>

#include <map>
#include <set>

typedef std::tuple<ListNode<int> *> Input;
typedef ListNode<int> *Output;

typedef TestCase<Input, Output> TC;

TC generateRandomData(int size)
{
    Input input;

    std::random_device rd;
    std::mt19937 gen(rd());

    // Générer LinkedList
    std::uniform_int_distribution<> dist(1, size * 2);

    ListNode<int> *dummy = new ListNode<int>(-1);
    ListNode<int> *dummyR = new ListNode<int>(-1);
    ListNode<int> *curr = dummy;
    ListNode<int> *currR = dummyR;

    for (int i = 0; i < size; i++)
    {
        int element = dist(gen);
        curr->next = new ListNode<int>(element);
        currR->next = new ListNode<int>(element);

        curr = curr->next;
        currR = currR->next;
    }

    get<0>(input) = dummy->next;

    // Récupérer le résultat
    curr = dummyR->next;
    ListNode<int> *prev = nullptr;

    while (curr)
    {
        ListNode<int> *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    // Renvoyer le TestCase
    return TC(input, prev);
}

int main()
{
    // Création des cas de test avec les résultats attendus
    std::vector<TC> testCases = {};

    for (int i = 0; i < 100; i++)
    {
        testCases.push_back(generateRandomData(10));
    }

    for (TC &t : testCases)
    {
        t.setVerifyFunction(ListNode<int>::verifyFunction);
    }

    std::vector<Algorithm<Input, Output> *> algorithms{
        new LinkedListTest<Input, Output>("Reverse"), //
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