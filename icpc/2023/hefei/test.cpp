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
    int n;cin >> n;
    int mid;
    if (n % 2 == 0) {
    	mid = n / 2;
    }
    else mid = n / 2;
    map<string,int>mp;
    int ok = -1;
    string ans;
    for (int i = 1;i <= n;++i) {
    	string s;cin >> s;
    	mp[s]++;
    	if (mp[s] > mid) {
    		ok = 1;
    		ans = s;
    	}
    }
    if (ok == 1) cout << ans;
    else if (ok == -1)cout << "uh-oh";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}