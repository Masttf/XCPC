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
void solve(){
    int n; cin >> n;
    vector<int> A(n + 1), B(n + 1);
    for(int i = 1; i <= n; i++) cin >> A[i];
    for(int i = 1; i <= n; i++) cin >> B[i];
    auto get = [&](vector<int> &a) -> vector<pair<int, int>>{
    	vector<pair<int, int>> op;
    	vector<pair<int, int>> d(20);
		auto swp = [&](int x, int y) -> void{
			op.push_back({y, x});
			op.push_back({x, y});
			op.push_back({y, x});
		};
		auto Xor = [&](int x, int y) -> void{
			if(x < y){
				for(int i = y; i > x + 1; i--){
					swp(i, i - 1);
				}
				op.push_back({x, x + 1});
				for(int i = x + 1; i < y; i++){
					swp(i, i + 1);
				}
			}else{
				for(int i = y; i < x - 1; i++){
					swp(i, i + 1);
				}
				op.push_back({x, x - 1});
				for(int i = x - 1; i > y; i--){
					swp(i, i - 1);
				}
			}
		};
		vector<int> bl(n + 1, -1);
		vector<int> need(n + 1);
		for(int i = 1; i <= n; i++){
			int x = a[i];
			int s = 0;
			for(int j = 14; j >= 0; j--){
				if(x >> j & 1){
					if(d[j].first){
						s ^= need[d[j].second];
						x ^= d[j].first;
					}else{
						s |= (1 << j);
						d[j] = {x, i};
						bl[i] = j;
						break;
					}
				}
			}
			need[i] = s;
		}
		for(int i = 1, r = 0; i <= n - r; i++){
			if(bl[i] != -1){
				for(int j = i; j < n - r; j++){
					if(bl[j] != -1){
						d[bl[j]].second = j + 1;
					}
					if(bl[j + 1] != -1){
						d[bl[j + 1]].second = j;
					}
					swap(bl[j], bl[j + 1]);
					swap(a[j], a[j + 1]);
					swap(need[j], need[j + 1]);
					if(need[j] >> bl[j + 1] & 1){
						a[j] ^= a[j + 1];
						op.push_back({j, j + 1});
					}
				}
				r++;
			}
		}
		dbg(r);
		for(int i = 1; i <= n; i++){
			cout << a[i] << " \n"[i == n];
		}
		return op;
    };
    // vector<int> t = A;
    // vector<int> t2 = B;
    vector<pair<int, int>> ans1 = get(A);
    vector<pair<int, int>> ans2 = get(B);
    reverse(ans2.begin(), ans2.end());
    cout << ans1.size() + ans2.size() << '\n';
    for(auto [x, y] : ans1){
    	// t[x] = t[x] ^ t[y];
    	cout << x << ' ' << y << '\n';
    }
    // dbg("BB");
    for(auto [x, y] : ans2){
    	// t[x] = t[x] ^ t[y];
    	cout << x << ' ' << y << '\n';
    }

	// for(int i = 1; i <= n; i++){
	// 	cout << t[i] << " \n"[i == n];
	// }
	// for(int i = 1; i <= n; i++){
	// 	cout << t2[i] << " \n"[i == n];
	// }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}