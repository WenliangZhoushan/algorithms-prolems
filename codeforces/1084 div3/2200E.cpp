#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define endl "\n"
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) { os << "{"; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << "}"; }
#define debug(x) cerr << #x << " = " << x << endl
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define debug3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define debug_arr(a, n) do { cerr << #a << " = ["; for (int i = 0; i < (n); ++i) { if (i) cerr << ", "; cerr << (a)[i]; } cerr << "]" << endl; } while(0)
#define line() cerr << "--------------------" << endl

const int INF = 0x3f3f3f3f;
const int NEG_INF = 0xcfcfcfcf;

int t, n;

int primebase(int x) {
  set<int> cnt;
  for (int i = 2; i * i <= x; ++i) {
    if (x % i != 0) {
      continue;
    }
    cnt.insert(i);
    while (x % i == 0) {
      x /= i;
    }
  }
  if (x > 1) cnt.insert(x);
  if (cnt.size() == 0) {
    return 1;
  } else if (cnt.size() > 1) {
    return -1;
  } else {
    return *cnt.begin();
  }
}

void solve() {
  cin >> n;
  vector<int> nums(n);
  for (int& x : nums) {
    cin >> x;
  }

  if (is_sorted(all(nums))) {
    cout << "Bob" << endl;
    return;
  }
  vector<int> primes(n);
  for (int i = 0; i < n; ++i) {
    primes[i] = primebase(nums[i]);
  }

  if (*min_element(all(primes)) == -1) {
    cout << "Alice" << endl;
  } else if (is_sorted(all(primes))) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  while (t--) {
    solve();
  }
}
