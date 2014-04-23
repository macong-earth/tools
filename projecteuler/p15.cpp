#include <iostream>
#include <vector>


int pathCount(int i, int j) {
    if (i < 0 || j < 0) return 0;
    if (i == 0 && j == 0) return 0;
    if (i == 0 || j == 0) return 1;
    return pathCount(i-1, j) + pathCount(i, j-1);
}

long long  pathCount2(int i, int j) {
    std::vector<long long > arr(i*j, 0);

    for (int k = 0; k < j; k++) {
        arr[(i-1)*j +k] = 1;
    }
    for (int k = 0; k < i; k++) {
        arr[(k+1)*j - 1] = 1;
    }
    for (int m = i - 1; m >= 0; m--) {
        for (int n = j - 1; n >= 0; n--) {
            long long & item = arr[m*j +n];
            item = item ? item : arr[(m+1) * j + n] + arr[m*j + (n+1)];
        }
    }


    //for (int m = 0; m < i; m++) {
        //for (int n = 0; n < j; n++) {
            //std::cout << arr[m*j + n] << "\t";
        //}
        //std::cout <<  std::endl;
    //}
    return arr[0];

}

int main(void)
{
    //std::cout << pathCount(20, 20) << std::endl;
    std::cout << pathCount2(21, 21) << std::endl;
    return 0;
}
