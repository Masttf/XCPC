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
	int p,x,k;cin >> p >> x >> k;
	vector<int>num;
	for (int i = 1;i * i <= k;i++) {
		if (k % i == 0) {
			int val = k / i;
			num.push_back(i);
			if (val * val != x) num.push_back(val);
		}
	}
	
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}