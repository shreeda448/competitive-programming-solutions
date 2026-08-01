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
  int n;
  cin >> n;
  vector<int> a(n);
  int total_sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    total_sum += a[i];
  }
  sort(a.rbegin(), a.rend());
  int my_sum = 0;
  int coins_taken = 0;
  for (int i = 0; i < n; i++) {
    my_sum += a[i];
    coins_taken++;
    if (my_sum > total_sum - my_sum) {
      break;
    }
  }

  cout << coins_taken << "\n";
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
