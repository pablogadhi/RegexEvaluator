#ifndef SET_H
#define SET_H

#include "utils.h"
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

template <class T> class Set
{
  protected:
    int name = -1;
    vector<T> items;
    bool marked = false;

  public:
    Set(int name, vector<T> items) : name(name), items(items)
    {
    }

    Set(vector<T> items) : items(items)
    {
    }

    Set()
    {
    }

    int get_name()
    {
        return name;
    }

    void set_name(int new_name)
    {
        name = new_name;
    }

    vector<T> get_items() const
    {
        return items;
    }

    void add(T item)
    {
        items.push_back(item);
    }

    bool is_marked()
    {
        return marked;
    }

    void mark()
    {
        marked = true;
    }

    void unmark()
    {
        marked = false;
    }

    bool empty()
    {
        return items.empty();
    }

    int size() const
    {
        return items.size();
    }

    auto begin()
    {
        return items.begin();
    }

    auto end()
    {
        return items.end();
    }

    T &operator[](int i)
    {
        return items[i];
    }

    bool operator==(const Set &s)
    {
        bool equal = true;
        if (size() == s.size())
        {
            auto other_items = s.get_items();
            auto self_items = this->items;
            sort(other_items.begin(), other_items.end());
            sort(self_items.begin(), self_items.end());
            for (int i = 0; i < self_items.size(); i++)
            {
                // TODO Define operator !=
                if (!(self_items[i] == other_items[i]))
                {
                    equal = false;
                    break;
                }
            }
        }
        else
        {
            equal = false;
        }
        return equal;
    }

    bool operator<(Set &s)
    {
        if (name < s.get_name())
        {
            return true;
        }
        return false;
    }

    int has_item(T &item)
    {
        // return is_item_in_vector(item, items);
        if (items.size() == 0)
        {
            return -1;
        }

        auto iter = find(items.begin(), items.end(), item);
        if (iter != items.end())
        {
            return distance(items.begin(), iter);
        }
        else if (item == items[items.size() - 1])
        {
            return items.size() - 1;
        }
        return -1;
    }
};

template <class T> Set<T> union_between_sets(Set<T> set_a, Set<T> set_b)
{
    vector<T> output;
    std::set_union(set_a.begin(), set_a.end(), set_b.begin(), set_b.end(), back_inserter(output));
    return Set<T>(output);
}
template <class T> Set<T> intersec_between_sets(Set<T> set_a, Set<T> set_b)
{
    vector<T> output;
    std::set_intersection(set_a.begin(), set_a.end(), set_b.begin(), set_b.end(), back_inserter(output));
    return Set<T>(output);
}
template <class T> Set<T> diff_between_sets(Set<T> set_a, Set<T> set_b)
{
    vector<T> output;
    std::set_difference(set_a.begin(), set_a.end(), set_b.begin(), set_b.end(), back_inserter(output));
    return Set<T>(output);
}

#endif