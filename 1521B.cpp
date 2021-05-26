// Problem link: https://codeforces.com/problemset/problem/1521/B

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

void solve() {
    int n;
    cin >> n;
    ll a[n];
    vvll v;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool change = true;
    for (int i = 0; i < n - 1; i++) {
        if (gcd(a[i], a[i + 1]) != 1) {
            ll new_val = change ? MOD : (ll)(MOD + 2);
            v.pb(emptyVector);
            v[sz(v) - 1].pb(i + 1);
            v[sz(v) - 1].pb(i + 2);
            if (a[i] < a[i + 1]) {
                a[i + 1] = new_val;
                v[sz(v) - 1].pb(a[i]);
                v[sz(v) - 1].pb(new_val);
            } else {
                a[i] = new_val;
                v[sz(v) - 1].pb(new_val);
                v[sz(v) - 1].pb(a[i + 1]);
            }
            change = !change;
        }
    }

    cout << sz(v) << endl;
    for (int i = 0; i < sz(v); i++) {
        for (int j = 0; j < 4; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
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