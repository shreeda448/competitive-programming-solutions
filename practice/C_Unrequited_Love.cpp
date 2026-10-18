#include <bits/stdc++.h>
using namespace std;

// Fast I/O
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
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

// Vector IO
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (int i = 0; i < sz(v); ++i)
        out << v[i] << (i == sz(v) - 1 ? "" : " ");
    return out;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    map<int, vector<int>> mp;
    for (int i = 0; i < n - 4; i++)
    {
        mp[a[i] + a[i + 2] - a[i + 4]].push_back(a[i]);
    }
    ll ans = 0;
    for (auto &[key, val] : mp)
    {
        ll v = val.size();
        ans += (v * 1LL * (v - 1) / 2);
    }
    for (int i = 0; i < n - 4; i++)
    {
        ll val1 = a[i] + a[i + 2] - a[i + 4];
        if (i + 6 < n)
        {
            ll val2 = a[i + 2] + a[i + 4] - a[i + 6];
            if (val1 == val2)
            {
                ans--;
            }
        }
        if (i + 8 < n)
        {
            ll val3 = a[i + 4] + a[i + 6] - a[i + 8];
            if (val1 == val3)
            {
                ans--;
            }
        }
    }
    cout << ans << nline;
    return;
}

int main()
{
    fastio();
    cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}