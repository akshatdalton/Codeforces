// Problem link: https://codeforces.com/problemset/problem/455/A

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

void solve() {
    ll n;
    cin >> n;
    ll freq[MAX + 5] = {0};
    ll ans[MAX + 5][2] = {0};
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        freq[x]++;
    }

    ans[1][0] += (ll)(freq[1] * 1);

    for (ll i = 2; i <= MAX + 3; i++) {
        ans[i][0] += (ll)(freq[i] * i) + (ll)(max(ans[i - 2][0], ans[i - 2][1]));
        ans[i][1] += 0 + (ll)(max(ans[i - 1][0], ans[i - 1][1]));
    }

    cout << (ll)(max(ans[MAX][0], ans[MAX][1])) << endl;
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