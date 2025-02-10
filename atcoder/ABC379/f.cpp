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
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> ans(q + 1, n + 1);
	vector<vector<pair<int, int>>> op(n + 1);
	for(int i = 1; i <= q; i++){
		int l, r; cin >> l >> r;
		op[r].push_back({r, i});
		op[l].push_back({r, i});
	}
	vector<int> res;
	for(int i = n; i >= 1; i--){
		for(auto [r, id] : op[i]){
			if(r == i){
				ans[id] = res.size();
			}else{
				// dbg(r, id);
				int L = 0, R = res.size() - 1;
				int t = -1;
				while(L <= R){
					// dbg(i, L, R);
					int mid = (L + R) >> 1;
					if(res[mid] > r){
						L = mid + 1;
						t = mid;
					}else R = mid - 1;
				}
				t++;
				ans[id] = min(ans[id], t);
			}
		}
		while(!res.empty() && a[res.back()] < a[i]){
			res.pop_back();
		}
		res.push_back(i);
	}
	for(int i = 1; i <= q; i++){
		cout << ans[i] << '\n';
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