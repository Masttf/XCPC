#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x) & -(x))
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
    int n, P; cin >> n >> P;
    vector<array<int, 2>> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin() + 1, a.end(), [&](array<int, 2>x, array<int, 2>y) -> bool{
    	if(x[0] != y[0])return x[0] > y[0];
    	return x[1] < y[1];
    });
    int ans = 0;
    vector<int> A(n + 5), B(n + 5);
    vector<int> p;
    for(int i = 1; i <= n; i++){
    	A[i] = a[i][0];
    	B[i] = a[i][1];
    	// dbg(i, A[i], B[i]);
    	p.push_back(B[i]);
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    auto get = [&](int x) -> int{
    	return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
    };
    vector<int> tr(n + 1);
    auto add = [&](int x) -> void{
    	while(x <= n){
    		tr[x]++;
    		x += lowbit(x);
    	}
    };
    auto ask = [&](int x) -> int{
    	int res = 0;
    	while(x){
    		res += tr[x];
    		x -= lowbit(x);
    	}
    	return res;
    };
    int mx = 0;

    for(int i = 0; i <= n; i++){
    	int temp = mx;
    	mx = max(mx, A[i + 1]);
    	// dbg(i, mx);
    	int limit = mx * P;
    	if(limit % 100 !=0){
    		limit = limit / 100 + 1;
    	}else limit = limit / 100;
    	int cnt = 0;
    	int l = i + 1, r = n;
    	while(l <= r){
    		int mid = (l + r) >> 1;
    		if(A[mid] >= limit){
    			cnt = mid - i;
    			l = mid + 1;
    		}else r = mid - 1;
    	}
    	int pos = get(limit);
    	cnt += ask(n) - ask(pos - 1);
    	add(get(B[i + 1]));
    	mx = max(temp, B[i + 1]);
    	ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
    	cout << "Case #" << i << ": ";
    	solve();
    }
    return 0;
}