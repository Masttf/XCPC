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
    vector<int> ans(n + 1);
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
   	ans[1] = a[1] + m;
   	for(int i = 2; i <= n; i++){
   		if(a[i] >= ans[i - 1])ans[i] = a[i] + m;
   		else ans[i] = ans[i - 1] + m;
   	}
   	for(int i = 1; i <= n; i++){
   		cout << ans[i] << '\n';
   	}
   	// cout << '\n';
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