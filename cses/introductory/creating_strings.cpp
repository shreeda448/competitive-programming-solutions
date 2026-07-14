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

vector<string> perms(string s) {
  int n = s.length();
  vector<string> ans;
  if (s.length() == 1) {
    ans.pb(s);
    return ans;
  }
  vector<string> b = perms(s.substr(0, n - 1));
  for (int i = 0; i < b.size(); i++) {
    ans.pb(b[i] + s[n - 1]);
    ans.pb(s[n - 1] + b[i]);
  }
  return ans;
}

void generatePermutations(int target_length, vector<int> &freq, string &current,
                          vector<string> &ans) {
  if (current.length() == target_length) {
    ans.push_back(current);
    return;
  }

  for (int i = 0; i < 26; i++) {
    if (freq[i] > 0) {
      current.push_back((char)(i + 'a'));
      freq[i]--;

      generatePermutations(target_length, freq, current, ans);

      current.pop_back();
      freq[i]++;
    }
  }
}

void solve() {
  string s;
  cin >> s;

  vector<int> freq(26, 0);
  for (char c : s) {
    freq[c - 'a']++;
  }

  vector<string> ans;
  string current = "";

  generatePermutations(s.length(), freq, current, ans);

  cout << ans.size() << "\n";
  for (const string &perm : ans) {
    cout << perm << "\n";
  }
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
