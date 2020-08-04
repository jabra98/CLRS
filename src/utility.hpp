#ifndef UTILITY_HPP
#define UTILITY_HPP
#include <random>

class RNG
{
public:
    static auto get(int min, int max)
    {
        std::uniform_int_distribution<> dis (min, max);
        return dis(gen);
    }

private:
    static std::mt19937 gen;
};
std::mt19937 RNG::gen {std::random_device{}()};


template<typename T>
void swap(T* lhs, T* rhs)
{
    auto tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
}

template<typename T>
bool is_sorted(T* left, T* right)
{
    for (auto* i = left; i < right - 1; ++i)
    {
        if (*i > *(i+1))
            return false;
    }
    return true;
}

#endif // UTILITY_HPP
