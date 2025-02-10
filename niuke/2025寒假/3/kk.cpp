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
    void init(){
        tr.assign(n + 1, Info());
    }
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
    vector g(n + 1, vector<int>());
    vector<array<int, 3>> a(n + 1);
    vector<int> p;
    for(int i = 1; i <= n; i++){
        int j; cin >> j;
        int l = 1e18, r = 0;
        while(j--){
            int x; cin >> x;
            l = min(l, x);
            r = max(r, x);
            p.push_back(x);
            g[i].push_back(x);
        }
        a[i] = {l, r, i};
    }
    sort(a.begin() + 1, a.end());
    reverse(a.begin() + 1, a.end());
    sort(p.begin(), p.end());
    auto get = [&](int x) -> int{
        return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
    };
    int sum = 0;
    int N = p.size();
    Fenwick<int> tr(N + 1);
    for(int i = 1; i <= n; i++){
        tr.init();
        const int sz = g[i].size();
        for(int j = sz - 1; j >= 0; j--){
            sum += tr.ask(get(g[i][j]));
            tr.add(get(g[i][j]), 1); 
        }
    }
    int mi = sum;
    int mx = mi;
    int tot = N;
    for(int i = 1; i <= n; i++){
        const int sz = g[a[i][2]].size();
        tot -= sz;
        mx += sz * tot;
    }
    // dbg(mi, mx);
    if(mi <= k && k <= mx){
        vector<int> res;
        int tot = N;
        for(int i = n; i >= 1; i--){
            const int sz = g[a[i][2]].size();
            tot -= sz;
            if(mx - sz * tot >= k){
                for(auto x : g[a[i][2]]){
                    res.push_back(x);
                }
                mx -= sz * tot;
            }else{
                // dbg(i);
                int l = res.size();
                for(int j = 1; j < i; j++){
                    for(auto x : g[a[j][2]]){
                        res.push_back(x);
                    }
                }
                k = mx - k;
                int now = 0;
                // dbg(k);
                while(k){
                    res.push_back(g[a[i][2]][now]);
                    for(int j = res.size() - 1; j > l; j--){
                        if(k == 0)break;
                        swap(res[j], res[j - 1]);
                        k--;
                    }
                    now++;
                    l++;
                }
                for(int j = now; j < sz; j++){
                    res.push_back(g[a[i][2]][j]);
                }
                break;
            }
        }
        cout << "Yes\n";
        for(auto x : res){
            cout << x << ' ';
        }
        cout << '\n';
        int cnt = 0;
        tr.init();
        for(int i = N - 1; i >= 0; i--){
            cnt += tr.ask(get(res[i]));
            tr.add(get(res[i]), 1);
        }
        // dbg(cnt, K);
        if(cnt != K){
            while(1);
        }
        assert(cnt == K);
    }else{
        cout << "No\n";
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