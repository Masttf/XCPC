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
constexpr int inf = 1e18;
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int m; cin >> m;
	for(int i = 1; i <= m; i++){
		string t; cin >> t;
		if(t[0] == 'c'){
    		int l, r; cin >> l >> r;
    		vector<int> temp(1, inf);
    		int ok = 1;
    		for(int j = l; j <= r; j++){
    			if(a[j] == temp.back())continue;
    			temp.push_back(a[j]);
    		}
    		temp.push_back(inf);
    		const int sz = temp.size();
    		int last = -inf;
    		for(int j = 1; j < sz - 1; j++){
    			if(temp[j] < temp[j - 1] && temp[j] < temp[j + 1]){
    				if(temp[j] <= last)ok = 0;
    				else last = temp[j];
    			}
    		}
    		// for(int j = l; j <= r; j++){
    		// 	cout << a[j] << ' ';
    		// }
    		// cout << endl;
    		// dbg(last);
    		if(ok)cout << "YES\n";
    		else cout << "NO\n";
    	}else{
    		int l, r, d; cin >> l >> r >> d;
    		for(int j = l; j <= r; j++){
    			a[j] += d;
    		}
    	}
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