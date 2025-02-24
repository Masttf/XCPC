#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \ 
}while(0)
void err(){
	cout << endl << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
constexpr int Max = 1e18;
void solve(){
	int n; cin >> n;
	vector<string>a(5);
	for(int i = 1; i <= 3; i++)cin >> a[i];
	int ans = n;
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			if(i == j)continue;
			int d = 0;
			for(int k = 0;k < n; k++){
				if(a[i][k] == a[j][k])d++;
			}
			ans = min(ans, (n + d) / 2);
		}
	}
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--)solve();
	return 0;
} 