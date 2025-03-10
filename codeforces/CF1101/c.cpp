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
    vector<array<int, 3>> a(n + 1);
    for(int i = 1; i <= n; i++){
    	int l, r; cin >> l >> r;
    	a[i] = {l, r, i};
    }
    sort(a.begin() + 1, a.end());
    int mxr = a[1][1];
    vector<int> ans(n + 1);
    int ok = 0;
    for(int i = 2; i <= n; i++){
    	auto [l, r, id] = a[i];
    	if(l > mxr){
    		ok = 1;
    		for(int j = 1; j <= n; j++){
    			int _ = a[j][2];
    			if(j < i)ans[_] = 1;
    			else ans[_] = 2;
    		}
    		break;
    	}
    	mxr = max(mxr, r);
    }
    if(ok){
    	for(int i = 1; i <= n; i++){
    		cout << ans[i] << ' ';
    	}
    	cout << '\n';
    	return ;
    }
    cout << -1 << '\n';
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