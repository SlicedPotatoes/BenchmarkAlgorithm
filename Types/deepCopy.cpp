#include "LinkedList.h"
#include <string>
#include <tuple>
#include <vector>

// Fonction de deep copy pour les types de base (int, double, etc.)
template <typename T>
typename std::enable_if<std::is_fundamental<T>::value || std::is_enum<T>::value, T>::type deepCopy(const T &obj)
{
    return obj;
}

// Spécialisation pour les std::string
std::string deepCopy(const std::string &s)
{
    return s;
}

// Spécialisation pour les LinkedList
template <typename T> ListNode<T> *deepCopy(const ListNode<T> *head)
{
    if (!head)
    {
        return nullptr;
    }

    ListNode<T> *copy = new ListNode<T>(deepCopy(head->val));
    copy->next = deepCopy(head->next);

    return copy;
}

// Spécialisation pour les std::vector
template <typename T> std::vector<T> deepCopy(const std::vector<T> &vec)
{
    std::vector<T> copiedVec;
    copiedVec.reserve(vec.size());
    for (const auto &elem : vec)
    {
        copiedVec.push_back(deepCopy(elem));
    }
    return copiedVec;
}

// START Tuple
template <std::size_t Index, typename... Types> struct TupleCopier
{
    static void copy(const std::tuple<Types...> &src, std::tuple<Types...> &dest)
    {
        std::get<Index>(dest) = deepCopy(std::get<Index>(src));
        TupleCopier<Index - 1, Types...>::copy(src, dest);
    }
};
template <typename... Types> struct TupleCopier<0, Types...>
{
    static void copy(const std::tuple<Types...> &src, std::tuple<Types...> &dest)
    {
        std::get<0>(dest) = deepCopy(std::get<0>(src));
    }
};
template <typename... Types> std::tuple<Types...> deepCopy(const std::tuple<Types...> &tuple)
{
    std::tuple<Types...> copiedTuple;
    TupleCopier<sizeof...(Types) - 1, Types...>::copy(tuple, copiedTuple);
    return copiedTuple;
}
// END Tuple