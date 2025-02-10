#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const int N = 3e5 + 7, MOD = 998244353;
int n, last[N], nex[N];
ll m, a[N];
map<ll, int> mp;

class SegTree {
private:
    struct Node {
        int l, r;
        ll maxn;
    } t[N * 4];

    void up(int id) {
        t[id].maxn = max(t[id * 2].maxn, t[id * 2 + 1].maxn);
    }

public:
    void build(int id, int l, int r) {
        t[id] = {l, r, 0};
        if (l == r) {
            t[id].maxn = a[l];
            return;
        }
        build(id * 2, l, (l + r) / 2);
        build(id * 2 + 1, (l + r) / 2 + 1, r);
        up(id);
    }

    void update(int id, int pos, ll x) {
        if (t[id].l == t[id].r) {
            t[id].maxn = x;
            return;
        }
        int mid = (t[id].l + t[id].r) / 2;
        if (pos <= mid) update(id * 2, pos, x);
        else update(id * 2 + 1, pos, x);
        up(id);
    }

    ll getMaxn(int id, int l, int r) {
        if (l > r) return 0;
        if (l <= t[id].l && t[id].r <= r) return t[id].maxn;
        int mid = (t[id].l + t[id].r) / 2;
        ll res = 0;
        if (l <= mid) res = getMaxn(id * 2, l, r);
        if (r > mid) res = max(res, getMaxn(id * 2 + 1, l, r));
        return res;
    }
} st;

class SegmentTree {
private:
    struct Node {
        int l, r;
        ll sum, add;
    } t[N * 4];

    void up(int id) {
        t[id].sum = t[id * 2].sum + t[id * 2 + 1].sum;
    }

    void down(int id) {
        ll add = t[id].add;
        t[id].add = 0;
        t[id * 2].sum += add * (t[id * 2].r - t[id * 2].l + 1);
        t[id * 2].add += add;
        t[id * 2 + 1].sum += add * (t[id * 2 + 1].r - t[id * 2 + 1].l + 1);
        t[id * 2 + 1].add += add;
    }

public:
    void build(int id, int l, int r) {
        t[id] = {l, r, 0, 0};
        if (l == r) return;
        build(id * 2, l, (l + r) / 2);
        build(id * 2 + 1, (l + r) / 2 + 1, r);
    }

    void update(int id, int pos, ll x) {
        if (t[id].l == t[id].r) {
            t[id].sum = x;
            t[id].add = 0;
            return;
        }
        down(id);
        int mid = (t[id].l + t[id].r) / 2;
        if (pos <= mid) update(id * 2, pos, x);
        else update(id * 2 + 1, pos, x);
        up(id);
    }

    void add(int id, int l, int r, ll x) {
        if (l > r) return;
        if (l <= t[id].l && t[id].r <= r) {
            t[id].sum += x * (t[id].r - t[id].l + 1);
            t[id].add += x;
            return;
        }
        down(id);
        int mid = (t[id].l + t[id].r) / 2;
        if (l <= mid) add(id * 2, l, r, x);
        if (r > mid) add(id * 2 + 1, l, r, x);
        up(id);
    }

    ll getSum(int id, int l, int r) {
        if (l > r) return 0;
        if (l <= t[id].l && t[id].r <= r) return t[id].sum;
        down(id);
        int mid = (t[id].l + t[id].r) / 2;
        ll res = 0;
        if (l <= mid) res += getSum(id * 2, l, r);
        if (r > mid) res += getSum(id * 2 + 1, l, r);
        return res;
    }
} ansL, ansR, ansMid;

int getFirstPos(int l, int r, ll x) {//求区间内最左>x的位置
    int L = l, res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        ll maxn = st.getMaxn(1, L, mid);
        if (maxn > x) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}

