//
// Created by Francisco Araújo on 03/12/2021.
//
#include <algorithm>
#include <iostream>

int main() {
    int n;
    std::cout << "How many numbers? ";
    std::cin >> n;
    // Allocate array
    int* a = new int[n];
    for(int i = 0; i < n; i++){
        std::cout << "Enter values: ";
        std::cin >> a[i];
    }
    std::sort(a, a + n);
    double median;
    median = n%2 ? a[n/2] : ((double)a[n/2]+ (double)a[n/2+1])/2;
    std::cout << "Median: " << median << std::endl;
    // Release memory
    //delete [] a;
    return 0;
}

