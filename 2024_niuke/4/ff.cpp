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
constexpr int Max = 1e18;
void solve(){
	int x; cin >> x;
	int d = sqrt(x);
	while(d * d < x)d++;
	while(d * d > x)d--;
	if(d * d == x){
		cout << 2 * d + 1 << '\n';
		return ;
	}
	int res = x - d * d;
	assert(res  <=  2 * d);
	if(res <= d){
		if(res % 2 == d % 2){
			cout << 2 * d + 2 << '\n';
		}else{
			cout << 2 * d + 3 << '\n';
		}
	}else{
		cout << 2 * d + 3 << '\n';
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