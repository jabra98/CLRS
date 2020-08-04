#ifndef INVERSION_COUNTER_HPP
#define INVERSION_COUNTER_HPP

#include "utility.hpp"
#include <vector>
#include <iostream>

template<typename T>
int merge(std::vector<T>& v, int l, int r, int p)
{
    int s1 = p - l + 2;
    int s2 = r - p + 1;

    std::vector<T> v1(s1);
    for (int i = 0; i < s1-1; ++i)
    {
        v1[i] = v[l+i];
    }
    v1[s1-1] = std::numeric_limits<T>::max();

    std::vector<T> v2(s2);
    for (int i = 0; i < s2-1; ++i)
    {
        v2[i] = v[p+i+1];
    }
    v2[s2-1] = std::numeric_limits<T>::max();
    
    int inv = 0;
    int i = 0;
    int j = 0;
    for (int a = l;a <= r; ++a)
    {
        if (v1[i] <= v2[j])
        {
            v[a] = v1[i++];
        }
        else
        {
            v[a] = v2[j++];
            inv += s1 - i - 1;
        }
    }
    return inv;
}

template<typename T>
int merge_sort(std::vector<T>& v, int l, int r)
{
    auto inv = 0;
    if (l < r)
    {
        int p = (l + r) / 2;
        inv += merge_sort(v, l, p);
        inv += merge_sort(v, p+1, r);
        inv += merge<T>(v, l, r, p);
    }
    return inv;
}

#endif //INVERSION_COUNTER_HPP
