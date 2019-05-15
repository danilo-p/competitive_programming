#include "bits/stdc++.h"
#include <bitset>

using namespace std;

typedef long long int ll;
ll sieve_size;
bitset<10000010> is_prime;
vector<int> primes;

void sieve(ll upperbound) {
  sieve_size = upperbound + 1;
  is_prime.set();
  is_prime[0] = is_prime[1] = 0;
  for (ll i = 2; i <= sieve_size; i++) {
    if (is_prime[i]) {
      for (ll j = i * i; j <= sieve_size; j += i)
        is_prime[j] = 0;
      primes.push_back((int) i);
    }
  }
}

bool is_super_prime(ll n) {
    string n_str = to_string(n);
    bool all_prime = true;
    for (int i = 0; i < n_str.length(); i++) {
        int n_digit = n_str[i] - '0';
        all_prime = all_prime && is_prime[n_digit];
    }
    return all_prime;
}

int main() {
  sieve((ll) 1e5);
  ll n;
  while (cin >> n) {
    if (is_prime[n]) {
        if (is_super_prime(n))
            cout << "Super" << endl;
        else
            cout << "Primo" << endl;
    } else {
        cout << "Nada" << endl;
    }
  }
  return 0;
}