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
	int a, b, c; cin >> a >> b >> c;
	if(a + b == c){
		cout << -1 << '\n';
		return ;
	}
	int ans = 0;
	auto check = [&](int k) -> bool{
		vector<int>t1, t2;
		int aa = a;
		while(aa){
			t1.push_back(aa % k);
			aa /= k;
		}
		int bb = b;
		while(bb){
			t2.push_back(bb % k);
			bb /= k;
		}
		int sz = max(t1.size(), t2.size());
		int p = 1;
		int res = 0;
		for(int i = 0; i < sz; i++){
			int d = 0;
			if(i < t1.size())d += t1[i];
			if(i < t2.size())d += t2[i];
			d %= k;
			res += p * d;
			p *= k;
		}
		return res == c;
	};
	int d = a + b - c;
	if(check(d))ans++;
	for(int i = 2; i * i <= d; i++){
		if(d % i == 0){
			if(check(i))ans++;
			if(i != d / i){
				if(check(d / i))ans++;
			}
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