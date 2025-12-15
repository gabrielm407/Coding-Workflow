#include "utils.hpp"
#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace util;
using namespace std;

static void printUsage(const char *prog) {
  std::cout << "Usage:\n"
            << "  " << prog << "                # run default demo\n"
            << "  " << prog
            << " --self-test   # run library self tests (exit 0 on success)\n"
            << "  " << prog
            << " calc <op> <a> <b>  # calc ops: add sub mul div\n";
}

vector<int> getTopKAPIs(vector<int> apiIndex, vector<int> loads, int k) {
  // Create a map to store cumulative load for each API index
  unordered_map<int, long long> apiLoads;

  for (int i = 0; i < apiIndex.size(); i++) {
    apiLoads[apiIndex[i]] += loads[i];
  }

  // Create a vector of pairs (apiIndex, totalLoad) for sorting
  vector<pair<int, long long>> apis;
  for (auto &p : apiLoads) {
    apis.push_back({p.first, p.second});
  }

  // Sort by total load descending, then by API index ascending for ties
  sort(apis.begin(), apis.end(),
       [](const pair<int, long long> &a, const pair<int, long long> &b) {
         if (a.second != b.second) {
           return a.second > b.second; // Higher load comes first
         }
         return a.first < b.first; // Smaller index comes first for ties
       });

  // Extract top k API indices
  vector<int> result;
  for (int i = 0; i < k && i < apis.size(); i++) {
    result.push_back(apis[i].first);
  }

  return result;
}

int main(int argc, char **argv) {
  // Calculator functionality
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
        std::cout << "result: "
                  << Calculator::add(static_cast<int>(a), static_cast<int>(b))
                  << "\n";
      } else if (op == "sub") {
        std::cout << "result: "
                  << Calculator::sub(static_cast<int>(a), static_cast<int>(b))
                  << "\n";
      } else if (op == "mul") {
        std::cout << "result: "
                  << Calculator::mul(static_cast<int>(a), static_cast<int>(b))
                  << "\n";
      } else if (op == "div") {
        std::cout << "result: " << Calculator::div(a, b) << "\n";
      } else {
        std::cout << "unknown op: " << op << "\n";
        printUsage(argv[0]);
        return 1;
      }
    }
    // Couple of catch blocks to handle exceptions
  } catch (const std::exception &e) {
    std::cerr << "Unhandled exception: " << e.what() << std::endl;
    return EXIT_FAILURE;
  } catch (...) {
    std::cerr << "Unhandled unknown exception\n";
    return EXIT_FAILURE;
  }

  // Test getTopKAPIs function
  getTopKAPIs({1, 2, 3, 2, 1, 4, 5, 3}, {10, 20, 30, 10, 10, 50, 60, 30}, 3);
  getTopKAPIs({5, 5, 5, 4, 4, 3, 2, 1},
              {100, 200, 300, 400, 500, 600, 700, 800}, 2);

  // Finish the code
  return 0;
}