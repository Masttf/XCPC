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
	int n, l, d; cin >> n >> l >> d;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++)cin >> a[i];
	sort(a.begin() + 2, a.end());
	auto check = [&](vector<int>&res) -> bool{
		if(res.size() != 4)return false;
		sort(res.begin(), res.end());
		if(res.back() - res[0] <= d)return false;
		int cnt = 0;
		for(auto x : res){
			if(x >= l)cnt++;
		}
		return cnt <= 1;
	};
	if(a[1] >= l){
		vector<int>res;
		res.push_back(a[1]);
		for(int i = 2; i <= 4; i++){
			res.push_back(a[i]);
		}
		if(check(res)){
			cout << "Yes \n";
			return ;
		}else {
			cout << "No\n";
		}
	}else{
		vector<int>res;
		res.push_back(a[1]);
		for(int i = 2; i <= n; i++){
			if(res.size() == 4)break;
			if(a[i] <= a[1]){
				res.push_back(a[i]);
			}
		}
		if(check(res)){
			cout << "Yes\n";
			return ;
		}
		res.clear();
		res.push_back(a[1]);
		for(int i = n; i >= 2; i--){
			if(res.size() == 4)break;
			res.push_back(a[i]);
		}
		if(check(res)){
			cout << "Yes\n";
			return ;
		}
		res.clear();
		res.push_back(a[1]);
		res.push_back(a[2]);
		res.push_back(a[n]);
		res.push_back(a[3]);
		if(check(res)){
			cout << "Yes\n";
			return ;
		}
		cout << "No\n";
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