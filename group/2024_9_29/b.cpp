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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int>p;
	for(int i = 1; i <= n; i++){
		p.push_back(a[i]);
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	auto get = [&](int x) -> int{
		return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
	};
	for(int i = 1; i <= n; i++) a[i] = get(a[i]);
	vector<int> cnt(n + 1);
	for(int i = 1; i <= n; i++)cnt[a[i]]++;
	vector<int>pre(n + 1), sum(n + 1);
	for(int i = 1; i <= n; i++){
		pre[i] = pre[i - 1] + cnt[i];
		sum[i] = sum[i - 1] + p[i - 1] * cnt[i];
	}
	auto C = [&](int m, int n) -> int{
		int res = 1;
		for(int i = n, j = 1; i >= n - m + 1; i--, j++){
			res = res * i / j;
		}
		return res;
	};
	int l = 1;
	for(int i = 1; i <= n; i++){
		dbg(i, k, l);
		while(pre[l] < i)l++;
		int num = i - pre[l - 1];
		int M = cnt[l];
		int d = C(num, M);
		dbg(p[l - 1], d);
		if(d < k) k -= d;
		else{
			int ans = sum[l - 1] + p[l - 1] * num;
			cout << ans << '\n';
			return ;
		}
	}
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}