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
constexpr int inf = 1e18;
void solve(){
	int n; cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector<int> pmax(n + 1), pmin(n + 1, inf);
	vector<int> smax(n + 5), smin(n + 5, inf);
	for(int i = 1; i <= n; i++){
		pmax[i] = max(pmax[i - 1], a[i]);
		pmin[i] = min(pmin[i - 1], a[i]);
	}
	for(int i = n; i >= 1; i--){
		smax[i] = max(smax[i + 1], a[i]);
		smin[i] = min(smin[i + 1], a[i]);
	}

	int ans = 2 * (pmax[n] - pmin[n]);
	vector<pair<int, int>> b(n + 1);
	for(int i = 1; i <= n; i++){
		b[i] = {a[i], i};
	}
	vector st(21, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		st[0][i] = a[i];
	}
	for(int k = 1; k <= 20; k++){
		for(int i = 1; i + (1 << k) <= n + 1; i++){
			st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
		}
	}
	auto get = [&](int l, int r) -> int{
		int d = __lg(r - l + 1);
		return max(st[d][l], st[d][r - (1 << d) + 1]);
	};
	sort(b.begin() + 1, b.end());
	int mm = pmin[n];
	auto work = [&](int l, int r) -> void{
		int mx = max({pmax[l - 1], smax[r + 1], 2 * get(l, r)});
		int mi = min({pmin[l - 1], smin[r + 1], 2 * mm});
		ans = min(ans, mx - mi);
	};
	int l = b[1].second;
	int r = b[1].second;
	
	for(int i = 1; i <= n; i++){
		int j = i;
		int l1 = l, r1 = r;
		int f = 1;
		while(j <= n && b[j].first == b[i].first){
			int pos = b[j].second;
			if(pos <= l) l1 = pos;
			if(pos >= r && f) r1 = pos, f = 0; 
			j++;
		}
		work(l1, r);
		work(l, r1);
		l = min(l, b[i].second);
		r = max(r, b[j - 1].second);
		i = j - 1;
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
min (mx - mi)
可以把一段区间 * 2
非空

n^2 -> nlog
how ?

把最小值变大
最优嘛？

最大值不能变大
最大值变大 那么最大值就是mx * 2
223322

那么一定要把最小值变大

最大值尽可能小，最小值尽可能大

值相同的选择顺序？

mi 不会变，但是mx在变我要让mx 尽可能小

mx 递增一定是第一次最优

*/