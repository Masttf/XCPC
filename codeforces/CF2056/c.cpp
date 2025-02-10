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
    if(n == 6){
    	cout << "1 1 2 3 1 2\n";
    	return ;
    }
    vector<int> ans(n + 1);
    ans[1] = 1;
    n--;
    int pos = 1;
    for(int i = 1; i <= (n + 1) / 2; i++){
    	ans[++pos] = i;
    }
    for(int i = (n + 1) / 2 + 1; i <= n; i++){
    	ans[++pos] = i - (n + 1) / 2;
    }
    n++;
    for(int i = 1; i <= n; i++){
    	cout << ans[i] << ' ';
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
1 321 321
1 2 3 1 2 3 1
5
1 2 3 4 1 2 3 1
*/