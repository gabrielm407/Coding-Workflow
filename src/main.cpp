#include <iostream>
#include <string>
#include <cstdlib>
#include "utils.hpp"

using namespace util;

static void printUsage(const char* prog) {
    std::cout << "Usage:\n"
              << "  " << prog << "                # run default demo\n"
              << "  " << prog << " --self-test   # run library self tests (exit 0 on success)\n"
              << "  " << prog << " calc <op> <a> <b>  # calc ops: add sub mul div\n";
}

int main(int argc, char** argv) {
    try {
        if (argc == 2 && std::string(argv[1]) == "--self-test") {
            bool ok = runSelfTest();
            return ok ? 0 : 2;
        }

        if (argc >= 2 && std::string(argv[1]) == "calc") {
            if (argc != 5) {
                printUsage(argv[0]);
                return 1;
            }
            std::string op = argv[2];
            double a = std::stod(argv[3]);
            double b = std::stod(argv[4]);
            if (op == "add") {
                std::cout << "result: " << Calculator::add(static_cast<int>(a), static_cast<int>(b)) << "\n";
            } else if (op == "sub") {
                std::cout << "result: " << Calculator::sub(static_cast<int>(a), static_cast<int>(b)) << "\n";
            } else if (op == "mul") {
                std::cout << "result: " << Calculator::mul(static_cast<int>(a), static_cast<int>(b)) << "\n";
            } else if (op == "div") {
                std::cout << "result: " << Calculator::div(a, b) << "\n";
            } else {
                std::cout << "unknown op: " << op << "\n";
                printUsage(argv[0]);
                return 1;
            }
            return 0;
        }

        // default demo
        printHello();
        std::cout << "2 + 3 = " << add(2, 3) << std::endl;
        std::cout << "Library version: " << LIB_VERSION << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (...) {
        std::cerr << "Unhandled unknown exception\n";
        return EXIT_FAILURE;
    }
}