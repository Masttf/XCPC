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
    int ans = 0;
	int m = *max_element(a.begin() + 1, a.end());
	vector<int> cnt(m + 1);
	for(int i = n; i >= 1; i--){
		
		int res = 1;
		int x = a[i];
		for(int j = 2; j * j <= x; j++){
			if(x % j == 0){
				int cnt = 0;
				while(x % j == 0){
					cnt++;
					x /= j;
				}
				if(cnt & 1)res *= j;
			}
		}
		if(x > 1)res *= x;
		if(a[i] == 0)ans += n - i;
		else{
			ans += cnt[0];
			for(int j = 1; j * j * res <= m; j++){
				ans += cnt[j * j * res];
			}
		}
		cnt[a[i]]++;
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