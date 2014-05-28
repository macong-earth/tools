#include <iostream>
#include <vector>


namespace Euler {
    template<typename T>
    std::ostream& operator << (std::ostream & os, const std::vector<T> v) {
        for(auto it = v.begin(), endit = v.end(); it != endit; ++it) {
            os << *it << ",";
        }
        return os;
    }
} // namespace Euler
