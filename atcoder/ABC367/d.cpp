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
    vector<int> suf(2 * n + 1);
	suf[2 * n] = a[n] % m;
	for(int i = 2 * n - 1; i >= 1; i--){
		if(i > n)suf[i] = (suf[i + 1] + a[i - n]) % m;
		else suf[i] = (suf[i + 1] + a[i]) % m;
	}
	int ans = 0;
	map<int, int>s;
	for(int i = n + 1; i <= 2 * n; i++){
		s[suf[i]]++;
		//dbg(i, suf[i]);
	}
	for(int i = n; i >= 1; i--){
		//dbg(i, suf[i]);
		s[suf[i + n]]--;
		if(s[suf[i + n]] == 0){
			s.erase(suf[i + n]);
		}
		if(s.count(suf[i]))ans += s[suf[i]];
		s[suf[i]]++;
		//dbg(i, ans);
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