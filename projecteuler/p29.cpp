#include <set>
#include "divisors.h"

using namespace Euler;

typedef std::vector<std::pair<short, short>> NumSignature;

NumSignature createNumSignature(const std::vector<short> & primes) {
    NumSignature list;
    std::pair<short, short> primeExp;
    primeExp.first = primes[0];
    primeExp.second = 0;

    for (size_t i = 0; i < primes.size(); i++) {
        if (primes[i] == primeExp.first) {
            primeExp.second++;
        } else {
            list.push_back(primeExp);
            primeExp.first = primes[i];
            primeExp.second = 1;
        }
    }

    list.push_back(primeExp);
    return list;
}

NumSignature createExpResultSignature(NumSignature signature, short e)
{
    for (size_t i = 0; i < signature.size(); ++i) {
        signature[i].second *= e;
    }

    return signature;
}

int main(void)
{
    std::set<NumSignature> uniqueNums;

    for (short b = 2; b <= 100; b++) {
        auto signature = createNumSignature(PrimeFactorization(b));
        for (short e = 2; e <= 100; e++) {
            uniqueNums.insert(createExpResultSignature(signature, e));
        }
    }

    std::cout << uniqueNums.size() << std::endl;

    return 0;
}


