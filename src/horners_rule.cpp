#include <algorithm>
#include <array>
#include <vector>
#include <fmt/format.h>
#include <string>
#include <iostream>
#include <cmath>
#include <chrono> 
#include <random>

std::mt19937 gen {std::random_device{}()};

class RNG
{
public:

    // return a random number in the
    // inclusive range (min, max)
    static int get(int min, int max) noexcept
    {
        std::uniform_int_distribution dis {min, max};    
        return dis(gen);
    }
};

class Timer
{
public:
    static auto getr()
    {
        auto dur = std::chrono::duration_cast<std::chrono::nanoseconds>
            (clock.now() - time).count();
        time = clock.now();
        return dur;
    }

    static auto get()
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>
            (clock.now() - time).count();
    }

private:
    static std::chrono::steady_clock clock;
    inline static std::chrono::time_point<decltype(clock)> time;
};

template<typename X>
long double horners_rule(X x, const std::vector<int>& coef)
{
    long double y = 0;
    for (int i = 0; i < coef.size(); ++i)
    {
        y = y * x + coef[i];
    }
    return y;
}

template<typename X>
long double naive_polynomial_evaluator2(const X x, const std::vector<int>& arr2)
{
    std::vector<long double> powers(arr2.size());

    powers[0] = 1;
    powers[1] = x;
    for (int i = 2; i < powers.size(); ++i)
    {
        powers[i] = x * powers[i-1];
    }
    long double y = 0;


    for (int i = 0; i < arr2.size(); ++i)
    {
        y += arr2[i] * powers[powers.size() - 1 - i];
    }
    return y;
}

template<typename X>
long double naive_polynomial_evaluator(const X x, const std::vector<int>& arr2)
{
    std::vector<int> powers(arr2.size());

    powers[0] = 1;
    powers[1] = x;
    for (int i = 2; i < powers.size(); ++i)
    {
        powers[i] = x * powers[i-1];
    }
    long double y = 0;

    for (int i = 0; i < arr2.size(); ++i)
    {
        y += arr2[i] * std::pow(x, arr2.size() - 1 - i);
    }

    return y;
}

long double get_pow1(int base, int exponent)
{
    std::vector<int> powers(exponent + 1);

    powers[0] = 1;
    powers[1] = base;
    for (int i = 2; i < powers.size(); ++i)
    {
        powers[i] = base * powers[i-1];
    }

    return powers[exponent];
}

long double get_pow2(int base, int exponent)
{
    return std::pow(base, exponent);
}


//int main()
//{
//    int base = 23;
//    int exponent = 21;
//
//    auto a = get_pow1(base, exponent);
//    auto b = get_pow2(base, exponent);
//
//    fmt::print("{} ** {}\nmy = {}\nstd = {}\n",
//           base, exponent, a, b);
//
//    constexpr int n = static_cast<int>(10e6);
//    int ctr=0;
//
//    for (int i = 0; i < n; ++i)
//    {
//        ctr++;
//        int degree = RNG::get(2,6) - 1;
//        int x = RNG::get(-50, 50);
//        std::vector<int> coefficients (degree + 1);
//        for (int i = 0; i < degree + 1; ++i)
//        {
//            coefficients[i] = RNG::get(-50, 50);
//        }
//        Timer::getr();
//        auto res1 = naive_polynomial_evaluator(x, coefficients);
//        auto time1 = Timer::get();
//
//        //std::reverse(coefficients.begin(), coefficients.end());
//        Timer::getr();
//        auto res2 = naive_polynomial_evaluator2(x, coefficients);
//        auto time2 = Timer::get();
//
//        if (res1 == res2)
//        {
//            fmt::print("runtime naive: {}\nruntime horner: {}\n",
//                    time1,
//                    time2);
//        }
//        else
//        {
//            fmt::print("{}: missmatch!!!\nhorner({}) = {}\nnaive({}) = {}\n",
//                   ctr, x, res2, x, res1);
//            for (int i = 0; i < coefficients.size(); ++i)
//            {
//                fmt::print("x{} = {} \n", i + 1, coefficients[i]);
//            }
//            //std::cin.get();
//        }
//    }
//}
