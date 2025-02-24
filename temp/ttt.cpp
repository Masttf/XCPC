#include<bits/stdc++.h>
// #define int long long
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
struct node{
	int l, r;
	int val;
};
void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }
    vector<int> root(n + 1);
	vector<node> tr(n * 40);
	int tot = 0;
	auto update = [&](auto self, int &u, int v, int l, int r, int x, int val) -> void{
		u = ++tot;
		tr[u] = tr[v];
		tr[u].val += val;
		if(l == r)return ;
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, tr[u].l, tr[v].l, l, mid, x, val);
		else self(self, tr[u].r, tr[v].r, mid + 1, r, x, val);
	};
	auto query = [&](auto self, int u, int l, int r, int x, int y) -> int{
		if(x <= l && r <= y)return tr[u].val;
		int mid = (l + r) >> 1;
		int res = 0;
		if(x <= mid)res += self(self, tr[u].l, l, mid, x, y);
		if(y > mid)res += self(self, tr[u].r, mid + 1, r, x, y);
		return res;
	};
	// vector<int> last(m + 1);
	map<int, int> last;
	for(int i = 1; i <= n; i++){
		if(last.count(a[i])){
			int temp;
			update(update, temp, root[i - 1], 1, n, last[a[i]], -1);
			update(update, root[i], temp, 1, n, i, 1);
		}else{
			update(update, root[i], root[i - 1], 1, n, i, 1);
		}
		last[a[i]] = i;
	}
	int ans = -1;
	// for(int i = 1; i <= m; i++){
	// 	int lp = 1;
	// 	for(auto x : pos[i]){
	// 		if(lp < x){
	// 			ans = max(ans, query(query, root[x - 1], 1, n, lp, x - 1) - i);
	// 		}
	// 		lp = x + 1;
	// 	}
	// }
	last.clear();
	for(int i = 1; i <= n; i++){
		last[a[i]] = 1;
	}
	for(int i = 1; i <= n; i++){
		int lp = last[a[i]];
		if(a[i] > 1){
			ans = max(ans, 0);
		}
		if(lp < i){
			ans = max(ans, query(query, root[i - 1], 1, n, lp, i - 1) - a[i]);
		}
		last[a[i]] = i + 1;
	}
	for(auto [x, y] : last){
		int now = n + 1;
		if(y < now){
			ans = max(ans, query(query, root[now - 1], 1, n, y, now - 1) - x);
		}
	}
	int now = 1;
	while(last.count(now))now++;
	ans = max(ans, query(query, root[n], 1, n, 1, n) - now);
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