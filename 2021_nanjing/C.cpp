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

unordered_map<int,int>mp;

void solve(){
    int n,k;cin >> n >> k;
    vector <int> a(n + 5);
    vector <pair<int,int>> b;
    for (int i = 1;i <= n;i++) cin >> a[i],mp[a[i]]++;
    for (int i = 1;i <= n;i++) {
    	int j = i + 1;
    	for (;j <= n;j++) {
    		if (a[j] != a[j - 1]) break;
    	}
    	int len = j - i;
    	b.push_back({a[i],len});
    	i = j - 1;
    }
    int mx = 0;
    for (auto i : mp) mx = max(mx,i.second);
    int siz = b.size();
    for (int i = 0;i < siz;i++) {
    	int nxt = b[i].first + k;
    	mx = max(mp[nxt] + b[i].second,mx);
    }
    cout << mx << '\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}
/*
n^2 -> nlog?
*/