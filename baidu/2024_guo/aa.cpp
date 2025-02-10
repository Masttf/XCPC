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
	vector<int>b(n + 1);
	for(int i = 1; i <= n; i++)cin >>b[i];
	vector a(n + 1, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)cin >> a[i][j];
	}
	auto get3 = [&](int i, int j, int k) -> int{
		return max({b[i], b[j], b[k], a[i][j], a[i][k], a[j][k], a[i][j] * a[j][k] * a[i][k]});
	};
	auto get2 = [&](int i, int j) -> int{
		return max({b[i], b[j], a[i][j]});
	};
	vector v2(n + 1, vector<int>(n + 1));
	vector v3(n + 1, vector(n + 1, vector<int>(n + 1)));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			v2[i][j] = get2(i, j);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				v3[i][j][k] = get3(i, j, k);
			}
		}
	}
	vector<int> dp((1ll << n) + 1, -Max);
	dp[0] = 0;
	for(int i = 1; i < 1ll << n; i++){
		int cnt = 0;
		vector<int>temp;
		for(int j = 0; j < n; j++){
			if(i >> j & 1){
				cnt++;
				temp.push_back(j);
			}
		}

		cnt %= 3;
		int sz = temp.size();
		if(cnt == 0){
			for(int j = 0; j < sz; j++){
				for(int k = j + 1; k < sz; k++){
					for(int p = k + 1; p < sz; p++){
						dp[i] = max(dp[i], dp[i ^ ((1ll <<temp[j]) | (1ll << temp[k]) | (1ll << temp[p]))] + v3[temp[j] + 1][temp[k] + 1][temp[p] + 1]);
					}
				}
			}
		}else if(cnt == 1){
			for(int j = 0; j < sz; j++){
				dp[i] = max(dp[i], dp[i ^ (1ll << temp[j])] + b[temp[j] + 1]);
			}
		}else{
			for(int j = 0; j < sz; j++){
				for(int k = j + 1; k < sz; k++){
					dp[i] = max(dp[i], dp[i ^ ((1ll <<temp[j]) | (1ll << temp[k]) )] + v2[temp[j] + 1][temp[k] + 1]);
				}
			}
		}
	}
	cout << dp[(1ll << n) - 1] << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1; //cin >> t;
	while(t--)solve();
	return 0;
}