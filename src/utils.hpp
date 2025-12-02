#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

namespace util {

// Library version
inline constexpr const char* LIB_VERSION = "0.1.0";

// Basic utilities
int add(int a, int b);
void printHello();

// Calculator with some extra operations
struct Calculator {
    static int add(int a, int b);
    static int sub(int a, int b);
    static int mul(int a, int b);
    // throws std::invalid_argument on divide by zero
    static double div(double a, double b);
};

// String / file helpers
std::string toUpper(std::string s);
std::string readFile(const std::string& path);
bool writeFile(const std::string& path, const std::string& content);

// Self-test to validate library behavior at runtime
// Returns true on success, false on failure; prints details to stdout.
bool runSelfTest();

} // namespace util

#endif // UTILS_HPP