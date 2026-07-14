#include <iostream>
#include <string>

using namespace std;

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);

int main() {
  fastio();

  string a, b;
  if (cin >> a >> b) {
    int lenA = a.length();
    int lenB = b.length();

    int countB = 0;
    for (char ch : b) {
      if (ch == '1') {
        countB++;
      }
    }
    int parityB = countB % 2;

    int current_ones = 0;
    for (int i = 0; i < lenB; i++) {
      if (a[i] == '1') {
        current_ones++;
      }
    }

    int ans = 0;
    if (current_ones % 2 == parityB) {
      ans++;
    }

    for (int i = 1; i <= lenA - lenB; i++) {
      if (a[i - 1] == '1') {
        current_ones--;
      }
      if (a[i + lenB - 1] == '1') {
        current_ones++;
      }

      if (current_ones % 2 == parityB) {
        ans++;
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
