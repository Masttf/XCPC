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
	int val;
};
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
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
	vector<int> p;
	vector<int> pre(n + 1);
	p.push_back(0);
	for(int i = 1; i <= n; i++){
		pre[i] = pre[i - 1] ^ a[i];
		// dbg(i, pre[i]);
		p.push_back(pre[i]);
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	auto getVal = [&](int x) -> int{
		return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
	};
	int tot = 0;
	vector<node> tr(n * 32);
	vector<int> root(n + 1);
	auto updata = [&](auto self, int &u, int v, int l, int r, int x) -> void{
		u = ++tot;
		tr[u] = tr[v];
		tr[u].val++;
		if(l == r)return ;
		int mid = (l + r) >> 1;
		if(x <= mid) self(self, tr[u].l, tr[v].l, l, mid, x);
		else self(self, tr[u].r, tr[v].r, mid + 1, r, x);
	};
	auto query = [&](auto self, int u, int v, int l, int r, int x) -> int{
		if(l == r)return tr[u].val - tr[v].val;
		int mid = (l + r) >> 1;
		if(x <= mid)return self(self, tr[u].l, tr[v].l, l, mid, x);
		else return self(self, tr[u].r, tr[v].r, mid + 1, r, x);
	};
	int N = p.size();
	updata(updata, root[0], 0, 1, N, getVal(0));
	for(int i = 1; i <= n; i++){
		updata(updata, root[i], root[i - 1], 1, N, getVal(pre[i]));
	}
	for(int i = 1; i <= n; i++){
		int pos = i;
		while(pos <= n){
			int l = pos, r = n;
			int x = get(i, pos);
			int res = pos;
			while(l <= r){
				int mid = (l + r) >> 1;
				if(get(i, mid) == x){
					res = mid;
					l = mid + 1;
				}else r = mid - 1;
			}
			// prer ^ pre(l - 1) == gcd(l, r)
			// RMQ pos, res, x
			// dbg(pos, res, x);
			x = x ^ pre[i - 1];
			// dbg(pos, res, x);
			int pp = getVal(x);
			if(pp <= N && p[pp - 1] == x){
				ans += query(query, root[res], root[max(i, pos - 1)], 1, N, pp);
			}
			// dbg(ans);
			pos = res + 1;
		}
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
区间gcd 递减
只有log轮
先做前缀异或
查询区间的值

主席树？
*/