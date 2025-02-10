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
vector<vector<pair<int, int>>> g(20);
void init(){
	g[0] = {{3, 7}, {4, 9}, {1, 2}};
	g[1] = {{4, 8}, {5, 10}};
	g[2] = {{5, 9}, {1, 0}, {6, 11}};
	g[3] = {{4, 5}, {8, 13}};
	g[4] = {{5, 6}, {8, 12}, {9, 14}};
	g[5] = {{4, 3}, {9, 13}, {10, 15}};
	g[6] = {{5, 4}, {10, 14}};
	g[7] = {{3, 0}, {8, 9}, {12, 16}};
	g[8] = {{4, 1}, {9, 10}, {13, 17}};
	g[9] = {{4, 0}, {8, 7}, {13, 16}, {14, 18}, {10, 11}, {5, 2}};
	g[10] = {{5, 1}, {9, 8}, {14, 17}};
	g[11] = {{6, 2}, {10, 9}, {15, 18}};
	g[12] = {{8, 4}, {13, 14}};
	g[13] = {{8, 3}, {9, 5}, {14, 15}};
	g[14] = {{9, 4}, {13, 12}, {10, 6}};
	g[15] = {{10, 5}, {14, 13}};
	g[16] = {{12, 7}, {13, 9}, {17, 18}};
	g[17] = {{13, 8}, {14, 10}};
	g[18] = {{17, 16}, {14, 9}, {15, 11}};
}


void solve(){
	init();
	int n = 19;
    vector<int> val(n);
    for(int i = 0; i < n; i++) cin >> val[i];
    vector id(10, vector<int>(10, -1));
	{
		int tot = 0;
		for(int i = 1; i <= 3; i++){
			for(int j = 1; j <= 2 + i; j++){
				id[i][j] = tot++;
			}
		}
		for(int i = 2, k = 4; i >= 1; i--, k++){
			for(int j = 1; j <= 2 + i; j++){
				id[k][j] = tot++;
			}
		}
	}
	// dbg("???");
	vector<int> ans(1 << n, -1);
	ans[0] = 0;
	for(int i = 0; i < n; i++){
		ans[(1 << i)] = 0;
	}
	auto dfs = [&](auto self, int s) -> int{
		if(ans[s] != -1)return ans[s];
		// dbg("new", s);
		int res = 0;
		for(int i = 0; i < n; i++){
			if(s >> i & 1){
				res = max(res, self(self, s ^ (1 << i)));
			}
		}
		for(int i = 0; i < n; i++){
			if(s >> i & 1){
				for(auto [mx, tx] : g[i]){
					// dbg(i, mx, tx);
					if(s >> tx & 1)continue;
					if(!(s >> mx & 1))continue;
					// dbg("yes");
					int ts = (1 << i) | (1 << mx) | (1 << tx);
					// dbg(s, ts, s ^ ts);
					res = max(res, self(self, s ^ ts) + val[mx]);
				}
			}
		}
		// dbg(s, res);
		return ans[s] = res;
	};
	int t; cin >> t;
	while(t--){
		int s = 0;
		vector<string> b(6);
		for(int i = 1; i <= 5; i++){
			cin >> b[i];
			b[i] = ' ' + b[i];
		}
		for(int i = 1; i <= 5; i++){
			for(int j = 1; j <= 5; j++){
				if(id[i][j] == -1)break;
				if(b[i][j] == '#'){
					// dbg(i, j);
					s |= (1 << id[i][j]);
				}
			}
		}
		// dbg(s);
		cout << dfs(dfs, s) << '\n';
	}
	// for(int i = 1; i <= 5; i++){
	// 	for(int j = 1; j <= 5; j++){
	// 		cout << id[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	// cout << dfs(dfs, 768);
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