#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x) & -(x))
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
    int n, m; cin >> n >> m;
    vector<int> label(n + 1);
    for(int i = 1; i <= n; i++) cin >> label[i];
    vector S(n + 1, vector<int>(m + 1));
	vector val(n + 1, vector<int>(m + 1));
	vector<int> p;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> S[i][j];
		}
		for(int j = 1; j <= m; j++){
			if(j != label[i]){
				val[i][j] = S[i][j] - S[i][label[i]];
				p.push_back(val[i][j]);
			}
		}
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	auto get = [&](int x) -> int{
		return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
	};
	int N = p.size();
	vector<pair<int, int>> tr(N + 1);
	auto add = [&](int x, int val) -> void{
		while(x <= N){
			tr[x].first += val;
			tr[x].second++;
			x += lowbit(x);
		}
	};
	auto ask = [&](int x) -> pair<int, int>{
		pair<int, int> res = {0, 0};
		while(x) {
			res.first += tr[x].first;
			res.second += tr[x].second;
			x -= lowbit(x);
		}
		return res;
	};
	int q; cin >> q;
	vector<int> ans(q + 1);
	vector op(n + 1, vector<array<int, 3>>());
	for(int i = 1; i <= q; i++){
		int l, r, h; cin >> l >> r >> h;
		op[l - 1].push_back({-h, -1, i});
		op[r].push_back({-h, 1, i});
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(j == label[i])continue;
			add(get(val[i][j]), val[i][j]);
		}
		for(auto [l, f, id] : op[i]){
			auto res1 = ask(N);
			auto res2 = ask(get(l) - 1);
			ans[id] += f * (res1.first - res2.first + (-l) * (res1.second - res2.second));
			// dbg(l, f, id, ans[id]);
		}
	}
	for(int i = 1; i <= q; i++){
		cout << ans[i] << '\n';
	}
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}