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

	map<array<int, 3>, int>m;
	auto dfs = [&](auto self, int a, int b, int c) -> int{
		//dbg(a, b, c);
		if(m.count({a, b, c}))return m[{a,b, c}];
		if(a == 1 && b == 1 && c == 1)return 0;
		int res[3];
		res[0] = a;
		res[1] = b;
		res[2] = c; 
		int tot = 0;
		int cnt = 0;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(i == j)continue;
				int o = 0 + 1 + 2 - i - j;
				for(int k = 1; k < res[i]; k++){
					tot++;
					cnt += self(self, res[o], res[i] - k, k);
				}
				for(int k = 1; k < res[j]; k++){
					tot++;
					cnt += self(self, res[o], res[j] - k, k);
				}
			}
		}
		if(tot != cnt)return m[{res[0], res[1], res[2]}] = 1;
		else return m[{res[0], res[1], res[2]}] = 0;
	};
	for(int i = 2; i <= 20; i += 2){
		for(int j = i; j <= 20; j += 2){
			for(int k = j; k <= 70; k += 2){
				int ans = dfs(dfs, i, j, k);
				if(ans == 0)dbg(i,j,k, ans);
			}
		}
	}
	//cout << dfs(dfs, 2, 2, 8);
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}