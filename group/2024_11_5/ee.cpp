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
int vis[N], cnt[N], num[N];
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    int v = 1;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	cnt[a[i]]++;
    	num[a[i]]++;
    }
    for(int i = N - 1; i >= 1; i--){
    	if(!cnt[i])continue;
    	for(int j = 2 * i; j < N; j += i){
    		if(cnt[j]){
    			vis[i] = j;
    			cnt[j] += cnt[i];
    		}
    	}
    }
    sort(a.begin() + 1, a.end());
   	int tot = 0;
   	for(int i = n; i >= 1; i--){
   		if(a[i] != a[i + 1])tot++;
   	}
   	vector<int> ans(n + 1);
   	ans[0] = tot;
   	ans[n] = 1;
   	vector<int> res;
   	vector<int> chose;
   	for(int i = 1; i < N; i++){
   		if(vis[i]){
   			res.push_back(i);
   		}else if(cnt[i]){
   			chose.push_back(num[i]);
   		}
   	}
   	vector<int> pre(chose.size() + 1);
   	for(int i = 0; i < chose.size(); i++){
   		pre[i + 1] = pre[i] + chose[i];
   	}
   	sort(res.begin(), res.end(), [&](int x, int y) -> bool{
   		return cnt[x] < cnt[y];
   	});
   	// for(auto x : res){
   	// 	cout << x << ' ' << cnt[x] << '\n';
   	// }
   	// cout << endl;
   	int sum = 0;
   	for(int i = 1, j = 0; i < n; i++){
   		while(j < res.size() && sum + cnt[res[j]] <= i){
   			sum += cnt[res[j]];
   			for(int k = 2 * res[j]; k < N; k += res[j]){
   				if(cnt[k]){
   					cnt[k] -= cnt[res[j]];
   				}
   			}
   			j++;
   		}
   		int d = i - sum;
   		int l = 1, r = chose.size();
   		int res = 0;
   		while(l <= r){
   			int mid = (l + r) >> 1;
   			if(pre[mid] <= d){
   				res = mid - 1;
   				l = mid + 1;
   			}else r = mid - 1;
   		}
   		ans[i] = tot - j - res;
   	}
   	for(int i = 0; i <= n; i++){
   		cout << ans[i] << ' ';
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
/*
相当于选k个数字 变成他们的lcm 的倍数, 最优肯定是变成已经有的
贡献是k / k-1
数字相同的应该同时操作, 或者不操作
所以个数少的先考虑, 因为同样都是减1, 我操作次数还少
lcm动的时候应该捆绑上 因子

*/