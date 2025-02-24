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
    int a, b; cin >> a >> b;
    int l = 0, r = 1e5;
    int ans = -1;
    auto check = [&](int tot) -> bool{
    	int cnta = a;
    	int cntb = b;
    	for(int i = tot; i >= 1; i--){
    		if(cnta >= i){
    			cnta -= i;
    		}else if(cntb >= i){
    			cntb -= i;
    		}else return false;
    	}
    	return true;
    };
    while(l <= r){
    	int mid = (l + r) >> 1;
    	if(check(mid)){
    		ans = mid;
    		l = mid + 1;
    	}else r = mid - 1;
    }
    vector<int> ansa, ansb;
    for(int i = ans; i >= 1; i--){
    	if(a >= i){
    		a -= i;
    		ansa.push_back(i);
    	}else if(b >= i){
    		b -= i;
    		ansb.push_back(i);
    	}
    }
    cout << ansa.size() << '\n';
    for(auto x : ansa){
    	cout << x << ' ';
    }
    cout << '\n';
    cout << ansb.size() << '\n';
    for(auto x : ansb){
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
/*
结论1 结果一定是连续
能放就放, 优?
如何证明这东西是对的？

*/