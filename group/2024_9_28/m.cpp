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
int dy[] = {0, 0, -1, 1};
void solve(){
    int n; cin >> n;
    set<pair<int ,int>> s;
    double ans = 2 * n;

    for(int i = 1; i <= n; i++){
    	int x, y; cin >> x >> y;
    	if(s.count({x, y})){
    		ans -= 2;
    		continue;
    	}
    	s.insert({x, y});
    	for(int j = 0; j < 4; j++){
    		int tx = x + dx[j];
    		int ty = y + dy[j];
    		if(s.count({tx, ty})){
    			ans -= 0.5;
    		}
    	}
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}