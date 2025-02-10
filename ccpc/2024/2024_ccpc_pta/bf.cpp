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
	int n; cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector<int> b = a;
	auto check = [&]() -> bool{
		// for(int i = 1; i <= n; i++){
		// 	cout << a[i] << ' ';
		// }
		// cout << endl;
		int cnt = 0;
		int ok = 0;
		int s = 0;
		for(int i = 1; i <= n; i++)s ^= a[i];
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= a[i]; j++){
				cnt++;
				int temp = s ^ a[i];
				temp ^= (a[i] - j);
				if(temp == 0)ok++;
			}
		}
		//dbg(cnt, ok);
		if(ok == 1)return true;
		else return false;
	};
	vector<pair<int, int>>res;
	auto dfs = [&](auto self, int t) -> void{
		int num = 0;
		for(int i = 1; i <= n; i++){
			num += a[i];
		}
		if(num == 0){
			vector<int> temp = b;
			num = 0;
			for(auto [i, val] : res){
				if(!num)dbg("after you");
				else dbg("after p");
				temp[i] -= val;
				for(int k = 1; k <= n; k++){
					cout << temp[k] << ' ';
				}
				cout << endl;
				num++;
			}
			return ;
		}
		if(t){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= a[i]; j++){
					a[i] -= j;
					if(check()){
						res.push_back({i, j});
						self(self, t ^ 1);
						res.pop_back();
					}
					a[i] += j;
				}
			}
		}else{
			int s = 0;
			for(int i = 1; i <= n; i++)s ^= a[i];
			//dbg(s);
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= a[i]; j++){
					int temp = s ^ a[i];
					temp ^= (a[i] - j);
					//dbg(i, j, temp);
					if(temp == 0){
						a[i] -= j;
						res.push_back({i, j});

						self(self, t ^ 1);
						a[i] += j;
						res.pop_back();
						break;
					}
				}
			}
		}
	};
	dfs(dfs, 1);
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}