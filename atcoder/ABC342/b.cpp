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
    vector<int> pos(n + 1);
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	int x; cin >> x;
    	pos[x] = i;
    	a[i] = x;
    }
    int q; cin >> q;
    for(int i = 1; i <= q; i++){
    	int l, r; cin >> l >> r;
    	int lp = pos[l], rp = pos[r];
    	if(lp < rp){
    		cout << l << '\n';
    	}else cout << r << '\n';
    	
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