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
constexpr int N = 1e6 + 5;
int cnt[N], num[N], vis[N];
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	cnt[a[i]]++;
    	num[a[i]]++;
    }
    for(int i = N - 1; i >= 1; i--){
    	if(!num[i])continue;
    	for(int j = i * 2; j < N; j += i){
    		if(cnt[j]){
    			vis[i] = 1;
    			cnt[j] += cnt[i];
    		}
    	}
    }
    int mi = 1e9;
    for(int i = 1; i < N; i++){
    	if(!num[i])continue;
    	if(!vis[i]){
    		mi = min(mi, num[i]);
    	}
    }
    // dbg(chose);
    sort(a.begin() + 1, a.end());
	int tot = 1;
	for(int i = n - 1; i >= 1; i--){
		if(a[i] != a[i + 1])tot++;
	}
	vector<int> ans(n + 1);
	ans[0] = tot;
	ans[n] = 1;
	set<pair<int, int>>s;
	int flag = 0;
	int chose = -1;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	for(int i = 1; i < N; i++){
		if(num[i] && num[i] == cnt[i]){
			if(vis[i])q.push({cnt[i], i});
			else{
				if(!flag && mi == num[i]){
					flag = 1;
					chose = i;
					q.push({cnt[i] + 1, i});
				}else s.insert({cnt[i], i});
			}
		}
	}
	
	int sum = 0;
	int j = 0;
	for(int i = 1; i < n; i++){
		while(!q.empty() && sum + q.top().first <= i){
			j++;
			auto [c, val] = q.top();
			dbg(val);
			q.pop();
			sum += c;
			if(val == chose){
				flag = 2;
				sum--;
			}
			if(flag == 2){
				for(auto [x, y] : s){
					q.push({x, y});
				}
				s.clear();
			}
			
			for(int k = 2 * val; k < N; k += val){
				if(cnt[k]){
					cnt[k] -= c;
					if(cnt[k] == num[k]){
						if(vis[k])q.push({cnt[k], k});
						else{
							if(!flag && mi == num[k]){
								flag = 1;
								chose = k;
								q.push({cnt[k] + 1, k});
							}else s.insert({cnt[k], k});
						}
					}
				}
			}
		}
		if(flag == 2)ans[i] = tot - j + 1;
		else ans[i] = tot - j;
	}
	for(auto x : ans){
		cout << x << ' ';
	}
	cout << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}