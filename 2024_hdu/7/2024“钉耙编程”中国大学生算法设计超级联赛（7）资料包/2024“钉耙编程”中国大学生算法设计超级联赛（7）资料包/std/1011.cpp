#include <iostream>
using namespace std;
#define ll long long
 
ll x, y;
 
ll gcd (ll a, ll b) {
    if (! b) return a;
    return gcd (b, a % b);
}
 
void solve () {
    cin >> x >> y;
    if (! (x % y)) cout << y << " " << x / y << endl;
    else cout << y << " " << 2 * x / gcd (2 * x, y) << endl;
}
 
int main () {
    ios::sync_with_stdio (false), cin.tie (nullptr), cout.tie (nullptr);
    int _ = 1; cin >> _;
    while (_ --) solve ();
    cout.flush ();
    return 0;
}
