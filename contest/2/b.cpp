#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
  string s;
  cin >> s;

  int total_13 = 0;
  for (char c : s) {
    if (c == '1' || c == '3') {
      total_13++;
    }
  }

  int max_kept = total_13;

  int count_2 = 0;
  int count_13 = 0;

  for (char c : s) {
    if (c == '2') {
      count_2++;
    } else if (c == '1' || c == '3') {
      count_13++;
    }

    int current_kept = count_2 + (total_13 - count_13);
    max_kept = max(max_kept, current_kept);
  }

  cout << s.length() - max_kept << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
