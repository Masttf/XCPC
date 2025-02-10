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
    int n, m; cin >> n >> m;
    map<int, int>mp1;
    map<int, int>mp2;
    map<int, int>row;
    map<int, int>col;
    vector<pair<int, int>>a(m + 1);
    for(int i = 1; i <= m; i++){
    	cin >> a[i].first >> a[i].second;
    	row[a[i].first] = 1;
    	col[a[i].second] = 1;
    	mp1[a[i].first + a[i].second] = 1;
    	mp2[a[i].first - a[i].second] = 1;
    }
    int ans = (n - row.size()) * (n - col.size());
    for(auto [d, _] : mp1){
    	set<int> s;
    	for(auto [x, y]: row){
    		if(1 <= d - x && d - x <= n){
    			s.insert(x);
    		}
    	}
    	for(auto [x, y] : col){
    		if(1 <= d - x && d - x <= n){
    			s.insert(d - x);
    		}
    	}
    	ans -= n - abs(n + 1 - d) - s.size();
    }
    for(auto [d, _] : mp2){
    	set<int> s;
    	for(auto [x, y]: row){
    		if(1 <= x - d && x - d <= n){
    			s.insert(x);
    		}
    	}
    	for(auto [x, y] : col){
    		if(1 <= d + x && d + x <= n){
    			s.insert(x + d);
    		}
    	}
    	for(auto [x, y] : mp1){
    		int i = (x + d) / 2;
    		int j = (x - d) / 2;
    		if((x + d) % 2 == 0 && (x - d) % 2 == 0 && 1 <= i && i <= n && 1 <= j && j <= n){
    			s.insert(i);
    		}
    	}
    	ans -= n - abs(d) - s.size();
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