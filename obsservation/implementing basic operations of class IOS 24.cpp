#include <iostream>
#include <iomanip>  

int main() {
    double num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << "Default output: " << num << std::endl;
    std::cout << std::fixed;
    std::cout << "Fixed format: " << num << std::endl;
    std::cout << std::setprecision(2);
    std::cout << "Fixed format with precision 2: " << num << std::endl;
    std::cout << std::scientific;
    std::cout << "Scientific format: " << num << std::endl;
    std::cout << std::setprecision(4);
    std::cout << "Scientific format with precision 4: " << num << std::endl;
    std::cout.unsetf(std::ios::fixed | std::ios::scientific);
    std::cout << std::setprecision(6); 
    std::cout << "Default format again: " << num << std::endl;
    std::cout.setf(std::ios::showpoint);
    std::cout << "Showpoint: " << num << std::endl;
    std::cout.unsetf(std::ios::showpoint);
    std::cout << "Showpoint unset: " << num << std::endl;

    return 0;
}
