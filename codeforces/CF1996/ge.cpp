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
	int n = 2e5;
	int m = 2e5;
	cout << n << ' ' << m << '\n';
	mt19937_64 gen(time(0));
	for(int i = 1; i <= m; i++){
		int a = gen()%n + 1;
		int b = gen()%n + 1;
		if(b <= a){
			b = gen()%n + 1;
		}
		cout << a << ' ' << b << '\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	cout << t << '\n';
	while(t--)solve();
	return 0;
}