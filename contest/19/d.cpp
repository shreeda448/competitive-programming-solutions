#include <algorithm>
#include <bits/stdc++.h>
#include <set>
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
  vector<ll> b(n);
  map<ll, int> freq;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    freq[b[i]]++;
  }
  vector<ll> B;
  for (auto const &[val, count] : freq) {
    B.push_back(val);
  }
  if (B[0] != 0) {
    cout << -1 << "\n";
    return;
  }

  int k = B.size();
  vector<ll> A(k);

  if (k == 1) {
    A[0] = 1;
  } else {
    long long prev_A = 0;
    for (int j = 1; j < k; j++) {
      long long diff = B[j] - B[j - 1];
      long long f = freq[B[j - 1]];
      if (diff % f != 0) {
        cout << -1 << "\n";
        return;
      }
      A[j - 1] = diff / f;
      if (A[j - 1] <= prev_A) {
        cout << -1 << "\n";
        return;
      }
      prev_A = A[j - 1];
    }
    A[k - 1] = A[k - 2] + 1;
  }
  map<long long, long long> c;
  for (int j = 0; j < k; j++) {
    c[B[j]] = A[j];
  }
  for (int i = 0; i < n; i++) {
    cout << c[b[i]] << " ";
  }
  cout << "\n";
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
