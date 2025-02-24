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
constexpr int Max = 1e18;
void solve(){
	int n; cin >> n;
	vector<array<int, 3>>a(n + 1); 
	for(int i = 1; i <= n; i++){
		char f;
		cin >> a[i][0] >> a[i][1] >> f;
		if(f == 'E')a[i][2] = 1;
		else if(f == 'W')a[i][2] = 2;
		else if(f == 'N')a[i][2] = 3;
		else a[i][2] = 4;
	}
	vector<vector<int>>res_x(5, vector<int>());
	vector<vector<int>>res_y(5, vector<int>());
	for(int i = 1; i <= n; i++){
		res_x[a[i][2]].push_back(a[i][0]);
		if(a[i][2] == 3){
			res_y[1].push_back(a[i][1]);
		}else if(a[i][2] == 4){
			res_y[2].push_back(a[i][1]);
		}else if(a[i][2] == 1){
			res_y[3].push_back(a[i][1]);
		}else res_y[4].push_back(a[i][1]);
		
	}
	for(int i = 1; i <= 4; i++){
		sort(res_x[i].begin(), res_x[i].end());
		sort(res_y[i].begin(), res_y[i].end());
	}
	auto check1 = [&](int x) -> bool{
		if(!res_x[1].empty()){
			int d = res_x[1].back() - res_x[1][0];
			if(d > x)return false;
		}
		if(!res_x[2].empty()){
			int d = res_x[2].back() - res_x[2][0];
			if(d > x)return false;
		}
		int sz1 = res_x[3].size();
		int sz2 = res_x[4].size();
		vector<int>temp(sz1 + sz2);
		for(int k = 0, i = 0, j = 0; k < sz1 + sz2; k++){
			if(i == sz1 || (j != sz2 && res_x[3][i] > res_x[4][j])){
				temp[k] = res_x[4][j];
				j++;
			}else{
				temp[k] = res_x[3][i];
				i++;
			}
		}
		if(temp.size() >= 2){
			int d = temp.back() - temp[0];
			if(d > x)return false;
		}
		int l = 0;
		int r = Max;
		if(!temp.empty()){
			for(auto xx : res_x[1]){
				int x1 = temp[0];
				if(x1 <= xx){
					r = min(r, x1 + x - xx);
				}else{
					l = max(l, x1 - x - xx);
					r = min(r, x1 + x - xx);
				}
				//dbg(xx, x1, l, r);
				x1 = temp.back();
				if(x1 <= xx){
					r = min(r, xx - x1 - x);
				}else{
					l = max(l, x1 - x - xx);
					r = min(r, x1 + x - xx);
				}
				//dbg(xx, x1, l, r);
			}

			for(auto xx : res_x[2]){
				int x1 = temp[0];
				if(x1 <= xx){
					l = max(l, xx - x1 - x);
					r = min(r, xx - x1 + x);
				}else{
					r = min(r, xx - x1 + x);
				}
				x1 = temp.back();
				if(x1 <= xx){
					l = max(l, xx - x1 - x);
					r = min(r, xx - x1 + x);
				}else{
					r = min(r, xx - x1 + x);
				}
			}
		}
		//dbg(x, l, r);
		if(!res_x[2].empty()){
			for(auto xx : res_x[1]){
				int x1 = res_x[2][0];
				if(x1 <= xx){
					int d = x - (xx - x1);
					r = min(r, d / 2);
				}else{
					int d = (x1 - xx) - x;
					l = max(l, (d + 1) / 2);
					r = min(r, (x + x1 - xx) / 2);
				}
				x1 = res_x[2].back();
				if(x1 <= xx){
					int d = x - (xx - x1);
					r = min(r, d / 2);
				}else{
					int d = (x1 - xx) - x;
					l = max(l, (d + 1) / 2);
					r = min(r, (x + x1 - xx) / 2);
				}
			}
		}
		//dbg(x, l, r);
		return l <= r;
	};
	int l = 0, r = 2e9;
	int ans1 = r;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check1(mid)){
			ans1 = mid;
			r = mid - 1;
		}else l = mid + 1;
	}

	for(int i = 1; i <= 4; i++)swap(res_x[i], res_y[i]);
	l = 0, r = 2e9;
	int ans2 = r;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check1(mid)){
			ans2 = mid;
			r = mid - 1;
		}else l = mid + 1;
	}
	//dbg(ans1, ans2);
	int ans = 2 * ans1 + 2 * ans2;
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}