#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Fast I/O
#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

// Type Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// Constants
const int MOD = 1e9 + 7;
const ll INF = 1e18;

// Macros
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define nline "\n"
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)

// Typedefs
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

// vector IO
template <typename T> istream &operator>>(istream &in, vector<T> &v) {
  for (auto &x : v)
    in >> x;
  return in;
}
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) {
  for (int i = 0; i < sz(v); ++i)
    out << v[i] << (i == sz(v) - 1 ? "" : " ");
  return out;
}
// edge if |ai| > |aj| from j to i
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  vector<int> deg(n);
  vector<bool> sign(n);
  vector<vector<int>> val;
  for (int i = 0; i < m; i++) {
    int o, p, q;
    cin >> o >> p >> q;
    val.pb({o, p - 1, q - 1});
    if (p == q && o == 1) {
      sign[p - 1] = true;
    }
  }

  for (int i = 0; i < val.size(); i++) {
    if ((val[i][0] == 1 && !sign[val[i][1]] && !sign[val[i][2]]) ||
        (val[i][0] == 2 && sign[val[i][1]] && sign[val[i][2]])) {
      cout << "NO" << nline;
      return;
    }
  }
  for (int i = 0; i < val.size(); i++) {
    int o = val[i][0];
    int u = val[i][1];
    int w = val[i][2];
    if (u != w) {
      if (sign[u] != sign[w]) {
        int pos = sign[u] ? u : w;
        int neg = sign[w] ? u : w;
        if (o == 1) {
          adj[neg].pb(pos);
          deg[pos]++;
        } else {
          adj[pos].pb(neg);
          deg[neg]++;
        }
      }
    }
  }
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      q.push(i);
    }
  }
  vector<int> order;
  while (!q.empty()) {
    int g = q.front();
    order.push_back(g);
    q.pop();
    for (int i = 0; i < adj[g].size(); i++) {
      deg[adj[g][i]]--;
      if (deg[adj[g][i]] == 0) {
        q.push(adj[g][i]);
      }
    }
  }
  if (order.size() < n) {
    cout << "NO" << nline;
    return;
  }
  cout << "YES" << nline;
  vector<int> res(n);
  for (int i = 0; i < n; i++) {
    res[order[i]] = i + 1;
  }
  for (int i = 0; i < n; i++) {
    if (!sign[i]) {
      res[i] *= -1;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << res[i] << " ";
  }
  cout << nline;
  return;
}

int main() {
  fastio();
  cout << fixed << setprecision(10); // Standardize floating point precision
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
