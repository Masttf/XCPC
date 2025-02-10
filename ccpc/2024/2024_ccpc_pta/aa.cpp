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
	mt19937_64 rd(time(0));
	int s, x; cin >> s >> x;
	if(__gcd(s, x) == 1){
		cout << 1 << '\n';
		cout << s << '\n';
		return ;
	}
	int lim = 1e9;
	lim--;
	for(int i = 1; i <= 1e6; i++){
		int xx = rd() % lim + 1;
		int yy = s - xx;
		if(__gcd(xx, x) == 1 && __gcd(yy, x) == 1){
			cout << 2 << '\n';
			cout << xx << ' ' << yy << '\n';
			return ;
		}
	}
	for(int i = 1; i <= 1e6; i++){
		int xx = 1;
		int yy = rd() % lim + 1;
		int zz = s - yy - xx;
		if(__gcd(yy, x) == 1 && __gcd(zz, x) == 1 && __gcd(xx, x)){
			cout << 3 << '\n';
			cout << xx << ' ' << yy << ' ' << zz << '\n';
			return ;
		}
		
		
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}