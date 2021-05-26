// Problem link: https://codeforces.com/problemset/problem/1520/E

// Author: Akshat

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define vvll vector<vll>
#define vld vector<ld>
#define pll pair<ll, ll>
#define ppll pair<ll, pll>
#define pld pair<ld, ld>
#define vpll vector<pll>
#define vpld vector<pld>
#define all(X) X.begin(), X.end()
#define endl "\n"
#define sz(x) ((ll)((x).size()))
vll emptyVector;
const ll MAX = 1e5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll binaryExpo(ll x, ll n) {
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return binaryExpo((x * x) % MOD, n / 2);
    return (x * binaryExpo((x * x) % MOD, n / 2)) % MOD;
}

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

/*-------------------------------------------		CODE STARTS FROM HERE		------------------------------------------*/

string trim(string& s) {
    while (!s.empty() && s.back() == '.') {
        s.pop_back();
    }
    return s;
}

void print(ll a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    trim(s);

    if (s.empty()) {
        cout << 0 << endl;
        return;
    }

    reverse(s.begin(), s.end());
    trim(s);

    int last_visited_index = n, neighbours_visited = 0;
    ll dp[2][n];

    for (int i = 0; i < n; i++) {
        dp[0][i] = dp[1][i] = 0;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '*') {
            dp[1][i] = (last_visited_index - i - 1) * neighbours_visited + dp[1][last_visited_index == n ? n - 1 : last_visited_index];
            last_visited_index = i;
            neighbours_visited++;
        }
    }

    last_visited_index = -1;
    neighbours_visited = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            dp[0][i] = (i - last_visited_index - 1) * neighbours_visited + dp[0][last_visited_index == -1 ? 0 : last_visited_index];
            last_visited_index = i;
            neighbours_visited++;
        }
    }

    ll mn = INF;

    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            mn = min(mn, dp[0][i] + dp[1][i]);
        }
    }

    cout << mn << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}