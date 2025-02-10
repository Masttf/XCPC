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
    vector<pair<int, int>> a(m + 1);
    for(int i = 1; i <= m; i++){
    	cin >> a[i].first;
    }
    int sum = 0;
    for(int i = 1; i <= m; i++){
    	cin >> a[i].second;
    	sum += a[i].second;
    }
    // dbg(sum);
    if(sum != n){
    	cout << -1 << '\n';
    	return ;
    }
    sort(a.begin() + 1, a.end());
    int ans = 0;
    int last = 0;
    for(int i = 1; i <= m; i++){
    	auto [x, num] = a[i];
    	if(last < x - 1){
    		cout << -1 << '\n';
    		return ;
    	}
		ans += (last - x + 1 + last + num - x) * num / 2;
		last += num;
    	
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