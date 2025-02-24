//
// Created by Luhao Yan on 2024/7/20.
//
 
#include <bits/stdc++.h>
 
using ll = long long;
 
struct Tree {
    int n, rt, idx{};
    std::vector< std::vector<int> > E, T;
    std::vector<int>dfn, dep, siz, fa;
    int LCA_INITED_FLAG = 0;
    explicit Tree(int n, int r = 1) : n(n), E(n + 1), rt(r) {}
    void add_edge(int u, int v) {
        E[u].push_back(v);
        E[v].push_back(u);
    }
    const std::vector<int>& operator [](int x) {
        return E[x];
    }
    int dfn_min(int x, int y) { return dfn[x] < dfn[y] ? x : y; }
    void dfs(int u,int f) {
        fa[u] = f;
        dep[u] = dep[f] + 1;
        siz[u] = 1;
 
        T[0][idx] = f;
        dfn[u] = ++idx;
        for (int v:E[u])
            if (v != f) {
                dfs(v,u);
                siz[u] += siz[v];
            }
    }
    void init() {
        dfn = std::vector(n + 1, 0);
        dep = std::vector(n + 1, 0);
        siz = std::vector(n + 1, 0);
        fa = std::vector(n + 1, 0);
        T.emplace_back(n + 1, 0);
        dfs(rt, 0);
        for (int i = 1; (1 << i) <= n; ++ i) {
            T.emplace_back(n + 1, 0);
            for (int j = 1; j + (1 << i) - 1 <= n; ++j)
                T[i][j] = dfn_min(T[i - 1][j], T[i - 1][j + (1 << (i - 1))]);
        }
        LCA_INITED_FLAG = 1;
    }
    int query(int l,int r) {
        int lg = std::__lg(r - l + 1);
        return dfn_min(T[lg][l], T[lg][r - (1 << lg) + 1]);
    }
    int LCA(int x,int y) {
        if (not LCA_INITED_FLAG) init();
        if (dfn[x] > dfn[y]) std::swap(x,y);
        if (x == y) return x;
        return query(dfn[x],dfn[y] - 1);
    }
};
// Persistent segment tree
const int maxn = 1e5 + 5;
const int lim = maxn * 200;
int ch[lim][2], tag[lim], sum[lim], cnt;
 
int new_node(int u = 0) {
    cnt ++;
    assert(cnt < lim);
    ch[cnt][0] = ch[u][0];
    ch[cnt][1] = ch[u][1];
    tag[cnt] = tag[u];
    sum[cnt] = sum[u];
    return cnt;
}
int add(int rt,int l,int r,int L,int R,int v) {
    if (l > R || r < L) return rt;
    int nrt = new_node(rt);
    if (l <= L && R <= r) {
        tag[nrt] += v;
        sum[nrt] += v * (R - L + 1);
        return nrt;
    }
    int ins = std::min(r,R) - std::max(l,L) + 1;
    sum[nrt] += ins * v;
    int mid = (L + R) >> 1;
    ch[nrt][0] = add(ch[rt][0], l, r, L, mid, v);
    ch[nrt][1] = add(ch[rt][1], l, r, mid + 1, R, v);
    return nrt;
}
 
int query(int rt,int l,int r,int L,int R) {
    if (l > R || r < L || (not rt)) return 0;
    if (l <= L && R <= r) return sum[rt];
    int ins = std::min(r,R) - std::max(l,L) + 1;
    return ins * tag[rt] + query(ch[rt][0], l, r, L, (L + R) >> 1) + query(ch[rt][1], l, r, ((L + R) >> 1) + 1, R);
}
int merge(int u,int v) {
    if (not u or not v) return u + v;
    int x = new_node(0);
    tag[x] = tag[u] + tag[v];
    sum[x] = sum[u] + sum[v];
    ch[x][0] = merge(ch[u][0], ch[v][0]);
    ch[x][1] = merge(ch[u][1], ch[v][1]);
    return x;
}
void reset() {
    cnt = 0;
}
 
void solve() {
    int n, m;
    std::cin >> n >> m;
    Tree T1(n), T2(n);
    for (int i = 1; i < n; ++ i) {
        int u, v; std::cin >> u >> v;
        T1.add_edge(u, v);
    }
    for (int i = 1; i < n; ++ i) {
        int u, v; std::cin >> u >> v;
        T2.add_edge(u, v);
    }
    std::vector<std::pair<int,int> >g(m);
    std::vector r(n + 1, std::vector<int>());
    std::vector rt_1(n + 1, 0), rt_2(n + 1, 0);
    for (int i = 0; auto &[x, y] : g) {
        std::cin >> x >> y;
        int l = T1.LCA(x, y);
        r[l].push_back(i++);
    }
    reset();
 
    ll ans = 0;
    auto query_at = [&](int u, int x, int y) {
        int l = T2.LCA(x, y);
        // case #1: l is contained in the other path
        ll res = query(rt_1[u], T2.dfn[l], T2.dfn[l] + T2.siz[l] - 1, 1, n);
        // case #2: the lca of the other path is contained in x - y, and is not the same as lca(x, y)
        res += query(rt_2[u], T2.dfn[x], T2.dfn[x], 1, n);
        res += query(rt_2[u], T2.dfn[y], T2.dfn[y], 1, n);
        res -= 2 * query(rt_2[u], T2.dfn[l], T2.dfn[l], 1, n);
        return res;
    };
    std::function<void(int,int)> dfs1 = [&](int u, int f) {
        std::map<int,int>c;
        for (auto e : r[u]) {
            auto [x, y] = g[e];
            int l = T2.LCA(x, y);
            ans += query_at(u, x, y);
 
            rt_1[u] = add(rt_1[u], T2.dfn[x], T2.dfn[x], 1, n, 1);
            rt_1[u] = add(rt_1[u], T2.dfn[y], T2.dfn[y], 1, n, 1);
            rt_1[u] = add(rt_1[u], T2.dfn[l], T2.dfn[l], 1, n, -1);
            if (T2.fa[l]) rt_1[u] = add(rt_1[u], T2.dfn[T2.fa[l]], T2.dfn[T2.fa[l]], 1, n, -1);
            rt_2[u] = add(rt_2[u], T2.dfn[l], T2.dfn[l] + T2.siz[l] - 1, 1, n, 1);
        }
        rt_1[u] = merge(rt_1[u], rt_1[f]);
        rt_2[u] = merge(rt_2[u], rt_2[f]);
        for (int v : T1[u]) {
            if (v == f) continue;
            dfs1(v, u);
        }
    };
    dfs1(1, 0);
 
    for (auto [x, y] : g) {
        int l = T1.LCA(x, y);
        ans += query_at(x, x, y);
        ans += query_at(y, x, y);
        ans -= 2 * query_at(l, x, y);
    }
    std::cout << ans << "\n";
}
 
int main() {
    std::ios::sync_with_stdio(false);
    int t; std::cin >> t;
    while (t-->0) solve();
    return 0;
}
