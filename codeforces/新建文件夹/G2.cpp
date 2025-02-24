#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int l = 2, r = 999;
	int ans = -1;
	while(l <= r){
		int len = (r - l + 1);
		int mid = l + len / 3;
		int mid2 = l + len * 2 / 3;
		cout << "? " << mid << ' ' << mid2 <<endl;
		int x; cin >> x;
		if(mid * mid2 == x){
			l = mid2 + 1;
		}else if((mid + 1) * (mid2 + 1) == x){
			r = mid - 1;
			ans = mid;
		}else{
			ans = mid2;
			r = mid2 - 1;
			l = mid + 1;
		}
	}
	cout << "! " << ans << endl;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}