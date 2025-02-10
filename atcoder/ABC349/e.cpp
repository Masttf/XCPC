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
	int n = 3;
    vector<vector<int>>a(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		cin >> a[i][j];
    	}
    }
    vector vis(n + 1, vector<int>(n + 1));
    vector<int> val(5);
    auto check = [&]() -> bool{
    	for(int i = 1; i <= 3; i++){
    		int ok = 1;
    		for(int j = 1; j <= 3; j++){
    			if(vis[i][j] != vis[i][1]) ok = 0;
    		}
    		if(ok && vis[i][1]) return false;
    	}
    	for(int i = 1; i <= 3; i++){
    		int ok = 1;
    		for(int j = 1; j <= 3; j++){
    			if(vis[j][i] != vis[1][i]) ok = 0;
    		}
    		if(ok && vis[1][i]) return false;
    	}
    	if(vis[1][1] && vis[1][1] == vis[2][2] && vis[2][2] == vis[3][3]){
    		return false;
    	}
    	if(vis[1][3] && vis[1][3] == vis[2][2] && vis[2][2] == vis[3][1]){
    		return false;
    	}
    	return true;
    };
    auto dfs = [&](auto self, int now, int step) -> int{
    	if(!check())return 0;
    	if(step == 10){
    		if(val[now] > val[3 - now])return 1;
    		else return 0;
    	}
    	int ok = 0;
    	for(int i = 1; i <= 3; i++){
    		for(int j = 1; j <= 3; j++){
    			if(vis[i][j])continue;
    			vis[i][j] = now;
    			val[now] += a[i][j];
    			int d = self(self, 3 - now, step + 1);
    			if(d == 0) ok = 1;
    			vis[i][j] = 0;
    			val[now] -= a[i][j];
    		}
    	}
    	return ok;
    };
    int ans = dfs(dfs, 1, 1);
    if(ans == 1){
    	cout << "Takahashi";
    }else cout << "Aoki";
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