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
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	a[i] = s[i] - 'a';
    }
    int ans = n;
    int l = 1, r = n;
    while(l <= r && a[l] == a[r]){
    	l++;
    	r--;
    	ans -= 2;
    }
    // dbg(n, l, r, r - l + 1);
    // for(int i = l; i <= r; i++){
    // 	cout << a[i] << ' ';
    // }
    // cout << endl;
    vector<int> cnt1(26, 0), cnt2(26, 0);
    for(int i = l; i <= r; i++){
    	cnt1[a[i]]++;
    }
    int mid = n / 2;
    for(int i = l; i <= r; i++){
    	cnt1[a[i]]--;
    	cnt2[a[i]]++;
    	if(i > mid){
    		// dbg(s[i], s[mid - (i - mid - 1)]);
    		if(a[i] == a[mid - (i - mid - 1)]){
    			cnt2[a[i]] -= 2;
    		}
    	}
    	// dbg(i, cnt2[a[i]], cnt1[a[i]]);
    	if(cnt2[a[i]] > cnt1[a[i]])break;
    	// dbg(i, r);
    	ans = min(ans, (r - i));
    }
    for(int i = 0; i < 26; i++){
    	cnt1[i] = cnt2[i] = 0;
    }
    for(int i = l; i <= r; i++){
    	cnt1[a[i]]++;
    }
    for(int i = r; i >= l; i--){
    	cnt1[a[i]]--;
    	cnt2[a[i]]++;
    	if(i <= mid){
    		if(a[i] == a[mid + (mid - i + 1)]){
    			cnt2[a[i]] -=2;
    		}
    	}
    	// dbg(i, cnt1[a[i]], cnt2[a[i]]);
    	if(cnt2[a[i]] > cnt1[a[i]])break;
    	ans = min(ans, (i - l));
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
长度为偶数也就是说成对出现
反转子串
那么一开始是 1 - n
如何1和n能对上 不需要管
不能对上则至少保留一边
枚举保留那一边?
跨界可以调整中间对称
*/