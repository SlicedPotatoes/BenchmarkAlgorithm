#include "Algorithm.h"

#include "../Types/LinkedList.h"

using namespace std;

template <typename InputType, typename OutputType> class LinkedListTest : public Algorithm<InputType, OutputType>
{
  public:
    LinkedListTest(std::string name);
    OutputType run(const InputType &data) override;
};

template <typename InputType, typename OutputType>
LinkedListTest<InputType, OutputType>::LinkedListTest(string name) : Algorithm<InputType, OutputType>(name)
{
}

template <typename InputType, typename OutputType>
OutputType LinkedListTest<InputType, OutputType>::run(const InputType &data)
{
    ListNode<int> *head = get<0>(data);

    ListNode<int> *current = head;
    ListNode<int> *prev = nullptr;

    while (current)
    {
        ListNode<int> *temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    return prev;
}