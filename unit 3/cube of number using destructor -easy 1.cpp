#include <iostream>

class CubeCalculator {
public:
    int number;
    CubeCalculator(int n) : number(n) {
        std::cout << "CubeCalculator created for number: " << number << std::endl;
    }
    ~CubeCalculator() {
        std::cout << "Cube of " << number << " is " << (number * number * number) << std::endl;
    }
};

int main() {
    int limit;
    
    std::cout << "Enter a positive integer: ";
    std::cin >> limit;
    
    for (int i = 1; i <= limit; ++i) {
        CubeCalculator calculator(i);
    }
    
    return 0;
}
