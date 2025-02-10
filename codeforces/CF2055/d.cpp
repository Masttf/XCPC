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
    int n, k, l; cin >> n >> k >> l;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	a[i] *= 2;
    }
    k *= 2;
    l *= 2;
    int ans = a[1];
	int pos = k;
	for(int i = 2; i <= n; i++){
		if(pos >= l)break;
		// i right
		while(i <= n){
			int l0 = a[i] - ans;
			int r0 = a[i] + ans;
			int l1 = pos - k + 1;
			int r1 = pos;
			int l = max(l0, l1);
			int r = min(r0, r1);
			if(l <= r){
				pos = r + k;
			}else if(a[i] <= pos){

			}else break;
			i++;
		}
		if(i <= n){ // 两边在走
			//左右距离pos 都是偶数位置
			int d = (a[i] - pos - ans) / 2;
			ans += d;
			pos += k + d;
		}
	}
	if(pos < l) ans += l - pos;
	cout << ans << '\n';
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
a1 肯定要
a1 -> 0
然后a1 往右移动导致 乌鸦一直往右跳
那么有用的稻草人只有左边最近的一个
所以一次跳后肯定是找到最近的左边 和右边
然后看右边过来要多久时间

*/