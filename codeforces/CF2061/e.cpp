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
void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n + 1), b(m + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    vector res(m + 1, vector<int>(n + 1));
	for(int i = 0; i <= m; i++){
		for(int j = 1; j <= n; j++){
			res[i][j] = a[j];
		}
	}
	// dbg("yes");
	vector<int> t;
	auto dfs = [&](auto self, int now) -> void{
		if(now == m + 1){
			int x = (1ll << 30) - 1;
			for(auto i : t) x &= i;
			int len = t.size();
			for(int i = 1; i <= n; i++){
				res[len][i] = min(res[len][i], a[i] & x);
			}
			return ;
		}
		self(self, now + 1);
		t.push_back(b[now]);
		self(self, now + 1);
		t.pop_back();
	};
	dfs(dfs, 1);
	// dbg("yes");
	priority_queue<array<int, 3>>q;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += a[i];
		q.push({a[i] - res[1][i], i, 1});
	}
	while(k > 0 && !q.empty()){
		auto [w, id, c] = q.top();
		// dbg(w, id, c);
		q.pop();
		ans -= w;
		if(c != m){
			q.push({res[c][id] - res[c + 1][id], id, c + 1});
		}
		k--;
	}
	cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
/*
每个ij 最多操作一次
m <= 10
枚举每个 i 操作几次？
预处理后 如何贪心呢？

每个数只能用一次
最优选择1次？？背包？？？

10次
res ji <= resj-1i

*/