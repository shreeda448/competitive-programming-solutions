#include <bits/stdc++.h>
using namespace std;

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
using ll = long long;
#define nline "\n"

int bin(const vector<pair<ll, ll>> &a, ll y) {
  int low = 0, high = (int)a.size() - 1;
  int ans = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (a[mid].second >= y) {
      ans = max(ans, mid);
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}

int bin2(const vector<pair<ll, ll>> &a, ll x) {
  int low = 0, high = (int)a.size() - 1;
  int ans = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (a[mid].first <= x) {
      ans = max(ans, mid);
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}

void solve() {
  ll S, q;
  if (!(cin >> S >> q))
    return;
  vector<pair<ll, ll>> div;
  for (ll i = 1; i * i <= S; i++) {
    if (S % i == 0) {
      div.push_back({i, S / i});
      if (i * i != S) {
        div.push_back({S / i, i});
      }
    }
  }
  sort(div.begin(), div.end());
  int n = div.size();
  vector<ll> suf(n, 0);
  for (int i = n - 1; i >= 0; i--) {
    ll prev_first = (i == 0) ? 0 : div[i - 1].first;
    ll area = 1LL * div[i].second * (div[i].first - prev_first);

    if (i == n - 1) {
      suf[i] = area;
    } else {
      suf[i] = suf[i + 1] + area;
    }
  }

  while (q--) {
    ll x, y;
    cin >> x >> y;
    int idx = bin(div, y);
    ll ans = 0;
    if (idx != -1) {
      ans += y * min(x, div[idx].first);
      int id1 = bin2(div, x);
      if (id1 > idx) {
        ans += suf[idx + 1] - (id1 + 1 < n ? suf[id1 + 1] : 0);
        if (x > div[id1].first && id1 + 1 < n) {
          ans += (x - div[id1].first) * div[id1 + 1].second;
        }
      } else if (idx < n - 1 && x > div[idx].first) {
        ans += (x - div[idx].first) * div[idx + 1].second;
      }
    } else {
      int id1 = bin2(div, x);
      if (id1 != -1) {
        ans += suf[0] - (id1 + 1 < n ? suf[id1 + 1] : 0);
        if (x > div[id1].first && id1 + 1 < n) {
          ans += (x - div[id1].first) * div[id1 + 1].second;
        }
      } else if (n > 0) {
        ans += x * div[0].second;
      }
    }
    cout << ans << nline;
  }
}

int main() {
  fastio();
  int t = 1;
  if (cin >> t) {
    while (t--) {
      solve();
    }
  }
  return 0;
}
