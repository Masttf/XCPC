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
    int n = 100;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	a[i] = i;
    }
    vector<int> b(n + 1);
    for(int i = 1; i <= n; i++){
    	b[i] = a[i] << 7;
    }
    cout << "? ";
    for(int i = 1; i <= n; i++){
    	cout << a[i] << " \n"[i == n];
    }
    cout << endl;
    int x1; cin >> x1;
    cout << "? ";
    for(int i = 1; i <= n; i++){
    	cout << b[i] << " \n"[i == n];
    }
    cout << endl;
    int x2; cin >> x2;
    int d = x1 ^ x2;
    // set<int> s;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		if((a[i] ^ b[j]) == d){
    			// dbg(a[i], b[j]);
    			int ans = a[i] ^ x1;
    			cout << "! " << ans << endl;
    			return ;
    		}
    		// s.insert(a[i] ^ b[j]);
    	}
    }
    // cout << s.size() << endl;
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}