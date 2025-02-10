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
void solve(int n){
	std::mt19937 rnd(time(0));
	auto add = [&](int &pos, int j) ->void {
		if(pos + j <= n) pos += j;
		else {
			j -= n - pos;
			pos = n - j;
		}
	};
	int T = 100000000;
	double ans = 0;
	for(int i = 1; i <= T; ++i) {
		int pos = 0;
		while(1) {
			if(pos == n) break;
			++ans;
			int j = rnd() % n + 1;
			// dbg(j);
			add(pos, j);
			if(j == n) {
				j = rnd() % (n - 1) + 1;
				add(pos, j);
			} 
		}
		
	}
	std::cout << ans / T;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve(6);
	return 0;
}