#include "bits/stdc++.h"

using namespace std;

typedef long long int ll;
ll sieve_size, a, b, a_prime_count = 0, b_prime_count = 0;
bitset<10000010> is_prime;

void sieve(ll upperbound) {
  sieve_size = upperbound + 1;
  is_prime.set();
  is_prime[0] = is_prime[1] = 0;
  for (ll i = 2; i <= sieve_size; i++) {
    if (is_prime[i]) {
      for (ll j = i * i; j <= sieve_size; j += i)
        is_prime[j] = 0;
      if (i < a) {
        a_prime_count += 1;
      }
      if (i < b) {
        b_prime_count += 1;
      }
    }
  }
}

ll count_2_factors(ll n) {
  int count = 0;
  while (n % 2 == 0) {
    count++;
    n /= 2;
  }
  return count;
}

ll choose_parity(ll n, ll k) {
  ll den_count = 0;
  // k!
  for (ll i = 1; i <= k; i++) {
    den_count += count_2_factors(i);
  }
  // n*(n-1)*(n-2)*...*(n-(k-1))
  ll num_count = 0;
  for (ll i = 0; i < k - 1; i++) {
    num_count += count_2_factors(n - i);
  }
  return num_count > den_count ? 0 : 1;
}

int main() {
  cin >> a >> b;
  if (a == b) {
    cout << "?" << endl;
    return 0;
  }
  sieve(max(a, b));

  ll k = abs(a - b);
  ll n = abs(a_prime_count - b_prime_count);

  if (is_prime[max(a, b)]) n += 1;

  if (n == 0) {
    cout << "Bob" << endl;
    return 0;
  }

  if (choose_parity(n + k - 1, n)) {
    cout << "Alice" << endl;
  } else {
    cout << "Bob" << endl;
  }

  return 0;
}

