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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
	int pos = -1;
	auto check = [&](int x, int y, int c, int d) -> bool{
		if(y != c)return false;
		if(x + y + c > d)return true;
		else return false;
	};
	for(int i = 1; i + 3 <= n; i++){
		for(int x = i; x <= i + 3; x++){
			for(int y = i; y <= i + 3; y++){
				if(y == x)continue;
				for(int c = i; c <= i + 3; c++){
					if(c == x || c == y)continue;
					for(int d = i; d <= i + 3; d++){
						if(d == x || d == y || d == c)continue;
						if(check(a[x], a[y], a[c], a[d])){
							cout << a[x] << ' ' << a[y] << ' ' << a[c] << ' ' << a[d] << '\n';
							return ;
						}
					}
				}
			}
		}
	}
	cout << -1 << '\n';
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