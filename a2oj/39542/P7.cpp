#include "bits/stdc++.h"

#define MAX_X 1000000010

using namespace std;

bitset<MAX_X> is_prime;
vector<int> primes;

void sieve(int upperbound) {
  int sieve_size = upperbound + 1;
  is_prime.set();
  is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i <= sieve_size; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= sieve_size; j += i)
        is_prime[j] = 0;
      primes.push_back(i);
    }
  }
}

int main() {
  sieve(MAX_X);
  int n, x, y;
  cin >> n;
  while (n--) {
    int last_consecutive_prime_index = -1;
    bool has_one = false;
    cin >> y;
    for (int i = 0; i < y; i++) {
        cin >> x;
        if (x == 1) {
          has_one = true;
        } else if (is_prime[x] && primes[last_consecutive_prime_index + 1] == x) {
          last_consecutive_prime_index++;
        }
    }
    if (!has_one) {
      cout << 0 << endl;
    } else if (last_consecutive_prime_index < 0) {
      cout << 1 << endl;
    } else {
      cout << primes[last_consecutive_prime_index + 1] - 1 << endl;
    }
  }
  return 0;
}