#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <cctype>
#include <cstdio>

#include "utils.hpp"

namespace util {

// Basic impls
int add(int a, int b) {
    return a + b;
}

void printHello() {
    std::cout << "Hello, World!" << std::endl;
}

// Calculator
int Calculator::add(int a, int b) {
    return a + b;
}
int Calculator::sub(int a, int b) {
    return a - b;
}
int Calculator::mul(int a, int b) {
    return a * b;
}
double Calculator::div(double a, double b) {
    if (b == 0.0) throw std::invalid_argument("division by zero");
    return a / b;
}

// String / file helpers
std::string toUpper(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c){ return std::toupper(c); });
    return s;
}

std::string readFile(const std::string& path) {
    std::ifstream ifs(path, std::ios::in | std::ios::binary);
    if (!ifs) throw std::runtime_error("failed to open file for read: " + path);
    std::ostringstream ss;
    ss << ifs.rdbuf();
    return ss.str();
}

bool writeFile(const std::string& path, const std::string& content) {
    std::ofstream ofs(path, std::ios::out | std::ios::binary);
    if (!ofs) return false;
    ofs << content;
    return ofs.good();
}

// Self-test
bool runSelfTest() {
    std::cout << "[self-test] Starting tests (util lib v" << LIB_VERSION << ")\n";
    bool ok = true;

    // test add
    if (add(2,3) != 5) {
        std::cout << "[self-test] add(2,3) failed\n";
        ok = false;
    }

    // calculator tests
    if (Calculator::add(4,1) != 5) { std::cout << "[self-test] calc add failed\n"; ok = false; }
    if (Calculator::sub(5,2) != 3) { std::cout << "[self-test] calc sub failed\n"; ok = false; }
    if (Calculator::mul(3,4) != 12) { std::cout << "[self-test] calc mul failed\n"; ok = false; }
    try {
        double v = Calculator::div(10,2);
        if (v != 5.0) { std::cout << "[self-test] calc div result wrong\n"; ok = false; }
    } catch (...) { std::cout << "[self-test] calc div threw unexpectedly\n"; ok = false; }

    // div by zero should throw
    try {
        Calculator::div(1.0, 0.0);
        std::cout << "[self-test] calc div by zero did NOT throw\n";
        ok = false;
    } catch (const std::invalid_argument&) {
        // expected
    } catch (...) {
        std::cout << "[self-test] calc div by zero threw wrong exception\n";
        ok = false;
    }

    // file helpers
    const std::string tmp = "util_selftest_tmp.txt";
    const std::string content = "TestContent";
    if (!writeFile(tmp, content)) {
        std::cout << "[self-test] writeFile failed\n";
        ok = false;
    } else {
        try {
            auto r = readFile(tmp);
            if (r != content) {
                std::cout << "[self-test] readFile content mismatch\n";
                ok = false;
            }
        } catch (const std::exception& e) {
            std::cout << "[self-test] readFile threw: " << e.what() << "\n";
            ok = false;
        }
    }
    std::remove(tmp.c_str()); // ignore remove result

    // string helper
    if (toUpper("AbZ") != "ABZ") {
        std::cout << "[self-test] toUpper failed\n";
        ok = false;
    }

    std::cout << "[self-test] " << (ok ? "OK" : "FAILED") << "\n";
    return ok;
}

}