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
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> p(n + 1);
	for(int i = 1; i <= n; i++){
		p[i] = p[i - 1] ^ a[i];
	}
    vector pre(30, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 30; j++){
			pre[j][i] += pre[j][i - 1];
			pre[j][i] += (a[i] >> j & 1);
		}
	}
	auto get = [&](int pos, int l, int r) -> int{
		return pre[pos][r] - pre[pos][l - 1];
	};
    for(int i = 1; i <= q; i++){
    	int x; cin >> x;
    	int last = n + 1;
    	for(int j = n; j >= 1; j--){
    		if(x >= a[j]){
    			x ^= a[j];
    			last = j;
    		}else{
    			break; 
    		}
    		// dbg(j, x);
    	}
    	cout << n + 1 - last << ' ';
    }
    cout << '\n';
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