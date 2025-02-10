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
	//dbg("yes");
	vector pre(2,vector<int>(n + 1));
	for(int i = 0; i < n; i++){
		pre[0][i + 1] = pre[0][i];
		pre[1][i + 1] = pre[1][i];
		pre[s[i] - '0'][i + 1]++;
	}
	//dbg("yes");
	int t1,t0;
	auto check = [&](int l, int r) -> bool{
		int b1 = l / n;
		int b2 = r / n;
		int cnt1 = 0;
		int cnt0 = 0;
		if(b1 == b2){
			cnt1 = pre[1][r + 1] - pre[1][l];
			cnt0 = pre[0][r + 1] - pre[0][l];
		}else if(b1 == b2 + 1){
			cnt1 = pre[1][n] - pre[1][l] + pre[1][r + 1] - pre[1][0];
			cnt0 = pre[0][n] - pre[0][l] + pre[0][r + 1] - pre[0][0];
		}else{
			int d = b2 - 1 - b1;
			cnt1 = pre[1][n] - pre[1][l] + pre[1][r + 1] - pre[1][0] + d * (pre[1][n] - pre[1][0]);
			cnt0 = pre[0][n] - pre[0][l] + pre[0][r + 1] - pre[0][0] + d * (pre[0][n] - pre[0][0]);
		}
		t1 = cnt1;
		t0 = cnt0;
		return cnt1 >= a || cnt0 >= a;
	};
	vector<int>nex(n);
	vector<int>val(n);
	for(int i = 0; i < n; i++){
		int l = i, r = n * a;
		int ans = -1;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(check(i, mid, pre1, a)){
				ans = mid;
				r = mid - 1;
			}else l = mid + 1;
		}
		nex[i] = (ans + 1) % n;
		if(t1 >= a)val[i] = 1;
	}
	for(int i = 0; i < n; i++){
		dbg(i, nex[i]);
	}
	vector<int> vis(n);
	vector<int> pos(n);
	int tot = 0;
	vector<vector<int>>res(n);
	vector<vector<int>>temp(n);
	for(int i = 0; i < n; i++){
		if(vis[i])continue;
		tot++;
		int now = i;
		while(!vis[now]){
			vis[now] = tot;
			pos[now] = res[tot].size();
			temp[tot].push_back(now);
			res[tot].push_back(val[now]);
			now = nex[now];
		}
	}
	vector<int> ans(n);
	auto get = [&](int num) -> void{
		int sz = res[num].size();
		vector p(2,vector<int>(sz + 1));
		for(int i = 0; i < sz; i++){
			p[0][i + 1] = p[0][i];
			p[1][i + 1] = p[1][i];
			p[res[num][i]][i + 1]++; 
		}
		for(auto x : temp[num]){
			int i = pos[x];
			int l = i , r = sz * b;
			int res = -1;
			while(l <= r){
				int mid = (l + r) >> 1;
				if(check(i, mid, p, b)){
					res = mid;
					r = mid -1;
				}else l = mid + 1;
			}
			if(t1 >= b)ans[x] = 1;
		}
	};
	for(int i = 1; i <= tot; i++){
		get(i);
	}
	for(int i =0 ; i < n; i++){
		cout << ans[i];
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