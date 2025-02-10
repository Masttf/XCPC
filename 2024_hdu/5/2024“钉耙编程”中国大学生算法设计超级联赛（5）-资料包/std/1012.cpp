#include <bits/stdc++.h>
 
using namespace std;
 
struct SAM {
    static constexpr int ALPHABET_SIZE = 26;
    struct Node {
        int len;
        int link;
        array<int, ALPHABET_SIZE> next;
        Node() : len{}, link{}, next{} {}
    };
    vector<Node> t;
    SAM() {
        init();
    }
    void init() {
        t.assign(2, Node());
        t[0].next.fill(1);
        t[0].len = -1;
    }
    int newNode() {
        t.emplace_back();
        return t.size() - 1;
    }
    int extend(int last, int ch) {
        int cur = newNode();
        t[cur].len = t[last].len + 1;
        int p = last;
        for(; p && !t[p].next[ch]; p = t[p].link) {
            t[p].next[ch] = cur;
        }
        if (!p) { t[cur].link = 1; return cur; }
 
        int q = t[p].next[ch];
        if (t[p].len + 1 ==  t[q].len){
            t[cur].link = q;
            return cur;
        }
        int clone = newNode();
 
        t[clone].len = t[p].len + 1;
        t[clone].link = t[q].link;
        for (int i = 0; i < 26; i++) {
            t[clone].next[i] = t[q].next[i];
        }
        t[q].link = t[cur].link = clone;
 
        for(; t[p].next[ch] == q; p = t[p].link) {
            t[p].next[ch] = clone;
        }
        return cur;
    }
};
 
void solve2() {
    string s;
    cin >> s;
 
    int n = s.size();
    vector<int> pos(n + 1);
    pos[0] = 1;
    SAM sam;
    for (int i = 0; i < n; i++) {
        pos[i + 1] = sam.extend(pos[i], s[i] - 'a');
    }
 
    int cnt = sam.t.size();
    vector<int> occ(cnt), right(cnt);
    for (int i = 1; i <= n; i++) {
        occ[pos[i]]++;
        right[pos[i]] = i;
    }
 
    vector<int> o(cnt - 1);
    iota(o.begin(), o.end(), 1);
    sort(o.begin(), o.end(), [&](int i, int j) {
        return sam.t[i].len < sam.t[j].len;
    });
 
    vector<array<int, 21>> fa(cnt);
    for (int i = cnt - 2; i; i--) {
        occ[sam.t[o[i]].link] += occ[o[i]];
 
        right[sam.t[o[i]].link] = right[o[i]];
        fa[o[i]][0] = sam.t[o[i]].link;
    }
    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i < cnt; i++) {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
        }
    }
    
    vector<int> f(cnt);
    vector<vector<int>> g(cnt);
    for (int i = cnt - 2; i; i--) {
        int x = o[i];
        f[x] = x;
        for (int j = 0; j < 26; j++) {
            int y = sam.t[x].next[j];
            if (y && occ[x] == occ[y]) {
                f[x] = f[y];
            }
        }
        g[f[x]].push_back(x);
    }
 
    vector<int> oo(cnt - 2);
    iota(oo.begin(), oo.end(), 2);
    oo.resize(cnt - 2);
    sort(oo.begin(), oo.end(), [&](int i, int j) {
        return occ[i] > occ[j];
    });
 
    auto get_l = [&](int x) {
        return sam.t[x].len - sam.t[sam.t[x].link].len;
    };
    
    vector<int64_t> dp1(cnt, 1E18);
    vector<vector<int64_t>> dp2(cnt);
    dp2[0].resize(n, 0);
    dp2[1].resize(n, 0);
    dp1[1] = dp1[0] = 0;

    for (int _ = 0; _ < cnt - 2; _++) {
        int i = oo[_];
        int m = g[i].size();
        if (m == 0) continue;

        dp2[i].resize(get_l(g[i][0]), 1E18);

        for (int j = 0; j < m; j++) {
            int x = g[i][j];
            int xlen = get_l(x);
            dp1[x] = dp1[sam.t[x].link] + 1ll * xlen * occ[x];

            if (j != 0) {
                int lst = g[i][j - 1];
                int y = sam.t[x].link;
                for (int k = 0, idx = 0; k < get_l(lst) - xlen; k++) {
                    assert(idx < dp2[y].size());
                    assert(dp2[i].size() > xlen + k);

                    dp1[lst] = min(dp1[lst], dp2[y][idx] + (xlen + k + 1) * occ[i]);
                    dp2[i][xlen + k] = min(dp2[i][xlen + k], dp2[y][idx] + 1ll * j * occ[i]);
                    idx++;
                    if (idx == dp2[y].size()) {
                        idx = 0;
                        y = sam.t[y].link;
                    }
                }
            }
        }
        {
            int y = pos[right[i] - m];
            for (int j = 20; j >= 0; j--) {
                if (sam.t[fa[y][j]].len + 1 >= sam.t[g[i][m - 1]].len) {
                    y = fa[y][j];
                }
            }
            for (int k = 0, idx = 0; k < get_l(g[i][m - 1]); k++) {
                assert(idx < dp2[y].size());

                dp1[g[i][m - 1]] = min(dp1[g[i][m - 1]], dp2[y][idx] + (k + 1) * occ[i]);
                dp2[i][k] = min(dp2[i][k], dp2[y][idx] + 1ll * m * occ[i]);
                idx++;
                if (idx == dp2[y].size()) {
                    idx = 0;
                    y = sam.t[y].link;
                }
            }
        }

        for (int j = int(dp2[i].size()) - 2; j >= 0; j--) {
            dp2[i][j] = min(dp2[i][j], dp2[i][j + 1] + occ[i]);
        }
        for (int j = m - 2; j >= 0; j--) {
            dp1[g[i][j]] = min(dp1[g[i][j]], dp1[g[i][j + 1]] + occ[i]);
        }
        dp1[i] = dp2[i][0] = min(dp1[i], dp2[i][0]);
    }
    cout << dp1[pos[n]] << '\n';;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve2();
    }
 
    return 0;
}
