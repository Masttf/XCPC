#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n; cin >> n;
    unordered_set<int> val;
    unordered_set<int> pos;
    for(int i = 1; i < n; i++) {
        val.insert(i);
        pos.insert(i);
    }
    val.insert(n);
    int bit = 0;
    vector<int> cnt(2, 0);
    vector<int> get_cnt(2, 0);
    vector<int> temp(n + 1);
    while(val.size() > 1) {
        int ask = 1 << bit;
        cnt.assign(2, 0);
        get_cnt.assign(2, 0);
        for (auto x : val) {
            int d = (x >> bit) & 1;
            cnt[d]++;
        }
        for (auto x : pos) {
            cout << "? " << x << ' ' << ask << endl;
            int res;
            cin >> res;
            temp[x] = res;
            get_cnt[res]++;
        }
        auto del = [&] (int b) -> void {
            auto it = val.begin();
            while(it != val.end()) {
                int x = *it;
                if (((x >> bit) & 1) == b) {
                    it = val.erase(it);
                } else {
                    it++;
                }
            }
            auto pos_it = pos.begin();
            while(pos_it != pos.end()) {
                int x = *pos_it;
                if (temp[x] == b) {
                    pos_it = pos.erase(pos_it);
                } else {
                    pos_it++;
                }
            }
        };
        if (cnt[0] == get_cnt[0]) {
            del(0);
        } else {
            del(1);
        }
        bit++;
    }
    cout << "! " << *(val.begin()) << endl;
    return ;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
