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
constexpr int Max = 1e18;
void solve(){
    int n, q; cin >> n >> q;
    vector<pair<int, int>> Q(q + 1);
    for(int i = 1; i <= q; i++){
    	char ty; cin >> ty;
    	int x; cin >> x;
    	x--;
    	if(ty == 'L')Q[i] = {0, x};
    	else Q[i] = {1, x};
    }
    vector dp(q + 1, vector<int>(n, Max));
    dp[0][1] = 0;
    auto get = [&](int from, int to, int ng) -> vector<pair<int, int>>{
    	vector<pair<int, int>>res;
    	if(to != ng){
    		if(min(from, to) < ng && ng < max(from, to)){
    			res.push_back({n - abs(from - to), ng});
    		}else{
    			res.push_back({abs(from - to), ng});
    		}
    	}
    	if(from < ng){
    		if(from < to && to <= ng){
    			res.push_back({n - (to - from) + ng - to + 1, to - 1});
    		}
    		if(to < from || ng <= to){
    			res.push_back({(to - from + n) % n + (to - ng + n) % n + 1, (to + 1) % n});
    		}
    	}else{
    		if(ng <= to && to < from){
    			res.push_back({n - (from - to) + to - ng + 1, to + 1});
    		}
    		if(to <= ng || to > from){
    			res.push_back({(from - to + n) % n + (ng - to + n) % n + 1, (to + n - 1) % n});
    		}
    	}
    	return res;
    };
    
    int lh = 0, lp = 0;
    for(int i = 0; i < q; i++){
    	auto [h, p] = Q[i + 1];
    	for(int j = 0; j < n; j++){
    		if(dp[i][j] == Max)continue;
    		array<int, 2>pos;
    		pos[lh] = lp;
    		pos[lh ^ 1] = j;
    		for(auto [num, np] : get(pos[h], p, pos[h ^ 1])){
    			dp[i + 1][np] = min(dp[i + 1][np], dp[i][j] + num);
    		}
    	}
    	dbg(i + 1);
    	for(int j = 0; j < n; j++){
    		dbg(j, dp[i + 1][j]);
    	}
    }
    int ans = Max;
    for(int i = 0; i < n; i++){
    	ans = min(ans, dp[q][i]);
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