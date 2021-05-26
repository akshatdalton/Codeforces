// Problem link: https://codeforces.com/problemset/problem/1516/B

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

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

/*-------------------------------------------		CODE STARTS FROM HERE		------------------------------------------*/

bool helper(int start_index, int n, int original_current_xor, int remaining_final_xor, int *a) {
    int current_xor = 0;
    for (int i = start_index; i < n - 1; i++) {
        current_xor ^= a[i];
        // cout << "a[" << i << "] = " << a[i] << " current_xor = " << current_xor << endl;
        if (current_xor == original_current_xor && current_xor == (remaining_final_xor ^ current_xor)) {
            cout << "YES" << endl;
            return true;
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;

    int a[n], final_xor = 0;
    for (auto &x : a) {
        cin >> x;
        final_xor ^= x;
    }

    int current_xor = 0;

    for (int i = 0; i < n - 1; i++) {
        current_xor ^= a[i];
        // cout << "a[" << i << "] = " << a[i] << " current_xor = " << current_xor << endl;
        if (current_xor == (final_xor ^ current_xor)) {
            cout << "YES" << endl;
            return;
        }
    }

    current_xor = 0;
    for (int i = 0; i < n - 1; i++) {
        current_xor ^= a[i];
        if (helper(i + 1, n, current_xor, final_xor ^ current_xor, a)) {
            return;
        }
    }

    cout << "NO" << endl;
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