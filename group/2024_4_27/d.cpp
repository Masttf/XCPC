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
	int n;
	std::cin >> n;
	std::string s;
	for(int i = 1; i <= n; ++i) {
		s += std::to_string(i);
	}
	int ans = 0;
	for(int i = 1; i < s.size(); ++i) {
		if(s[i - 1] == '4' and s[i] == '2') ++ans;
	}
	std::cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}