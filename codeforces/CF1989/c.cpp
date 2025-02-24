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
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    array<int, 2>val = {0, 0};
	int c1 = 0, c2 = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 1 && b[i] == 1){
			c1++;
		}else if(a[i] == -1 && b[i] == -1){
			c2++;
		}else{
			if(a[i] == 1)val[0]++;
			if(b[i] == 1)val[1]++;
		}
	}
	int mx = -n;
	for(int i = 0; i <= c1; i++){
		int t1 = val[0] + i;
		int t2 = val[1] + c1 - i;
		int d = abs(t2 - t1);
		if(c2 <= d){
			mx = max(mx, min(t1, t2));
		}else{
			int k = c2 - d;
			k = (k + 1) / 2;
			mx = max(mx, min(t1, t2) - k);
		}
	}
	cout << mx << '\n';
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