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
    vector<int>pos(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> pos[i];
    }
    vector<int>val(n + 1), pre(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> val[i];
    	pre[i] = pre[i - 1] + val[i];
    }
    int q; cin >> q;
    for(int i = 1; i <= q; i++){
    	int l, r; cin >> l >> r;
    	int L = lower_bound(pos.begin() + 1, pos.end(), l) - pos.begin();
    	int R = upper_bound(pos.begin() + 1, pos.end(), r) - pos.begin() - 1;
    	//dbg(L, R);
    	if(L <= R){
    		cout << pre[R] - pre[L - 1] << '\n';
    	}else cout << 0 << '\n';
    }
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