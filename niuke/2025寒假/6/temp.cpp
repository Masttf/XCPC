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
    vector<int> res;
    int n = 100;
    vector<int> a(n + 1);
    for(int i = 0, j = 1; j <= n; i += 2, j++){
    	a[j] = i;
    }
    for(int i = 1; i <= n; i++){
    	int sum = a[i];
    	for(int j = i + 1; j <= n; j++){
    		sum += a[j];
    		res.push_back(sum);
    	}
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    for(auto x : res)cout << x << ' ';
    cout << endl;
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