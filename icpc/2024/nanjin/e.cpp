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
void solve(){
	int n, k;
	cin >> n >> k;
	k = min(k, 10LL);
	string s;
	cin >> s;
	int ans = 0;

	deque<char> dq;
	for(auto i:s) dq.push_back(i);

	k++;

	while(k--) {
		int mx = 0;
		for(int i = 6; i < n; ++i) {
			if(dq[i-6]=='n' && dq[i-5]=='a' && dq[i-4]=='n'
				&& dq[i-3]=='j' && dq[i-2]=='i' && dq[i-1]=='n' && dq[i]=='g') ++mx;
		}
		ans = max(ans, mx);
		dq.push_back(dq.front());
		dq.pop_front();
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