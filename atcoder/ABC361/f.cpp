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
int qmi(int a, int b, int up){
	int res = 1;
	while(b){
		if(a > up)return -1;
		if(b & 1){
			if(up / res < a)return -1;
			res = res * a;
		}
		b >>= 1;
		if(b && up / a < a)return -1;
		a = a * a;
	}
	return res;
}
bool isW(int x){
	int d = sqrt(x);
	while(d * d < x)d++;
	while(d * d > x)d--;
	return d * d == x;
	// int l = 1, r = 1e9;
	// int res = -1;
	// while(l <= r){
	// 	int mid = (l + r) >> 1;
	// 	if(mid * mid >= x){
	// 		res = mid;
	// 		r = mid - 1;
	// 	}else l = mid + 1;
	// }
	// return res * res == x;
}
void solve(){
    int n; cin >> n;
    int ans = sqrt(n);
    while(ans * ans < n)ans++;
    while(ans * ans > n)ans--;
    // int L = 1, R = 1e9;
	// while(L <= R){
	// 	int mid = (L + R) >> 1;
	// 	if(mid * mid <= n){
	// 		ans = mid;
	// 		L = mid + 1;
	// 	}else R = mid - 1;
	// }
    map<int, int>mp;
    for(int i = 3; i <= 60; i++){
    	for(int j = 1; ; j++){
    		int d = qmi(j, i, n);
    		if(d != -1){
    			if(isW(d) || mp.count(d))continue;
    			// dbg(d);
    			mp[d] = 1;
    			ans++;
    		}else break;
    	}
    	// dbg(mp.size());
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