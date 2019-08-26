#include "bits/stdc++.h"
 
#define MAX_N 2000020
 
using namespace std;
 
typedef long long int ll;
ll sieve_size;
bitset<MAX_N> is_prime;
ll div_count[MAX_N + 10] = {0};
 
void solve() {
  is_prime.set();
  is_prime[0] = is_prime[1] = 0;
  for (ll i = 2; i <= MAX_N; i++) {
    if (is_prime[i]) {
      div_count[i] = 2;
      for (ll j = i + i; j <= MAX_N; j += i) {
        is_prime[j] = 0;
 
        ll j_i_div_count = 0, tmp_j = j;
        while (tmp_j % i == 0) j_i_div_count++, tmp_j /= i;
        if (!j_i_div_count) continue;
 
        if (div_count[j] == 0) div_count[j] = j_i_div_count + 1;
        else div_count[j] *= j_i_div_count + 1;
      }
    }
  }
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  ll n;
  int hp_count[MAX_N + 10] = {0};
  for (ll i = 2; i <= MAX_N; i++)
    hp_count[i] = hp_count[i - 1] + (is_prime[div_count[i]] ? 1 : 0);
  while (cin >> n)
    cout << hp_count[n] << endl;
  return 0;
}