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
    vector<int> ans(n + 1, m);
	int ok = 1;
	for(int i = 1; i <= n; i++){
		if(ans[i] <= 0)ok = 0;
		for(int j = i * 2; j <= n; j += i){
			ans[j] = ans[i] - 1;
		}
	}
	if(!ok){
		cout << -1 << '\n';
		return ;
	}
	for(int i = 1; i <= n; i++){
		cout << a[ans[i]] << " \n"[i == n];
	}
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