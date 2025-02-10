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
	vector<int> a(n);
	std::unordered_set<int> s;
	for(int i = 0; i < n; ++i) {
		std::cin >> a[i];
		s.insert(a[i]);
	}
	int k = 0;
	A:;
	for(int i = 0; i < a.size(); ++i) {
		for(int j = i + 1; j < a.size(); ++j) {
			int num = std::gcd(a[i], a[j]);
			if(s.count(num)) continue;
			++k, s.insert(num), a.push_back(num);
			goto A;
		}
	}
	std::cout << k << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}