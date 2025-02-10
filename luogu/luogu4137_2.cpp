#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int N = n + 1;
	vector pos(N + 1, vector<int>());
	for(int i = 0; i <= N; i++)pos[i].push_back(0);
	for(int i = 1; i <= n; i++){
		if(a[i] <= N)pos[a[i]].push_back(i);
	}
	for(int i = 0; i <= N; i++)pos[i].push_back(n + 1);
	vector op(n + 1, vector<pair<int, int>>());
	for(int i = 0; i <= N; i++){
		int sz = pos[i].size();
		for(int j = 1; j < sz; j++){
			int l = pos[i][j - 1] + 1;
			int r = pos[i][j] - 1;
			if(l <= r)op[l].push_back({r, i});
		}
	}
	vector<int> tr(n * 4, N);
	auto updata = [&](auto self, int l, int r, int x, int val, int p) -> void{
		if(l == r){
			tr[p] = min(tr[p], val);
			return ;
		}
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, val, p << 1);
		else self(self, mid + 1, r, x, val, p << 1 | 1);
		tr[p] = min(tr[p << 1], tr[p << 1 | 1]);
	};
	auto query = [&](auto self, int l, int r, int x, int y, int p) -> int{
		if(x <= l && r <= y){
			return tr[p];
		}
		int mid = (l + r) >> 1;
		int res = N;
		if(x <= mid)res = min(res, self(self, l, mid, x, y, p << 1));
		if(y > mid)res = min(res, self(self, mid + 1, r, x, y, p << 1 | 1));
		return res;
	};
	vector Q(n + 1, vector<pair<int, int>>());
	for(int i = 1; i <=m; i++){
		int l, r; cin >> l >> r;
		Q[l].push_back({r, i});
	}
	vector<int> ans(m + 1);
	for(int i = 1; i <= n; i++){
		for(auto [r, val] : op[i]){
			updata(updata, 1, n, r, val, 1);
		}
		for(auto [r, id] : Q[i]){
			ans[id] = query(query, 1, n, r, n, 1);
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << '\n';
	}
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}