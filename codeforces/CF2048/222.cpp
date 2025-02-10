//Mercy
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 2e5 + 7;
const ll INFLL = 1e15 + 7;
int n, m;
ll c[N];
pii p[N];
multiset<int> s;

class SegTree {
private:
    struct Node {
        int l, r;
        ll mark;
    } t[N * 4];

    void down(int id) {
        t[id << 1].mark = min(t[id << 1].mark, t[id].mark);
        t[id << 1 | 1].mark = min(t[id << 1 | 1].mark, t[id].mark);
    }

public:
    void build(int id, int l, int r) {
        t[id] = {l, r, INFLL};
        if (l == r) return;
        build(id << 1, l, (l + r) / 2);
        build(id << 1 | 1, (l + r) / 2 + 1, r);
    }

    void update(int id, int l, int r, ll minn) {
        if (l <= t[id].l && t[id].r <= r) {
            t[id].mark = min(t[id].mark, minn);
            return;
        }
        down(id);
        int mid = (t[id].l + t[id].r) / 2;
        if (l <= mid) update(id << 1, l, r, minn);
        if (r > mid) update(id << 1 | 1, l, r, minn);
    }

    ll getVal(int id, int pos) {
        if (t[id].l == t[id].r) return t[id].mark;
        down(id);
        int mid = (t[id].l + t[id].r) / 2;
        if (pos <= mid) return getVal(id << 1, pos);
        else return getVal(id << 1 | 1, pos);
    }
} st;

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= m; i++) {
        cin >> p[i].first >> p[i].second;
        s.insert(p[i].second);
    }
    sort(p + 1, p + 1 + m);
    st.build(1, 1, n);
    ll ans = INFLL;
    for (int i = 0, j = 1; i <= n; i++) {
        while (j <= m && p[j].first <= i) {
            auto it = s.find(p[j].second);
            s.erase(it);
            j++;
        }
        int minn = n;
        if (!s.empty()) minn = *s.begin();
        ll now;
        if (i == 0) now = 0;
        else now = st.getVal(1, i) + c[i];
        st.update(1, i + 1, minn, now);

        if (s.empty()) ans = min(ans, now);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
//    cin >> tc;
    while (tc--) solve();
    return 0;
}