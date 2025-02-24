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
	vector<node> v(8);
	for(int i = 0; i < 8; ++i) {
		cin >> v[i].s >> v[i].num;
	}
	node a = *max_element(v.begin(), v.begin() + 4);
	node b = *max_element(v.begin() + 4, v.begin() + 8);
	if(a < b) swap(a, b);
	cout << a.s << " beats " << b.s << '\n'; 

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