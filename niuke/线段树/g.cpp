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
template<class Info>
struct Fenwick{
	#define lowbit(x) ((x) & (-x))
	vector<Info> tr;
	int n;
	Fenwick(int n_) : n(n_), tr(n_ + 1){}
	void add(int x, Info val){
		while(x <= n){
			tr[x] = tr[x] + val;
			x += lowbit(x);
		}
	}
	Info ask(int x){
		Info res = Info();
		while(x > 0){
			res = res + tr[x];
			x -= lowbit(x);
		}
		return res;
	}
	Info rangeAsk(int l, int r){
		return ask(r) - ask(l - 1);
	}
	template<class F>
	int find(F &&check){
		int p = 0;
		Info res = Info();
		int d = __lg(n);
		for(int i = d; i >= 0; i--){
			int v = p + (1ll << i);
			if(v <= n && check(res + tr[v])){
				p = v;
				res = res + tr[p];
			}
		}
		return p;
	}
};
void solve(){
    int n; cin >> n;
    vector<pair<int, int>> a(n + 1);
    vector<int> p;
    for(int i = 1; i <= n; i++){
    	int x, y; cin >> x >> y;
    	a[i] = {x, y};
    	p.push_back(x);
    	p.push_back(y);
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    auto get = [&](int x) -> int{
    	return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
    };
    for(int i = 1; i <= n; i++){
    	a[i].first = get(a[i].first);
    	a[i].second = get(a[i].second);
    }
    sort(a.begin() + 1, a.end());
    vector<int> cnt(n);
    Fenwick<int> tr(p.size());
    for(int i = 1; i <= n; i++){
    	auto [x, y] = a[i];
    	cnt[tr.ask(y)]++;
    	tr.add(y, 1);
    }
    for(auto x : cnt){
    	cout << x << '\n';
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