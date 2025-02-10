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
    vector<array<int, 3>> a(n + 1);
    for(int i = 1; i <= n; i++){
    	int l, r; cin >> l >> r;
    	a[i] = {l, r, i};
    }
    sort(a.begin() + 1, a.end());
    vector<int> ans(n + 1);
    set<pair<int, int>> s;
    int ok = 1;
    for(int i = 1, j = 1; i <= n; i++){
    	while(!s.empty() && (*s.begin()).first < i){
    		s.erase(s.begin());
    	}
    	while(j <= n && a[j][0] <= i){
    		s.insert({a[j][1], a[j][2]});
    		j++;
    	}
    	if(s.empty()){
    		ok = 0;
    		break;
    	}
    	auto [pos, id] = *(s.begin());
    	ans[id] = i;
    	s.erase(s.begin());
    }
    for(int i = 1; i <= n; i++){
    	if(ans[i] == 0){
    		cout << -1 << '\n';
    		return ;
    	}
    }
	for(int i = 1; i <= n; i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return ;
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
/*
根据 窗口大小来贪心

*/