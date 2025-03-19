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
    vector<int> a(m + 1);
    for(int i = 1; i <= m; i++) cin >> a[i];
    int ans = 0;
	sort(a.begin() + 1, a.end());
    for(int i = 1; i < n; i++){
    	int len = n - i;
    	int pos1 = lower_bound(a.begin() + 1, a.end(), i) - a.begin();
    	int pos2 = lower_bound(a.begin() + 1, a.end(), len) - a.begin();
    	if(pos1 > n || pos2 > n)continue;
    	if(pos1 < pos2){
    		ans += (pos2 - pos1) * (m - pos2 + 1);
    		ans += (m -pos2 + 1) * (m - pos2);
    	}else{
    		ans += (m - pos1 + 1) * (m - pos2);
    	}
    	// dbg(i, ans, pos1, pos2);
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}