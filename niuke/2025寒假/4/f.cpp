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
    int n, p, k; cin >> n >> p >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	a[i] %= p;
    }
    sort(a.begin() + 1, a.end());
    // for(int i = 1; i <= n; i++){
    // 	cout << a[i] << ' ';
    // }
    // cout << endl;
    priority_queue<array<int, 4>> q;
    for(int i = 1; i <= n; i++){
    	int l = i + 1, r = n;
    	int res = n + 1;
    	while(l <= r){
    		int mid = (l + r) >> 1;
    		if(a[mid] + a[i] >= p){
    			r = mid - 1;
    			res = mid;
    		}else{
    			l = mid + 1;
    		}
    	}
    	// dbg(i, res);
    	if(res - 1 > i){
    		q.push({a[i] + a[res - 1], res - 1, i + 1, i});
    	}
    	if(res <= n){
    		q.push({a[i] + a[n] - p, n, res, i});
    	}
    }
    vector<int> ans(k + 1, -1);
    int now = 1;
    while(!q.empty() && now <= k){
    	auto [val, r, l, id] = q.top();
    	q.pop();
    	ans[now] = val;
    	if(r != l){
    		q.push({(a[id] + a[r - 1]) % p, r - 1, l, id});
    	}
    	now++;
    }
    for(int i = 1; i <= k; i++){
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
前k大在 %p 情况下
最大就是 p - 1
ai + aj = k * p + p - 1

ai + aj + 1 是p的倍数
同理 ai + aj + d 是p的倍数 那么结果就是d

不对
(ai + aj) % p
= (ai % p + aj % p) % p
那么情况只有两种一种是和超过p, 一种是和不超过p
先sort 一下 然后算出分界点 既可以拿到每个数的贡献
然后优先队列即可
*/