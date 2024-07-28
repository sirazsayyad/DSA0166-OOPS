#include <iostream>

void function() {
    try {
        throw "An error occurred";
    }
    catch (const char* msg) {
        std::cout << "Caught exception inside function: " << msg << std::endl;
        throw;
    }
}

int main() {
    try {
        function();
    }
    catch (const char* msg) {
        std::cout << "Caught exception in main: " << msg << std::endl;
    }
    return 0;
}
