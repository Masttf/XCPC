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
    int n, k; cin >> n >> k;
    int K = k;
    vector<pair<int, int>> a(n);
    for(int i = 1; i <= n; i++){
    	int j; cin >> j;
    	int l = 1e18, r = 0;
    	while(j--){
    		int x; cin >> x;
    		l = min(l, x);
    		r = max(r, x);
    	}
    	a[i - 1] = {l, r};
    }
    sort(a.begin() + 1, a.end());
    vector<int> ans;
    for(auto [l, r] : a){
    	for(int j = l; j <= r; j++){
    		ans.push_back(j);
    	}
    }
    reverse(ans.begin(), ans.end());
    // for(auto x : ans){
    // 	cout << x << ' ';
    // }
    // cout << endl;
    int len = ans.size();
    int tot = (len - 1) * len / 2;
    if(tot < k){
    	cout << "NO\n";
    	return ;
    }
    vector<int> res;
    for(int i = len - 1; i > 0; i--){
    	if(tot - i >= k){
    		res.push_back(ans[i]);
    		tot -= i;
    	}else{
    		for(int j = 0; j <= i; j++){
    			res.push_back(ans[j]);
    		}
    		break;
    	}
    }
    int now = len - 1;
    k = tot - k; 
    while(k--){
    	swap(res[now], res[now - 1]);
    }
    cout << "Yes\n";
    for(auto x : res){
    	cout << x << ' ';
    }
    cout << '\n';
    vector<int> b = ans;
    reverse(b.begin(), b.end());
    auto get = [&](int x) -> int{
    	return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
    };
    Fenwick<int> tr(len);
    int sum = 0;
    for(int i = len - 1; i >= 0; i--){
    	sum += tr.ask(get(res[i]));
    	tr.add(get(res[i]), 1);
    }
    // dbg(sum, K);
    if(sum != K){
    	while(1);
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
/*
如何构造逆序对是k？？？
先构造全逆序对

冒泡排序一次会少一个逆序对

*/