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
    int m; cin >> m;
    vector<int>res;
    while(m){
    	res.push_back(m % 3);
    	m /= 3;
    }
    vector<int>temp;
    int sz = res.size();
    for(int i = 0; i < sz; i++){
    	for(int j = 1; j <= res[i]; j++){
    		temp.push_back(i);
    	}
    }
    cout << temp.size() << '\n';
    for(auto x : temp) cout << x << ' ';
    cout << '\n';
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