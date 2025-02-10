#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ... args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}


void solve(){
	int n, m; cin >> n >> m;
	vector<string> a(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] = ' ' + a[i];
	}
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	vector vis(n + 1, vector<int>(m + 1));
	auto check_8 = [&](int i, int j) -> void{
		vector<string> res = {"#####", "#.#.#", "#####"};
		vector<string> res2 = {"###", "#.#", "###", "#.#", "###"};
		if(i + 2 <= n && j + 4 <= m){
			vector<string> t1;
			int ok = 1;
			for(int x = i; x <= i + 2; x++){
				string temp = "";
				for(int y = j; y <= j + 4; y++){
					if(vis[x][y])ok = 0;
					temp += a[x][y];
				}
				t1.push_back(temp);
			}
			if(t1 == res && ok){
				cnt3++;
				for(int x = i; x <= i + 2; x++){
					for(int y = j; y <= j + 4; y++){
						vis[x][y] = 1;
					}
				}
			}
		}
		if(i + 4 <= n && j + 2 <= m){
			vector<string> t1;
			int ok = 1;
			for(int x = i; x <= i + 4; x++){
				string temp = "";
				for(int y = j; y <= j + 2; y++){
					if(vis[x][y])ok = 0;
					temp += a[x][y];
				}
				t1.push_back(temp);
			}
			if(t1 == res2 && ok){
				cnt3++;
				for(int x = i; x <= i + 4; x++){
					for(int y = j; y <= j + 2; y++){
						vis[x][y] = 1;
					}
				}
			}
		}
	};
	auto check_0 = [&](int i, int j) -> void{
		vector<string>res = {"###", "#.#", "###"};
		if(i + 2 <= n && j + 2 <= m){
			vector<string> t1;
			int ok = 1;
			for(int x = i; x <= i + 2; x++){
				string temp = "";
				for(int y = j; y <= j + 2; y++){
					if(vis[x][y])ok = 0;
					temp += a[x][y];
				}
				t1.push_back(temp);
			}
			if(t1 == res && ok){
				cnt2++;
				for(int x = i; x <= i + 2; x++){
					for(int y = j; y <= j + 2; y++){
						vis[x][y] = 1;
					}
				}
			}
		}
	};
	auto check_1 = [&](int i, int j) -> void{
		string res = "###";
		if(i + 2 <= n){
			int ok = 1;
			string temp = "";
			for(int x = i; x <= i + 2; x++){
				if(vis[x][j])ok = 0;
				temp += a[x][j];
			}
			if(temp == res && ok){
				cnt1++;
				for(int x = i; x <= i + 2; x++){
					vis[x][j] = 1;
				}
			}
		}
		if(j + 2 <= m){
			int ok = 1;
			string temp = "";
			for(int y= j; y <= j + 2; y++){
				if(vis[i][y])ok = 0;
				temp += a[i][y];
			}
			if(temp == res && ok){
				cnt1++;
				for(int y= j; y <= j + 2; y++){
					vis[i][j] = 1;
				}
			}
		}
	};
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == '#' && !vis[i][j]){
				check_8(i, j);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == '#' && !vis[i][j]){
				check_0(i, j);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == '#' && !vis[i][j]){
				check_1(i, j);
			}
		}
	}
	cout <<cnt1 << ' ' << cnt2 << ' ' << cnt3 << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1; //cin >> t;
	while(t--)solve();
	return 0;
}