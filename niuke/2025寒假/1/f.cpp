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
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
	for(int i = n; i >= 1; i--){
		map<int, int> mp;
		int l = i;
		while(mp.size() <= 2){
			if(l == 0){
				l++;
				break;
			}
			mp[a[l]]++;
			if(mp.size() == 3){
				mp.erase(a[l]);
				l++;
				break;
			}
			l--;
		}
		if(mp.size() <= 1)break;
		map<int, int> sum;
		int s = 0;
		// dbg(l, i);
		sum[0]++;
		for(int j = l; j <= i; j++){
			if(a[j] == a[i]) s += 1;
			else s += -1;
			// dbg(s);
			if(sum.count(s)){
				ans += sum[s];
			}
			sum[s]++;
		}
		i = l;
		while(a[i] == a[l])i++;
	}
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
子数组
长度为偶数不需要考虑
两种个数相同保证了长度是偶数
1.种类为2 可以二分出来这个区间
2.两种种类个数一样，
如果只有两种
标记-1， 1
即可统计完

做法
枚举每一段只有两种字母的区间

*/