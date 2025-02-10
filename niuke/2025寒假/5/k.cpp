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
    int n; cin >> n;
    vector<array<int, 3>> a(n + 1);
    for(int i = 1; i <= n; i++){
    	int x, y, r; cin >> x >> y >> r;
    	a[i] = {x, y, r};
    }
    int tot = 0;
    int N = 2e5 + 5;
    vector res(2 * N, vector<pair<int, int>>());
    vector prim(N, vector<int>());
    for(int i = 2; i < N; i++){
    	if(prim[i].empty()){
    		for(int j = i; j < N; j += i){
    			prim[j].push_back(i);
    		}
    	}
    }
    for(int b = 1; b <= 200000; b++){
    	int t = b * b;
    	vector<pair<int, int>> temp;
    	for(auto x : prim[b]){
    		int cnt = 0;
    		while(t % x == 0){
    			t /= x;
    			cnt++;
    		}
    		if(cnt)temp.push_back({x, cnt});
    	}
    	t = b * b;
    	auto dfs = [&](auto self, int now, int val) -> void{
    		if(val * val > t)return ;
    		if(now == temp.size()){
    			int t1 = val, t2 = t / val;
    			if(t1 % 2 == t2 % 2){
    				int r = (t1 + t2) / 2;
    				int y = (t2 - t1) / 2;
    				if(r < 2 * N && y > 0){
    					res[r].push_back({y, b});
    				}
    			}
    			return ;
    		}
    		for(int i = 0; i <= temp[now].second; i++){
    			self(self, now + 1, val);
    			val *= temp[now].first;
    			if(val * val > t)break;
    		}
    	};
    	dfs(dfs, 0, 1);
    }
    unordered_map<int, int> mp;
    for(int i = 1; i <= n; i++){
    	auto [x, y, r] = a[i];
    	mp[x * 10000000LL + y]++;
    }
    int ans = 0;
    auto get = [&](int x, int y) ->void{
    	if(mp.count(x * 10000000LL + y)) ans += mp[x * 10000000LL + y];
    };
    for(int i = 1; i <= n; i++){
    	auto [x, y, r] = a[i];
    	if(r >= 2 * N)continue;
    	get(x + r, y);
        get(x - r, y);
        get(x, y + r);
        get(x, y - r);
    	for(int s1 : {-1, 1}){
    		for(int s2 : {-1, 1}){
    			for(auto [dx, dy] : res[r]){
    				get(x + dx * s1, y + dy * s2);
    			}
    		}
    	}
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