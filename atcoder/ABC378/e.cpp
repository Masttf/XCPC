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
    int n, mod; cin >> n >> mod;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	a[i] %= mod;
    }
    vector<int> pre(n + 1);
	for(int i = 1; i <= n; i++){
		pre[i] = pre[i - 1] + a[i];
		pre[i] %= mod;
	}
	vector<pair<int, int>> tr(mod + 1);
	auto add = [&](int x, int val) -> void{
		x++;
		while(x <= mod){
			tr[x].first += val;
			tr[x].second++;
			x += lowbit(x);
		}
	};
	auto ask = [&](int x) -> pair<int, int>{
		x++;
		pair<int, int>res = {0, 0};
		while(x){
			res.first += tr[x].first;
			res.second += tr[x].second;
			x -= lowbit(x);
		}
		return res;
	};
	add(0, 0);
	int sum = 0;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		auto [val, cnt] = ask(pre[i]);
		ans += cnt * pre[i] - val;
		int ret = i - cnt;
		ans += ret * pre[i] - (sum - val) + ret * mod;
		add(pre[i], pre[i]);
		sum += pre[i];
	}
	cout << ans << '\n';
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
/*
erfen ?
num - 

*/