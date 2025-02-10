#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout << endl << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}

using Pii = pair<int, int>;


void solve(){
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1);
    for(int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        v[x].push_back(i);
    }
    vector<int> maxdep(n + 1);
    auto dfs1 = [&](auto self, int p)->void {
        for(int i:v[p]) {
            self(self, i);
            maxdep[p] = max(maxdep[p], maxdep[i] + 1);
        }
    };
    dfs1(dfs1, 1);
    int ans = 0;
    auto dfs = [&](auto self, int p, int dep)->int {
        ++ans;
        // dbg(p, dep, ans);
        priority_queue<Pii, vector<Pii>, greater<Pii>> q;
        for(int i:v[p]) q.emplace(maxdep[i], i);

        int last = 0;
        bool f = true;
        while(!q.empty()) {
            auto [_, i] = q.top();
            q.pop();
            ans += min(last, dep);
            last = self(self, i, dep + 1);
            // dbg(last);
        }
        if(v[p].empty()) return 1;
        else return last + 1;

    };
    dfs(dfs, 1, 0);
    cout << ans - 1 << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
    	cout << "Case #" << i << ": ";
    	solve();
    }
    return 0;
}