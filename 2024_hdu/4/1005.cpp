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
	int n, m, hp, dmg;
	cin >> n >> m >> hp >> dmg;
	vector ans(n + 2, vector<char>(m + 2));
	for(int i = 0; i <= n + 1; i++){
		for(int j = 0;j <= m + 1; j++){
			ans[i][j] = ' ';
		}
	}
	ans[0][0] = ans[0][m + 1] = ans[n + 1][0] = ans[n + 1][m + 1] = '+';
	for(int i = 1; i <= m; i++){
		ans[0][i] = ans[n + 1][i] ='-';
	}
	for(int i = 1; i <= n; i++){
		ans[i][0] = ans[i][m + 1] = '|';
	}
	int k = (hp + m - 1) / m - 1;
	int now = k % 5;
	int last = (hp - 1) % m + 1;
	int temp = last;
	while(ans[1][last] == ' ' && hp){
		ans[1][last] = 'A' + now;
		last--;
		if(!last){
			last = m;
			now = (now + 4) % 5;
		}
		hp--;
	}
	while(ans[1][temp] != '.' && dmg){
		ans[1][temp] = '.';
		temp--;
		if(!temp){
			temp = m;
		}
		dmg--;
	}
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= m; j++){
			ans[i][j] = ans[1][j];
		}
	}
	for(int i = 0; i <= n + 1; i++){
		for(int j = 0; j <= m + 1; j++){
			cout << ans[i][j];
		}
		cout << '\n';
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