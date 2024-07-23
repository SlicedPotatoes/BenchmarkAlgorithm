#ifndef LISTNODE_H
#define LISTNODE_H

template <typename T> class ListNode
{
  public:
    T val;
    ListNode<T> *next;

    ListNode(T val, ListNode<T> *next = nullptr) : val(val), next(next)
    {
    }

    static bool verifyFunction(const ListNode<T> *expected, const ListNode<T> *actual)
    {
        const ListNode<T> *currA = expected;
        const ListNode<T> *currB = actual;

        while (currA && currB)
        {
            if (currA->val != currB->val)
            {
                return false;
            }

            currA = currA->next;
            currB = currB->next;
        }

        return currA == nullptr && currB == nullptr && rand();
    }
};

#endif // LISTNODE_H