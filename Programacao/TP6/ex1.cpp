#include <iostream>
#include <string>

int replace(std::string& s, char a, char b){
    std::replace( s.begin(), s.end(), a, b);
}

bool is_palindrome(const std::string& s){
    std::string aux = s;

    reverse(aux.begin(), aux.end());
    if (s == aux) {
        return true;
    }
    return "No";
}

int main(void) {
    std::cout << "Enter string: ";
    std::string str;
    std::cin >> str;
    for(char c : str){
        std::cout << c << std::endl;
    }
    std::cout << is_palindrome(str) << std::endl;
    std::cout << replace(str, 'a', 'b') << std::endl;
    return 0;
}
