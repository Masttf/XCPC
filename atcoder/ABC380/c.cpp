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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    s = ' ' + s;
    vector<char>ans(n + 1);
    int last = 0;
    vector<int> l(k + 1), r(k + 1);
    int cnt = 0;
    for(int i = 1; i <= n; i++){
    	if(cnt == k)break;
    	if(s[i] == '0'){
    		if(i - last > 1){
    			cnt++;
    			l[cnt] = last + 1;
    			r[cnt] = i - 1;
    		}
    		last = i;
    	}
    }
    if(cnt != k){
    	cnt++;
    	l[cnt] = last + 1;
    	r[cnt] = n;
    }
    for(int i = 1; i <= r[k - 1]; i++){
    	ans[i] = s[i];
    }
    for(int i = r[k - 1] + 1; i <= r[k - 1] + r[k] - l[k] + 1; i++){
    	ans[i] = '1';
    }
    for(int i = r[k - 1] + r[k] - l[k] + 2; i <= r[k]; i++){
    	ans[i] = '0';
    }
    for(int i = r[k] + 1; i <= n; i++){
    	ans[i] = s[i];
    }
    for(int i = 1; i <= n; i++){
    	cout << ans[i];
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