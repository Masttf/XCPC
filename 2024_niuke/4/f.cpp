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


int need;
using i128 = __int128;

std::ostream& operator<< (std::ostream& out, const i128 X) {
	std::vector<int> v;
	i128 x = X;
	while(x) {
		v.push_back(x % 10);
		x /= 10;
	}
	std::reverse(v.begin(), v.end());
	for(int i:v) out << i;
	return out;
}

bool check(int x) {
	if (x % 2 == 0) {
		int half = (x - 1) / 2;
		int val = x / 2;
		int num = x - 1;
		i128 mi = ((i128)1 + (i128)half) * (i128)half + (i128)val;
		i128 mx = ((i128)1 + (i128)num) * (i128)num / (i128)2;
		i128 res = mx - mi;
		i128 ori = need;
		//cout << res << ' ' << ori << '\n'; 
		if (res >= ori) return 1;
		else return 0;
	}
	else {
		int half = x / 2;
		int val = x / 2;
		int num = x - 1;
		i128 mi = ((i128)1 + (i128)half) * (i128)half;
		i128 mx = ((i128)1 + (i128)num) * (i128)num / (i128)2;
		i128 res = mx - mi;
		i128 ori = need;
		if (res >= ori) return 1;
		else return 0;
	}
}

void solve(){
	cin >> need;
	if (need == 1) {
		cout << 3 << '\n';
		return ;
	}
	//int mx = (1 + (x - 1)) * (x - 1) / 2;
	//cout << mx << '\n';
	int l = 4,r = 1e10;
	int ans = 1e10;
	// while (l <= r) {
	// 	int mid = (l + r) >> 1;
	// 	if (check(mid)) {
	// 		r = mid - 1;
	// 		ans = min(ans,mid);
	// 	}
	// 	else l = mid + 1;
	// }
	check(r);
	cout << ans << '\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}