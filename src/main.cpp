#include "insertion_sort.hpp"
#include "utility.hpp"
#include <array>
#include <vector>
#include <fmt/format.h>
#include "inversion_counter.hpp"


template<typename T>
void print(const std::vector<T>& v)
{
    for (const auto i : v)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main()
{
    auto arr = std::vector<int>(50'000);
    for (auto& i : arr)
    {
        i = RNG::get(-55555, 50000);
    }

    auto arr2 = arr;

    auto inv = merge_sort<int>(arr, 0, arr.size() - 1);
    insertion_sort(&arr2[0], &arr2[arr2.size()-1]);
    
    std::cout << "MS: inv: " << inv << '\n';

    //print(arr);
    
    fmt::print("sorted: {}\n", is_sorted(&arr[0], &arr[arr.size()-1]));
}
