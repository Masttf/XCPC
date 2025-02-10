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
    int n, m; cin >> n >> m;
    if(m == n || (m + 1) * 26 < n){
    	cout << "NO\n";
    	return ;
    }
    vector<char> ans(n + 1);
    for(int i = 0; i < 26; i++){
    	int s = (m + 1) * i + 1;
    	char res = 'a' + i;
    	for(int j = 0; j <= m && s + j <= n; j++){
    		ans[s + j] = res;
    	}
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++){
    	cout << ans[i];
    }
    cout << '\n';
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

aaaaaaa(m + 1)个

m = 3
aaaabbbb
aaababbb
m个长度
首字母和尾字母后面不再出现

*/