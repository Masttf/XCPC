#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
constexpr int C = 2000, inf = 1e9;
struct Heap {
    std::priority_queue<int> a, b;
    void add(int x) {
        a.push(x);
    }
    void del(int x) {
        b.push(x);
    }
    int getMax() {
        while (!b.empty() && a.top() == b.top()) {
            a.pop();
            b.pop();
        }
        if (a.empty()) {
            return -inf;
        }
        return a.top();
    }
};
struct SegmentTree {
    Heap h[1 << 12];
    void add(int p, int l, int r, int x, int y, int v, int o) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            if (o == 0) {
                h[p].add(v);
            } else {
                h[p].del(v);
            }
            return;
        }
        int m = (l + r) / 2;
        add(2 * p, l, m, x, y, v, o);
        add(2 * p + 1, m, r, x, y, v, o);
    }
    void add(int l, int r, int x, int o) {
        add(1, 0, C, l, r, x, o);
    }
    void query(int p, int l, int r, int x, int *a) {
        x = std::max(x, h[p].getMax());
        if (r - l == 1) {
            a[l] = x;
            return;
        }
        int m = (l + r) / 2;
        query(2 * p, l, m, x, a);
        query(2 * p + 1, m, r, x, a);
    }
    void query(int *a) {
        query(1, 0, C, -inf, a);
    }
};
template <typename T>
struct Fenwick {
    const int n;
    std::vector<T> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> x1(n), y1(n), x2(n), y2(n);
    std::vector<std::tuple<int, int, int, int, int>> events;
    for (int i = 0; i < n; i++) {
        std::cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        events.emplace_back(x1[i], y1[i], y2[i], i, 0);
        events.emplace_back(x2[i], y1[i], y2[i], i, 1);
    }
    std::sort(events.begin(), events.end());
    SegmentTree t1, t2;
    int L[C * C], R[C * C];
    for (int i = 0, j = 0; i < C; i++) {
        while (j < int(events.size()) && std::get<0>(events[j]) == i) {
            auto [x, y1, y2, k, o] = events[j++];
            t1.add(y1, y2, k, o);
            t2.add(y1, y2, -k, o);
        }
        t1.query(R + i * C);
        t2.query(L + i * C);
    }
    for (int i = 0; i < C * C; i++) {
        L[i] = -L[i];
    }
    std::vector<int> cnt(n);
    int p[C * C] = {};
    for (int i = 0; i < C * C; i++) {
        if (L[i] < n) {
            cnt[L[i]]++;
        }
    }
    for (int i = 1; i < n; i++) {
        cnt[i] += cnt[i - 1];
    }
    int tot = cnt[n - 1];
    for (int i = 0; i < C * C; i++) {
        if (L[i] < n) {
            p[--cnt[L[i]]] = i;
        }
    }
    std::reverse(p, p + tot);
    std::vector<int> l(q), r(q);
    std::vector<int> ans(q);
    std::vector<int> pq(q);
    for (int i = 0; i < q; i++) {
        std::cin >> l[i] >> r[i];
        l[i]--;
    }
    std::iota(pq.begin(), pq.end(), 0);
    std::sort(pq.begin(), pq.end(), [&](int i, int j) {
        return l[i] > l[j];
    });
    Fenwick<int> fen(n);
    for (int i = 0, j = 0; i < q; i++) {
        while (j < tot && L[p[j]] >= l[pq[i]]) {
            fen.add(R[p[j++]], 1);
        }
        ans[pq[i]] = tot - fen.sum(r[pq[i]]);
    }
    for (int i = 0; i < q; i++) {
        std::cout << ans[i] << "\n";
    }
    return 0;
}