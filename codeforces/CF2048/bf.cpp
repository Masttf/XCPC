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
    int n, m;
    cin >> n >> m;
    vector a(2 * n + 1, vector<int>(m + 1));
    multiset<int> res;
    vector<int> vis(2 * n + m + 1);
    int ok = 1;
    auto dfs2 = [&](auto self, int v, int t, int f) -> void{
    	// dbg(v);
    	if(vis[v]){
    		if(v != t)return ;
    		int x = *res.rbegin();
    		int y = *res.begin();
    		if(x == y){
    			ok = 0;
    		}
    		return ;
    	}
    	vis[v] = 1;
    	if(v <= 2 * n){
    		for(int i = 1; i <= m; i++){
    			if(2 * n + i == f)continue;
    			res.insert(a[v][i]);
    			self(self, 2 * n + i, t, v);
    			res.erase(res.find(a[v][i]));
    		}
    	}else{
    		for(int i = 1; i <= 2 * n; i++){
    			if(i == f)continue;
    			res.insert(a[i][v - 2 * n]);
    			self(self, i, t, v);
    			res.erase(res.find(a[i][v - 2 * n]));
    		}
    	}
    	vis[v] = 0;
    };
    auto dfs = [&](auto self, int i, int j) -> void{
    	if(j == m + 1)i++, j = 1;
    	if(i == 2 * n + 1){
    		ok = 1;
    		// dfs2(dfs2, 1, 1, 0);
    		for(int x = 1; x <= 2 * n; x++){
    			if(!ok)break;
    			dfs2(dfs2, x, x, 0);
    		}
    		if(ok){
    			for(int x = 1; x <= 2 * n; x++){
    				for(int y = 1; y <= m; y++){
    					cout << a[x][y] << ' ';
    				}
    				cout << '\n';
    			}
    			cout << endl;
    		}
    		return ;
    	}
    	for(int c = 1; c <= n; c++){
    		a[i][j] = c;
    		self(self, i, j + 1);
    	}
    };
    dfs(dfs, 1, 1);
    cout << "????";
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