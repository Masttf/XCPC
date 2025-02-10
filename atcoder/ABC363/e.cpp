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
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector a(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		cin >> a[i][j];
    	}
    }
    int ans = n * m;
    set<array<int, 3>>s;
    vector vis(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= m; i++){
    	s.insert({a[1][i], 1, i});
    	if(n != 1)s.insert({a[n][i], n, i});
    }
    for(int i = 1; i <= n; i++){
    	s.insert({a[i][1], i, 1});
    	if(m != 1)s.insert({a[i][m], i, m});
    }
    for(int i = 1; i <= k; i++){
    	while(!s.empty() && (*s.begin())[0] <= i){
    		auto [val, x, y] = *s.begin();
    		//if(i == 1)dbg(val, x, y);
    		s.erase(s.begin());
    		ans--;
    		vis[x][y] = 1;
    		for(int j = 0; j < 4; j++){
    			int tx = x + dx[j];
    			int ty = y + dy[j];
    			if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && !vis[tx][ty])s.insert({a[tx][ty], tx, ty});
    		}
    	}
    	cout << ans << '\n';
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