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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int limit = (n + 1) / 2;
	sort(a.begin() + 1, a.end());
	int ans = a[1] - 1;
	int cnt = 0;
	for(int i = n; i >= 1; i--){
		int j = i;
		while(j <= n && a[j] == a[i]){
			cnt++;
			j--;
		}
		if(cnt >= limit){
			ans = max(ans, a[i] - 1);
		}
		i = j + 1;
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