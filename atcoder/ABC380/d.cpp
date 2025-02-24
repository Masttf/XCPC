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
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    auto dfs = [&](auto self, int x, int f, int d) -> int{
    	if(d == 1) return f;
    	if(x > d / 2) return self(self, x - d / 2, f ^ 1, d / 2);
    	else return self(self, x, f, d / 2);
    };
    int q; cin >> q;
    for(int i = 1; i <= q; i++){
    	int x; cin >> x;
    	int pos = (x + n - 1) / n;
    	int d = 1;
    	while(d < pos){
    		d *= 2;
    	}
    	int f = dfs(dfs, pos, 0, d);
    	int w = x % n;
    	if(w == 0) w = n;
    	if(f == 1){
    		char res;
    		if(s[w] >= 'a' && s[w] <= 'z'){
    			res = s[w] - 'a' + 'A';
    		}else res = s[w] - 'A' + 'a';
    		cout << res << ' ';
    	}else cout << s[w] << ' ';
    }
    cout << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}