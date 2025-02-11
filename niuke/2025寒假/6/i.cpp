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
struct node{
	int l, r;
	int cnt = 0;
};
void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int tot = 0;
	vector<int> root(n + 1);
	vector<node> tr(n * 40);
	auto update = [&](auto self, int l, int r, int &u, int v, int x) -> void{
		u = ++tot;
		tr[u] = tr[v];
		tr[u].cnt++;
		if(l == r)return ;
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, tr[u].l, tr[v].l, x);
		else self(self, mid + 1, r, tr[u].r, tr[v].r, x);
		return ;
	};
	auto query = [&](auto self, int l, int r, int u, int v, int x) -> int{
		if(l == r)return 0;
		int res = 0;
		int mid = (l + r) >> 1;
		if(x <= mid){
			res = self(self, l, mid, tr[u].l, tr[v].l, x);
		}else{
			res += tr[tr[u].l].cnt - tr[tr[v].l].cnt;
			res += self(self, mid + 1, r, tr[u].r, tr[v].r, x);
		}
		return res;
	};
	for(int i = 1; i <= n; i++){
		update(update, 1, n, root[i], root[i - 1], a[i]);
	}
	for(int i = 1; i <= m; i++){
		int l, r, c; cin >> l >> r >> c;
		int val = a[c];
		int ans = l + query(query, 1, n, root[r], root[l - 1], val);
		cout << ans << '\n';
	}
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