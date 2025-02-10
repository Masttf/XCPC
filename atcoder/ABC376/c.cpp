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
    vector<int>b(n);
	for(int i = 1; i < n; i++) cin >> b[i];
	sort(a.begin() + 1, a.end());
	sort(b.begin() + 1, b.end());
	auto check = [&](int x) -> bool{
		int pos = lower_bound(b.begin() + 1, b.end(), x) - b.begin();
		// dbg(x, pos);
		int f = 0;
		for(int i = 1, j = 1; i <= n; i++){
			// dbg(i);
			if(!f && j == pos){
				f = 1;
				// dbg(i, a[i], x);
				if(a[i] > x)return false;
			}else{
				// dbg(i, a[i], j, b[j]);
				if(a[i] > b[j])return false;
				j++;
			}
		}
		return true;
	};
	int ans = -1;
	int l = 0, r = a[n];
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)){
			ans = mid;
			r = mid - 1;
		}else l = mid + 1;
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