// Problem link: https://codeforces.com/problemset/problem/489/C

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
const ll MAX = 2e5 + 5;
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

bool error_func_called = false;
void error() {
    cout << -1 << " " << -1 << endl;
    error_func_called = true;
}

void print_smallest(int m, int s) {
    int a[m] = {0};
    a[0] = 1;

    int i = m - 1;
    while (s && i >= 0) {
        if (i == 0 && s >= 9) {
            error();
            return;
        }
        if (s < 9) {
            a[i] += s;
            s = 0;
        } else {
            a[i] += 9;
            s -= 9;
        }
        i--;
    }

    for (int i = 0; i < m; i++) {
        cout << a[i];
    }
    cout << " ";
}

void print_largest(int m, int s) {
    int a[m] = {0};
    int i = m - 1;
    while (s && i >= 0) {
        if (s < 9) {
            a[i] += s;
            s = 0;
        } else {
            a[i] += 9;
            s -= 9;
        }
        i--;
    }

    for (int i = m - 1; i >= 0; i--) {
        cout << a[i];
    }
    cout << endl;
}

void solve() {
    int m, s;
    cin >> m >> s;

	if (s == 0 && m == 1) {
        cout << 0 << " " << 0 << endl;
        return;
    }

    if (s == 0) {
        error();
        return;
    }

    print_smallest(m, s - 1);
    if (error_func_called) {
        return;
    }
    print_largest(m, s);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--) {
    solve();
    // }

    return 0;
}