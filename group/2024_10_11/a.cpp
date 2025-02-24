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
    vector<vector<int>>g(10);
    vector<vector<int>> id(5, vector<int>(5));
    int num = 0;
    for(int i = 1; i <= 3; i++){
    	for(int j = 1; j <= 3; j++){
    		id[i][j] = ++num;
    	}
    }
    for(int i = 1; i <= n; i++){
    	int u, v; cin >> u >> v;
    	g[v].push_back(u);
    }
    for(int i = 1; i <= 9; i++){
    	sort(g[i].begin(), g[i].end());
    	g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
    }
    vector<vector<int>> res(5, vector<int>(5));
    auto check = [&]() -> bool{
    	for(int i = 1; i <= 3; i++){
    		int cnt = 0;
    		for(int j = 1; j <= 3; j++){
    			if(res[i][j] == res[i][1])cnt++;
    		}
    		if(cnt == 3 && res[i][1] != 0)return true;
    	}
    	for(int j = 1; j <= 3; j++){
    		int cnt = 0;
    		for(int i = 1; i <= 3; i++){
    			if(res[i][j] == res[1][j])cnt++;
    		}
    		if(cnt == 3 && res[1][j] != 0)return true;
    	}
    	int cnt = 0;
    	for(int i = 1; i <= 3; i++){
    		if(res[i][i] == res[1][1])cnt++;
    	}
    	if(cnt == 3 && res[1][1] != 0)return true;
    	cnt = 0;
    	for(int i = 1; i <= 3; i++){
    		if(res[4 - i][i] == res[1][3])cnt++;
    	}
    	if(cnt == 3 && res[1][3] != 0 )return true;
    	return false;
    };
    int tot = 9;
    // lose 1, draw 2, win 3
    vector<int> vis(10);
    auto dfs = [&](auto self, int now) -> int{
    	if(check())return 1;
    	if(tot == 0)return 2;
    	int use = 0;
    	array<int, 4> cnt = {0, 0, 0, 0};
    	for(int i = 1; i <= 3; i++){
    		for(int j = 1; j <= 3; j++){
    			int ok = 1;
    			for(auto v : g[id[i][j]]){
    				if(!vis[v])ok = 0;
    			}
    			if(!vis[id[i][j]] && ok){
    				res[i][j] = now;
    				vis[id[i][j]] = 1;
    				use++;
    				tot--;
    				cnt[self(self, 3 - now)]++;
    				tot++;
    				res[i][j] = 0;
    				vis[id[i][j]] = 0;
    			}
    		}
    	}
    	if(use == 0)return 2;
    	if(cnt[1] > 0)return 3;
    	if(cnt[3] == use)return 1;
    	return 2;
    };
    int ans = dfs(dfs, 1);
    if(ans == 1)cout << "O\n";
    else if(ans == 2) cout  << "E\n";
    else cout << "X\n";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}