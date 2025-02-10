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
void solve(){
	int n; cin >> n;
	if(n == 0){
		cout << "NO\n";
		return ;
	}
	vector<int>ans(32);
	for(int i = 0; i < 32; i++){
		if(n >> i & 1){
			ans[i] = 1;
		}
	}
	int ok = 1;
	for(int i = 0; i <= 30; i++){
		if(ans[i] == 0 && ans[i + 1] == 0)ok = 0;
	}
	auto pf = [&]() -> void{
		cout << "YES\n";
		int f = 0;
		for(int i = 0; i < 32; i++){
			f++;
			cout << ans[i] << ' ';
			if(f == 8){
				cout << '\n';
				f = 0;
			}
		}
		return ;
	};
	if(ok){
		pf();
		return ;
	}
	auto check = [&](int x) -> void{
		ans[31] = 1;
		for(int i = 0; i < 31; i++){
			ans[i] = -1;
		}
		for(int i = 1; i < 32; i++){
			if(x >> i & 1){
				ans[i - 1] = 1;
			}
		}
	};
	if(n % 2 == 1){
		check(n);
		pf();
		return ;
	}else{
		check(n + 1);
		if(ans[0] == 1){
			ans[0] = 0;
			pf();
			return ;
		}
		check(n - 1);
		if(ans[0] == -1){
			ans[0] = 0;
			pf();
			return ;
		}
		cout << "NO\n";
		return ;
	}
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