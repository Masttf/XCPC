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
    int n, m; cin >> n >> m;
    int sx, sy; cin >> sx >> sy;
    int ok = 1;
    auto run = [&](int l, int r, int target) -> vector<pair<int, int>>{
    	vector<pair<int, int>> res;
    	if(target == l || target == r)return res;
    	while(l < r){
    		if((l + r) % 2 != 0){
    			ok = 0;
    			break;
    		}
    		int mid = (l + r) >> 1;
    		res.push_back({l, r});
    		if(mid == target)break;
    		else if(mid < target){
    			l = mid;
    		}else r = mid;
    	}
    	if((l + r) % 2 != 0)ok = 0;
    	if((l + r) / 2 != target)ok = 0;
    	return res;
    };
    vector<pair<int, int>> x = run(0, n, sx);
    vector<pair<int, int>> y = run(0, m, sy);
    if(!ok){
    	cout << -1 << '\n';
    	return ;
    }else{
        vector<pair<int, int>>chose = {{0, 0}, {0, m}, {n, 0}, {n, m}};
    	vector<array<int, 4>> res;
        auto dfs = [&](auto self, pair<int, int> t) -> void{
            auto [xx, yy] = t;
            if(xx == 0 && yy == 0)return ;
            if(xx == 0 && yy == m)return ;
            if(xx == n && yy == 0)return ;
            if(xx == n && yy == m)return ;
            int cx = 0;
            if(2 * xx > n)cx = n;
            int cy = 0;
            if(2 * yy > m)cy = m;
            int ccx = abs(cx - 2 * xx);
            int ccy = abs(cy - 2 * yy);
            self(self, {ccx, ccy});
            res.push_back({cx, cy, ccx, ccy});
        };
        dfs(dfs, {sx, sy});
        cout << res.size() << '\n';
        for(auto [a, b, c, d] : res){
            cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
        }
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