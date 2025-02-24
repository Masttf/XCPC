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
    int n, m, c; cin >> n >> m >> c;
    vector cnt(c + 1, vector(105, vector<int>(105)));
    vector<array<int, 3>> a(n);
    for(auto &[x, y, s] : a){
    	cin >> x >> y >> s;
    }
    for(int i = 0; i <= c; i++){
    	for(auto [x, y, s] : a){
    		s = (s + i) % (c + 1);
    		cnt[i][x][y] += s;
    	}
    }
    for(int i = 0; i <= c; i++){
    	for(int j = 1; j <= 100; j++){
    		for(int k = 1; k <= 100; k++){
    			cnt[i][j][k] += cnt[i][j - 1][k] + cnt[i][j][k - 1] - cnt[i][j - 1][k - 1];
    		}
    	}
    }
    for(int i = 1; i <= m; i++){
    	int t, x1, y1, x2, y2; cin >> t >> x1 >> y1 >> x2 >> y2;
    	t %= (c + 1);
    	cout << cnt[t][x2][y2] - cnt[t][x1 - 1][y2] - cnt[t][x2][y1 - 1] + cnt[t][x1 - 1][y1 - 1] << '\n';
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