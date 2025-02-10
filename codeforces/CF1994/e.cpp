#include<bits/stdc++.h>
using namespace std;

void solve() {
    int k;
    cin >> k;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        for (int j = 0; j < a[i] - 1; ++j) {
            int trash;
            cin >> trash;
        }
    }
    sort(a.begin(), a.end(), greater<>());
    int ans = 0;
    for (auto x : a) {
        for (int h = 23; h >= 0; --h) {
            int ca = ans >> h & 1, cx = x >> h & 1;
            if (cx == 0) continue;
            if (ca == 0) ans |= 1 << h;
            else {
                ans |= (1 << h) - 1;
                break;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}