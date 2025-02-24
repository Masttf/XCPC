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
		vector<int> bl(n + 1, -1);
		auto insert = [&](int x, int id) -> void{
			for(int i = 14; i >= 0; i--){
				if(x >> i & 1){
					if(d[i].first){
						x ^= d[i].first;
					}else{
						bl[id] = i;
						d[i] = {x, id};
						break;
					}
				}
			}
		};
		for(int i = 1; i <= n; i++){
			insert(a[i], i);
		}
		// sort
		int l = 0;
		for(int i = 14; i >= 0; i--){
			if(d[i].first){
				l++;
				for(int j = d[i].second; j > l; j--){
					if(bl[j] != -1){
						d[bl[j]].second = j - 1;
					}
					if(bl[j - 1] != -1){
						d[bl[j - 1]].second = j;
					}
					swap(bl[j], bl[j - 1]);
					swap(a[j], a[j - 1]);
					swp(j, j - 1);
				}
				// dbg(i, d[i].second);
			}
		}
		// dbg(l);
		// for(int i = 1; i <= n; i++){
		// 	cout << a[i] << " \n"[i == n];
		// }
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
		for(int i = 1; i <= l; i++){
			for(int j = 14; j >= 0; j--){
				if(a[i] >> j & 1){
					if(d[j].first){
						if(d[j].second == i)break;
						a[i] ^= d[j].first;
						Xor(i, d[j].second);
					}
				}
				// dbg(j, a[i]);
			}
		}
		// for(int i = 1; i <= n; i++){
		// 	cout << a[i] << " \n"[i == n];
		// }
		for(int i = 14; i >= 0; i--){
			for(int j = i - 1; j >= 0; j--){
				if((d[i].first >> j & 1 )&& d[j].first){
					a[d[i].second] ^= d[j].first;
					d[i].first ^= d[j].first;
					Xor(d[i].second, d[j].second);
				}
			}
		}
		// for(int i = 1; i <= n; i++){
		// 	cout << a[i] << " \n"[i == n];
		// }
		for(int i = l, r = 0; i >= 1; i--, r++){
			for(int j = i; j < n - r; j++){
				swp(j, j + 1);
				swap(a[j], a[j + 1]);
				int temp = a[j];
				for(int k = 14; k >= 0; k--){
					if(temp >> k & 1){
						if(d[k].first){
							temp ^= d[k].first;
							if(d[k].second == i){
								a[j] ^= d[k].first;
								op.push_back({j, j + 1});
							}
						}
					}
				}
			}
			// dbg(i);
			// for(int j = 1; j <= n; j++){
			// 	cout << a[j] << " \n"[j == n];
			// }
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