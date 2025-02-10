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
    int N = 2e5;
    vector<vector<int>> tr(26, vector<int>(N + 1));
    vector<int> need(N + 1, N);
    int p = 0;
    int tot = 0;
    auto insert = [&](string s) -> int{
    	int p = 0;
    	int mi = s.size();
    	int flag = 1;
    	int len = 0;
    	for(auto x : s){
    		int d = x - 'a';
    		if(!tr[d][p]){
    			flag = 0;
    			tr[d][p] = ++tot;
    		}
    		p = tr[d][p];
    		len++;
    		if(flag)mi = min(mi, need[p] + (int)s.size() - len);
    		need[p] = min(need[p], (int)s.size() - len);
    		// dbg(p, need[p]);
    	}
    	return mi;
    };
    for(int i = 1; i <= n; i++){
    	string s; cin >> s;
    	cout << insert(s) << '\n';
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