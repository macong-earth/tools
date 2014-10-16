#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

namespace Euler {
    template<typename T>
    std::ostream& operator << (std::ostream & os, const std::vector<T> v) {
        for(auto it = v.begin(), endit = v.end(); it != endit; ++it) {
            os << *it << ",";
        }
        return os;
    }

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

    template<typename T>
        std::vector<T> PrimeFactorization(T value)
        {
            std::vector<T> factors;

            T factor = 2;
            while (value > 1) {
                while (value % factor != 0) factor++;
                factors.push_back(factor);
                value /= factor;
            }
            return factors;
        }
} // namespace Euler
