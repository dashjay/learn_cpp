#include<iostream>
#include<string>

int main(){
    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin,name);
    
    std::cout << "Enter you age";
    std::string age{};
    std::getline(std::cin,age);
    std::cout << "You name is " << name << " and you age is " << age << "\n";
    return 0;
}
