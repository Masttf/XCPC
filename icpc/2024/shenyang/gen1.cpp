#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}

struct node {
	string s;
	int num;
	friend bool operator<(node a, node b) {
		return a.num < b.num;
	}
};
void solve(){
	mt19937 rng(random_device{}());
	uniform_int_distribution<int> dist(1,10);
	int N = 15;
	int a[20] = {};
	cout << 3 << '\n';
	for (int i = 2;i <= 15;i++) {
		a[i] = dist(rng);
		cout << a[i] << ' ';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t--)solve();
	return 0;
}