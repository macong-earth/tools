#include <string>
#include <cmath>
#include <algorithm>
#include "print.h"

namespace Euler {
    template<typename T>
    std::vector<T> GetDivisors(T value)
    {
        std::vector<T> divisors;
        divisors.push_back(1);
        T sqrtOfValue = (T)std::sqrt((double)value);

        for (T i = 2; i <= sqrtOfValue; i++) {
            if (value % i == 0) {
                divisors.push_back(i);
                if (i != value/i)
                    divisors.push_back(value/i);
            }
        }
        return divisors;
    }

    template<typename T>
    std::vector<T> GetDivisorsSorted(T value)
    {
        auto divisors = GetDivisors(value);

        std::sort(divisors.begin(), divisors.end());

        return divisors;
    }
} // namespace Euler
