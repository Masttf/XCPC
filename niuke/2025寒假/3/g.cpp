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
    int n, k; cin >> n >> k;
    vector<array<int, 3>> res;
    for(int i = 1, r; i <= n; i = r + 1){
    	int d = n / i;
		r = n / (n / i);
		int s = n % r;
		int e = n % i;
		// dbg(s, e, d);
		res.push_back({s, e, d});
	}
	auto check = [&](int mid) -> bool{
		int cnt = 0;
		for(auto [s, e, d] : res){
			if(mid <= e){
				int rr = max(s, mid);
				int ss = ((rr - s) + d - 1) / d * d + s;
				// dbg(s, e, ss);
				cnt += (e - ss) / d + 1;
			}
		}
		// dbg(mid, cnt);
		return cnt >= k;
	};
	int limit = 0;
	int l = 0, r = n;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)){
			limit = mid;
			l = mid + 1;
		}else r = mid - 1;
	}
	int ans = 0;
	//先不加limit
	limit++;
	// dbg(limit);
	for(auto [s, e, d] : res){
		if(limit <= e){
			int rr = max(s, limit);
			int ss = ((rr - s) + d - 1) / d * d + s;
			int num = (e - ss) / d + 1;
			int tot = (ss + e) * num / 2;
			// dbg(ss, e, tot, num);
			k -= num;
			ans += tot;
		}
	}
	// dbg(ans);
	limit--;
	// dbg(limit);
	for(auto [s, e, d] : res){
		if(k == 0)break;
		if(s <= limit && limit <= e){
			ans += limit;
			k--;
		}
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
下取整
n - (n / i) * i = d
(n / i) 只有根号种
数论分块 可以拿到区间
k = n / i
d 的分布？连续？
不连续 是一个等差 每隔 n / i
公差是 n / i
也就是说每次放入一个等差数列
最大的k个和？
这个怎么做？
二分

等差数列求和 (a1 + an) * n / 2


*/