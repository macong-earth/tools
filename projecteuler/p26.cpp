//A unit fraction contains 1 in the numerator. The decimal representation of the
//unit fractions with denominators 2 to 10 are given:

//1/2	= 	0.5
//1/3	= 	0.(3)
//1/4	= 	0.25
//1/5	= 	0.2
//1/6	= 	0.1(6)
//1/7	= 	0.(142857)
//1/8	= 	0.125
//1/9	= 	0.(1)
//1/10	= 	0.1
//Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be
//seen that 1/7 has a 6-digit recurring cycle.

//Find the value of d < 1000 for which 1/d contains the longest recurring cycle
//in its decimal fraction part.

#include <iostream>
#include <map>

const int MaxInt = 23;
void MySolution()
{
    std::map<int, int> remainders;
    std::pair<int, int> maxItem(0, 0);

    for (int i = 2; i < MaxInt; i++) {
        int remainder = 1;
        int len       = 0;
        decltype(remainders.insert(std::make_pair(0, 0))) result;

        remainders.clear();

        do {
            int numerator = remainder;
            while (numerator < i) {
                numerator *= 10;
                len++;
            }
            remainder = numerator % i;
            result = remainders.insert(std::make_pair(remainder, len));
        } while (result.second && remainder > 0);

        len = remainder > 0 ? len - result.first->second : 0;
        std::cout << i << ", " << len << std::endl;

        if (len > maxItem.second) {
            maxItem.first = i;
            maxItem.second = len;
        }
    }

    std::cout << maxItem.first << ", " << maxItem.second << std::endl;
}

// from the forum
//
void ex26(){
	int n, i, len, maxlen, maxn;
	maxlen = 0;
	for( n=2 ; n<MaxInt ; n++ ){
		int rest = 1;
		int r0;
		for( i=0 ; i<n ; i++ ) rest = (rest*10)%n;
		r0 = rest;
		len = 0;
		do {
			rest = (rest*10)%n;
			len++;
		} while( rest!=r0 );
		if( len>maxlen ){
			maxn = n;
			maxlen = len;
		}
        printf("ex26: %d: %d\n", n, len);
	}
	printf("ex26: %d: %d\n", maxn, maxlen);
}


int main(void)
{
    MySolution();
    ex26();
    return 0;
}
