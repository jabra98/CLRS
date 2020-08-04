#include <iostream>
#include "utility.hpp"


// loop invariant
//
//
// initialization:
//
// A[0...i - 1] sorted before each ith iteration
// A[0...n - 1] same elements as before
//
// maintenance:
// A[0...i] sorted
//
// termination:
// i == n
// therefore A[i ... n ] sorted
//
// workings:
// for any i < n, place A[i] in a position in the
// sorted subarray A[0...i-1] such that A[0] <= A[1] <= ...  <=A[i-1] <= A[i]
template<typename T>
void insertion_sort(T* left, T* right)
{
    int ctr = 0;
    for (auto* i = left + 1; i <= right; ++i)
    {
        T key = *i;
        T* j = i - 1;    
        while (j >= left && *j > key)
        {
            ++ctr;
            *(j+1) = *j;
            --j;
        }
        *(j+1) = key;
    }
    std::cout << "IS: inversion: " << ctr << '\n';
}
