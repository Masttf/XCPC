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
    vector<int> p (n + 1);
    p[0] = 1;
    for(int i = 1; i <= n; i++){
    	p[i] = p[i - 1] * 3;
    }
    vector ans(p[n] + 1, vector<char>(p[n] + 1, '.'));
    auto dfs = [&](auto self, int x, int y, int len) -> void{
    	if(len == 0){
    		ans[x][y] = '#';
    		return ;
    	}
    	int dlen = p[len - 1];
    	self(self, x, y, len - 1);
    	self(self, x + dlen, y, len - 1);
    	self(self, x + 2 * dlen, y, len - 1);
    	self(self, x, y + dlen, len - 1);
    	self(self, x + 2 * dlen, y + dlen, len - 1);
    	self(self, x, y + 2 * dlen, len - 1);
    	self(self, x + dlen, y + 2 * dlen, len - 1);
    	self(self, x + 2 * dlen, y + 2 *dlen, len - 1);
    };
    dfs(dfs, 1, 1, n);
    for(int i = 1; i <= p[n]; i++){
    	for(int j = 1; j <= p[n]; j++){
    		cout << ans[i][j];
    	}
    	cout << '\n';
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