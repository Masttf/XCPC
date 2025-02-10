#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
void solve(){
    int n, s; cin >> n >> s;
    vector<int>a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    vector st(21, vector<pair<int, int>>(n + 1));
	for(int i = 1; i <= n; i++){
		st[0][i] = {a[i], i};
	}
	for(int k = 1; k <= 20; k++){
		for(int i = 1; i + (1 << k) <= n + 1; i++){
			st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k  - 1))]);
		}
	}
	auto get_min = [&](int l, int r) -> int{
		int d = r - l + 1;
		d = __lg(d);
		return min(st[d][l], st[d][r - (1 << d) + 1]).second;
	};
	for(int i = 1; i <= n; i++){
		b[i] += b[i - 1];
	}
	auto dfs = [&](auto self, int l, int r) -> int{
		int ans = 0;
		int x = get_min(l, r);
		if(x != l)ans += self(self, l, x - 1);
		if(x != r)ans += self(self, x + 1, r);
		if(x - l < r - x){
			for(int i = l - 1; i <= x - 1; i++){
				int L = x, R = r;
				int res = x - 1;
				while(L <= R){
					int mid = (L + R) >> 1;
					if(b[mid] - b[i] + a[x] <= s){
						res = mid;
						L = mid + 1;
					}else R = mid - 1;
				}
				ans += res - x + 1;
			}
		}else{
			for(int i = x; i <= r; i++){
				int L = l - 1, R = x - 1;
				int res = x;
				while(L <= R){
					int mid = (L + R) >> 1;
					if(b[i] - b[mid] + a[x] <= s){
						res = mid;
						R = mid - 1;
					}else L = mid + 1;
				}
				ans += x - res;
			}
		}
		return ans;
	};
	cout << dfs(dfs, 1, n) << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;//cin >> t;
    while(t--)solve();
    return 0;
}