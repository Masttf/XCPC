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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }
    int ans = 0;
    vector<int>res;
    int temp = a[1];
    while(temp){
    	res.push_back(temp % 10);
    	temp /= 10;
    }
    auto add = [&](int x) -> void{
    	vector<int> t;
    	while(x){
    		t.push_back(x % 10);
    		x /= 10;
    	}
    	if(t.size() > res.size())swap(res, t);
    	for(int i = 0; i < t.size(); i++){
    		res[i] += t[i];
    	}
    	for(int i = 0; i < res.size(); i++){
    		if(res[i] >= 10){
    			ans++;
    			if(i != res.size() - 1)res[i + 1] += res[i] / 10;
    			else res.push_back(res[i] / 10);
    			res[i] %= 10;
    		}
    	}
    };
    for(int i = 2; i <= n; i++){
    	add(a[i]);
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