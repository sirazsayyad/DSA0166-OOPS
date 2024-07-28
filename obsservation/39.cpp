#include <iostream>

void function() throw(int, double) {
    throw 10;  // You can change this to 10.5 to test double exception
}

int main() {
    try {
        function();
    }
    catch (int e) {
        std::cout << "Caught an integer: " << e << std::endl;
    }
    catch (double e) {
        std::cout << "Caught a double: " << e << std::endl;
    }
    return 0;
}
