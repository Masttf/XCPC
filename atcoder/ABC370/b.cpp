#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
void solve(){
    int n; cin >> n;
    vector a(n + 1,vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= i; j++){
    		cin >> a[i][j];
    	}
    }
    int now = 1;
    for(int i = 1; i <= n; i++){
    	now = a[max(now, i)][min(now, i)];
    }
    cout << now << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}