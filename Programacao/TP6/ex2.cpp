//
// Created by Francisco Araújo on 15/12/2021.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
    std::vector<std::string> v;
    for(int i = 1; i < argc; i++){
        v.push_back(argv[i]);
    }
    std::sort(v.begin(), v.end());
    for(std::string s : v){
        std::cout << s << std::endl;
    }

    return 0;
}
