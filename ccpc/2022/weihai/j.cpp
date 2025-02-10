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
    int n,k;cin >> n >> k;
    vector <int> a(n + 5);
    unordered_map<int,int>mp;
    unordered_map<int,int>lim;
    vector<pair<int,int>>pi(k + 5);
    for (int i = 1;i <= n;i++) cin >> a[i],mp[a[i]]++;
    for (int i = 1;i <= k;i++) {
    	cin >> pi[i].first >> pi[i].second;
    	int x = pi[i].first,y = pi[i].second;
    	lim[x] = y;
    	if (y == 0) lim[x] = -1;
    } 
    sort(pi.begin() + 1,pi.begin() + 1 + n);
    int cnt = 0;
    for (int i = 1;i <= k;i++) {
    	int x = pi[i].first,y = pi[i].second;
    	if (mp[x] >= y + 2) {
    		cout << "FuuFuu" << '\n';
    		return ;
    	}
    	if (mp[x] >= y + 1) cnt++;
    }
    if (cnt >= 2) {
    	cout << "FuuFuu" << '\n';
    	return ;
    }
    int ok = 0;
    for (int i = 1;i <= k;i++) {
    	int x = pi[i].first,y = pi[i].second;
    	if (mp[x] == y + 1) {
    		if (x == 0) {
    			cout << "FuuFuu" << '\n';
    			return ;
    		}
    		if (lim[x - 1] == -1) {
    			if (mp[x - 1] == 0) {
    				cout << "FuuFuu" << '\n';
    				return ;
    			}
    		}
    		else {
    			 if (mp[x - 1] == lim[x - 1]) {
    				cout << "FuuFuu" << '\n';
    				return ;
    			}
    		}
    		ok = 1;
    		mp[x]--;
    		mp[x - 1]++;
    	}
    }
    //dbg(1);
    a.clear();
    for (auto i : mp) {
    	int now = i.second;
    	while (now) {
    		a.push_back(i.first);
    		now--;
    	}
    }
    //dbg(1);
    int now = a.size() - 1,sum = 0;
    for (int i = k;i >= 1;i--) {
    	int x = pi[i].first;
    	if (lim[x] == -1) {
    		int all = 0,ti = 0;
    		while (now >= 0) {
    			dbg(a[now],x);
    			if (a[now] > x) {
    				all += a[now] - x;
    				ti++;
    				now--;
    			}
    			else break;
    		}
    		dbg(all,ti);
    		int st = x + 1;
    		while (lim[st] > 0) {
    			if (ti >= lim[st]) {
    				all -= (ti - lim[st]);
    				ti -= lim[st];
    				if (ti == 0) break;
    			}
    			else {
    				ti = 0;
    				break;
    			}
    		}
    		sum += all;
    		dbg(all);
    	}
    }
    //dbg(1);
    if (lim[0] != -1 && lim[0] > 0) {
    	int all = 0,ti = 0;
    	while (now >= 0) {
    		if (a[now] > 0) {
    			all += a[now] - 0;
    			ti++;
    			now--;
    		}
    		else break;
    	}
    	int st = 0;
    	while (lim[st] > 0) {
    		if (ti >= lim[st]) {
    			all -= (ti - lim[st]);
    			ti -= lim[st];
   				if (ti == 0) break;
    		}
    		else {
    			ti = 0;
    			break;
    		}
    	}
    	sum += all;
    }
    dbg(sum);
    if (ok) {
    	if (sum & 1) {
    		cout << "FuuFuu" << '\n';
    		return ;
    	}
    	else {
    		cout << "Pico" << '\n';
    		return ;
    	}
    }
    else {
    	if (sum & 1) {
    		cout << "Pico" << '\n'; 
    	}
    	else {
    		cout << "FuuFuu" << '\n';
    	} 
    }
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