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
mt19937_64 rd(time(0));
void solve(){
    int n; cin >> n;
    int q; cin >> q;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    vector<int> h(n + 1);
	for(int i = 1; i <= n; i++){
		h[i] = rd();
	}
	vector<unsigned int>prea(n + 1), preb(n + 1);
	for(int i = 1; i <= n; i++){
		prea[i] = prea[i - 1] + h[a[i]];
		preb[i] = preb[i - 1] + h[b[i]];
	}
	for(int i = 1; i <= q; i++){
		int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
		if(r2 - l2 == r1 - l1 && prea[r1] - prea[l1 - 1] == preb[r2] - preb[l2 - 1]){
			cout << "Yes\n";
		}else cout << "No\n";
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