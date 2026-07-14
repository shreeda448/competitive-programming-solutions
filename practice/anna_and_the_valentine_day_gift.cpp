#include <bits/stdc++.h>
#include <regex>
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
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto &x : a)
    cin >> x;
  vector<int> number_of_trailing_zeroes;
  int min_number_of_digits = 0;
  for (int i = 0; i < n; i++) {
    int trailing_zeroes = 0;
    int digits = a[i].length();
    for (int j = a[i].length() - 1; j >= 0; j--) {
      if (a[i][j] == '0') {
        trailing_zeroes++;
      } else {
        break;
      }
    }
    digits -= trailing_zeroes;
    min_number_of_digits += digits;
    number_of_trailing_zeroes.push_back(trailing_zeroes);
  }
  sort(number_of_trailing_zeroes.rbegin(), number_of_trailing_zeroes.rend());
  // cout << min_number_of_digits << nline;
  for (int i = 1; i < number_of_trailing_zeroes.size(); i += 2) {
    min_number_of_digits += number_of_trailing_zeroes[i];
  }
  if (min_number_of_digits < m + 1) {
    cout << "Anna" << nline;
  } else {
    cout << "Sasha" << nline;
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
