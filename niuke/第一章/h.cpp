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
    int n, b; cin >> n >> b;
    vector<int> a(n + 1);
    int pos = -1;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	if(a[i] == b){
    		a[i] = 0;
    		pos = i;
    	}else if(a[i] < b)a[i] = -1;
    	else a[i] = 1;
    }
    vector<int> pre(n + 1);
    int ans = 0;
    map<int, int> m1, m0;
    m0[0]++;
    for(int i = pos - 1; i >= 1; i--){
    	pre[i] = pre[i + 1] + a[i];
    	if((pos - i) % 2 == 1)m1[pre[i]]++;
    	else m0[pre[i]]++;
    	// dbg(i, pre[i]);
    }
    for(int i = pos; i <= n; i++){
    	if(i != pos)pre[i] = pre[i - 1] + a[i];
    	// dbg(i, pre[i]);
    	if((i - pos + 1) % 2 == 1){
    		if(m0.count(-pre[i])){
    			ans += m0[-pre[i]];
    		}
    	}else{
    		if(m1.count(-pre[i])){
    			ans += m1[-pre[i]];
    		}
    	}
    	// dbg(i, ans);
    }
    cout << ans << '\n';
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
/*
排列
有b
cnt <b = cnt >b

*/