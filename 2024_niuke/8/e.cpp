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
constexpr int maxn = 1e6 + 5;
int f[maxn];
void init(){
	auto get = [&](int x) -> int{
		int sum = 0;
		while(x){
			sum += x % 10;
			x /= 10;
		}
		return sum;
	};
	for(int i = 1; i < maxn; i++){
		f[i] = get(i);
	}
}
void solve(){
	int n; cin >> n;
	int ans = 0;
	int d = sqrt(n);
	while(d * d < n) d++;
	while(d * d > n) d--;
	for(int i = 1; i <= d; i++){
		int t = (n - 109 + i) / i * i;
		for(int j = t; j < n; j += i){
			if(j <= 0)continue;
			int dis = n - j;
			if(i > dis && f[i] == dis){
				ans++;
			}
			int tt = j / i;
			if(tt != i && tt > dis){
				if(f[tt / 1000000] + f[tt % 1000000] == dis){
					ans++;
				}
			}
		}
	}
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}