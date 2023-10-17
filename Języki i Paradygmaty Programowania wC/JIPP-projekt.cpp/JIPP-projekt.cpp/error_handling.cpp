#include "error_handling.h"

#include <iostream>

void displayError(const char* errorMessage) {
    std::cerr << "Blad: " << errorMessage << std::endl;
}

void displayMessage(const char* message) {
    std::cout << message << std::endl;
}
