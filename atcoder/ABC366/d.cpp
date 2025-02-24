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
    vector pre(n + 1, vector(n + 1, vector<int>(n + 1)));
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		for(int k = 1; k <= n; k++){
    			cin >> pre[i][j][k];
    		}
    	}
    }
    
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		for(int k = 1; k <= n; k++){
    			pre[i][j][k] += pre[i - 1][j][k];
    		}
    	}
    }
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		for(int k = 1; k <= n; k++){
    			pre[i][j][k] += pre[i][j - 1][k];
    		}
    	}
    }
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		for(int k = 1; k <= n; k++){
    			pre[i][j][k] += pre[i][j][k - 1];
    		}
    	}
    }
    int q; cin >> q;
    for(int i = 1; i <= q; i++){
    	int x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    	int ans = pre[y1][y2][y3] - pre[x1 - 1][y2][y3] - pre[y1][x2 - 1][y3] + pre[x1 - 1][x2 - 1][y3] - (pre[y1][y2][x3 - 1] - pre[x1 - 1][y2][x3 - 1] - pre[y1][x2 - 1][x3 - 1] + pre[x1 - 1][x2 - 1][x3 - 1]);
    	cout << ans << '\n';
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}