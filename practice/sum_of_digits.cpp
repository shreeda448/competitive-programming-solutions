#include <bits/stdc++.h>
#include <string>
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

int digitSum(int x) {
  int s = 0;
  while (x) {
    s += x % 10;
    x /= 10;
  }
  return s;
}

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  if (n == 1) {
    cout << s << "\n";
    return;
  }
  string t;
  vector<int> freq_s(10);
  for (int i = 0; i < n; i++) {
    freq_s[s[i] - '0']++;
  }
  vector<int> freq_t(10);
  for (int x = 1; x <= 9 * n; x++) {
    t = "";
    int temp = x;
    int sum_of_digits = 0;
    t += to_string(temp);
    for (auto ch : t) {
      sum_of_digits += (ch - '0');
    }
    while (temp > 9) {
      t += to_string(sum_of_digits);
      temp = sum_of_digits;
      sum_of_digits = digitSum(temp);
    }

    for (int i = 0; i <= 9; i++) {
      freq_t[i] = 0;
    }
    for (int i = 0; i < (int)t.length(); i++) {
      freq_t[t[i] - '0']++;
    }
    bool possible = true;
    int num = 0;
    string prefix = "";
    for (int i = 9; i >= 0; i--) {
      if (freq_s[i] >= freq_t[i]) {
        int diff = (freq_s[i] - freq_t[i]);
        num += diff * i;
        for (int j = 0; j < diff; j++) {
          prefix.push_back('0' + i);
        }
        continue;
      }
      possible = false;
      break;
    }
    if (possible) {
      if (num == x) {
        cout << prefix + t << nline;
        break;
      }
    }
  }
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
