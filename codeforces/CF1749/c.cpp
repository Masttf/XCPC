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
    sort(a.begin() + 1, a.end());
	int ans = 0;
	auto run = [&](int k) -> bool{
		int r = 1;
		while(r <= n && a[r] <= k)r++;
		r--;
		int l = 1;
		int cnt = 0;
		for(int i = r, j = k; i >= l; i--, j--){
			while(i >= l && a[i] > j)i--;
			if(i < l)break;
			cnt++;
			l++;
		}
		return cnt >= k;
	};
	for(int i = n; i >= 1; i--){
		if(run(i)){
			ans = i;
			break;
		}
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