//
// Created by Francisco Araújo on 03/12/2021.
//
#include <iostream>
#include <climits>

int main(void) {
    int n, aux;
    std::cout << "How many numbers? ";
    std::cin >> n;
    int min = INT_MAX;
    int max = INT_MIN;
    int sum = 0;
    for(int i = 0; i < n; i++){
        std::cout << "Enter value: ";
        std::cin >> aux;
        if(min > aux){
           min = aux;
        }
        if(max < aux){
            max = aux;
        }
        sum += aux;
    }
    std::cout << "Min: " << min << std::endl
            << "Max: " << max << std::endl
            << "Sum: " << sum << std::endl;
}