int getLastPos(int l, int r, ll x) {//求区间内最右>x的位置
    int R = r, res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        ll maxn = st.getMaxn(1, mid, R);
        if (maxn > x) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    st.build(1, 1, n);
    ansL.build(1, 1, n);
    ansR.build(1, 1, n);
    ansMid.build(1, 1, n);

    for (int i = 1; i <= n; i++) {
        int pos = getLastPos(1, i - 1, a[i]);
        if (pos > 0) ansL.add(1, i, i, ansL.getSum(1, pos, pos) + 1);
    }
    for (int i = n; i >= 1; i--) {
        int pos = getFirstPos(i + 1, n, a[i]);
        if (pos > 0) ansR.add(1, i, i, ansR.getSum(1, pos, pos) + 1);
    }
    for (int i = 1; i <= n; i++) {
        if (mp.count(a[i])) {
            nex[mp[a[i]]] = i;
            last[i] = mp[a[i]];
        }
        mp[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (i + 1 > nex[i] - 1) continue;
        ll maxn = st.getMaxn(1, i + 1, nex[i] - 1);
        if (maxn < a[i]) ansMid.add(1, i + 1, nex[i] - 1, -1);
    }

    int q;
    cin >> q;
    while (q--) {
        int op, x, y;
        cin >> op >> x;
        if (op == 1) {
            if (a[x] == a[x + 1]) continue;
            if (a[x] < a[x + 1]) {
                int pos = getLastPos(1, x - 1, a[x] - 1);
                ansR.add(1, pos + 1, x - 1, -1);
                pos = getFirstPos(x + 2, n, a[x] - 1);
                if (pos == 0) pos = n + 1;
                ansL.add(1, x + 2, pos - 1, 1);
            } else {
                int pos = getLastPos(1, x - 1, a[x + 1] - 1);
                ansR.add(1, pos + 1, x - 1, 1);
                pos = getFirstPos(x + 2, n, a[x + 1] - 1);
                if (pos == 0) pos = n + 1;
                ansL.add(1, x + 2, pos - 1, -1);
            }

            if (last[x] && st.getMaxn(1, last[x] + 1, x - 1) < a[x])
                ansMid.add(1, last[x] + 1, x - 1, 1);
            if (nex[x] && st.getMaxn(1, x + 1, nex[x] - 1) < a[x])
                ansMid.add(1, x + 1, nex[x] - 1, 1);
            if (last[x + 1] && st.getMaxn(1, last[x + 1] + 1, x) < a[x + 1])
                ansMid.add(1, last[x + 1] + 1, x, 1);
            if (nex[x + 1] && st.getMaxn(1, x + 2, nex[x + 1] - 1) < a[x + 1])
                ansMid.add(1, x + 2, nex[x + 1] - 1, 1);

            if (last[x]) nex[last[x]]++;
            if (nex[x]) last[nex[x]]++;
            if (last[x + 1]) nex[last[x + 1]]--;
            if (nex[x + 1]) last[nex[x + 1]]--;
            swap(last[x], last[x + 1]);
            swap(nex[x], nex[x + 1]);

            swap(a[x], a[x + 1]);
            st.update(1, x, a[x]);
            st.update(1, x + 1, a[x + 1]);

            if (last[x] && st.getMaxn(1, last[x] + 1, x - 1) < a[x])
                ansMid.add(1, last[x] + 1, x - 1, -1);
            if (nex[x] && st.getMaxn(1, x + 1, nex[x] - 1) < a[x])
                ansMid.add(1, x + 1, nex[x] - 1, -1);
            if (last[x + 1] && st.getMaxn(1, last[x + 1] + 1, x) < a[x + 1])
                ansMid.add(1, last[x + 1] + 1, x, -1);
            if (nex[x + 1] && st.getMaxn(1, x + 2, nex[x + 1] - 1) < a[x + 1])
                ansMid.add(1, x + 2, nex[x + 1] - 1, -1);

            int pos = getLastPos(1, x - 1, a[x]);
            if (pos) ansL.update(1, x, ansL.getSum(1, pos, pos) + 1);
            else ansL.update(1, x, 0);

            pos = getLastPos(1, x, a[x + 1]);
            if (pos) ansL.update(1, x + 1, ansL.getSum(1, pos, pos) + 1);
            else ansL.update(1, x + 1, 0);

            pos = getFirstPos(x + 2, n, a[x + 1]);
            if (pos) ansR.update(1, x + 1, ansR.getSum(1, pos, pos) + 1);
            else ansR.update(1, x + 1, 0);

            pos = getFirstPos(x + 1, n, a[x]);
            if (pos) ansR.update(1, x, ansR.getSum(1, pos, pos) + 1);
            else ansR.update(1, x, 0);
        } else {
            cin >> y;
            ll cnt = ansL.getSum(1, x, y) + ansR.getSum(1, x, y) + ansMid.getSum(1, x, y);
            cout << cnt * m + (y - x + 1) * (n - 1) << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
//    cin >> tc;
    while (tc--) solve();
    return 0;
}