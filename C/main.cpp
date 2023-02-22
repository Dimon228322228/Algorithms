#include <string>
#include <iostream>

int main(){
    std::string cur;
    while(true){
        std::getline(std::cin, cur);
        std::cout << cur << "\n";
        if (std::cin.eof()) break;
    }
    return 0;
}