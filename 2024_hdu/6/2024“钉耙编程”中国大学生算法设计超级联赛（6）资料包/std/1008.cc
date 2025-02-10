#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdio>
#include <vector>
#include <queue>
#include <array>

struct Trie {
    int n;
    std::vector<int> lc, rc, tag, next;

    Trie(size_t size): n(size), lc(size), rc(size), tag(size, -1) {}

    void build_acam() {
        std::queue<int> q;
        std::vector<int> fail(n, 0);

        next.assign(n, 0);

        for(auto ch: (int[2]){lc[0], rc[0]}) if(ch) q.push(ch);

        while(q.size()) {
            int hd = q.front(); q.pop();
            if(tag[fail[hd]] >= 0) next[hd] = fail[hd];
            else                   next[hd] = next[fail[hd]];

            if(lc[hd]) fail[lc[hd]] = lc[fail[hd]], q.push(lc[hd]);
            else            lc[hd]  = lc[fail[hd]];
            if(rc[hd]) fail[rc[hd]] = rc[fail[hd]], q.push(rc[hd]);
            else            rc[hd]  = rc[fail[hd]];
        }
    }
};

void solve() {
    int n, m;
    std::cin >> n;
    Trie s(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> s.lc[i] >> s.rc[i];
    }
    std::cin >> m;
    Trie t(m);

    for(int i = 0; i < m; ++i)
        std::cin >> t.lc[i] >> t.rc[i];

    int t_leave = 0;

    auto dfs1 = [&](auto self, int cur, int depth) -> void {
        if(!t.lc[cur] && !t.rc[cur]) {
            t.tag[cur] = depth;
            t_leave += 1;
            return ;
        }
        if(t.lc[cur]) self(self, t.lc[cur], depth + 1);
        if(t.rc[cur]) self(self, t.rc[cur], depth + 1);
    };

    dfs1(dfs1, 0, 1);

    t.build_acam();

    /// for(int i = 0; i < m; ++i) std::cout << t.tag[i] << char(i == m - 1 ? 10 : 32);
    
    std::vector<int> stack;
    std::vector<int> count(n, 0);
    std::vector<int> ans;

    stack.reserve(n);

    auto dfs2 = [&](auto self, int cur, int status) -> void {
        stack.push_back(cur);

        if(t.tag[status] >= 0) count[stack[stack.size() - t.tag[status]]] += 1;

        for(int i = t.next[status]; i ; i = t.next[i]) {
            assert(m > i && i >= 0);
            count[stack[stack.size() - t.tag[i]]] += 1;
        }
        
        if(s.lc[cur]) self(self, s.lc[cur], t.lc[status]);
        if(s.rc[cur]) self(self, s.rc[cur], t.rc[status]);

        // std::cerr << "count[" << cur << "] = " << count[cur] << char(10);

        if(count[cur] == t_leave) ans.push_back(cur);

        stack.pop_back();
    };

    dfs2(dfs2, 0, 0);

    std::sort(ans.begin(), ans.end());

    std::cout << ans.size() << char(10);
    if(ans.empty()) std::cout << char(10);
    for(int i = 0; i < ans.size(); ++i) std::cout << ans[i] << char(i == ans.size() - 1 ? 10 : 32);

    return ;
}

int main() {
    std::ios::sync_with_stdio(false);
    int T; std::cin >> T;
    while(T--) solve();
    return 0;
}
