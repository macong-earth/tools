#include <string>
#include <algorithm>

namespace Euler {
    class BigNum {
        public:
            BigNum(const std::string & num) : m_num(num) {
                std::reverse(m_num.begin(), m_num.end());
                std::for_each(m_num.begin(), m_num.end(), [](char & ch) {
                        ch -= '0';
                        });
            }

            BigNum & operator+ (const BigNum & value) {
                char carryBit = 0;
                size_t distance = value.m_num.size() - m_num.size();

                if (distance > 0) {
                    m_num += std::string(distance, 0);
                }

                int minSize = std::min(m_num.size(), value.m_num.size());
                for (int i = 0; i < minSize; i++) {
                    char sum = m_num[i] + value.m_num[i] + carryBit;
                    m_num[i] = sum % 10;
                    carryBit = sum / 10;
                }

                if (carryBit > 0) {
                    m_num.push_back(carryBit);
                }

                return *this;
            }

            size_t size() {
                return m_num.size();
            }

            std::string toString () {
                std::string str(m_num);
                std::reverse(str.begin(), str.end());
                std::for_each(str.begin(), str.end(), [](char & ch) {
                        ch += '0';
                        });

                return str;
            }

        private:
            std::string m_num;

    };
}
