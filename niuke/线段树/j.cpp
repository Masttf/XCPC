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
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int q; cin >> q;
	vector st(21, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		st[0][i] = a[i];
	}
	for(int k = 1; k <= 20; k++){
		for(int i = 1; i + (1 << k) <= n + 1; i++){
			st[k][i] = __gcd(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
		}
	}
	auto get = [&](int l, int r) -> int{
		int d = __lg(r - l + 1);
		return __gcd(st[d][l], st[d][r - (1 << d) + 1]);
	};

	vector Q(n + 1, vector<pair<int, int>>());
	vector<pair<int ,int>> ans(q + 1);
	for(int i = 1; i <= q; i++){
		int l, r; cin >> l >> r;
		Q[l].push_back({r, i});
		ans[i].first = get(l, r);
	}
	vector<map<int, pair<int, int>>> tr(n * 4);
	int temp;
	auto update = [&](auto self, int l, int r, int x, int y, int val, int p) -> void{
		if(x <= l && r <= y){
			if(tr[p].count(temp)){
				tr[p][temp].first++;
				tr[p][temp].second += val;
			}else{
				tr[p][temp] = {1, val};
			}
			return ;
		}
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, y, val, p << 1);
		if(y > mid)self(self, mid + 1, r, x, y, val, p << 1 | 1);
		return ;
	};
	pair<int, int> res;
	auto query = [&](auto self, int l, int r, int x, int p) -> void{
		if(tr[p].count(temp)){
			res.first += tr[p][temp].first;
			res.second += tr[p][temp].second;
		}
		if(l == r)return ;
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, p << 1);
		else self(self, mid + 1, r, x, p << 1 | 1);
	};
	for(int i = n; i >= 1; i--){
		int pos = i;
		while(pos <= n){
			int l = pos, r = n;
			int tg = get(i, pos);
			int pr = pos;
			while(l <= r){
				int mid = (l + r) >> 1;
				if(get(i, mid) == tg){
					pr = mid;
					l = mid + 1;
				}else r = mid - 1;
			}
			temp = tg;
			// dbg(i, pos, pr, tg);
			update(update, 1, n, pos, pr, pos, 1);
			pos = pr + 1;
		}
		for(auto [r, id] : Q[i]){
			res = {0, 0};
			temp = ans[id].first;
			query(query, 1, n, r, 1);
			ans[id].second = (r + 1) * res.first - res.second;
			// dbg(id, ans[id].second);
		}
	}
	for(int i = 1; i <= q; i++){
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	}
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
    	cout << "Case #" << i << ":\n";
    	solve();
    }
    return 0;
}
/*
gcd 递减
每个数最多log次
预处理每个位置gcd的左边界 log个

*/