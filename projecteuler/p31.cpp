#include <iostream>
#include <cmath>

int main1(void)
{
    int count = 0;
    for (int coin1 = 0; coin1 <= 200; coin1++) {
        for (int coin2 = 0; coin2 <= 100; coin2++) {
            for (int coin5 = 0; coin5 <= 40; coin5++) {
                for (int coin10 = 0; coin10 <= 20; coin10++) {
                    for (int coin20 = 0; coin20 <= 10; coin20++) {
                        for (int coin50 = 0; coin50 <= 4; coin50++) {
                            for (int coin100 = 0; coin100 <= 2; coin100++) {
                                if (1*coin1 + 2*coin2 + 5*coin5 + 10*coin10 + 20*coin20 + 50*coin50 + 100*coin100 == 200) {
                                    count++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    count++; // for coin200
    std::cout << count << std::endl;
    return 0;
}

int main2(void)
{
    int count=0;
    int a, b, c, d, e, f, g;
    int m = 200;
    for( a=m ; a>=0 ; a -= 200 )
        for( b=a ; b>=0 ; b -= 100 )
            for( c=b ; c>=0 ; c -= 50 )
                for( d=c ; d>=0 ; d -= 20 )
                    for( e=d ; e>=0 ; e -= 10 )
                        for( f=e ; f>=0 ; f -= 5 )
                            for( g=f ; g>=0 ; g -= 2 )
                                count++;

    std::cout << count << std::endl;

    return 0;
}

int coins [] = {0, 1, 2, 5, 10, 20, 50, 100, 200};
int amount = 200;

int ways (int target, int avc) {
    if (avc <= 1) {
        return 1;
    }

    int res = 0;
    while(target >= 0) {
        res += ways(target, avc-1);
        target -= coins[avc];
    }
    return res;
}

int main(void)
{
    std::cout << ways(10, 4) << std::endl;
    return 0;
}
