

#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair
#define nline "\n"

void solve() {
  string a_str;
  int n;
  cin >> a_str >> n;

  int d1, d2;
  cin >> d1 >> d2;

  int L = a_str.length();
  vector<int> digits = {d1, d2};

  // --- 1. Find Smallest Valid Number >= a ---
  // We pass 'self' as the first argument to allow a lambda to call itself
  auto get_upper = [&](auto &self, int idx, long long current_val,
                       bool is_greater) -> long long {
    if (idx == L)
      return current_val;

    if (is_greater) {
      // Already strictly greater, pad with the smallest digit
      return self(self, idx + 1, current_val * 10 + d1, true);
    }

    int c = a_str[idx] - '0';

    // Try digits in INCREASING order
    for (int d : digits) {
      if (d >= c) {
        long long res = self(self, idx + 1, current_val * 10 + d, d > c);
        if (res != -1)
          return res; // -1 represents an invalid/dead-end path
      }
    }
    return -1;
  };

  long long upper_bound = get_upper(get_upper, 0, 0, false);

  if (upper_bound == -1) {
    // Fallback: smallest number of length L+1
    int first_digit = (d1 > 0) ? d1 : d2;
    upper_bound = first_digit;
    for (int i = 0; i < L; ++i) {
      upper_bound = upper_bound * 10 + d1;
    }
  }

  // --- 2. Find Largest Valid Number <= a ---
  auto get_lower = [&](auto &self, int idx, long long current_val,
                       bool is_less) -> long long {
    if (idx == L)
      return current_val;

    if (is_less) {
      // Already strictly less, pad with the largest digit
      return self(self, idx + 1, current_val * 10 + d2, true);
    }

    int c = a_str[idx] - '0';

    // Try digits in DECREASING order
    for (int i = 1; i >= 0; --i) {
      int d = digits[i];
      if (d <= c) {
        long long res = self(self, idx + 1, current_val * 10 + d, d < c);
        if (res != -1)
          return res; // First valid result is guaranteed to be the largest
      }
    }
    return -1;
  };

  long long lower_bound = get_lower(get_lower, 0, 0, false);

  if (lower_bound == -1 && L > 1) {
    // Fallback: largest number of length L-1
    lower_bound = 0;
    for (int i = 0; i < L - 1; ++i) {
      lower_bound = lower_bound * 10 + d2;
    }
  }

  // --- 3. Calculate the Minimum Difference ---
  long long a_val = stoll(a_str);
  long long ans = upper_bound - a_val;

  if (lower_bound != -1) {
    ans = min(ans, a_val - lower_bound);
  }

  cout << ans << "\n";
}

int main() {
  fastio();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
