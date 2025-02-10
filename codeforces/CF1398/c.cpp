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
    string s; cin >> s;
    s = ' ' + s;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	a[i] = s[i] - '0';
    }
    vector<int> pre(n + 1);
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	int ans = 0;
	map<int, int> mp;
	mp[0] = 1;
	for(int i = 1; i <= n; i++){
		int d = pre[i] - i;
		ans += mp[d];
		mp[d]++;
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