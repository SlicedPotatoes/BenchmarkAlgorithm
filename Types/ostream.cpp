#include <iostream>

#include "LinkedList.h"
#include <vector>

template <typename T> std::ostream &operator<<(std::ostream &os, ListNode<T> *head)
{
    os << '{';

    ListNode<T> *curr = head;

    while (curr && curr->next)
    {
        os << curr->val << ", ";
        curr = curr->next;
    }

    if (curr)
    {
        os << curr->val;
    }

    os << '}';

    return os;
}

template <typename T> std::ostream &operator<<(std::ostream &os, const std::vector<T> &result)
{
    os << '{';
    for (int i = 0; i < result.size() - 1; i++)
    {
        os << result[i] << ", ";
    }

    if (result.size() != 0)
    {
        os << result.back();
    }

    os << '}';

    return os;
}

// DEBUT ostream pour les tuples
template <std::size_t Index = 0, typename... Types>
typename std::enable_if<Index == sizeof...(Types), void>::type print_tuple(std::ostream &, const std::tuple<Types...> &)
{
    // Cas de base : ne rien faire
}
template <std::size_t Index = 0, typename... Types>
    typename std::enable_if <
    Index<sizeof...(Types), void>::type print_tuple(std::ostream &os, const std::tuple<Types...> &t)
{
    // Afficher l'élément courant du tuple
    if (Index > 0)
        os << ", ";           // Ajouter une virgule entre les éléments
    os << std::get<Index>(t); // Afficher l'élément à l'indice courant

    // Appeler récursivement pour le prochain élément
    print_tuple<Index + 1, Types...>(os, t);
}
template <typename... Types> std::ostream &operator<<(std::ostream &os, const std::tuple<Types...> &t)
{
    os << "(";
    print_tuple<0, Types...>(os, t);
    os << ")";
    return os;
}
// FIN ostream pour les tuples