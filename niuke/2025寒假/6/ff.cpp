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
template<class T, 
	class Cmp = std::less<T>>
struct ST{
	int n, k;
	const Cmp cmp = Cmp();
	vector<vector<T>> st;
	ST(){}
	ST(const vector<T> &a){
		init(a);
	}
	void init(const vector<T> &a){
		n = a.size() - 1;
		k = __lg(n);
		st.resize(k + 1, vector<T>(n + 1));
		for(int i = 1; i <= n; i++){
			st[0][i] = a[i];
		}
		for(int s = 1; s <= k; s++){
			for(int i = 1; i + (1 << s) <= n + 1; i++){
				st[s][i] = min(st[s - 1][i], st[s - 1][i + (1 << (s - 1))], cmp);
			}
		}
	}
	T get(int l, int r){
		int d = __lg(r - l + 1);
		return min(st[d][l], st[d][r - (1 << d) + 1], cmp);
	}
};
void solve(){
	int n; cin >> n;
	vector<pair<int, int>> a(n + 1);
	for(int i = 1; i <= n; i++){
		int x, y; cin >> x >> y;
		a[i] = {x, y};
	}
	sort(a.begin() + 1, a.end());
	vector<pair<int, int>> b(n + 1);
	for(int i = 1; i <= n; i++){
		auto [x, y] = a[i];
		b[i] = {x + y, i};
	}
	ST<pair<int, int>, greater<pair<int, int>>> to(b);
	auto find = [&](int i, int val) -> int{
		int l = i, r = n;
		int res = -1;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(a[mid].first <= val){
				res = mid;
				l = mid + 1;
			}else r = mid - 1;
		}
		return res;
	};
	vector st(21, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		auto [x, y] = a[i];
		int res = find(i, x + y);
		st[0][i] = to.get(i, res).second;
	}
	for(int k = 1; k <= 20; k++){
		for(int i = 1; i <= n; i++){
			st[k][i] = st[k - 1][st[k - 1][i]];
		}
	}
	int ans = a[n].first;
	for(int i = 1; i <= n; i++){
		int val = a[i].first;
		if(i > 1){
			int v = to.get(1, i - 1).second;
			val = max(val, b[v].first);
		}
		ans = max(ans, val);
		int vv;
		//过程中不能用i这个ai + bi 
		int res = find(i + 1, val);
		if(res != -1){
			int v = to.get(i + 1, res).second;
			//只有两种可能b[v].first > val
			// 那么用v跳很优
			// 否则val 还是不变
			vv = st[20][v];
			ans = max(ans, b[vv].first);
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
假设已知第一个ai
设当前的最大为mx
那么后面只要， ai <= mx 都可以被更新 ai + bi
那么我先按ai sort
预处理 一个变成ai + bi 后能连锁的最远距离
*/