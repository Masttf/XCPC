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
    vector<int> a(m + 1);
    for(int i = 1; i <= m; i++){
    	cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    
    vector<int> res;
    for(int i = 1; i < m; i++){
    	int len = a[i + 1] - a[i] - 1;
    	res.push_back(len);
    }
    int len = n - a[m] + a[1] - 1;
    res.push_back(len);
    sort(res.begin(), res.end(), greater<int>());
    int ans = 0;
    int cnt = 0;
    for(auto x : res){
    	x -= cnt * 2;
    	if(x <= 0)continue;
    	if(x == 1){
    		ans++;
    		cnt++;
    	}else{
    		ans += x - 1;
    		cnt += 2;
    	}
    }
    cout << n - ans << '\n';
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
20
3 7 12
3 4 10
9 1
*/