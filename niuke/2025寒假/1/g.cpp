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
    int sum = 0;
	for(int i = 1; i <= n; i++){
		sum += a[i];
	}
	if(sum != (n + 1) * n / 2){
		cout << -1 << '\n';
		return ;
	}
	sort(a.begin() + 1, a.end());
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += abs(a[i] - i);
	}
	ans /= 2;
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
/*
操作次数最少
sort后对应
*/