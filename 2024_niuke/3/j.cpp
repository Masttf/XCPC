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
	int n, a, b; cin >> n >> a >> b;
	string s;cin >> s;
	vector pre(2,vector<int>(n + 1));
	for(int i = 0; i < n; i++){
		pre[0][i + 1] = pre[0][i];
		pre[1][i + 1] = pre[1][i];
		pre[s[i] - '0'][i + 1]++;
	}
	int t1 =0, t0 = 0;
	auto check = [&](int l, int r) -> bool{
		int b1 = l / n;
		int b2 = r / n;
		r %= n;
		int cnt1 = 0;
		int cnt0 = 0;
		if(b1 == b2){
			cnt1 = pre[1][r + 1] - pre[1][l];
			cnt0 = pre[0][r + 1] - pre[0][l];
		}else{
			int d = b2 - 1 - b1;
			cnt1 = pre[1][n] - pre[1][l] + pre[1][r + 1] - pre[1][0] + d * (pre[1][n] - pre[1][0]);
			cnt0 = pre[0][n] - pre[0][l] + pre[0][r + 1] - pre[0][0] + d * (pre[0][n] - pre[0][0]);
		}
		t1 = cnt1;
		t0 = cnt0;
		return cnt1 >= a || cnt0 >= a;
	};
	vector nex(25, vector<array<int, 3>>(n));
	for(int i = 0; i < n; i++){
		int l = i + a - 1, r = 2 * a + i - 2;
		int ans = -1;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(check(i, mid)){
				ans = mid;
				r = mid - 1;
			}else l = mid + 1;
		}
		check(i, ans);
		nex[0][i][2] = (ans + 1) % n;
		if(t1 == a)nex[0][i][1]++;
		else nex[0][i][0]++;
	}
	
	for(int s = 1; s <= 20; s++){
		for(int i = 0; i < n; i++){
			auto [x1, y1, z1] = nex[s - 1][i];
			auto [x2, y2, z2] = nex[s - 1][z1];
			nex[s][i] = {x1 + x2, y1 + y2, z2};
		}
	}
	for(int i = 0; i < n; i++){
		int cnt1 = 0;
		int cnt0 = 0;
		int now = i;
		for(int j = 20; j >= 0; j--){
			auto [x, y, z] = nex[j][now];
			if(cnt0 + x < b && cnt1 + y < b){
				cnt0 += x;
				cnt1 += y;
				now = z;
			}
		}
		cnt0 += nex[0][now][0];
		cnt1 += nex[0][now][1];
		if(cnt1 == b)cout << 1;
		else cout << 0;
	}
	cout << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}