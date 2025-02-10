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
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    set<int> s1, s2;
    for(int i = 1; i <= n; i++){
    	s1.insert(a[i]);
    	s2.insert(b[i]);
    }
    if(s1.size() >= 3 || s2.size() >= 3){
    	cout << "Yes\n";
    	return ;
    }
    if(s1.size() == 2 && s2.size() == 2){
    	cout << "Yes\n";
    	return ;
    }
    cout << "No\n";
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