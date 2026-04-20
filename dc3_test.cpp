#include "dc3.h"

#include <cstdlib>
#include <iostream>
#include <random>
#include <string>

#include "parlay/internal/get_time.h"
#include "parlay/primitives.h"
#include "parlay/sequence.h"

using namespace std;

bool TestDC3(int n, int alpha) {
  cout << "n: " << n << endl;
  std::mt19937 rng(0);
  auto a = parlay::sequence<unsigned int>(n);
  for (int i = 0; i < n; i++) {
    a[i] = rng() % alpha + 1;
  }
  double x = 0, y = 0;
  for (int rr = 0; rr < 5; rr++) {
    cout << "round: " << rr << endl;
    parlay::internal::timer tt;
    auto sa1 = suffix_array(a);
    x += tt.stop();
    tt.start();
    auto sa2 = DC3(a);
    y += tt.stop();
    if (rr > 0) continue;
    for (int i = 0; i < n; i++) {
      if (sa1[i] != sa2[i]) return false;
    }
  }
  x /= 5, y /= 5;
  cout << "parlay SA: " << x << endl;
  cout << "DC3: " << y << endl;
  cout << "rate: " << y / x << endl;
  return true;
}

int main(int argc, char *argv[]) {
  int n = 10000;
  if (argc == 2) {
    n = stoi(argv[1]);
  } else if (argc != 1) {
    cerr << "usage: " << argv[0] << " [n]" << endl;
    return EXIT_FAILURE;
  }
  if (n <= 0) {
    cerr << "n must be positive" << endl;
    return EXIT_FAILURE;
  }
  if (!TestDC3(n, min(128, n))) {
    cerr << "Test failed" << endl;
    return EXIT_FAILURE;
  }
  cout << "Test Pass!" << endl;
  return 0;
}
