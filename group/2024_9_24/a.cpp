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
    int n, h, t; cin >> n >> h >> t;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
	int sum = 0;
	for(int i = 1; i <= n; i++){
		if(sum + a[i] > h){
			int d = (sum - (h - a[i]) + t - 1) / t;
			ans += d;
			sum = max(0ll, sum - d * t);
		}
		int j = i;
		while(j <= n && a[j] + sum <= h){
			sum += a[j];
			j++;
		}
		i = j - 1;
	}
	ans += (sum + t - 1) / t;
	cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;// cin >> t;
    while(t--)solve();
    return 0;
}