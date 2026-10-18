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
    string s;
    cin >> s;
    int pos5 = n + 1, pos6 = n + 1;
    int pos25 = n + 1, pos26 = n + 1;
    int pos025 = n + 1, pos026 = n + 1;
    int pos2025 = n + 1, pos2026 = n + 1;
    vector<int> R5(n, n + 1);
    vector<int> R6(n, n + 1);
    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] == '5')
            pos5 = i;
        if (s[i] == '6')
            pos6 = i;
        if (s[i] == '2')
        {
            pos2025 = min(pos2025, pos025);
            pos2026 = min(pos2026, pos026);
            pos25 = min(pos25, pos5);
            pos26 = min(pos26, pos6);
        }
        if (s[i] == '0')
        {
            pos025 = min(pos025, pos25);
            pos026 = min(pos026, pos26);
        }
        R5[i] = pos2025;
        R6[i] = pos2026;
    }
    vector<ll> D1(n + 2, 0);
    vector<ll> D2(n + 2, 0);
    for (int l = 0; l < n; ++l)
    {
        int r_start = R5[l];
        int r_end = R6[l] - 1;
        if (r_start <= r_end)
        {
            ll C = r_end - r_start + 1;
            if (l < n)
                D1[l] += C;
            if (r_start + 1 < n)
                D2[r_start + 1] -= 1;
            if (r_end + 2 < n)
                D2[r_end + 2] += 1;
        }
    }
    ll curr_D2 = 0;
    ll curr_D1 = 0;
    for (int i = 0; i < n; ++i)
    {
        curr_D2 += D2[i];
        D1[i] += curr_D2;
        curr_D1 += D1[i];
        ll bad_count = curr_D1;
        ll total_substrings = 1LL * (i + 1) * (n - i);
        cout << (total_substrings - bad_count) << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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