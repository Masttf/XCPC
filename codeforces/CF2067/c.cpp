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
    int t = n;
    int ans = 20;
    auto check = [&]() -> bool{
    	string res = to_string(n);
    	return res.find('7') != -1;
    };
    if(check())ans = 0;
    int p = 9;
    for(int i = 1; i <= 10; i++){
    	n = t;
		for(int j = 1; j <= 20; j++){
	    	n += p;
	    	if(check())ans = min(ans, j);
	    }
	    p = p * 10 + 9;
    }
    cout << ans << '\n';
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
/*
20 次以内
*/