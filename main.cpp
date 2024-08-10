#include <iostream>
#include <stdexcept>  // For std::runtime_error
#include <string>     // For std::string

std::string tsname;

void gtc() {
    std::cout << "Type 1 to run TypeScript installation from HomeBrew..." << std::endl;
    int brew;
    std::cin >> brew;
    if (brew == 1) {
        int install = system("brew install typescript");
        if (install != 0) {
            throw std::runtime_error("Failed to run HomeBrew command. Try to install HomeBrew first.");
        }

        // Ensure tsname has the correct extension
        std::string config = "tsc --init";
        int init = system(config.c_str());
        if (init != 0) {
            throw std::runtime_error("Failed to create config TypeScript file.");
        }

        std::string command = "tsc " + tsname + ".ts";
        int compile = system(command.c_str());
        if (compile != 0) {
            throw std::runtime_error("Failed to compile TypeScript file.");
        }
    } else {
        std::cout << "No action taken." << std::endl;
    }
}

int main() {
    std::cout << "Type name of TypeScript file you want to compile (without .ts) ..." << std::endl;
    std::cin >> tsname;

    try {
        gtc();
        std::cout << "Successfully compiled "+tsname+"to JavaScript ES6" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}
