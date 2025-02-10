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

const int maxn = 2e6 + 5;
vector <int> v[maxn];
unordered_map<int,int>mp;

void solve(){
    int n,k;cin >> n >> k;
    //k = abs(k);
    vector <int> a(n + 5);
    int mx = 0;
    for (int i = 1;i <= n;i++) {
    	cin >> a[i];
    	v[a[i] + 1000000].push_back(i);
    	mp[a[i]]++;
    }
    for (auto i : mp) mx = max(mx,i.second);
   	//dbg(mx);
   	if (k == 0) {
   		cout << mx << '\n';
   		return ;
   	}
    vector <int> b;
    if (k > 0) {
    	for (int i = -1e6;i <= 1e6;i++) {
	    	int now = i + 1e6;
	    	int v1 = now - k,v2 = now;
	    	if (v1 < 0) continue;
	    	if (!v[v1].empty() && !v[v2].empty()) {
	    		int len1 = v[v1].size(),len2 = v[v2].size();
	    		int l1 = 0,l2 = 0;
	    		b.clear();
	    		while (l1 < len1 && l2 < len2) {
	    			if (v[v1][l1] < v[v2][l2]) {
	    				b.push_back(1);
	    				l1++;
	    			}
	    			else {
	    				b.push_back(-1);
	    				l2++;
	    			}
	    		}
	    		while (l1 < len1) {
	    			b.push_back(1);
	    			l1++;
	    		}
	    		while (l2 < len2) {
	    			b.push_back(-1);
	    			l2++;
	    		}
	    		int ans = 0,res = 0,len = b.size();
	    		for (int j = 0;j < len;j++) {
	    			res = max(b[j],res + b[j]);
	    			res = max(res,(int)0);
	    			ans = max(ans,res);
	    		}
	    		mx = max(mx,ans + mp[i]);
	    	}
    	}
    }
    else {
    	for (int i = -1e6;i <= 1e6;i++) {
	    	int now = i + 1e6;
	    	int v1 = now - k,v2 = now;
	    	//dbg(v1,v2,i);
	    	if (v1 > 2000000) continue;
	    	if (!v[v1].empty() && !v[v2].empty()) {
	    		int len1 = v[v1].size(),len2 = v[v2].size();
	    		int l1 = 0,l2 = 0;
	    		b.clear();
	    		while (l1 < len1 && l2 < len2) {
	    			if (v[v1][l1] < v[v2][l2]) {
	    				b.push_back(1);
	    				l1++;
	    			}
	    			else {
	    				b.push_back(-1);
	    				l2++;
	    			}
	    		}
	    		while (l1 < len1) {
	    			b.push_back(1);
	    			l1++;
	    		}
	    		while (l2 < len2) {
	    			b.push_back(-1);
	    			l2++;
	    		}
	    		int ans = 0,res = 0,len = b.size();
	    		for (int j = 0;j < len;j++) {
	    			res = max(b[j],res + b[j]);
	    			res = max(res,(int)0);
	    			ans = max(ans,res);
	    		}
	    		mx = max(mx,ans + mp[i]);
	    	}
    	}
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