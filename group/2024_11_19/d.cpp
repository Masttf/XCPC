#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout << endl << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
constexpr int rp = 2333333;
int cnt[25][25];
int res[25][25];
void solve(){
    int n; cin >> n;
    vector<int> limit(10);
    for(int i = 1; i <= 6; i++) cin >> limit[i];
	int x = 0, y = 0, z = 0;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		x = (y * limit[1] + limit[2]) % rp;
		y = (z * limit[3] + limit[4]) % rp;
		z = (x * limit[5] + limit[6]) % rp;
		int BX = x % 20 + 1;
		int X = x % 20 * 100 + y % 10 * 10 + z % 10;
		x = (y * limit[1] + limit[2]) % rp;
		y = (z * limit[3] + limit[4]) % rp;
		z = (x * limit[5] + limit[6]) % rp;
		int BY = x % 20 + 1;
		int Y = x % 20 * 100 + y % 10 * 10 + z % 10;
		cnt[BX][BY]++;
		res[BX][BY] += X + Y;
	}
	for(int i = 1; i <= 20; i++){
		for(int j = 1; j <= 20; j++){
			cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
			res[i][j] += res[i - 1][j] + res[i][j - 1] - res[i - 1][j - 1];
		}
	}
	auto get = [&](int x, int y) -> pair<int, int>{
		int c = cnt[20][20] - cnt[x][20] - cnt[20][y] + cnt[x][y];
		int cc = res[20][20] - res[x][20] - res[20][y] + res[x][y];
		return {cc, c};
	};
	x = y = z = 0;
	int ct = 0;
	for(int i = 1; i <= n; i++){
		x = (y * limit[1] + limit[2]) % rp;
		y = (z * limit[3] + limit[4]) % rp;
		z = (x * limit[5] + limit[6]) % rp;
		int BX = x % 20 + 1;
		int X = x % 20 * 100 + y % 10 * 10 + z % 10;
		x = (y * limit[1] + limit[2]) % rp;
		y = (z * limit[3] + limit[4]) % rp;
		z = (x * limit[5] + limit[6]) % rp;
		int BY = x % 20 + 1;
		int Y = x % 20 * 100 + y % 10 * 10 + z % 10;
		auto [cc, c] = get(BX, BY);
		ans += cc - c * (X + Y);
		ct += c;
	}
	// dbg(ans);
	double res = ans / (100.0 * ct);
	cout << fixed << setprecision(5) << res << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}