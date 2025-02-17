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
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> p(n + 5);
	for(int i = 1; i <= n; i++){
		p[i] = p[i - 1] ^ a[i];
	}
	p[n + 1] = p[n];
	vector<int> b(n + 1);
    for(int i = 1; i <= n; i++){
    	for(int j = 29; j >= 0; j--){
    		if(a[i] >> j & 1){
    			b[i] = j;
    			break;
    		}
    	}
    }
    ST<int, greater<int>> st(b);
    for(int i = 1; i <= q; i++){
    	int x; cin >> x;
    	int now = n;
    	for(int j = 29; j >= 0; j--){
    		if(now == 0 || x < a[now])break;
    		if(x >> j & 1){
    			int l = 1, r = now;
    			int res = now + 1;
    			while(l <= r){
    				int mid = (l + r) >> 1;
    				if(st.get(mid, r) < j){
    					res = mid;
    					r = mid - 1;
    				}else l = mid + 1;
    			}
    			x ^= (p[now] ^ p[res - 1]);
    			now = res - 1;
    			if(now == 0)break;
    			if(x >= a[now]){
    				x ^= a[now];
    				now--;
    			}
    			// dbg(j, x, now + 1);
    		}
    	}
    	cout << n - now << ' ';
    }
    cout << '\n';
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
往左吃，值变异或
先看最高位的1

*/