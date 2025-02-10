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
    vector<pair<int, int>> a(n + 1);
    map<int, int> mpx;
    set<int> s;
    for(int i = 1; i <= n; i++){
    	int x; cin >> x;
    	char ty; cin >> ty;
    	if(ty == '.'){
    		a[i] = {x, 0};
    	}else if(ty == '+'){
    		a[i] = {x, 1};
    	}else a[i] = {x, -1};
    	s.insert(x);
    	s.insert(x - 1);
    	s.insert(x + 1);
    }
    int cnt = 0;
    for(auto x : s){
    	mpx[x] = ++cnt;
    }
    vector<int> val(s.size() + 5);
    for(int i = 1; i <= n; i++){
    	auto [x, ty] = a[i];
    	x = mpx[x];
    	if(ty == 0){
    		val[x]++;
    		val[x + 1]--;
    	}else if(ty == 1){
    		val[0]++;
    		val[x]--;
    	}else{
    		val[x + 1]++;
    	}
    }
    for(int i = 1; i < val.size(); i++){
    	val[i] += val[i - 1];
    }
    int ans = 0;
    for(auto x : val){
    	ans = max(ans, x);
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