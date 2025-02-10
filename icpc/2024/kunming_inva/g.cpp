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

const int maxn = 1e6 + 5;
int ans[maxn];

void solve(){
    int n;cin >> n;
    int res = 0;
    for (int i = 0;i < n;i++) res ^= i;
   	if (res == 0) {
   		cout << "impossible" << '\n';
   		return ;
   	}
   	if (n == 2) {
   		cout << "1 0" << '\n';
   		return ;
   	}
   	int op[4] = {2,-1,2,1};
   	int now = 0;
   	int num = 2;
   	ans[1] = 1;
   	ans[2] = 0;
   	for (int i = 3;i <= n;i++) {
   		ans[i] = num;
   		num += op[now];
   		now = (now + 1) % 4;
   	}
   	res = 0;
   	for (int i = 1;i <= n;i++) {
   		res ^= ans[i];
   		if (res == 0) while (1);
   	}
   	for (int i = 1;i <= n;i++) {
   		cout << ans[i] << ' ';
   	}
   	cout << '\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
     cin >> t;
    while(t--)solve();
    return 0;
}