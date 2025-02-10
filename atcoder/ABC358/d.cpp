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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
   	vector<int> b(m + 1);
   	for(int i = 1; i <= m; i++) cin >> b[i];
   	sort(a.begin() + 1, a.end());
   	sort(b.begin() + 1, b.end());
   	int l = 1;
   	int ok = 1;
   	int ans = 0;
   	for(int i = 1; i <= m; i++){
   		while(l <= n && a[l] < b[i]){
   			l++;
   		}
   		if(l > n){
   			ok = 0;
   			break;
   		}
   		// dbg(i, l);
   		ans += a[l++];
   	}
   	if(ok)cout << ans << '\n';
   	else cout << -1 << '\n';
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