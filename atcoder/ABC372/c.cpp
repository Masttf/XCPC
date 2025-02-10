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
    int q; cin >> q;
    string s; cin >> s;
    s = ' ' + s;
    int cnt = 0;
    for(int i = 2; i < n; i++){
    	if(s[i] == 'B' && s[i - 1] == 'A' && s[i + 1] == 'C')cnt++;
    }
    auto check = [&](int x) -> int{
    	int res = 0;
    	if(x >= 2 && s[x - 2] == 'A' && s[x - 1] == 'B' && s[x] == 'C')res++;
    	if(x >= 1 && s[x - 1] == 'A' && s[x] == 'B' && s[x + 1] == 'C')res++;
    	if(x <= n - 2 && s[x] == 'A' && s[x + 1] == 'B' && s[x + 2] == 'C')res++;
    	return res;
    };
    for(int i = 1; i <= q; i++){
    	int x; cin >> x;
    	char t; cin >> t;
    	cnt -= check(x);
    	s[x] = t;
    	cnt += check(x);
    	cout << cnt << '\n';
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}