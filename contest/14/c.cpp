#include <bits/stdc++.h>
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
  long long k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> freq;
  int curr = a[0];
  int cnt = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] == curr) {
      cnt++;
    } else {
      freq.push_back(cnt);
      curr = a[i];
      cnt = 1;
    }
  }
  freq.push_back(cnt);
  sort(freq.begin(), freq.end());
  vector<int> uniq_freq = freq;
  uniq_freq.erase(unique(uniq_freq.begin(), uniq_freq.end()), uniq_freq.end());
  long long total = 0;
  for (int f : freq) {
    total += f;
  }
  int ans = 0;
  int p = uniq_freq.size();
  long long cnt1 = freq.size();
  long long sum = total;
  int idx = 0;
  for (int j = 0; j < p; ++j) {
    long long u = uniq_freq[j];
    long long diff = k - sum;
    if (diff % cnt1 == 0) {
      long long g = diff / cnt1;
      if (g >= 1 - u) {
        ans++;
      }
    }
    while (idx < freq.size() && freq[idx] == u) {
      sum -= freq[idx];
      cnt1--;
      idx++;
    }
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
