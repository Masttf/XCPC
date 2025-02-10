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
    for(int i = 1; i <= n; i++){
    	cin >> a[i].first >> a[i].second;
    }
    sort(a.begin() + 1, a.end());
    Fenwick<int> tr(2 * n);
    int cnt = 0;
    for(int i = 1; i <= n; i++){
    	auto [l, r] = a[i];
    	cnt += tr.rangeAsk(l, r);
    	tr.add(r, 1);
    }
    if(cnt != n - 1){
    	cout << "NO\n";
    	return ;
    }
    vector<int> f(n + 1);
    for(int i = 1; i <= n; i++)f[i] = i;
    auto find = [&](auto self, int x) -> int{
    	return f[x] == x ? x : f[x] = self(self, f[x]);
    };
    auto merge = [&](int a, int b) -> void{
    	int fa = find(find, a);
    	int fb = find(find, b);
    	if(fa == fb)return ;
    	f[fa] = fb;
    };
    set<pair<int, int>> s;
    for(int i = 1; i <= n; i++){
    	auto [l, r] = a[i];
    	auto it = s.lower_bound({l, 0});
    	while(it != s.end() && (*it).first < r){
    		merge(i, (*it).second);
    		it++;
    	}
    	s.insert({r, i});
    }
    cnt = 0;
    for(int i = 1; i <= n; i++){
    	if(find(find, i) == i)cnt++;
    }
    if(cnt == 1)cout << "YES\n";
    else cout << "NO\n";
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
l < r 且端点都不相同
先判总边数是不是n - 1
是再判是不是连通块

边数是n-1
判相交
li < lj < ri < rj
先按l排序
那么就是找 lj < ri < rj 的个数 fenwick

判连通块
已知边数是n - 1
我能不能暴力连？
nlog 可以找到所有边

*/