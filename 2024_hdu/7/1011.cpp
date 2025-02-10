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
	int x, y; cin >> x >> y;
	__int128 xx = x;
	__int128 yy = y;
	__int128 ans = xx * yy / __gcd(x, y);
	auto pf = [&](__int128 t) -> void{
		vector<int>res;
		while(t){
			res.push_back(t % 10);
			t /= 10;
		}
		reverse(res.begin(), res.end());
		for(auto x : res)cout <<x ;
	};
	if((ans == x or ans == y) and x >= y) {
		pf(yy);
		cout << ' ';
		pf(ans / y);
		cout << '\n';
	} else{
		if(ans % 2 == 1) ans *= 2;
		pf(yy);
		cout << ' ';
		pf(ans / y); cout << '\n';
	}
	
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}