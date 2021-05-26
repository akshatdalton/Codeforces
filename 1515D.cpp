// Problem link: https://codeforces.com/problemset/problem/1515/D

// Author: Akshat
// Date: 24/05/2021

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

void print_vector(vll v) {
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}

vll eliminate_same_elements(vll v) {
    vll v_new;

    if (v.size() == 0) {
        return v_new;
    }

    int i = 0;
    for (; i < v.size() - 1; i++) {
        if (v[i] == v[i + 1]) {
            i++;
            continue;
        }
        v_new.pb(v[i]);
    }

    if (i == v.size() - 1) {
        v_new.pb(v.back());
    }

    return v_new;
}

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    vll cl(l), cr(r);

    for (auto &x : cl) {
        cin >> x;
    }

    for (auto &x : cr) {
        cin >> x;
    }

    sort(cl.begin(), cl.end());
    sort(cr.begin(), cr.end());

    vll vl, vr;

    // Eliminate the common elements.
    int itl = 0, itr = 0;
    while (itl < l && itr < r) {
        if (cl[itl] == cr[itr]) {
            itl++;
            itr++;
        } else if (cl[itl] > cr[itr]) {
            vr.pb(cr[itr++]);
        } else {
            vl.pb(cl[itl++]);
        }
    }

    for (; itl < l; itl++) {
        vl.pb(cl[itl]);
    }

    for (; itr < r; itr++) {
        vr.pb(cr[itr]);
    }

    // These vectors must be sorted.
    // print_vector(vl);
    // print_vector(vr);

    ll cost = min(vl.size(), vr.size());
    vll v_larger = vl.size() > vr.size() ? vl : vr;
    vll v_remaining = eliminate_same_elements(v_larger);
    int n_duplicates = v_larger.size() - v_remaining.size();

    // print_vector(v_remaining);

    int diff = v_larger.size() - cost;

    if (n_duplicates >= diff) {
        cost += diff / 2;
    } else {
        cost += (n_duplicates / 2 + (diff - n_duplicates));
    }

    cout << cost << endl;
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